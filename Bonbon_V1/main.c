#include <stdio.h>
#include <stdlib.h>
#include "bonbon.h"
#include "distributeur.h"
#include "combinaison.h"
#include "joueur.h"
#include "score.h"


#include "constantes.h"
#include <string.h>
#include "jeu.h"

void afficherMenuPrincipal() {
    printf("\n");

    printf("      MACHINE A BONBONS      \n \n");

    printf(" 1. Jouer une partie          \n");
    printf(" 2. Parametrer le jeu         \n");
    printf(" 3. Voir les scores           \n");
    printf(" 4. Quitter                   \n");

}

int main() {
    Jeu jeu;
    initialiserJeu(&jeu);

    int choix;
    do {
        afficherMenuPrincipal();
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                lancerPartieAuto(&jeu);
                break;
            case 2:
                parametrerJeu(&jeu);
                break;
            case 3:
                afficherScoresJeu(&jeu);
                break;
            case 4:
                printf("Merci d'avoir joue a bientot\n");
                break;
            default:
                printf("Choix invalide  Veuillez choisir entre 1 et 4.\n");
        }
    } while(choix != 4);
    return 0 ;
}
