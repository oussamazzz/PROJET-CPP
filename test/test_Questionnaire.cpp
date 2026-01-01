#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include <fstream>
#include <memory>
#include "../Questionnaire.h"
#include "../QuestionText.h"
#include "../QuestionNum.h"
#include "../QuestionQCM.h"

TEST_CASE("Questionnaire")
{
    SUBCASE("Constructeur initialise un questionnaire vide")

    {
        Questionnaire q;
        REQUIRE(q.taille() == 0);
    }

    SUBCASE("Ajout d'une question augmente la taille")
    {
        Questionnaire q;

        q.ajouterQuestion(
            std::make_unique<QuestionTexte>(
                "Titre", "Question ?", "Reponse"
            )
        );

        REQUIRE(q.taille() == 1);
    }

    SUBCASE("getQuestions retourne le bon nombre de questions")
    {

        Questionnaire q;

        q.ajouterQuestion(
            std::make_unique<QuestionTexte>(
                "T1", "Q1", "R1"
            )
        );

        REQUIRE(q.getQuestions().size() == 1);
    }

    SUBCASE("Sauvegarde cree un fichier")
    {
        const std::string fichier = "test_save.txt";

        Questionnaire q("Test sauvegarde");
        q.ajouterQuestion(
            std::make_unique<QuestionTexte>(

                "Titre", "Capital de la France ?", "Paris"
            )
        );

        q.sauvegarder(fichier);

        std::ifstream f(fichier);
        REQUIRE(f.good());
    }

    SUBCASE("lectureDepuisFichier - fichier valide")
    {
        
        std::ofstream f("test_questionnaire.txt");
        f << "Questionnaire Test\n";
        f << "3\n";

        f << "QuestionTexte\n";
        f << "Titre 1\n";
        f << "Quelle est la capitale de la France ?\n";
        f << "Paris\n";

        f << "QuestionNumerique\n";
        f << "Maths\n";
        f << "2 + 2 = ?\n";
        f << "4 0 10\n";

        f << "QuestionQCM\n";
        f << "Info\n";
        f << "Langage C++ ?\n";
        f << "3\n";
        f << "Java\n";
        f << "C++\n";
        f << "Python\n";
        f << "1\n";
        f.close();

        Questionnaire q;
        bool ok = q.lectureDepuisFichier("test_questionnaire.txt");

        REQUIRE(ok == true);
        REQUIRE(q.taille() == 3);
    }

    SUBCASE("lectureDepuisFichier - fichier inexistant")
    {
        Questionnaire q;
        bool ok = q.lectureDepuisFichier("fichier_inexistant.txt");

        REQUIRE(ok == false);
        REQUIRE(q.taille() == 0);
    }
}