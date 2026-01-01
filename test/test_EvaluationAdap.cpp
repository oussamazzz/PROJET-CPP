#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../EvaluationAdap.h"
#include "../QuestionText.h"
#include <string>

TEST_CASE("test dans EvaluationAdap sur .lancer") {
    SUBCASE("si le questionnaire est vide") {
        Questionnaire q("Vide");
        EvaluationAdaptative evaluation(q);

        std::istringstream fakeInput("");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 0);
        REQUIRE(evaluation.get_Essais() == 0);
        REQUIRE(evaluation.get_Bonnes() == 0);
    }

    SUBCASE("si les reponse des deux questions sont bonne") {
        Questionnaire q("Adaptative");
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q1"), std::string("Capital de la France ?"), std::string("Paris")));
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q2"), std::string("2+2 ?"), std::string("4")));

        EvaluationAdaptative evaluation(q);

        
        std::istringstream fakeInput("Paris\n4\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 2);
        REQUIRE(evaluation.get_Essais() == 2);
        REQUIRE(evaluation.get_Bonnes() == 2);
    }

    SUBCASE("si l'un des deux reponse est mauvaise") {
        Questionnaire q("Adaptative");
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q1"), std::string("Capital de la France ?"), std::string("Paris")));
        q.ajouterQuestion(std::make_unique<QuestionTexte>(
            std::string("Q2"), std::string("2+2 ?"), std::string("4")));

        EvaluationAdaptative evaluation(q);

        
        std::istringstream fakeInput("XXX\n4\nParis\n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        evaluation.lancer();

        std::cin.rdbuf(oldCin);

        REQUIRE(evaluation.get_NbQuestions() == 2);
        REQUIRE(evaluation.get_Essais() == 3);
        REQUIRE(evaluation.get_Bonnes() == 2);
    }
}
