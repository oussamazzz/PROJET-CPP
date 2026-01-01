#include "Questionnaire.h"
#include "QuestionText.h"
#include "QuestionNum.h"
#include "QuestionQCM.h"
#include <iostream>
#include <fstream>
#include <memory>

Questionnaire::Questionnaire(const std::string& t)
    : d_titre(t) {}
void Questionnaire::ajouterQuestion(std::unique_ptr<Question>  q) {
    d_questions.push_back(std::move(q));
}
int Questionnaire::taille() const
{ return d_questions.size() ;}

const std::vector<std::unique_ptr<Question>> & Questionnaire::getQuestions() const {
    return d_questions;
}
void Questionnaire::sauvegarder(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);

    if (!fichier) {
        std::cout << "Erreur ouverture fichier.\n";
        return;
    }

    fichier << d_titre << std::endl;
    fichier << d_questions.size() << std::endl;

    for (const auto & q : d_questions) {
        q->sauvegarder(fichier);
    }

    fichier.close();
}

bool Questionnaire::lectureDepuisFichier(const std::string& nomFichier) {
    d_questions.clear();

    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cout << "Erreur ouverture fichier : " << nomFichier << std::endl;
        return false;
    }

    if (!getline(fichier, d_titre)) {
        std::cout << "Erreur : titre manquant\n";
        return false;
    }

    int nbQuestions;
    if (!(fichier >> nbQuestions)) {
        std::cout << "Erreur : nombre de questions invalide\n";
        return false;
    }
    fichier.ignore();

    for (int i = 0; i < nbQuestions; ++i) {
        std::string type;
        if (!getline(fichier, type)) {
            std::cout << "Erreur : type de question manquant\n";
            return false;
        }

        if (type == "QuestionTexte" || type == "QuestionText") {
            std::string titre, texte, reponse;
            if (!getline(fichier, titre) ||
                !getline(fichier, texte) ||
                !getline(fichier, reponse)) {
                std::cout << "Erreur lecture QuestionTexte\n";
                return false;
            }

            d_questions.push_back(
                std::make_unique<QuestionTexte>(titre, texte, reponse)
            );
        }
        else if (type == "QuestionNumerique" || type == "QuestionNum") {
            std::string titre, texte;
            int reponse, minVal, maxVal;

            if (!getline(fichier, titre) ||
                !getline(fichier, texte) ||
                !(fichier >> reponse >> minVal >> maxVal)) {
                std::cout << "Erreur lecture QuestionNumerique\n";
                return false;
            }
            fichier.ignore();

            d_questions.push_back(
                std::make_unique<QuestionNumerique>(titre, texte, reponse, minVal, maxVal)
            );
        }
        else if (type == "QuestionQCM") {
            std::string titre, texte;
            int nbChoix, bonneRep;

            if (!getline(fichier, titre) ||
                !getline(fichier, texte) ||
                !(fichier >> nbChoix)) {
                std::cout << "Erreur lecture QuestionQCM (entete)\n";
                return false;
            }
            fichier.ignore();

            std::vector<std::string> choix;
            for (int j = 0; j < nbChoix; ++j) {
                std::string c;
                if (!getline(fichier, c)) {
                    std::cout << "Erreur lecture choix QCM\n";
                    return false;
                }
                choix.push_back(c);
            }

            if (!(fichier >> bonneRep)) {
                std::cout << "Erreur lecture bonne reponse QCM\n";
                return false;
            }
            fichier.ignore();

            d_questions.push_back(
                std::make_unique<QuestionQCM>(titre, texte, choix, bonneRep)
            );
        }
        else {
            std::cout << "Type de question inconnu : " << type << std::endl;
            return false;
        }
    }

    return true;
}
