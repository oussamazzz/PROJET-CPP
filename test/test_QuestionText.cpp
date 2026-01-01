#include "../doctest/doctest.h"
#include "../QuestionText.h"
#include <string>

TEST_CASE("QuestionText : verificationreponse et BonneReponse") {
    std::string titre = "Capitale";
    std::string text = "Quelle est la capitale de la France ?";
    std::string reponse = "Paris";

    QuestionText q(titre, text, reponse);

    REQUIRE(q.verificationreponse("Paris") == true);
    REQUIRE(q.verificationreponse("Lyon") == false);
    REQUIRE(q.BonneReponse() == "Paris");
}
