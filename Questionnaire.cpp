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

void Questionnaire::lectureDepuisFichier(const std::string& nomFichier) {
    d_questions.clear();

    ifstream fichier(nomFichier);
    if (!fichier) {
        cout << "Erreur ouverture fichier : " << nomFichier << endl;
        return;
    }

    // recuperer le Titre du questionnaire
    if (!getline(fichier, d_titre)) {
        cout << "Erreur : titre manquant\n";
        return;
    }

    // Nb question
    int nbQuestions;
    fichier >> nbQuestions;
    fichier.ignore();

    for (int i = 0; i < nbQuestions; ++i) {
        string type;
        getline(fichier, type);

        // QuestionText
        if (type == "QuestionText") {
            string titre, texte, reponse;
            getline(fichier, titre);
            getline(fichier, texte);
            getline(fichier, reponse);

            d_questions.push_back(
                make_unique<QuestionText>(titre, texte, reponse)
            );
        }

        //  QuestionNum
        else if (type == "QuestionNum") {
            string titre, texte;
            int reponse, minVal, maxVal;

            getline(fichier, titre);
            getline(fichier, texte);
            fichier >> reponse >> minVal >> maxVal;
            fichier.ignore();

            d_questions.push_back(
                make_unique<QuestionNum>(titre, texte, reponse, minVal, maxVal)
            );
        }

        // QuestionQCM
        else if (type == "QuestionQCM") {
            string titre, texte;
            int nbChoix, bonneRep;

            getline(fichier, titre);
            getline(fichier, texte);
            fichier >> nbChoix;
            fichier.ignore();

            vector<string> choix;
            for (int j = 0; j < nbChoix; ++j) {
                string c;
                getline(fichier, c);
                choix.push_back(c);
            }

            fichier >> bonneRep;
            fichier.ignore();

            d_questions.push_back(
                make_unique<QuestionQCM>(titre, texte, choix, bonneRep)
            );
        }

        else {
            cout << "Type de question inconnu : " << type << endl;
            return;
        }
    }
}


