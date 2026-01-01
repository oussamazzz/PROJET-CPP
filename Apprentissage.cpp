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
        std::cout << "\nQuestion " << i + 1 << " / " << q.taille() << std::endl;
        std::cout << "------------------" << std::endl;

        Question* question = q.getQuestions()[i].get();
        question->afficherquestion();

        std::cout << "Bonne reponse : "
             << question->BonneReponse() << std::endl;

        std::cout << "\nAfficher la question suivante ? (o = oui / autre = non) : ";
        std::cin >> choix;
    }

    std::cout << "Fin de la phase d'apprentissage." << std::endl;
}
    
