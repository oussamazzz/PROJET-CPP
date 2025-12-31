#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionQCM.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

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

TEST_CASE("QuestionQCM : BonneReponse") {
    std::vector<std::string> choix = {
        "Option A",
        "Option B",
        "Option C"
    };

    QuestionQCM q(
        "Test",
        "Choisissez une option",
        choix,
        2
    );

    REQUIRE(q.BonneReponse() == "2");
}

TEST_CASE("QuestionQCM : sauvegarder") {
    std::vector<std::string> choix = {
        "Rouge",
        "Vert",
        "Bleu"
    };

    QuestionQCM q(
        "Couleur",
        "Quelle est la couleur du ciel ?",
        choix,
        3
    );

    std::ofstream fichier("test_temp.txt");
    q.sauvegarder(fichier);
    fichier.close();

    std::ifstream lecture("test_temp.txt");
    std::string ligne;
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "QuestionQCM");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Couleur");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Quelle est la couleur du ciel ?");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "3");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Rouge");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Vert");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "Bleu");
    
    std::getline(lecture, ligne);
    REQUIRE(ligne == "3");
    
    lecture.close();
    remove("test_temp.txt");
}

TEST_CASE("QuestionQCM : afficherquestion") {
    std::vector<std::string> choix = {
        "Rouge",
        "Vert",
        "Bleu"
    };

    QuestionQCM q(
        "Couleur",
        "Quelle est la couleur du ciel ?",
        choix,
        3
    );

    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    
    q.afficherquestion();
    
    std::cout.rdbuf(oldCout);
    
    std::string output = oss.str();
    REQUIRE(output.find("Couleur") != std::string::npos);
    REQUIRE(output.find("Quelle est la couleur du ciel ?") != std::string::npos);
    REQUIRE(output.find("1. Rouge") != std::string::npos);
    REQUIRE(output.find("2. Vert") != std::string::npos);
    REQUIRE(output.find("3. Bleu") != std::string::npos);
}
