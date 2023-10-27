#include <cstdlib>
#include <iostream>
using namespace std;

int* creeSuiteVide(int);
void initialise(int*, int, int);
void saisieJeu(const int*, int, int&, int&);
void affiche(const int*, int);
bool finJeu(const int*, int);
int simulePartie(int*, int);
void jouerPartie(int, int);

int main()
{
    int tailleMax = 7; 
    int valeurMax = 9;

    jouerPartie(tailleMax, valeurMax);

    return 0;
}

int* creeSuiteVide(int tailleMax)
{
    int* suite = new int[tailleMax];
    
    for (int i = 0; i < tailleMax; ++i)
        suite[i] = 0;

    return suite;
}

void initialise(int* suite, int taille, int valeurMax)
{
    for (int i = 0; i < taille; ++i)
        suite[i] = rand() % valeurMax + 1;
}

void saisieJeu(const int* suite, int taille, int& quelElement, int& valeur)
{
    do {
        cout << "Saisir l'index de l'élément (entre 0 et " << taille - 1 << "): ";
        cin >> quelElement;
    } while (quelElement < 0 || quelElement >= taille || suite[quelElement] == 0);

    do {
        cout << "Saisir la valeur à retrancher (entre 1 et " << suite[quelElement] << "): ";
        cin >> valeur;
    } while (valeur < 1 || valeur > suite[quelElement]);
}

void affiche(const int* suite, int taille)
{
    for (int i = 0; i < taille; ++i)
        cout << suite[i] << " ";
    cout << endl;
}

bool finJeu(const int* suite, int taille)
{
    bool res = true;
    
    for (int i = 0; i < taille; ++i) {
        if (suite[i] != 0)
            res = false;
    }
    
    return res;
}

int simulePartie(int* suite, int taille)
{
    int joueur = 1;

    while (!finJeu(suite, taille)) {
        affiche(suite, taille);
        
        int quelElement, valeur;
        saisieJeu(suite, taille, quelElement, valeur);
        suite[quelElement] -= valeur;

        if (joueur == 1)
            joueur = 2;
        else
            joueur = 1;
    }

    return joueur;
}

void jouerPartie(int tailleMax, int valeurMax)
{
    int* suite = creeSuiteVide(tailleMax);
    initialise(suite, tailleMax, valeurMax);

    cout << "La partie commence" << endl;
    int gagnant = simulePartie(suite, tailleMax);
    cout << gagnant << " a gagné" << endl;

    delete[] suite;
}

/*
./a.out
La partie commence
6 9 8 5 9 2 4
Saisir l'index de l'├®l├®ment (entre 0 et 6): 4
Saisir la valeur ├á retrancher (entre 1 et 9): 8
6 9 8 5 1 2 4
Saisir l'index de l'├®l├®ment (entre 0 et 6): 5
Saisir la valeur ├á retrancher (entre 1 et 2): 1
6 9 8 5 1 1 4 
Saisir l'index de l'├®l├®ment (entre 0 et 6): 6
Saisir la valeur ├á retrancher (entre 1 et 4): 3
6 9 8 5 1 1 1 
Saisir l'index de l'├®l├®ment (entre 0 et 6): 2
Saisir la valeur ├á retrancher (entre 1 et 8): 7
6 9 1 5 1 1 1 
Saisir l'index de l'├®l├®ment (entre 0 et 6): 5
Saisir la valeur ├á retrancher (entre 1 et 1): 1
6 9 1 5 1 0 1
*/
