#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionText.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


TEST_CASE("Tests complets QuestionTexte") {

    QuestionTexte q("Capitale", "Quelle est la capitale de la France ?", "Paris");

    SUBCASE("verificationreponse - plusieurs cas") {
        REQUIRE(q.verificationreponse("Paris") == true);
        REQUIRE(q.verificationreponse("paris") == false); 
        REQUIRE(q.verificationreponse("Londres") == false);
    }

    SUBCASE("BonneReponse") {
        REQUIRE(q.BonneReponse() == "Paris");
    }

    SUBCASE("afficherquestion - structure") {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());
        q.afficherquestion();
        std::cout.rdbuf(old);

        std::istringstream iss(oss.str());
        std::string l1, l2;

        std::getline(iss, l1);
        std::getline(iss, l2);

        REQUIRE(l1 == "Thème : Capitale");
        REQUIRE(l2 == "Quelle est la capitale de la France ?");
    }

    SUBCASE("Autre question texte pour compléter la couverture") {
        QuestionTexte q2("Sport", "Sport national du Japon ?", "Sumo");

        REQUIRE(q2.verificationreponse("Sumo") == true);
        REQUIRE(q2.verificationreponse("Judo") == false);
        REQUIRE(q2.BonneReponse() == "Sumo");
    }
}