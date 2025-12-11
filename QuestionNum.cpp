#include "QuestionNum.h"
#include <fstream>
#include <string>
using namespace std;

QuestionNum::QuestionNum(const string &titre, const string &text, int reponse, int limiteminimale, int limitemaximale)
    : Question (titre, text), d_reponse(reponse), d_limiteminimale(limiteminimale), d_limitemaximale(limitemaximale) {}

bool QuestionNum::verificationreponse(const string &reponse) const {
    int reponsen = stoi(reponse);
  if (reponsen >= d_limiteminimale && reponsen <= d_limitemaximale) {
      return reponsen == d_reponse;
  } else {
      return false;
  }
    
}

string QuestionNum::BonneReponse() const {
    return to_string(d_reponse);
}
void QuestionNum::sauvegarder(ofstream &fichiertxt) const {
    fichiertxt << "QuestionNum" << endl;
    fichiertxt << d_titre << endl;
    fichiertxt << d_text << endl;
    fichiertxt << d_reponse << endl;
    fichiertxt << d_limiteminimale << endl;
    fichiertxt << d_limitemaximale << endl;
}