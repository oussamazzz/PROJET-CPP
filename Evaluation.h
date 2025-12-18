#ifndef EVALUATION_H
#define EVALUATION_H
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"



class Evaluation {
protected:

    Questionnaire& d_questionnaire;
    int d_essais = 0;
    int d_bonnes = 0;

public:

    Evaluation(Questionnaire& q);
    virtual ~Evaluation() = default;
    virtual void lancer() = 0;

    bool poserQuestion(const std::unique_ptr<Question>& ptr, bool afficherBonne);
    int get_NbQuestions()const ;

    int get_Essais() const { return d_essais; }
    int get_Bonnes() const { return d_bonnes; }
};

#endif