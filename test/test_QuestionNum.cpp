#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionNum.h"
#include <string>

TEST_CASE("QuestionNum : verificationreponse") {
    QuestionNum q(
        "Maths",
        "Combien font 2 + 2 ?",
        4,
        0,
        10
    );

    REQUIRE(q.verificationreponse("4") == true);
    REQUIRE(q.verificationreponse("3") == false);
    REQUIRE(q.verificationreponse("11") == false); 
    REQUIRE(q.BonneReponse() == "4");
}
