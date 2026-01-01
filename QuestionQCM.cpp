#include "QuestionQCM.h"

QuestionQCM::QuestionQCM(const std::string &titre, const std::string &text, const std::vector<std::string> &choix,  int bonnereponse)
    : Question{titre, text}, d_choix{choix}, d_bonnereponse{bonnereponse} {}

bool QuestionQCM::verificationreponse(const std::string &reponse) const {

    return std::stoi(reponse) == d_bonnereponse;

}
std::string QuestionQCM::BonneReponse() const {
    return std::to_string(d_bonnereponse);
}
void QuestionQCM::sauvegarder(std::ofstream &fichiertxt) const {
    fichiertxt << "QuestionQCM" << std::endl;

      fichiertxt << d_titre << std::endl;
    fichiertxt << d_text << std::endl;
     fichiertxt << d_choix.size() << std::endl;
    for (const auto &choix : d_choix) {


        fichiertxt << choix << std::endl;
    }

    fichiertxt << d_bonnereponse << std::endl;
}
void QuestionQCM::afficherquestion() const {

    Question::afficherquestion();

    for (size_t i = 0; i < d_choix.size(); ++i) {
       
        std::cout << i + 1 << ". " << d_choix[i] << std::endl;
    }
}
