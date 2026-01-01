#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <sstream>
#include <iostream>

#include "Apprentissage.h"
#include "Questionnaire.h"
#include "QuestionText.h"

TEST_CASE("Apprentissage::AfficheQuestionsAvecReponses")
{
    Apprentissage app;

    SUBCASE("Affiche toutes les questions quand l'utilisateur repond o")
    {
        std::istringstream fakeInput("o o");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        std::ostringstream fakeOutput;
        std::streambuf* oldCout = std::cout.rdbuf(fakeOutput.rdbuf());

        Questionnaire q;
        q.ajouterQuestion(new QuestionText("2 + 2 = ?", "4"));
        q.ajouterQuestion(new QuestionText("Capital de la France ?", "Paris"));

        app.AfficheQuestionsAvecReponses(q);

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string output = fakeOutput.str();

        REQUIRE(output.find("2 + 2 = ?") != std::string::npos);
        REQUIRE(output.find("4") != std::string::npos);
        REQUIRE(output.find("Capital de la France ?") != std::string::npos);
        REQUIRE(output.find("Paris") != std::string::npos);
    }

    SUBCASE("S'arrete apres la premiere question si l'utilisateur ne repond pas o")
    {
        std::istringstream fakeInput("n");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        std::ostringstream fakeOutput;
        std::streambuf* oldCout = std::cout.rdbuf(fakeOutput.rdbuf());

        Questionnaire q;
        q.ajouterQuestion(new QuestionText("Q1", "R1"));
        q.ajouterQuestion(new QuestionText("Q2", "R2"));

        app.AfficheQuestionsAvecReponses(q);

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string output = fakeOutput.str();

        REQUIRE(output.find("Q1") != std::string::npos);
        REQUIRE(output.find("R1") != std::string::npos);
        REQUIRE(output.find("Q2") == std::string::npos);
    }

    SUBCASE("Fonctionne correctement avec une seule question")
    {
        std::istringstream fakeInput("o");
        std::streambuf* oldCin = std::cin.rdbuf(fakeInput.rdbuf());

        std::ostringstream fakeOutput;
        std::streambuf* oldCout = std::cout.rdbuf(fakeOutput.rdbuf());

        Questionnaire q;
        q.ajouterQuestion(new QuestionText("Question unique", "Bonne reponse"));

        app.AfficheQuestionsAvecReponses(q);

        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);

        std::string output = fakeOutput.str();

        REQUIRE(output.find("Question unique") != std::string::npos);
        REQUIRE(output.find("Bonne reponse") != std::string::npos);
    }
}
