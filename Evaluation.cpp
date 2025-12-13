#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"
// #include "Questionnaire.h"  //classe n'ai pas encore crée
#include "Evaluation.h"


using namespace std;

Evaluation::Evaluation(Questionnaire& q):
    d_questionnaire(q), d_essais(0), d_bonnes(0) {}


    
int Evaluation::get_NbQuestions() const {
    
    return d_questionnaire.taille();   // .taille() une methode a declarer dans la class Questionnaire
}



bool Evaluation::poserQuestion(const std::unique_ptr<Question>& ptr, bool afficherBonneReponse) {

    ptr->afficherquestion();

    cout << "Votre réponse : ";
    string reponse;
    getline(cin, reponse);

    bool correct = ptr->verificationreponse(reponse);

    cout << (correct ? "Bonne réponse.\n" : "Mauvaise réponse.\n");

    if (afficherBonneReponse) {
        cout << "Réponse correct : " << ptr->BonneReponse() << "\n";
    }

    return correct;
}


