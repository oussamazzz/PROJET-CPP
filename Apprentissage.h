#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"


class Apprentissage {

public:

    Apprentissage();;
    void AfficheQuestionsAvecReponses (const Questionnaire & q) const;
    
}
#endif