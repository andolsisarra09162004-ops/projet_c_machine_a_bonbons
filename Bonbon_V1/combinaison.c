#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combinaison.h"
#include "bonbon.h"


/// Fonction pour compter les couleurs
int countColor(Bonbon tab[], int nb, const char *couleur) {
    int c = 0;
    for (int i = 0; i < nb; i++) {
        if (strcmp(tab[i].couleur, couleur) == 0)
            c++;
    }
    return c;
}

/// Créer des combinaisons prédéfinies pour choix1
Combinaison creerCombinaisonChoix1(Bonbon tab[], int nb) {
    Combinaison C;
    C.nbBonbons = nb;  // ← La combinaison contient tous les bonbons tirés

    // Copier les bonbons tirés dans la combinaison
    for(int i = 0; i < nb; i++) {
        C.bonbons[i] = tab[i];
    }

    int nbRouge = countColor(tab, nb, "rouge");
    int nbBleu  = countColor(tab, nb, "bleu");
    int nbVert  = countColor(tab, nb, "vert");

    // 3 rouge = 80pt
    if (nbRouge == 3 && nb == 3) {
        C.id = 1;
        C.points = 80;
        return C;
    }
    // 2 bleu + 1 vert = 50pt
    else if (nbBleu == 2 && nbVert == 1 && nb == 3) {
        C.id = 2;
        C.points = 50;
        return C;
    }
    else {
        // Pas de combinaison prédéfinie - somme des valeurs
        C.id = 0;
        C.points = 0;
        for (int i = 0; i < nb; i++) {
            C.points += tab[i].valeur;
        }
    }
    return C;
}


void afficherToutesCombinaisons(Combinaison tab[], int nb) {
    if (nb == 0) {
        printf("Aucune combinaison configuree.\n");
        return;
    }

    for (int i = 0; i < nb; i++) {
        printf("%d. ", i + 1);
        afficherCombinaison(tab[i]);
    }
}

/// Création des combinaisons de façon manuelle choix2
Combinaison creerCombinaisonManuelle() {
    Combinaison C;
    int ok;

    do {
        ok = 1;

        printf("ID de la combinaison : ");
        if (scanf("%d", &C.id) != 1 || C.id < 0) {
            ok = 0;
            printf("ID invalide.\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Nombre de bonbons dans la combinaison (1-3) : ");
        if (scanf("%d", &C.nbBonbons) != 1 || C.nbBonbons < 1 || C.nbBonbons > 3) {
            ok = 0;
            printf("Nombre invalide. Doit etre entre 1 et 3.\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Saisie des %d bonbons :\n", C.nbBonbons);
        for(int i = 0; i < C.nbBonbons; i++) {
            printf("Bonbon %d:\n", i+1);
            printf("  Couleur : ");
            scanf("%19s", C.bonbons[i].couleur);
            printf("  Valeur : ");
            scanf("%d", &C.bonbons[i].valeur);
        }

        printf("Points de la combinaison : ");
        if (scanf("%d", &C.points) != 1 || C.points < 0) {
            ok = 0;
            printf("Points invalides.\n");
            while(getchar() != '\n');
        }

    } while (!ok);

    printf("Combinaison creee avec succes!\n");
    return C;
}


/// afficher combinaison
void afficherCombinaison(Combinaison c) {
    printf("ID : %d | ", c.id);
    printf("Bonbons : ");
    for(int i = 0; i < c.nbBonbons; i++) {
        printf("%s(%d)", c.bonbons[i].couleur, c.bonbons[i].valeur);
        if(i < c.nbBonbons - 1) printf(" + ");
    }
    printf(" | Points : %d\n", c.points);
}







/// Chercher une combinaison
int chercherCombinaison(Combinaison tab[], int nb, int id) {
    for (int i = 0; i < nb; i++) {
        if (tab[i].id == id) {
            return i;
        }
    }
    return -1;
}

/// Modification
int modifierCombinaison(Combinaison tab[], int nb, int id, Combinaison nouv) {
    int pos = chercherCombinaison(tab, nb, id);
    if (pos == -1) return 0;

    tab[pos] = nouv;
    return 1;
}

/// Ajouter une combinaison
int ajouterCombinaison(Combinaison tab[], int *nb, Combinaison c) {
    if (*nb >= MAX_Combinaison)
        return 0; // tableau plein
    tab[*nb] = c;
    (*nb)++;
    return 1;
}

/// Supprimer une combinaison
int supprimerCombinaison(Combinaison tab[], int *nb, int id) {
    int pos = chercherCombinaison(tab, *nb, id);
    if (pos == -1) return 0;

    // Remplacement par décalage
    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    return 1;
}



