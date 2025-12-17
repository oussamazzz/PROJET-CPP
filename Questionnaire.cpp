#include "Questionnaire.h"
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



