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

const std::vector<unique_ptr<Question>> & Questionnaire::getQuestions() const {
    return d_questions;
}
void Questionnaire::sauvegarder(const std::string& nomFichier) const {
    ofstream fichier(nomFichier);

    if (!fichier) {
        cout << "Erreur ouverture fichier.\n";
        return;
    }

    fichier << d_titre << endl;
    fichier << d_questions.size() << endl;

    for (const auto & q : d_questions) {
        q->sauvegarder(fichier);
    }

    fichier.close();
}
// a verifier 
void Questionnaire::charger(const std::string& nomFichier) {
    d_questions.clear();
// si ya une erreur on affiche un message d'erreur
    ifstream fichier(nomFichier);
    if (!fichier) {
        cout << "Erreur ouverture fichier.\n";
        return;
    }

    // Lecture du titre
    if (!std::getline(fichier, d_titre)) {
        cout << "Fichier questionnaire vide ou invalide.\n";
        return;
    }

    // Lecture du nombre de questions
    std::string ligne;
    if (!std::getline(fichier, ligne)) {
        cout << "Format de fichier invalide (nombre de questions manquant).\n";
        return;
    }
    int nbQuestions = std::stoi(ligne);

    for (int i = 0; i < nbQuestions; ++i) {
        std::string type;
        if (!std::getline(fichier, type)) {
            cout << "Format de fichier invalide (type de question manquant).\n";
            break;
        }

        if (type == "QuestionText") {
            std::string titre, text, reponse;
            if (!std::getline(fichier, titre)) break;
            if (!std::getline(fichier, text)) break;
            if (!std::getline(fichier, reponse)) break;

            auto q = std::make_unique<QuestionText>(titre, text, reponse);
            d_questions.push_back(std::move(q));

        } else if (type == "QuestionNum") {
            std::string titre, text;
            std::string repStr, minStr, maxStr;

            if (!std::getline(fichier, titre)) break;
            if (!std::getline(fichier, text)) break;
            if (!std::getline(fichier, repStr)) break;
            if (!std::getline(fichier, minStr)) break;
            if (!std::getline(fichier, maxStr)) break;

            int rep = std::stoi(repStr);
            int minVal = std::stoi(minStr);
            int maxVal = std::stoi(maxStr);

            auto q = std::make_unique<QuestionNum>(titre, text, rep, minVal, maxVal);
            d_questions.push_back(std::move(q));

        } else if (type == "QuestionQCM") {
            std::string titre, text;
            std::string nbChoixStr;

            if (!std::getline(fichier, titre)) break;
            if (!std::getline(fichier, text)) break;
            if (!std::getline(fichier, nbChoixStr)) break;

            int nbChoix = std::stoi(nbChoixStr);
            std::vector<std::string> choix;
            choix.reserve(nbChoix);

            for (int j = 0; j < nbChoix; ++j) {
                std::string c;
                if (!std::getline(fichier, c)) {
                    cout << "Format de fichier invalide (choix QCM manquant).\n";
                    break;
                }
                choix.push_back(c);
            }

            std::string bonneRepStr;
            if (!std::getline(fichier, bonneRepStr)) break;
            int bonneRep = std::stoi(bonneRepStr);

            auto q = std::make_unique<QuestionQCM>(titre, text, choix, bonneRep);
            d_questions.push_back(std::move(q));

        } else {
            cout << "Type de question inconnu dans le fichier : " << type << "\n";
            break;
        }
    }
}
