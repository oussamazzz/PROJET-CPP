#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"
#include "EvaluationTest.h"


EvaluationTest::EvaluationTest(Questionnaire& q)
    : Evaluation(q) {}

void EvaluationTest::lancer() {
    int total = get_NbQuestions();
    if (total == 0) {
        std::cout << "Aucune question dans le questionnaire.\n";
        return;
    }

    int numQuestion = 0;

    for (const auto& questions : d_questionnaire.getQuestions()) { 

        ++numQuestion;
        std::cout << "Question courante : " << numQuestion << " / " << total << "\n";
        ++d_essais;
        bool correct = poserQuestion(questions, false);
        if (correct) ++d_bonnes;
    }
    
    std::cout << "\nRésultats :\n";
    std::cout << "Nombre de questions : " << total << "\n";
    std::cout << "Nombre d'essais : " << d_essais << "\n";
    std::cout << "Nombre de bonnes réponses : " << d_bonnes << "\n";
    
}