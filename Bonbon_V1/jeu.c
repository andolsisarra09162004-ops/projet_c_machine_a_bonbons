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

    // Initialisation des distributeurs - CORRIGÉ
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

    printf("\n=== LANCEMENT DE LA PARTIE AUTOMATIQUE ===\n");
    printf("Nombre de tours: %d\n", jeu->nbTours);

    for(int tour = 1; tour <= jeu->nbTours; tour++) {
        printf("\n--- Tour %d ---\n", tour);

        // Chaque distributeur éjecte un bonbon
        Bonbon bonbonsTires[3];
        for(int i = 0; i < MAX_DISTRIBUTEURS; i++) {
            if(jeu->distributeurs[i].nbBonbons > 0) {
                int index = rand() % jeu->distributeurs[i].nbBonbons;// rand  fonction qui retourne des valeurs aleatoire
                bonbonsTires[i] = jeu->distributeurs[i].reserve[index];
                printf("Distributeur %d: ", i+1);
                afficherBonbon(bonbonsTires[i]);
            }
        }

        // Calcul du score pour ce tour
        Combinaison combinaison = creerCombinaisonChoix1(bonbonsTires, MAX_DISTRIBUTEURS);
        printf("Combinaison: %s - %d points\n", combinaison.couleur, combinaison.points);

        // Ajout du score au joueur
        ajouterPointsJoueur(&jeu->joueurs[0], combinaison.points);
        printf("Score actuel de %s: %d points\n",
               jeu->joueurs[0].pseudo, jeu->joueurs[0].scoreTotal);
    }

    // Sauvegarde du score final
    Score nouveauScore = creerScore(jeu->joueurs[0].pseudo, jeu->joueurs[0].scoreTotal);
    ajouterScore(jeu->scores, &jeu->nbScores, &nouveauScore);

    printf("\n=== PARTIE TERMINÉE ===\n");
    printf("Score final de %s: %d points\n",
           jeu->joueurs[0].pseudo, jeu->joueurs[0].scoreTotal);
}



///============================================choix2===============================
void parametrerJeu(Jeu* jeu) {
    int choix;
    do {
        printf("\n=== PARAMÉTRAGE DU JEU ===\n");
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
                    printf("Joueur %s ajouté!\n", pseudo);
                } else {
                    printf("Nombre maximum de joueurs atteint!\n");
                }
                break;
            }
            case 2: {
                printf("\n=== CONFIGURATION DES DISTRIBUTEURS ===\n");
                for(int i = 0; i < MAX_DISTRIBUTEURS; i++) {
                    printf("\nDistributeur %d:\n", i+1);
                    afficherDistributeur(jeu->distributeurs[i]);
                }
                break;
            }
            case 3: {
                printf("\n=== COMBINAISONS ===\n");
                afficherToutesCombinaisons(jeu->combinaisons, jeu->nbCombinaisons);
                break;
            }
            case 4: {
                printf("Nouveau nombre de tours (actuel: %d): ", jeu->nbTours);
                scanf("%d", &jeu->nbTours);
                printf("Nombre de tours modifié à %d\n", jeu->nbTours);
                break;
            }
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while(choix != 5);
}





///=======================choix3========================





void afficherScoresJeu(Jeu* jeu) {
    int choix;
    do {
        printf("\n=== AFFICHAGE DES SCORES ===\n");
        printf("1. Par ordre croissant\n");
        printf("2. Par ordre décroissant\n");
        printf("3. Par ordre alphabétique\n");
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
                printf("Choix invalide!\n");
        }
    } while(choix != 6);
}

void sauvegarderDonnees(Jeu* jeu) {
    printf("Sauvegarde des données...\n");
    // À implémenter avec les fichiers
}

void chargerDonnees(Jeu* jeu) {
    printf("Chargement des données...\n");
    // À implémenter avec les fichiers
}
