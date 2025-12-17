#include "../doctest/doctest.h"
#include "../QuestionQCM.h"
#include <vector>
#include <string>

TEST_CASE("QuestionQCM : verificationreponse") {
    std::vector<std::string> choix = {
        "Rouge",
        "Vert",
        "Bleu",
        "Jaune"
    };

    QuestionQCM q(
        "Couleur",
        "Quelle est la couleur du ciel ?",
        choix,
        3
    );

    REQUIRE(q.verificationreponse("3") == true);
    REQUIRE(q.verificationreponse("1") == false);
    REQUIRE(q.BonneReponse() == "3");
}
