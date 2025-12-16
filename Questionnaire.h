#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H

#include <vector>
#include <string>
#include "Question.h"

class Questionnaire {
private:
    std::string d_titre;
    std::vector<std::unique_ptr<Question>> d_questions;

public:
    Questionnaire(const std::string& t = "");
    ~Questionnaire();

    void ajouterQuestion(const std::vector<std::unique_ptr<Question>> & q);
    int taille() const;
    const std::vector<unqiue_ptr<Question>> & getQuestions() const;

};

#endif
