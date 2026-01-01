#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "Question.h"
#include "Questionnaire.h"
#include "Evaluation.h"

Evaluation::Evaluation(Questionnaire& q)
    : d_questionnaire(q), d_essais(0), d_bonnes(0) {}

int Evaluation::get_NbQuestions() const {
    return d_questionnaire.taille();
}



bool Evaluation::poserQuestion(const std::unique_ptr<Question>& ptr, bool afficherBonneReponse) {

    ptr->afficherquestion();

    std::cout << "Votre réponse : ";
    std::string reponse;
    std::getline(std::cin, reponse);

    bool correct = ptr->verificationreponse(reponse);

    
    std::cout << (correct ? "Bonne réponse.\n" : "Mauvaise réponse.\n");

    if (afficherBonneReponse) {
        std::cout << "Réponse correct : " << ptr->BonneReponse() << "\n";
    }

    return correct;
}


