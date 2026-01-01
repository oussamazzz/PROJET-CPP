//
// Created by oussa on 03/12/2025.
//

#include "QuestionText.h"
#include <fstream>
#include <string>
using namespace std;

QuestionText::QuestionText(const string &titre, const string &text, const string &reponse)
    : Question{titre, text}, d_reponse{reponse} {}

bool QuestionText::verificationreponse(const string &reponse) const {
    return reponse == d_reponse;
}

string QuestionText::BonneReponse() const {
    return d_reponse;
}
void QuestionText::sauvegarder(ofstream &fichiertxt) const {
    fichiertxt << "QuestionText" << endl;
    fichiertxt << d_titre << endl;
    fichiertxt << d_text << endl;
    fichiertxt << d_reponse << endl;
}
void QuestionText::afficherquestion() const {
    Question::afficherquestion();
}