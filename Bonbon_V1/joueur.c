#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
#define  MAX_JOUEURS  30
/// creer joueur
Joueur creerJoueur(const char* pseudo) {
    Joueur joueur;
    strncpy(joueur.pseudo, pseudo, MAX_PSEUDO - 1);
    joueur.scoreTotal = 0;
    return joueur;
}
/// afficher joueur
void afficherJoueur(const Joueur* joueur)
{
    printf("Joueur: %s, Score: %d\n",
    joueur->pseudo,
     joueur->scoreTotal);
}
/// modifier joueur
void modifierJoueur(Joueur* joueur, const char* nouveauPseudo) {
    if (joueur != NULL)
    {
        strcpy(joueur->pseudo, nouveauPseudo);

    }
}
/// ajouter score
void ajouterPointsJoueur(Joueur* joueur, int points) {
    if (joueur != NULL) {
        joueur->scoreTotal += points;
    }


}
/// suprimer joueur
int supprimerJoueur(Joueur joueurs[], int* nbJoueurs, const char* pseudo)
 {
    if (joueurs == NULL || nbJoueurs == NULL || pseudo == NULL)
        {
        return 0;
    }

    for (int i = 0; i < *nbJoueurs; i++)
        {
        if (strcmp(joueurs[i].pseudo, pseudo) == 0)
        {
            // Decalage des éléments pour remplir le trou
            for (int j = i; j < *nbJoueurs - 1; j++) {
                joueurs[j] = joueurs[j + 1];
            }
            (*nbJoueurs)--;
            return 1;
        }
    }
    return 0; // Joueur non trouve
}
