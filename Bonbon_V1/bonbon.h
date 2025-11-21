#ifndef BONBON_H_INCLUDED
#define BONBON_H_INCLUDED
typedef struct Bonbon {
      char couleur[20];
      int valeur;}Bonbon;



///prototype
Bonbon creerBonbon();
void afficherBonbon(Bonbon b);
int supprimerBonbon(Bonbon tab[], int *nb, char couleur[]);
int modifierBonbon(Bonbon tab[], int nb, char couleur[], char newCouleur[], int newValeur);



#endif // BONBON_H_INCLUDED
