//
// Created by oussa on 03/12/2025.
//

#include "QuestionText.h"
#include <fstream>
#include <string>

QuestionTexte::QuestionTexte(const std::string &titre, const std::string &text, const std::string &reponse)
    : Question{titre, text}, d_reponse{reponse} {}

bool QuestionTexte::verificationreponse(const std::string &reponse) const {
    return reponse == d_reponse;
}

std::string QuestionTexte::BonneReponse() const {
    return d_reponse;
}
void QuestionTexte::sauvegarder(std::ofstream &fichiertxt) const {
    fichiertxt << "QuestionTexte" << std::endl;
    fichiertxt << d_titre << std::endl;
    fichiertxt << d_text << std::endl;
    fichiertxt << d_reponse << std::endl;
}
void QuestionTexte::afficherquestion() const {
    Question::afficherquestion();
}