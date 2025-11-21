#include <stdio.h>
#include <stdlib.h>
#include "score.h"

#include <string.h>
#include <time.h>


/// Fonction pour obtenir la date actuelle
void getCurrentDateTime(char* buffer) {
    time_t maintenant = time(NULL);
    struct tm* date = localtime(&maintenant);


    sprintf(buffer, "%02d/%02d/%04d %02d:%02d",
            date->tm_mday,          // Jour
            date->tm_mon + 1,       // Mois (+1 car janvier=0)
            date->tm_year + 1900,   // Année (+1900 car depuis 1900)
            date->tm_hour,          // Heures
            date->tm_min);          // Minutes
}

///Créer un score avec date automatique
Score creerScore(const char* pseudo, int valeur)
 {
    Score nouveauScore;


    strcpy(nouveauScore.pseudo, pseudo);


    nouveauScore.valeur = valeur;

    // Générer la date automatiquement
    getCurrentDateTime(nouveauScore.date);

    return nouveauScore;
}

/// Afficher un score
void afficherScore(const Score* score) {
    printf("%s: %d points (le %s)\n",
           score->pseudo, score->valeur, score->date);
}

/// Afficher tous les scores avec tri
void afficherScores(const Score scores[], int nbScores, int modeTri) {
    if (nbScores == 0) {
        printf("Aucun score enregistré.\n");
        return;
    }

    /// Créer une copie pour le tri (pour ne pas modifier l'original)
    Score* scoresTries = malloc(nbScores * sizeof(Score));
    for (int i = 0; i < nbScores; i++) {
        scoresTries[i] = scores[i];
    }

    /// Trier la copie
    trierScores(scoresTries, nbScores, modeTri);

    /// Afficher les scores triés
    printf("\n=== LISTE DES SCORES ===\n");
    for (int i = 0; i < nbScores; i++) {
        printf("%d. ", i + 1);
        afficherScore(&scoresTries[i]);
    }


    free(scoresTries);
}

/// Fonction de tri (bulle simple)
void trierScores(Score scores[], int nbScores, int modeTri) {
    int i, j;
    Score temp;

    for (i = 0; i < nbScores - 1; i++) {
        for (j = 0; j < nbScores - i - 1; j++) {
            int doitEchanger = 0;

            switch (modeTri) {
                case TRI_CROISSANT:
                    doitEchanger = scores[j].valeur > scores[j + 1].valeur;
                    break;

                case TRI_DECROISSANT:
                    doitEchanger = scores[j].valeur < scores[j + 1].valeur;
                    break;

                case TRI_ALPHABETIQUE:
                    doitEchanger = strcmp(scores[j].pseudo, scores[j + 1].pseudo) > 0;
                    break;

                case TRI_CHRONOLOGIQUE:
                    // Comparer les dates (format permet la comparaison avec strcmp)
                    doitEchanger = strcmp(scores[j].date, scores[j + 1].date) > 0;
                    break;
            }

            if (doitEchanger) {
                // echanger
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

/// Ajouter un score au tableau
int ajouterScore(Score scores[], int* nbScores, const Score* nouveauScore) {
    if (*nbScores < MAX_SCORES) {
        scores[*nbScores] = *nouveauScore;
        (*nbScores)++;
        return 1;
    }
    return 0;
}
