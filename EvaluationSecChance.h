#ifndef EVALUATIONSECCHANCE_H
#define EVALUATIONSECCHANCE_H
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"

class EvaluationSecondeChance : public Evaluation {
public:
    EvaluationSecondeChance(Questionnaire& q);
    
    void lancer() override;
};


#endif