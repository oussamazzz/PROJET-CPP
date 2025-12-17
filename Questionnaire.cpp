#include "Questionnaire.h"
#include <iostream>

Questionnaire::Questionnaire(const std::string& t)
    : titre(t) {}

Questionnaire::~Questionnaire() {
    for (Question* q : questions) {
        delete q;
    }
}

void Questionnaire::ajouterQuestion(const std::vector<std::unique_ptr<Question>> & q) {
    questions.move(q);
}
int Questionnaire::taille() const
{ return d_questions.size() 
}

const std::vector<unqiue_ptr<Question>> Questionnaire::getQuestions() const {
    return questions;
}
void Questionnaire::sauvegarder(const string& nomFichier) const {
    ofstream fichier(nomFichier);

    if (!fichier) {
        cout << "Erreur ouverture fichier.\n";
        return;
    }

    fichier << d_titre << endl;
    fichier << d_questions.size() << endl;

    for (Question* q : questions) {
        q->sauvegarder(fichier); 
    }

    fichier.close();
}



