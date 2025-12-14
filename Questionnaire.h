#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H

#include <vector>
#include <string>
#include "Question.h"

class Questionnaire {
private:
    std::string titre;
    std::vector<Question*> questions;

public:
    Questionnaire(const std::string& t = "");
    ~Questionnaire();

    void ajouterQuestion(Question* q);
    const std::vector<Question*>& getQuestions() const;

    void afficher() const;
};

#endif
