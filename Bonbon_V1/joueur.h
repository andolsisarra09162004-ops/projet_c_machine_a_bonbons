#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string.h>

#define MAX_PSEUDO 30

typedef struct {
    char pseudo[MAX_PSEUDO];
    int scoreTotal;
} Joueur;

// Prototypes des fonctions
Joueur creerJoueur(const char* pseudo);
void afficherJoueur(const Joueur* joueur);
void modifierJoueur(Joueur* joueur, const char* nouveauPseudo);
void ajouterPointsJoueur(Joueur* joueur, int points);
int supprimerJoueur(Joueur joueurs[], int* nbJoueurs, const char* pseudo);







#endif // JOUEUR_H_INCLUDED
