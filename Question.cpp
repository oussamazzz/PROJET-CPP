
#include "Question.h"
#include <iostream>
#include <string>

using namespace std;

Question::Question(string &titre, string &text):d_titre{titre},d_text{text}{}

string Question::get_titre() const {
    return d_titre;
}      
string Question::get_text() const {
    return d_text;
}

void Question::afficherquestion() const {
    cout << d_titre << endl;
    cout << d_text << endl;
}












