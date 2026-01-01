#include "QuestionNum.h"
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

QuestionNumerique::QuestionNumerique(const string &titre, const string &text, int reponse, int limiteminimale, int limitemaximale)
    : Question (titre, text), d_reponse(reponse), d_limiteminimale(limiteminimale), d_limitemaximale(limitemaximale) {}

bool QuestionNumerique::verificationreponse(const string &reponse) const {
    try {
        size_t pos = 0;
        int reponsen = stoi(reponse, &pos);
        if (pos != reponse.size()) {
            return false;
        }
        if (reponsen < d_limiteminimale || reponsen > d_limitemaximale) {
            return false;
        }
        return reponsen == d_reponse;
    } catch (const std::exception &) {
        return false;
    }
}

string QuestionNumerique::BonneReponse() const {
    return to_string(d_reponse);
}
void QuestionNumerique::sauvegarder(ofstream &fichiertxt) const {
    fichiertxt << "QuestionNumerique" << endl;
    fichiertxt << d_titre << endl;
    fichiertxt << d_text << endl;
    fichiertxt << d_reponse << endl;
    fichiertxt << d_limiteminimale << endl;
    fichiertxt << d_limitemaximale << endl;
}
void QuestionNumerique::afficherquestion() const {
   Question::afficherquestion();
    cout <<"veuillez choisir un nombre entre " << d_limiteminimale << " et " <<  d_limitemaximale << "." << endl;
}
