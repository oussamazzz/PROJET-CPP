#include "Questionnaire.h"
#include "QuestionText.h"
#include "QuestionNum.h"
#include "QuestionQCM.h"
#include <iostream>

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

void Questionnaire::lectureDepuisFichier(const std::string& nomFichier) {
    d_questions.clear();

    std::ifstream fichier(nomFichier);
    if (!fichier) {
        std::cout << "Erreur ouverture fichier : " << nomFichier << std::endl;
        return;
    }

    // recuperer le Titre du questionnaire
    if (!std::getline(fichier, d_titre)) {
        std::cout << "Erreur : titre manquant\n";
        return;
    }

    // Nb question
    int nbQuestions;
    fichier >> nbQuestions;
    fichier.ignore();

    for (int i = 0; i < nbQuestions; ++i) {
        std::string type;
        std::getline(fichier, type);

        // QuestionTexte
        if (type == "QuestionTexte" || type == "QuestionText") {
            std::string titre, texte, reponse;
            std::getline(fichier, titre);
            std::getline(fichier, texte);
            std::getline(fichier, reponse);

            d_questions.push_back(
                std::make_unique<QuestionTexte>(titre, texte, reponse)
            );
        }

        //  QuestionNumerique
        else if (type == "QuestionNumerique" || type == "QuestionNum") {
            std::string titre, texte;
            int reponse, minVal, maxVal;

            std::getline(fichier, titre);
            std::getline(fichier, texte);
            fichier >> reponse >> minVal >> maxVal;
            fichier.ignore();

            d_questions.push_back(
                std::make_unique<QuestionNumerique>(titre, texte, reponse, minVal, maxVal)
            );
        }

        // QuestionQCM
        else if (type == "QuestionQCM") {
            std::string titre, texte;
            int nbChoix, bonneRep;

            std::getline(fichier, titre);
            std::getline(fichier, texte);
            fichier >> nbChoix;
            fichier.ignore();

            std::vector<std::string> choix;
            for (int j = 0; j < nbChoix; ++j) {
                std::string c;
                std::getline(fichier, c);
                choix.push_back(c);
            }

            fichier >> bonneRep;
            fichier.ignore();

            d_questions.push_back(
                std::make_unique<QuestionQCM>(titre, texte, choix, bonneRep)
            );
        }

        else {
            std::cout << "Type de question inconnu : " << type << std::endl;
            return;
        }
    }
}


