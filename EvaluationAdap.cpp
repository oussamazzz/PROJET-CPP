#include "EvaluationAdap.h"
#include "Questionnaire.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // rand, srand
#include <ctime>    // time



EvaluationAdaptative::EvaluationAdaptative(Questionnaire& q)
    : Evaluation(q) {}

void EvaluationAdaptative::lancer() {
    int total = get_NbQuestions();
    if (total == 0) {
        std::cout << "Aucune question dans le questionnaire.\n";
        return;
    }

    const auto& questions = d_questionnaire.getQuestions();

    std::srand(std::time(0));

    std::vector<int> indices(total);
    for (int i = 0; i < total; ++i) {
        indices[i] = i;
    }

    for (int i = total - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(indices[i], indices[j]);
    }

    std::vector<int> aReposer;
    int numQuestion = 0;

    for (int idx : indices) {

        ++numQuestion;
        std::cout << "Question courante : " << numQuestion << " / " << total << "\n";
        std::cout << "Il reste " << (total - numQuestion) << " question(s) après celle-ci.\n";

        ++d_essais;
        bool correct = poserQuestion(questions[idx], false);
        if (correct) {
            ++d_bonnes;
        } else {
            aReposer.push_back(idx);
        }
    }


    for (int idx : aReposer) {
        std::cout << "Question reposée :\n";
        ++d_essais;
        bool correct = poserQuestion(questions[idx], true);
        if (correct) {
            ++d_bonnes;
        }
    }


    std::cout << "\n----- Résultats -----\n";
    std::cout << "Nombre de questions : " << total << "\n";
    std::cout << "Nombre d'essais : " << d_essais << "\n";
    std::cout << "Nombre de bonnes réponses : " << d_bonnes << "\n";
}

