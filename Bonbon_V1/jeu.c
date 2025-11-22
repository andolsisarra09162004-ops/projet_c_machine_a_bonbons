#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.h"


void initialiserJeu(Jeu* jeu) {
    // Initialisation des valeurs par défaut
    jeu->nbTours = 5;
    jeu->toursEffectues = 0;
    jeu->modeJeu = 1; // Solo par défaut
    jeu->nbJoueurs = 0;
    jeu->nbCombinaisons = 0;
    jeu->nbScores = 0;

    // Initialisation des distributeurs
    for(int i = 0; i < MAX_DISTRIBUTEURS; i++) {
        jeu->distributeurs[i] = creerDistributeur(i+1);
        remplirDistributeurAuto(&jeu->distributeurs[i]);
    }

    printf("Jeu initialisé avec succès!\n");
}






///========================================choix1 automatiquement=================================================


void lancerPartieAuto(Jeu* jeu) {
    if (jeu->nbJoueurs == 0) {
        printf("Aucun joueur, Veuillez d'abord ajouter un joueur.\n");
        return;
    }

    // DEMANDER quel joueur joue
    int joueurActuel = 0;
    if (jeu->nbJoueurs > 1) {
        printf("\nJoueurs disponibles:\n");
        for(int i = 0; i < jeu->nbJoueurs; i++) {
            printf("%d. %s\n", i+1, jeu->joueurs[i].pseudo);
        }
        printf("Quel joueur joue ? (1-%d): ", jeu->nbJoueurs);
        scanf("%d", &joueurActuel);
        joueurActuel--;
    }

    printf("\n=== LANCEMENT DE LA PARTIE POUR %s ===\n", jeu->joueurs[joueurActuel].pseudo);
    printf("Nombre de tours: %d\n", jeu->nbTours);

    for(int tour = 1; tour <= jeu->nbTours; tour++) {
        printf("\n--- Tour %d ---\n", tour);

        // Chaque distributeur ejecte un bonbon
        Bonbon bonbonsTires[3];
        for(int i = 0; i < MAX_DISTRIBUTEURS; i++) {
            if(jeu->distributeurs[i].nbBonbons > 0) {
                int index = rand() % jeu->distributeurs[i].nbBonbons;
                bonbonsTires[i] = jeu->distributeurs[i].reserve[index];
                printf("Distributeur %d: ", i+1);
                afficherBonbon(bonbonsTires[i]);
            }
        }

        // Calcul du score pour ce tour
        Combinaison combinaison = creerCombinaisonChoix1(bonbonsTires, MAX_DISTRIBUTEURS);

        // Afficher la combinaison
        printf("Combinaison: ");
        for(int i = 0; i < combinaison.nbBonbons; i++) {
            printf("%s(%d)", combinaison.bonbons[i].couleur, combinaison.bonbons[i].valeur);
            if(i < combinaison.nbBonbons - 1) printf(" + ");
        }
        printf(" - %d points\n", combinaison.points);

        // Ajout du score au joueur
        ajouterPointsJoueur(&jeu->joueurs[joueurActuel], combinaison.points);
        printf("Score actuel de %s: %d points\n",
               jeu->joueurs[joueurActuel].pseudo, jeu->joueurs[joueurActuel].scoreTotal);
    }

    // Sauvegarde du score final
    Score nouveauScore = creerScore(jeu->joueurs[joueurActuel].pseudo,
                                   jeu->joueurs[joueurActuel].scoreTotal);
    ajouterScore(jeu->scores, &jeu->nbScores, &nouveauScore);

    printf("\n=== PARTIE TERMINEE ===\n");
    printf("Score final de %s: %d points\n",
           jeu->joueurs[joueurActuel].pseudo, jeu->joueurs[joueurActuel].scoreTotal);
}
///=======================choix2==========================
void parametrerJeu(Jeu* jeu) {
    int choix;
    do {
        printf("\n=== PARAMETRAGE DU JEU ===\n");
        printf("1. Ajouter un joueur\n");
        printf("2. Configurer les distributeurs\n");
        printf("3. Configurer les combinaisons\n");
        printf("4. Modifier le nombre de tours\n");
        printf("5. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                if(jeu->nbJoueurs < MAX_JOUEURS) {
                    char pseudo[MAX_PSEUDO];
                    printf("Pseudo du joueur: ");
                    scanf("%s", pseudo);
                    jeu->joueurs[jeu->nbJoueurs] = creerJoueur(pseudo);
                    jeu->nbJoueurs++;
                    printf("Joueur %s ajoute\n", pseudo);
                } else {
                    printf("Nombre maximum de joueurs atteint\n");
                }
                break;
            }
            case 2: {
                int choixDistri;
                do {
                    printf("\n=== CONFIGURATION DES DISTRIBUTEURS ===\n");
                    for(int i = 0; i < MAX_DISTRIBUTEURS; i++) {
                        printf("\nDistributeur %d:\n", i+1);
                        afficherDistributeur(jeu->distributeurs[i]);
                    }

                    printf("\nOptions:\n");
                    printf("1. Remplir un distributeur automatiquement\n");
                    printf("2. Remplir un distributeur manuellement\n");
                    printf("3. Vider un distributeur\n");
                    printf("4. Retour au parametrage\n");
                    printf("Choix: ");
                    scanf("%d", &choixDistri);

                    switch(choixDistri) {
                        case 1: {
                            int numDistri;
                            printf("Numero du distributeur (1-%d): ", MAX_DISTRIBUTEURS);
                            scanf("%d", &numDistri);
                            if(numDistri >= 1 && numDistri <= MAX_DISTRIBUTEURS) {
                                remplirDistributeurAuto(&jeu->distributeurs[numDistri-1]);
                                printf("Distributeur %d rempli automatiquement\n", numDistri);
                            } else {
                                printf("Numero de distributeur invalide\n");
                            }
                            break;
                        }
                        case 2: {
                            int numDistri;
                            printf("Numero du distributeur (1-%d): ", MAX_DISTRIBUTEURS);
                            scanf("%d", &numDistri);
                            if(numDistri >= 1 && numDistri <= MAX_DISTRIBUTEURS) {
                                remplirDistributeurManuel(&jeu->distributeurs[numDistri-1]);
                                printf("Distributeur %d rempli manuellement\n", numDistri);
                            } else {
                                printf("Numero de distributeur invalide\n");
                            }
                            break;
                        }
                        case 3: {
                            int numDistri;
                            printf("Numero du distributeur a vider (1-%d): ", MAX_DISTRIBUTEURS);
                            scanf("%d", &numDistri);
                            if(numDistri >= 1 && numDistri <= MAX_DISTRIBUTEURS) {
                                jeu->distributeurs[numDistri-1].nbBonbons = 0;
                                printf("Distributeur %d vidé!\n", numDistri);
                            } else {
                                printf("Numero de distributeur invalide\n");
                            }
                            break;
                        }
                        case 4:
                            printf("Retour au parametrage...\n");
                            break;
                        default:
                            printf("Choix invalide!\n");
                    }
                } while(choixDistri != 4);
                break;
            }
            case 3: {
                int choixComb;
                do {
                    printf("\n=== CONFIGURATION DES COMBINAISONS ===\n");
                    printf("Combinaisons existantes:\n");
                    if(jeu->nbCombinaisons == 0) {
                        printf("Aucune combinaison configurée.\n");
                    }
                    else {
                        afficherToutesCombinaisons(jeu->combinaisons, jeu->nbCombinaisons);
                    }

                    printf("\n Options:\n");
                    printf("1. Creer une nouvelle combinaison\n");
                    printf("2. Modifier une combinaison\n");
                    printf("3. Supprimer une combinaison\n");
                    printf("4. Retour au parametrage\n");
                    printf("Choix: ");
                    scanf("%d", &choixComb);

                    switch(choixComb) {
                        case 1: {
                           Combinaison nouvelle = creerCombinaisonManuelle();
                            if(ajouterCombinaison(jeu->combinaisons, &jeu->nbCombinaisons, nouvelle))
                                {
                                        printf("Combinaison ajoutée avec succes\n");
                                                                    }
                        }
                        case 2: {
                            if(jeu->nbCombinaisons > 0)
                            {
                                int id;
                                printf("ID de la combinaison a modifier: ");
                                scanf("%d", &id);

                                int pos = chercherCombinaison(jeu->combinaisons, jeu->nbCombinaisons, id);
                                if(pos != -1) {
                                    printf("Modification de la combinaison ID %d:\n", id);
                                    Combinaison nouvelle = creerCombinaisonManuelle();
                                    if(modifierCombinaison(jeu->combinaisons, jeu->nbCombinaisons, id, nouvelle)) {
                                        printf("Combinaison modifiee avec succes\n");
                                    } else {
                                        printf("Erreur lors de la modification.\n");
                                    }
                                } else {
                                    printf("Combinaison non trouvee\n");
                                }
                            } else {
                                printf("Aucune combinaison a modifier.\n");
                            }
                            break;
                        }
                        case 3: {
                            if(jeu->nbCombinaisons > 0)
                            {
                                int id;
                                printf("ID de la combinaison a supprimer: ");
                                scanf("%d", &id);

                                if(supprimerCombinaison(jeu->combinaisons, &jeu->nbCombinaisons, id)) {
                                    printf("Combinaison supprimee avec succes \n");
                                }
                                else {
                                    printf("Combinaison non trouvee\n");
                                }
                            } else {
                                printf("Aucune combinaison a supprimer.\n");
                            }
                            break;
                        }
                        case 4:
                            printf("Retour au parametrage...\n");
                            break;
                        default:
                            printf("Choix invalide \n");
                    }
                } while(choixComb != 4);
                break;
            }
            case 4: {
                printf("Nouveau nombre de tours (actuel: %d): ", jeu->nbTours);
                scanf("%d", &jeu->nbTours);
                printf("Nombre de tours modifie a %d\n", jeu->nbTours);
                break;
            }
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while(choix != 5);
}




