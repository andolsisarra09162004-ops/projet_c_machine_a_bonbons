#ifndef COMBINAISON_H_INCLUDED
#define COMBINAISON_H_INCLUDED
#define   MAX_Combinaison   50
#include "bonbon.h"

typedef struct {
int id;
char couleur[MAX_Combinaison];
int points;
} Combinaison;


///prototype
int countColor(Bonbon tab[], int nb, const char *couleur);
Combinaison creerCombinaisonChoix1(Bonbon tab[], int nb);
Combinaison creerCombinaisonChoix2(Bonbon tab[], int nb);
void afficherToutesCombinaisons(Combinaison tab[], int nb);
void afficherCombinaison(Combinaison c);
int chercherCombinaison(Combinaison tab[], int nb, int id);
int modifierCombinaison(Combinaison tab[], int nb, int id, Combinaison nouv);
int ajouterCombinaison(Combinaison tab[], int *nb, Combinaison c);
int supprimerCombinaison(Combinaison tab[], int *nb, int id);


#endif // COMBINAISON_H_INCLUDED
