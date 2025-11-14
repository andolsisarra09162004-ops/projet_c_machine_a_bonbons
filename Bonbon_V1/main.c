#include <stdio.h>
#include <stdlib.h>
//======STRUCTURES DU PROJET=====//
/* Bonbon*/
typedef struct Bonbon {
      char couleur[20];
      int valeur;}Bonbon;

/*Combinaison*/
typedef struct Combinaison {
    Bonbon b1;
    Bonbon b2;
    Bonbon b3;
    int points;} Combinaison;


/*Distributeur*/
typedef struct Distributeur {
    Bonbon reserve[100];
    int nbBonbons;} Distributeur;

/*Joueur*/
typedef struct Joueur {
    char pseudo[30];
    int score;} Joueur;

/* ===MENU===*/
void menuPrincipale()
{int choix;
    do{
            printf("###JEU DE MACHINE A BONBONS### /n");
            printf("1) Jouer /n");
            printf("2) Paramétrer le jeu");
            printf("3)Afficher les scores /n");
            printf("4)Quitter le jeu");
            printf("Votre choix : ");
            scanf(" %d", & choix);
            switch (choix) {

                   case 1:
                        jouerAuto();
                        break;
                   case 2:
                        parametrageManuel();
                        break;
                    case 3:
                       afficherScores();
                        break;
                    case 4:
                        quitterJeu();
                         break;
                    default:
                        printf("\n Choix invalide, veuillez réessayer.\n");        }
                            }while choix != 4);}


}

/*

//===jouerAuto=== //

void jouerAuto() {
    printf("\n jouer automatiquement \n");
    creer_distributeurs();
    creer_combinaisons();
    MAJ_Joueur();}

//parametrageManuelle//

void parametrageManuel() {
    int choix;
    do {
        printf("\n### PARAMETRAGE DU JEU ###\n");
printf("1. Créer un nouveau type de bonbon\n");
printf("2. Définir la taille des réserves\n");
printf("3. Créer de nouvelles combinaisons\n");
printf("4. Retour au menu principal\n");
printf("Votre choix : ");
scanf("%d", &choix);
        switch (choix) {
            case 1:
                creerBonbon();
                break;
            case 2:
                definirTailleReserve();
                break;
            case 3:
                creerCombinaison();
                break;
            case 4:
                printf("Retour au menu principal\n");
                break;
            default:
                printf("Choix invalide Réessayez\n");        }
    } while (choix != 4);}

//afficherScores//

void afficherScores() {}


*/



int main()
{
    menuPrincipal();

    return 0;
}
