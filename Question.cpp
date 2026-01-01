
#include "Question.h"
#include <iostream>
#include <string>


Question::Question(const std::string &titre, const std::string &text):d_titre{titre},d_text{text}{}

std::string Question::get_titre() const {
    return d_titre;
}      
std::string Question::get_text() const {
    return d_text;
}

void Question::afficherquestion() const {
    std::cout << "Thème : " << d_titre << std::endl;
    std::cout << d_text << std::endl;
}












