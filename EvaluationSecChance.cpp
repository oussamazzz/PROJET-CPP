#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"
#include "EvaluationSecChance.h"




EvaluationSecondeChance::EvaluationSecondeChance(Questionnaire& q)
    : Evaluation(q) {}

void EvaluationSecondeChance::lancer() {
    if (d_questionnaire.taille() == 0) {
        cout << "Aucune question dans le questionnaire.\n";
        return;
    }


    const auto& ptr = d_questionnaire.getQuestions(); 

    for (const auto& q : ptr) {
        ++d_essais;
        bool correct = poserQuestion(q, false);

        if (correct) {
            ++d_bonnes;
            continue;           
        }

        cout << "Seconde chance...\n";
        ++d_essais;

        correct = poserQuestion(q, true);
        if (correct) ++d_bonnes;
    }
}