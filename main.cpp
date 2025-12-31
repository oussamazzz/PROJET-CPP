#include <iostream>
#include "Questionnaire.h"
#include "Apprentissage.h"
#include "EvaluationTest.h"
#include "EvaluationSecChance.h"
#include "EvaluationAdap.h"
#include "goto_xy_windows.h"

using namespace std;

int main() {
    Questionnaire questionnaire;
    questionnaire.lectureDepuisFichier(
        "bin\\Debug\\questionnaire.txt"
    );

    system("cls");

    int x = 25;
    int y = 3;

    goto_xy(x, y++);
    cout << "===============================";
    goto_xy(x, y++);
    cout << "      Gestion Questionnaire";
    goto_xy(x, y++);
    cout << "===============================";

    y++;

    goto_xy(x, y++);
    cout << "1. Apprentissage";
    goto_xy(x, y++);
    cout << "2. Evaluation (test)";
    goto_xy(x, y++);
    cout << "3. Evaluation (seconde chance)";
    goto_xy(x, y++);
    cout << "4. Evaluation (adaptative)";

    y += 2;
    goto_xy(x, y);
    cout << "Choix : ";

    int choix;
    cin >> choix;
    cin.ignore();

    system("cls");

    switch (choix) {
        case 1: {
            Apprentissage app;
            app.AfficheQuestionsAvecReponses(questionnaire);
            break;
        }
        case 2: {
            EvaluationTest eval(questionnaire);
            eval.lancer();
            break;
        }
        case 3: {
            EvaluationSecondeChance eval(questionnaire);
            eval.lancer();
            break;
        }
        case 4: {
            EvaluationAdaptative eval(questionnaire);
            eval.lancer();
            break;
        }
        default:
            cout << "Choix invalide." << endl;
    }

    return 0;
}
