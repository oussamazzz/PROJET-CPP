#ifndef EVALUATIONTEST_H
#define EVALUATIONTEST_H
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"



class EvaluationTest : public Evaluation {
public:

    EvaluationTest(Questionnaire& q);
    void lancer() override;
    
};


#endif