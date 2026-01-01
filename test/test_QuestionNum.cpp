#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "../QuestionNum.h"
#include <sstream>
#include <fstream>

TEST_CASE("QuestionNumerique - verificationreponse") {

    QuestionNumerique q("Maths","2+2 ?",4,0,10);

    SUBCASE("Bonnee reponse") {
        REQUIRE(q.verificationreponse("4") == true);
    }

    SUBCASE("Mauvaised reponse") {
        REQUIRE(q.verificationreponse("3") == false);
    }
    SUBCASE("Réponse hors limite") {
        REQUIRE(q.verificationreponse("11") == false);
        REQUIRE(q.verificationreponse("-5") == false);
    }
    SUBCASE("Réponse non numérique") {
        REQUIRE(q.verificationreponse("abc") == false);
        REQUIRE(q.verificationreponse("4a") == false);
        REQUIRE(q.verificationreponse("") == false);
    }
}

TEST_CASE("QuestionNumerique - BonneReponse") {
    SUBCASE("Retourne bien la réponse numérique en string") {
        QuestionNumerique q("Maths","5*3 ?",15,0,20);
         REQUIRE(q.BonneReponse() == "15");
    }
}

TEST_CASE("QuestionNumerique - sauvegarder fichier") {

    QuestionNumerique q("Maths","2+2 ?",4,0,10);

    SUBCASE("Les données sauvegardées sont correctes") {
        std::ofstream f("temp.txt");

        q.sauvegarder(f);

        f.close();

        std::ifstream in("temp.txt");
        std::string l;

        std::getline(in,l); REQUIRE(l == "QuestionNumerique");

        std::getline(in,l); REQUIRE(l == "Maths");
        std::getline(in,l); REQUIRE(l == "2+2 ?");
        std::getline(in,l); REQUIRE(l == "4");
        std::getline(in,l); REQUIRE(l == "0");
        std::getline(in,l); REQUIRE(l == "10");

        in.close();
        remove("temp.txt");
    }
}

TEST_CASE("QuestionNumerique - afficherquestion()") {

    QuestionNumerique q("Maths","2+2 ?",4,0,10);


    SUBCASE("Affichage en console correct") {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        q.afficherquestion();
        std::cout.rdbuf(old);

        std::string out = oss.str();
        REQUIRE(out.find("Maths") != std::string::npos);

        REQUIRE(out.find("2+2 ?") != std::string::npos);

        REQUIRE(out.find("0") != std::string::npos);
        REQUIRE(out.find("10") != std::string::npos);
    }
}
