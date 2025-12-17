//
// Created by oussa on 03/12/2025.
//
#ifndef PROJETQUESTION_QUESTIONNUM_H
#define PROJETQUESTION_QUESTIONNUM_H
#include "Question.h"
#include <string>
#include <fstream>
using namespace std;

class QuestionNum: public Question {
public :
QuestionNum(const std::string &titre, const std::string &text, int reponse, int limiteminimale, int limitemaximale);
bool verificationreponse(const string &reponse) const override ;
    string BonneReponse() const override ;
    void sauvegarder(ofstream &fichiertxt) const override;
    void afficherquestion() const override ;
private :
    int  d_reponse;
    int d_limiteminimale  ;
    int d_limitemaximale ;
};

#endif //PROJETQUESTION_QUESTIONNUM_H