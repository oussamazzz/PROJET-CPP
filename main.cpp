#include <iostream>
#include <string>
#include "Questionnaire.h"
#include "Apprentissage.h"
#include "EvaluationTest.h"
#include "EvaluationSecChance.h"
#include "EvaluationAdap.h"

int main() {
    while (true) {
        system("cls");

        Questionnaire questionnaire;
        std::string nomFichier;

        bool chargeOk = false;
        while (!chargeOk) {
            std::cout << "Entrez le nom du fichier questionnaire : ";
            std::getline(std::cin, nomFichier);

            if (nomFichier.empty()) {
                std::cout << "Nom de fichier vide. Reessayez.\n";
                continue;
            }

            chargeOk = questionnaire.lectureDepuisFichier(nomFichier);
            if (!chargeOk) {
                std::cout << "\nEchec du chargement.\n";
                std::cout << "Voulez-vous reessayer avec un autre nom ? (o/n) : ";
                char r;
                std::cin >> r;
                std::cin.ignore();
                if (r == 'o' || r == 'O') {
                    system("cls");
                    continue;
                } else {
                    std::cout << "Au revoir.\n";
                    return 0;
                }
            }
        }

        bool continuerAvecCeFichier = true;
        while (continuerAvecCeFichier) {
            system("cls");

            std::cout << "===============================\n";
            std::cout << "      Gestion Questionnaire\n";
            std::cout << "===============================\n\n";

            std::cout << "1. Apprentissage\n";
            std::cout << "2. Evaluation\n";
            std::cout << "3. Quitter le programme\n\n";

            std::cout << "Choix : ";

            int choixPrincipal;
            std::cin >> choixPrincipal;
            std::cin.ignore();

            system("cls");

            switch (choixPrincipal) {
                case 1: {
                    Apprentissage app;
                    app.AfficheQuestionsAvecReponses(questionnaire);
                    break;
                }
                case 2: {
                    int choixEval = 0;
                    do {
                        system("cls");

                        std::cout << "====== Choix de l'evaluation ======\n";
                        std::cout << "1. Evaluation (test)\n";
                        std::cout << "2. Evaluation (seconde chance)\n";
                        std::cout << "3. Evaluation (adaptative)\n";
                        std::cout << "4. Retour au menu principal\n\n";
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

            std::cout << "\nQue voulez-vous faire maintenant ?\n";
            std::cout << "1. Revenir au menu (meme questionnaire)\n";
            std::cout << "2. Charger un autre questionnaire\n";
            std::cout << "3. Quitter le programme\n";
            std::cout << "Choix : ";

            int suite;
            std::cin >> suite;
            std::cin.ignore();

            if (suite == 1) {
                continue;
            } else if (suite == 2) {
                continuerAvecCeFichier = false;
            } else {
                std::cout << "Au revoir.\n";
                return 0;
            }
        }
    }

    return 0;
}