///=======================choix3========================





void afficherScoresJeu(Jeu* jeu) {
    int choix;
    do {
        printf("\n=== AFFICHAGE DES SCORES ===\n");
        printf("1. Par ordre croissant\n");
        printf("2. Par ordre decroissant\n");
        printf("3. Par ordre alphabetique\n");
        printf("4. Pour un joueur donné\n");
        printf("5. Par ordre chronologique\n");
        printf("6. Retour au menu principal\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                afficherScores(jeu->scores, jeu->nbScores, TRI_CROISSANT);
                break;
            case 2:
                afficherScores(jeu->scores, jeu->nbScores, TRI_DECROISSANT);
                break;
            case 3:
                afficherScores(jeu->scores, jeu->nbScores, TRI_ALPHABETIQUE);
                break;
            case 4: {
                char pseudo[MAX_PSEUDO];
                printf("Pseudo du joueur: ");
                scanf("%s", pseudo);
                printf("\nScores de %s:\n", pseudo);
                for(int i = 0; i < jeu->nbScores; i++) {
                    if(strcmp(jeu->scores[i].pseudo, pseudo) == 0) {
                        afficherScore(&jeu->scores[i]);
                    }
                }
                break;
            }
            case 5:
                afficherScores(jeu->scores, jeu->nbScores, TRI_CHRONOLOGIQUE);
                break;
            case 6:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide \n");
        }
    } while(choix != 6);
}

