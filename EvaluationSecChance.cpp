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

    int total = get_NbQuestions();
    if (total == 0) {
        std::cout << "Aucune question dans le questionnaire.\n";
        return;
    }


    const auto& ptr = d_questionnaire.getQuestions();
    int numQuestion = 0;

    for (const auto& q : ptr) {
        
        ++numQuestion;
        std::cout << "Question courante : " << numQuestion << " / " << total << "\n";
        std::cout << "Il reste " << (total - numQuestion) << " question(s) après celle-ci.\n";

        ++d_essais;
        bool correct = poserQuestion(q, false);

        if (correct) {
            ++d_bonnes;
            continue;
        }

        std::cout << "Seconde chance...\n";
        ++d_essais;

        correct = poserQuestion(q, true);
        if (correct) ++d_bonnes;
    }

    std::cout << "\n----- Résultats -----\n";
    std::cout << "Nombre de questions : " << total << "\n";
    std::cout << "Nombre d'essais : " << d_essais << "\n";
    std::cout << "Nombre de bonnes réponses : " << d_bonnes << "\n";
}