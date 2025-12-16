#include "Questionnaire.h"
#include <iostream>

Questionnaire::Questionnaire(const std::string& t)
    : titre(t) {}

Questionnaire::~Questionnaire() {
    for (Question* q : questions) {
        delete q;
    }
}

void Questionnaire::ajouterQuestion(Question* q) {
    questions.push_back(q);
}

const std::vector<Question*>& Questionnaire::getQuestions() const {
    return questions;
}

void Questionnaire::afficher() const {
    std::cout << "Questionnaire : " << titre << std::endl;
    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << i + 1 << ". ";
        questions[i]->afficherquestion();
    }
}
