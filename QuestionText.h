//
// Created by moundir on 03/12/2025.
//
#ifndef PROJETQUESTION_QUESTIONTEXT_H
#define PROJETQUESTION_QUESTIONTEXT_H
#include "Question.h"
#include <string>
#include <fstream>



class QuestionTexte : public Question {
public :
    QuestionTexte(const std::string &titre, const std::string &text, const std::string &reponse);
    bool verificationreponse(const std::string &reponse) const override ;
    std::string BonneReponse() const override ;
    void sauvegarder(std::ofstream &fichiertxt) const override;
    void afficherquestion() const override ;


private :
    std::string d_reponse;
};


#endif //PROJETQUESTION_QUESTIONTEXT_H
