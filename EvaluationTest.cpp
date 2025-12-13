#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
// #include "Questionnaire.h"  //classe n'ai pas encore crée
#include "Evaluation.h"
#include "EvaluationTest.h"


EvaluationTest::EvaluationTest(Questionnaire& q)
    : Evaluation(q) {}

void EvaluationTest::lancer() {
    if (d_questionnaire.taille() == 0) {
        cout << "Aucune question dans le questionnaire.\n";
        return;
    }

    for (const auto& ptr : d_questionnaire.questions()) {   //.question c'est un getter (declarer dans class questionnaire) pour recuperer les questions du questinnaire 
        ++d_essais;
        bool correct = poserQuestion(ptr, false);
        if (correct) ++d_bonnes;
    }
}