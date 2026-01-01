#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionQCM.h"
#include <sstream>
#include <iostream>


TEST_CASE("Tests complets QuestionQCM") {

    std::vector<std::string> choix1 = {"Rouge", "Vert", "Bleu"};
    QuestionQCM q("Couleur", "Quelle est la couleur du ciel ?", choix1, 3);

    SUBCASE("verificationreponse - bon et mauvais cas") {
        REQUIRE(q.verificationreponse("3") == true);  
        REQUIRE(q.verificationreponse("2") == false);  
        REQUIRE(q.verificationreponse("0") == false); 
        REQUIRE(q.verificationreponse("10") == false); 
    }

    SUBCASE("BonneReponse - retour correct") {
        REQUIRE(q.BonneReponse() == "3");
    }

    SUBCASE("afficherquestion - structure correcte") {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
        q.afficherquestion();
        std::cout.rdbuf(old);

        std::istringstream iss(oss.str());
        std::string l1, l2, l3, l4, l5;

        std::getline(iss, l1);
        std::getline(iss, l2);
        std::getline(iss, l3);
        std::getline(iss, l4);
        std::getline(iss, l5);

        REQUIRE(l1 == "Thème : Couleur");
        REQUIRE(l2 == "Quelle est la couleur du ciel ?");
        REQUIRE(l3 == "1. Rouge");
        REQUIRE(l4 == "2. Vert");
        REQUIRE(l5 == "3. Bleu");
    }

    SUBCASE("Ajout d'un second QCM pour meilleure couverture") {
        std::vector<std::string> choix2 = {"Dog", "Cat"};
        QuestionQCM q2("Animal", "Best pet ?", choix2, 1);
        REQUIRE(q2.verificationreponse("1") == true);
        REQUIRE(q2.verificationreponse("2") == false);

        REQUIRE(q2.BonneReponse() == "1");
    }
}
