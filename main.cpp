
#include <iostream>
#include "Questionnaire.h"
#include "Apprentissage.h"
#include "EvaluationTest.h"
#include "EvaluationSecChance.h"
#include "EvaluationAdap.h"

using namespace std;

int main() {
    Questionnaire questionnaire;

    questionnaire.lectureDepuisFichier("C:\\Users\\ramzi\\Desktop\\projet_Qualitr_Prog\\PROJET-CPP\\bin\\Debug\\questionnaire.txt");
    cout << "Nombre de questions chargees = "
     << questionnaire.taille() << endl;


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


