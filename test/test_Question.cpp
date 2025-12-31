#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../Question.h"
#include "../QuestionText.h"
#include <string>
#include <sstream>
#include <iostream>

TEST_CASE("Question : get_titre et get_text") {
    QuestionTexte q(
        "Test Titre",
        "Test texte de la question",
        "Reponse"
    );

    REQUIRE(q.get_titre() == "Test Titre");
    REQUIRE(q.get_text() == "Test texte de la question");
}

TEST_CASE("Question : constructeur") {
    QuestionTexte q(
        "Titre1",
        "Texte1",
        "Reponse1"
    );

    REQUIRE(q.get_titre() == "Titre1");
    REQUIRE(q.get_text() == "Texte1");
}

TEST_CASE("Question : afficherquestion (méthode de base)") {
    QuestionTexte q(
        "Titre Test",
        "Texte Test",
        "Reponse"
    );

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    
    q.afficherquestion();
    
    std::cout.rdbuf(oldCout);
    
    std::string output = oss.str();
    REQUIRE(output.find("Titre Test") != std::string::npos);
    REQUIRE(output.find("Texte Test") != std::string::npos);
}

