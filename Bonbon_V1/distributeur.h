#ifndef DISTRIBUTEUR_H_INCLUDED
#define DISTRIBUTEUR_H_INCLUDED

#include "bonbon.h"

#define MAX_BONBONS 100

typedef struct Distributeur {
    int id;
    Bonbon reserve[MAX_BONBONS];
    int nbBonbons;
} Distributeur;

// Prototypes
Distributeur creerDistributeur(int id);
int ajouterBonbonDistributeur(Distributeur *d, Bonbon b);
int supprimerBonbonDistributeur(Distributeur *d, char couleur[]);
int modifierBonbonDistributeur(Distributeur *d, char couleur[], char newCouleur[], int newValeur);
void afficherDistributeur(Distributeur d);
void remplirDistributeurManuel(Distributeur *d);
void remplirDistributeurAuto(Distributeur *d);

#endif // DISTRIBUTEUR_H_INCLUDED
