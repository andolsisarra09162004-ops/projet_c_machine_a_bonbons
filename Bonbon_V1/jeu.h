#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED



#include "bonbon.h"
#include "distributeur.h"
#include "combinaison.h"
#include "joueur.h"
#include "score.h"
#include "constantes.h"

typedef struct {
    // Configuration du jeu
    int nbTours;
    int toursEffectues;
    int modeJeu; // 1=solo, 2=multijoueur

    // Données du jeu
    Distributeur distributeurs[MAX_DISTRIBUTEURS];
    Combinaison combinaisons[MAX_COMBINAISONS];
    int nbCombinaisons;

    // Joueurs
    Joueur joueurs[MAX_JOUEURS];
    int nbJoueurs;

    // Scores
    Score scores[MAX_SCORES];
    int nbScores;

} Jeu;

// Prototypes
void initialiserJeu(Jeu* jeu);
void lancerPartieAuto(Jeu* jeu);
void parametrerJeu(Jeu* jeu);
void afficherScoresJeu(Jeu* jeu);
void sauvegarderDonnees(Jeu* jeu);
void chargerDonnees(Jeu* jeu);

#endif // JEU_H_INCLUDED

