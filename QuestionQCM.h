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
        std::vector<std::string> d_choix;

        int d_bonnereponse;
 public :

 QuestionQCM( const std::string &titre, const std::string &text, const std::vector<std::string> &choix,  int bonnereponse);

    bool verificationreponse(const std::string &reponse) const override ;

    std::string BonneReponse() const override ;
    
    void sauvegarder(std::ofstream &fichiertxt) const override;
    void afficherquestion() const override ;

};









#endif //PROJETQUESTION_QUESTIONQCM_H