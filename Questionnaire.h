#ifndef QUESTIONNAIRE_H
#define QUESTIONNAIRE_H

#include <vector>
#include <string>
#include <fstream>  
#include <iostream>
#include <memory>
#include "Question.h"

class Questionnaire {
private:
    std::string d_titre;
    std::vector<std::unique_ptr<Question>> d_questions;

public:
    Questionnaire(const std::string& t = "");
    ~Questionnaire()= default;

    void ajouterQuestion(const std::unique_ptr<Question> & q);
    int taille() const;
    const std::vector<std::unique_ptr<Question>> & getQuestions() const;
    void sauvegarder(const string& nomFichier) const;

};

#endif
