#include "bonbon.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
// Création d'un bonbon
Bonbon creerBonbon(char couleur[], int valeur)
 {    Bonbon b;
     strcpy(b.couleur, couleur);
     b.valeur = valeur;
      return b;}
// Affichage d'un bonbon
void afficherBonbon(Bonbon b) {
   printf("Bonbon : %s - %d pts\n", b.couleur, b.valeur);
   }
  // Supprimer un bonbon d'un tableau de bonbons
int supprimerBonbon(Bonbon tab[], int *nb, char couleur[])       // *nb le nombre des element du tableau dans distrib
 { for (int i = 0; i < *nb; i++)
 {
       if (strcmp(tab[i].couleur, couleur) == 0)
       {                                                            // décalage vers la gauche
            for (int j = i; j < (*nb - 1); j++)
            {                tab[j] = tab[j + 1];            }
                    (*nb)--;
                       return 1;
                          }    }
                          return 0; }
// Modifier un bonbon dans le tableau
int modifierBonbon(Bonbon tab[], int nb, char couleur[], char newCouleur[], int newValeur)
{    for (int i = 0; i < nb; i++)
{        if (strcmp(tab[i].couleur, couleur) == 0)
{            strcpy(tab[i].couleur, newCouleur);
  tab[i].valeur = newValeur;
   return 1;

   }    }    return 0;

   }
