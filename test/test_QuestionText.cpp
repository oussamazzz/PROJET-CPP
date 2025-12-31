#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionText.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

TEST_CASE("QuestionTexte : verificationreponse et BonneReponse") {
    std::string titre = "Capitale";
    std::string text = "Quelle est la capitale de la France ?";
    std::string reponse = "Paris";

    QuestionTexte q(titre, text, reponse);

    REQUIRE(q.verificationreponse("Paris") == true);
    REQUIRE(q.verificationreponse("Lyon") == false);
    REQUIRE(q.BonneReponse() == "Paris");
}

TEST_CASE("QuestionTexte : sauvegarder") {
    QuestionTexte q(
        "Capitale",
        "Quelle est la capitale de la France ?",
        "Paris"
    );

    std::ofstream fichier("test_temp.txt");
    q.sauvegarder(fichier);
    fichier.close();

    std::ifstream lecture("test_temp.txt");
    std::string ligne;
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "QuestionTexte");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Capitale");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Quelle est la capitale de la France ?");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Paris");
    
    lecture.close();
    remove("test_temp.txt");
}

TEST_CASE("QuestionTexte : afficherquestion") {
    QuestionTexte q(
        "Capitale",
        "Quelle est la capitale de la France ?",
        "Paris"
    );

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    
    q.afficherquestion();
    
    std::cout.rdbuf(oldCout);
    
    std::string output = oss.str();
    REQUIRE(output.find("Capitale") != std::string::npos);
    REQUIRE(output.find("Quelle est la capitale de la France ?") != std::string::npos);
}
