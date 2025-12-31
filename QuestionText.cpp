//
// Created by oussa on 03/12/2025.
//

#include "QuestionText.h"
#include <fstream>
#include <string>
using namespace std;

QuestionTexte::QuestionTexte(const string &titre, const string &text, const string &reponse)
    : Question{titre, text}, d_reponse{reponse} {}

bool QuestionTexte::verificationreponse(const string &reponse) const {
    return reponse == d_reponse;
}

string QuestionTexte::BonneReponse() const {
    return d_reponse;
}
void QuestionTexte::sauvegarder(ofstream &fichiertxt) const {
    fichiertxt << "QuestionTexte" << endl;
    fichiertxt << d_titre << endl;
    fichiertxt << d_text << endl;
    fichiertxt << d_reponse << endl;
}
void QuestionTexte::afficherquestion() const {
    Question::afficherquestion();
}