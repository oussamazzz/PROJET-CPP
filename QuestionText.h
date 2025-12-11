//
// Created by moundir on 03/12/2025.
//
#ifndef PROJETQUESTION_QUESTIONTEXT_H
#define PROJETQUESTION_QUESTIONTEXT_H
#include "Question.h"
#include <string>
#include <fstream>


using namespace std;


class QuestionText : public Question {
public :
    QuestionText(string &text, string &titre,string &reponse):Question{text,titre},d_reponse{reponse}{}
    bool verificationreponse(const string &reponse) const override ;
    string BonneReponse() const override ;
    void sauvegarder(ofstream &fichiertxt) const override;





private :
    string d_reponse;
};


#endif //PROJETQUESTION_QUESTIONTEXT_H
