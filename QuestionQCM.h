//
// Created by oussa on 03/12/2025.
//
#ifndef PROJETQUESTION_QUESTIONQCM_H
#define PROJETQUESTION_QUESTIONQCM_H

#include "Question.h"
#include <string>
#include <fstream>
#include <vector>



class QuestionQCM : public Question {

    private :
        std::vector<string> d_choix;
        int d_bonnereponse;
    public :

    QuestionQCM( const string &titre, const string &text, const vector<string> &choix,  int bonnereponse);

    bool verificationreponse(const string &reponse) const override ;

    string BonneReponse() const override ;
    
    void sauvegarder(ofstream &fichiertxt) const override;
    void afficherquestion() const override ;

};









#endif //PROJETQUESTION_QUESTIONQCM_H