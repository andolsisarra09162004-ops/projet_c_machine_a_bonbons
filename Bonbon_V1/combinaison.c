#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combinaison.h"
#include "bonbon.h"

// Fonction pour compter les couleurs
int countColor(Bonbon tab[], int nb, const char *couleur) {
    int c = 0;
    for (int i = 0; i < nb; i++) {
        if (strcmp(tab[i].couleur, couleur) == 0)
            c++;
    }
    return c;
}

// Créer des combinaisons prédéfinies pour choix1
Combinaison creerCombinaisonChoix1(Bonbon tab[], int nb) {
    Combinaison C;

    int nbRouge = countColor(tab, nb, "rouge");
    int nbBleu  = countColor(tab, nb, "bleu");
    int nbVert  = countColor(tab, nb, "vert");

    // 3 rouge par 3 tire  20pt
    if (nbRouge == 3 && nb == 3) {
        C.id = 1;
        strcpy(C.couleur, "rouge");
        C.points = 20;
        return C;
    }
    // 2 bleu 1 vert  8pt
    else if (nbBleu == 2 && nbVert == 1 && nb == 3) {
        C.id = 2;
        strcpy(C.couleur, "bleu/vert");
        C.points = 50;
        return C;
    }
    else { // Ajouter else et accolades
        //pas de combinaison prédéfinie
        C.id = 0;
        strcpy(C.couleur, tab[0].couleur);
        C.points = 0;
        for (int i = 0; i < nb; i++)
            C.points += tab[i].valeur;
    }
    return C;
}

// Création des combinaisons de façon manuelle choix2
Combinaison creerCombinaisonChoix2(Bonbon tab[], int nb) {
    Combinaison C;
    int ok;

    do {
        ok = 1;

        printf("ID : ");//contrôle ID
        if (scanf("%d", &C.id) != 1 || C.id < 0) {
            ok = 0;
            printf("ID invalide.\n");
            while(getchar() != '\n'); // Vider le buffer
            continue;
        }

        printf("Couleur : ");
        if (scanf("%19s", C.couleur) != 1) { // CORRIGÉ le format
            ok = 0;
            printf("Couleur invalide.\n");
            while(getchar() != '\n');
            continue;
        }

        int existe = 0;
        for (int i = 0; i < nb; i++)
            if (strcmp(tab[i].couleur, C.couleur) == 0)
                existe = 1;

        if (!existe) {
            ok = 0;
            printf("Cette couleur n'existe pas dans le jeu.\n");
            continue;
        }

        printf("Points : ");
        if (scanf("%d", &C.points) != 1 || C.points < 0) {
            ok = 0;
            printf("Points invalides.\n");
            while(getchar() != '\n');
        }

    } while (!ok);

    printf("Combinaison créée avec succès.\n");
    return C;
}

// Afficher toutes les combinaisons
void afficherToutesCombinaisons(Combinaison tab[], int nb) {
    for (int i = 0; i < nb; i++)
        afficherCombinaison(tab[i]);
}

// Afficher une seule combinaison
void afficherCombinaison(Combinaison c) {
    printf("ID : %d | Couleur : %s | Points : %d\n", c.id, c.couleur, c.points);
}

// Chercher une combinaison - CORRIGÉ (return -1 à la fin)
int chercherCombinaison(Combinaison tab[], int nb, int id) {
    for (int i = 0; i < nb; i++) {
        if (tab[i].id == id) {
            return i;
        }
    }
    return -1; // CORRIGÉ : return -1 à la fin
}

// Modification
int modifierCombinaison(Combinaison tab[], int nb, int id, Combinaison nouv) {
    int pos = chercherCombinaison(tab, nb, id);
    if (pos == -1) return 0;

    tab[pos] = nouv;
    return 1;
}

// Ajouter une combinaison
int ajouterCombinaison(Combinaison tab[], int *nb, Combinaison c) {
    if (*nb >= MAX_Combinaison)
        return 0; // tableau plein
    tab[*nb] = c;
    (*nb)++;
    return 1;
}

// Supprimer une combinaison
int supprimerCombinaison(Combinaison tab[], int *nb, int id) {
    int pos = chercherCombinaison(tab, *nb, id);
    if (pos == -1) return 0;

    // Remplacement par le dernier élément
    for (int i = pos; i < *nb - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*nb)--;
    return 1;
}




