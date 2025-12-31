//
// Created by moundir on 03/12/2025.
//
#ifndef PROJETQUESTION_QUESTIONTEXT_H
#define PROJETQUESTION_QUESTIONTEXT_H
#include "Question.h"
#include <string>
#include <fstream>


using namespace std;


class QuestionTexte : public Question {
public :
    QuestionTexte(const string &titre, const string &text, const string &reponse);
    bool verificationreponse(const string &reponse) const override ;
    string BonneReponse() const override ;
    void sauvegarder(ofstream &fichiertxt) const override;
    void afficherquestion() const override ;


private :
    string d_reponse;
};


#endif //PROJETQUESTION_QUESTIONTEXT_H
