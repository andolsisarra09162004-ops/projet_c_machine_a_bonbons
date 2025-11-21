#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define MAX_PSEUDO 30
#define MAX_DATE 20
#define MAX_SCORES 100

// Types de tri
#define TRI_CROISSANT 1
#define TRI_DECROISSANT 2
#define TRI_ALPHABETIQUE 3
#define TRI_CHRONOLOGIQUE 4

typedef struct {
    char pseudo[MAX_PSEUDO];
    int valeur;
    char date[MAX_DATE];
} Score;

// Prototypes des fonctions
void getCurrentDateTime(char* buffer);
Score creerScore(const char* pseudo, int valeur);
void afficherScore(const Score* score);
void afficherScores(const Score scores[], int nbScores, int modeTri);
void trierScores(Score scores[], int nbScores, int modeTri);

int ajouterScore(Score scores[], int* nbScores, const Score* nouveauScore);

#endif // SCORE_H_INCLUDED
