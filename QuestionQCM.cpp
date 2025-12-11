#include "QuestionQCM.h"

QuestionQCM::QuestionQCM(const string &titre, const string &text, const vector<string> &choix,  int bonnereponse)
    : Question{titre, text}, d_choix{choix}, d_bonnereponse{bonnereponse} {}

bool QuestionQCM::verificationreponse(const string &reponse) const {
    return stoi(reponse) == d_bonnereponse;
}
string QuestionQCM::BonneReponse() const {
    return to_string(d_bonnereponse);
}
void QuestionQCM::sauvegarder(ofstream &fichiertxt) const {
    fichiertxt << "QuestionQCM" << endl;
    fichiertxt << d_titre << endl;
    fichiertxt << d_text << endl;
    fichiertxt << d_choix.size() << endl;
    for (const auto &choix : d_choix) {
        fichiertxt << choix << endl;
    }
    fichiertxt << d_bonnereponse << endl;
}
