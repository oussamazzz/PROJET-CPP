#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../EvaluationTest.h"
#include "../QuestionText.h"
#include <string>

TEST_CASE("test dans EvaluationTest sur .lancer") {
    SUBCASE("si questionnaire vide") {

        Questionnaire q("Vide");
        EvaluationTest evaluation(q);

        std::istringstream fakeInput("");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 0);
        REQUIRE(evaluation.get_Essais() == 0);
        REQUIRE(evaluation.get_Bonnes() == 0);
    }

    SUBCASE("si questionnaire avec une mauvaise et une bonne reponse") {
        Questionnaire q("Test");

        q.ajouterQuestion ( std::make_unique<QuestionText> ( std::string("Q1") , std::string ("Capital de la France ?") , std::string("Paris") ));
        q.ajouterQuestion ( std::make_unique<QuestionText> ( std::string("Q2") , std::string("2+2 ?") , std::string("4") ));

        std::istringstream fakeInput("Lyon\n4\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        EvaluationTest evaluation(q);
        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 2);
        REQUIRE(evaluation.get_Essais() == 2);
        REQUIRE(evaluation.get_Bonnes() == 1);
    }
}
