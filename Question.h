#ifndef PROJETQUESTION_QUESTION_H
#define PROJETQUESTION_QUESTION_H

#include <string>
#include <fstream>  
#include <iostream>

using namespace std;


class Question {

    public:

    Question(const string &titre,const string &text);
    virtual ~Question()=default;
    string get_titre()  const ;
    string get_text() const ;
    virtual void sauvegarder(ofstream& fichiertxt)const =0 ;
    virtual bool verificationreponse(const string& reponse) const =0;
    virtual string BonneReponse() const =0;
    virtual void afficherquestion() const  ;

protected:
    string d_titre;
    string d_text;

    


};

#endif //PROJETQUESTION_QUESTION_H