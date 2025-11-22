#ifndef COMBINAISON_H_INCLUDED
#define COMBINAISON_H_INCLUDED

#include "bonbon.h"

#define MAX_Combinaison 50
#define MAX_BONBONS_COMBINAISON 3

typedef struct {
    int id;
    Bonbon bonbons[MAX_BONBONS_COMBINAISON];
    int nbBonbons;
    int points;
} Combinaison;

///prototype
int countColor(Bonbon tab[], int nb, const char *couleur);
Combinaison creerCombinaisonChoix1(Bonbon tab[], int nb);
Combinaison creerCombinaisonManuelle();
void afficherToutesCombinaisons(Combinaison tab[], int nb);
void afficherToutesCombinaisons(Combinaison tab[], int nb);
void afficherCombinaison(Combinaison c);
int chercherCombinaison(Combinaison tab[], int nb, int id);
int modifierCombinaison(Combinaison tab[], int nb, int id, Combinaison nouv);
int ajouterCombinaison(Combinaison tab[], int *nb, Combinaison c);
int supprimerCombinaison(Combinaison tab[], int *nb, int id);

#endif // COMBINAISON_H_INCLUDED
