#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"
#include "Apprentissage.h"


Apprentissage::Apprentissage()
{}

void Apprentissage::AfficheQuestionsAvecReponses(const Questionnaire& q) const
{
    char choix = 'o';

    for (int i = 0; i < q.taille() && (choix == 'o' || choix == 'O'); ++i)
    {
        cout << "\nQuestion " << i + 1 << " / " << q.taille() << endl;
        cout << "------------------" << endl;

        Question* question = q.getQuestions()[i].get();
        question->afficherquestion();

        cout << "Bonne reponse : "
             << question->BonneReponse() << endl;

        cout << "\nAfficher la question suivante ? (o = oui / autre = non) : ";
        cin >> choix;
    }

    cout << "Fin de la phase d'apprentissage." << endl;
}

