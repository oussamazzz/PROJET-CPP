#include "EvaluationAdap.h"
#include "Questionnaire.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

EvaluationAdaptative::EvaluationAdaptative(Questionnaire& q)
    : Evaluation(q) {}

void EvaluationAdaptative::lancer() {
    if (d_questionnaire.taille() == 0) {
        cout << "Aucune question dans le questionnaire.\n";
        return;
    }

    const auto& qs = d_questionnaire.getQuestions(); 
    int n = d_questionnaire.taille();

    srand(time(0));


    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);  
        std::swap(indices[i], indices[j]);
    }

    vector<int> aReposer;

    
    for (int idx : indices) {
        ++d_essais;
        bool correct = poserQuestion(qs[idx], false);
        if (correct) {
            ++d_bonnes;
        } else {
            aReposer.push_back(idx);
        }
    }


    for (int idx : aReposer) {
        cout << "Question reposée :\n";
        ++d_essais;
        bool correct = poserQuestion(qs[idx], true);
        if (correct) {
            ++d_bonnes;
        }
    }
}
