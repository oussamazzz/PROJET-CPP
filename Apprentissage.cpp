#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"
#include "Apprentissage.h"

using namespace std;

Apprentissage::Apprentissage()
{}

void Apprentissage::AfficheQuestionsAvecReponses(const Questionnaire & q) const
{
    char choix;

    for (int i = 0; i < q.taille(); i++) {
        cout << "\nQuestion " << i + 1 << " / " << q.taille() << endl;
        cout << "------------------" << endl;

        q.getQuestions()[i]->afficherquestion();
        cout << "Bonne reponse : " << q.getQuestions()[i]->BonneReponse() << endl;

        cout << "\nAfficher la question suivante ? (o = oui / autre = non) : ";
        cin >> choix;

        if (choix != 'o' && choix != 'O') {
            cout << "Fin de la phase d'apprentissage." << endl;
            break;
        }
    }
}