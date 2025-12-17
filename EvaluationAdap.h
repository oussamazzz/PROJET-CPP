#ifndef EVALUATION_ADAPTATIVE_H
#define EVALUATION_ADAPTATIVE_H
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"

class EvaluationAdaptative : public Evaluation {
public:
    explicit EvaluationAdaptative(Questionnaire& q);

    void lancer() override;
};

#endif