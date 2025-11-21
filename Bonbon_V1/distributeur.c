#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distributeur.h"
#include "bonbon.h"

// Créer un distributeur
Distributeur creerDistributeur(int id) {
    Distributeur d;
    d.id = id;
    d.nbBonbons = 0;
    return d;
}

// Ajouter un bonbon
int ajouterBonbonDistributeur(Distributeur *d, Bonbon b) {
    if (d->nbBonbons >= MAX_BONBONS) {
        printf("Reserve pleine ! Impossible d'ajouter.\n");
        return 0;
    }
    d->reserve[d->nbBonbons] = b;
    d->nbBonbons++;
    return 1;
}

// Supprimer un bonbon
int supprimerBonbonDistributeur(Distributeur *d, char couleur[]) {
    for (int i = 0; i < d->nbBonbons; i++) {
        if (strcmp(d->reserve[i].couleur, couleur) == 0) {
            // Décalage vers la gauche
            for (int j = i; j < d->nbBonbons - 1; j++) {
                d->reserve[j] = d->reserve[j + 1];
            }
            d->nbBonbons--;
            return 1;
        }
    }
    return 0;
}

// Modifier un bonbon
int modifierBonbonDistributeur(Distributeur *d, char couleur[], char newCouleur[], int newValeur) {
    for (int i = 0; i < d->nbBonbons; i++) {
        if (strcmp(d->reserve[i].couleur, couleur) == 0) {
            strcpy(d->reserve[i].couleur, newCouleur);
            d->reserve[i].valeur = newValeur;
            return 1;
        }
    }
    return 0;
}

// Afficher la réserve
void afficherDistributeur(Distributeur d) {
    printf("\n--- Distributeur %d ---\n", d.id);
    printf("Nombre de bonbons : %d\n", d.nbBonbons);

    for (int i = 0; i < d.nbBonbons; i++) {
        printf("%d) Couleur : %s | Valeur : %d\n",
               i + 1,
               d.reserve[i].couleur,
               d.reserve[i].valeur);
    }
}
void remplirDistributeurManuel(Distributeur *d) {
    int n;
    printf("Combien de bonbons voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char couleur[20];
        int valeur;

        printf("Bonbon %d couleur : ", i + 1);
        scanf("%s", couleur);

        printf("Valeur : ");
        scanf("%d", &valeur);


        Bonbon b = creerBonbon(couleur, valeur);
        ajouterBonbonDistributeur(d, b);
    }
}

// Remplissage automatique
void remplirDistributeurAuto(Distributeur *d) {

    char *couleurs[] = {"rouge", "bleu", "vert", "jaune"};
    int valeurs[] = {5, 10, 15, 20};

    for (int i = 0; i < 4; i++) {

        Bonbon b = creerBonbon(couleurs[i], valeurs[i]);
        ajouterBonbonDistributeur(d, b);
    }
}
