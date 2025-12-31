#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../EvaluationSecChance.h"
#include "../QuestionText.h"
#include <string>


TEST_CASE("test dans EvaluationSecondeChance sur .lancer") {
    SUBCASE("si questionnaire vide") {
        Questionnaire q("Test vide");
        EvaluationSecondeChance evaluation(q);

        std::istringstream fakeInput("");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 0);
        REQUIRE(evaluation.get_Essais() == 0);
        REQUIRE(evaluation.get_Bonnes() == 0);
    }

    SUBCASE(" si une question avec rep mauvaise puis bonne") {
        Questionnaire q("Second chance");
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q1"), std::string("Capital de la France ?"), std::string("Paris")));

        EvaluationSecondeChance evaluation(q);

        std::istringstream fakeInput("Lyon\nParis\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 1);
        REQUIRE(evaluation.get_Essais() == 2);
        REQUIRE(evaluation.get_Bonnes() == 1);
    }

    SUBCASE("une question avec rep mauvaise puis mauvaise") {
        Questionnaire q("Second chance");
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q1"), std::string("Capital de la France ?"), std::string("Paris")));

        EvaluationSecondeChance evaluation(q);

        std::istringstream fakeInput("Lyon\nMarseille\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 1);
        REQUIRE(evaluation.get_Essais() == 2);
        REQUIRE(evaluation.get_Bonnes() == 0);
    }

    SUBCASE("deux questions avec combinaison de cas") {
        Questionnaire q("Second chance");
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q1"), std::string("Capital de la France ?"), std::string("Paris")));
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q2"), std::string("2+2 ?"), std::string("4")));

        EvaluationSecondeChance evaluation(q);

        std::istringstream fakeInput("Paris\n5\n4\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 2);
        REQUIRE(evaluation.get_Essais() == 3);
        REQUIRE(evaluation.get_Bonnes() == 2);
    }
}