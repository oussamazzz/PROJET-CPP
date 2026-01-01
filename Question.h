#ifndef PROJETQUESTION_QUESTION_H
#define PROJETQUESTION_QUESTION_H

#include <string>
#include <fstream>  
#include <iostream>



class Question {

    public:

    Question(const std::string &titre,const std::string &text);
    virtual ~Question()=default;
    std::string get_titre()  const ;
    std::string get_text() const ;
    virtual void sauvegarder(std::ofstream& fichiertxt)const =0 ;
    virtual bool verificationreponse(const std::string& reponse) const =0;
    virtual std::string BonneReponse() const =0;
    virtual void afficherquestion() const   ;

protected:
    std::string d_titre;
    std::string d_text;

    


};

#endif //PROJETQUESTION_QUESTION_H