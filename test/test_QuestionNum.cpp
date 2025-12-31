#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionNum.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

TEST_CASE("QuestionNumerique : verificationreponse") {
    QuestionNumerique q(
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

TEST_CASE("QuestionNumerique : BonneReponse") {
    QuestionNumerique q(
        "Maths",
        "Combien font 5 * 3 ?",
        15,
        0,
        20
    );

    REQUIRE(q.BonneReponse() == "15");
}

TEST_CASE("QuestionNumerique : sauvegarder") {
    QuestionNumerique q(
        "Maths",
        "Combien font 2 + 2 ?",
        4,
        0,
        10
    );

    std::ofstream fichier("test_temp.txt");
    q.sauvegarder(fichier);
    fichier.close();

    std::ifstream lecture("test_temp.txt");
    std::string ligne;
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "QuestionNumerique");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Maths");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Combien font 2 + 2 ?");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "4");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "0");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "10");
    
    lecture.close();
    remove("test_temp.txt");
}

TEST_CASE("QuestionNumerique : afficherquestion") {
    QuestionNumerique q(
        "Maths",
        "Combien font 2 + 2 ?",
        4,
        0,
        10
    );

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    
    q.afficherquestion();
    
    std::cout.rdbuf(oldCout);
    
    std::string output = oss.str();
    REQUIRE(output.find("Maths") != std::string::npos);
    REQUIRE(output.find("Combien font 2 + 2 ?") != std::string::npos);
    REQUIRE(output.find("veuillez choisir un nombre entre") != std::string::npos);
}
