#include <iostream>
#include <string>
#include "Questionnaire.h"
#include "Apprentissage.h"
#include "EvaluationTest.h"
#include "EvaluationSecChance.h"
#include "EvaluationAdap.h"
#include "goto_xy_windows.h"

int main() {
    while (true) {
        system("cls");

        // 1) Demander le fichier questionnaire
        std::string nomFichier;
        goto_xy(10, 5);
        std::cout << "Entrez le nom du fichier questionnaire : ";
        std::getline(std::cin, nomFichier);

        Questionnaire questionnaire;
        questionnaire.lectureDepuisFichier(nomFichier);

        // 2) Menu principal : Apprentissage / Evaluation / Quitter
        bool continuerMenuPrincipal = true;
        while (continuerMenuPrincipal) {
            system("cls");

            int x = 25;
            int y = 3;

            goto_xy(x, y++);
            std::cout << "===============================";
            goto_xy(x, y++);
            std::cout << "      Gestion Questionnaire";
            goto_xy(x, y++);
            std::cout << "===============================";

            y++;

            goto_xy(x, y++);
            std::cout << "1. Apprentissage";
            goto_xy(x, y++);
            std::cout << "2. Evaluation";
            goto_xy(x, y++);
            std::cout << "3. Quitter";

            y += 2;
            goto_xy(x, y);
            std::cout << "Choix : ";

            int choixPrincipal;
            std::cin >> choixPrincipal;
            std::cin.ignore();

            system("cls");

            switch (choixPrincipal) {
                case 1: {
                    // Apprentissage
                    Apprentissage app;
                    app.AfficheQuestionsAvecReponses(questionnaire);
                    break;
                }
                case 2: {
                    // 3) Sous-menu des types d'évaluation
                    int choixEval = 0;
                    do {
                        system("cls");
                        int xe = 25;
                        int ye = 5;

                        goto_xy(xe, ye++);
                        std::cout << "====== Choix de l'evaluation ======";
                        goto_xy(xe, ye++);
                        std::cout << "1. Evaluation (test)";
                        goto_xy(xe, ye++);
                        std::cout << "2. Evaluation (seconde chance)";
                        goto_xy(xe, ye++);
                        std::cout << "3. Evaluation (adaptative)";
                        goto_xy(xe, ye++);
                        std::cout << "4. Retour";

                        ye += 2;
                        goto_xy(xe, ye);
                        std::cout << "Choix : ";

                        std::cin >> choixEval;
                        std::cin.ignore();
                        system("cls");

                        switch (choixEval) {
                            case 1: {
                                EvaluationTest evaluation(questionnaire);
                                evaluation.lancer();
                                break;
                            }
                            case 2: {
                                EvaluationSecondeChance evaluation(questionnaire);
                                evaluation.lancer();
                                break;
                            }
                            case 3: {
                                EvaluationAdaptative evaluation(questionnaire);
                                evaluation.lancer();
                                break;
                            }
                            case 4:
                                // Retour au menu principal
                                break;
                            default:
                                std::cout << "Choix invalide.\n";
                                break;
                        }

                        if (choixEval >= 1 && choixEval <= 3) {
                            std::cout << "\nAppuyez sur Entree pour revenir au menu des evaluations...";
                            std::cin.get();
                        }
                    } while (choixEval != 4);
                    break;
                }
                case 3:
                    std::cout << "Au revoir.\n";
                    return 0;
                default:
                    std::cout << "Choix invalide.\n";
                    break;
            }

            // Après Apprentissage ou un passage par Evaluation, proposer de :
            // - revenir au menu principal avec le même fichier
            // - choisir un nouveau fichier
            // - quitter
            std::cout << "\nQue voulez-vous faire maintenant ?\n";
            std::cout << "1. Revenir au menu (meme fichier)\n";
            std::cout << "2. Choisir un autre fichier\n";
            std::cout << "3. Quitter\n";
            std::cout << "Choix : ";

            int suite;
            std::cin >> suite;
            std::cin.ignore();

            if (suite == 1) {
                // on reste dans le while(continuerMenuPrincipal) avec le meme questionnaire
                continue;
            } else if (suite == 2) {
                // sortir du menu principal pour recommencer au début avec un autre fichier
                continuerMenuPrincipal = false;
            } else {
                std::cout << "Au revoir.\n";
                return 0;
            }
        }
    }

    return 0;
}

