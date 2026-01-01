#include "QuestionNum.h"
#include <fstream>
#include <string>
#include <stdexcept>

QuestionNumerique::QuestionNumerique(const std::string &titre, const std::string &text, int reponse, int limiteminimale, int limitemaximale)
    : Question (titre, text), d_reponse(reponse), d_limiteminimale(limiteminimale), d_limitemaximale(limitemaximale) {}

bool QuestionNumerique::verificationreponse(const std::string &reponse) const {
    try {
        size_t pos = 0;
        int reponsen = std::stoi(reponse, &pos);
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

std::string QuestionNumerique::BonneReponse() const {
    return std::to_string(d_reponse);
}
void QuestionNumerique::sauvegarder(std::ofstream &fichiertxt) const {
    fichiertxt << "QuestionNumerique" << std::endl;
    fichiertxt << d_titre << std::endl;
    fichiertxt << d_text << std::endl;
    fichiertxt << d_reponse << std::endl;
    fichiertxt << d_limiteminimale << std::endl;
    fichiertxt << d_limitemaximale << std::endl;
}
void QuestionNumerique::afficherquestion() const {
   Question::afficherquestion();
    std::cout <<"veuillez choisir un nombre entre " << d_limiteminimale << " et " <<  d_limitemaximale << "." << std::endl;
}
