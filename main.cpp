
#include <iostream>
#include "Questionnaire.h"
#include "Apprentissage.h"
#include "EvaluationTest.h"
#include "EvaluationSecChance.h"
#include "EvaluationAdap.h"

int main() {
    Questionnaire questionnaire;

    questionnaire.charger("questionnaire.txt");

    int choix;
    cout << "===============================\n";
    cout << "  Gestion de Questionnaire\n";
    cout << "===============================\n";
    cout << "1. Apprentissage\n";
    cout << "2. Evaluation (test)\n";
    cout << "3. Evaluation (seconde chance)\n";
    cout << "4. Evaluation (adaptative)\n";
    cout << "Choix : ";
    cin >> choix;
    cin.ignore();

    switch (choix) {
        case 1: {
            Apprentissage app;
            app.AfficheQuestionsAvecReponses(questionnaire);
            break;
        }
        case 2: {
            EvaluationTest eval;
            eval.lancer(questionnaire);
            break;
        }
        case 3: {
            EvaluationSecChance eval;
            eval.lancer(questionnaire);
            break;
        }
        case 4: {
            EvaluationAdap eval;
            eval.lancer(questionnaire);
            break;
        }
        default:
            cout << "Choix invalide." << endl;
    }

    return 0;
}


