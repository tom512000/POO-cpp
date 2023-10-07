#include <cstdlib>
#include <iostream>
using namespace std;

int* creationTableau(int);
void afficherTableau(const int*, int);
int trouverIndiceValeurMin(const int*, int);
double calculerMoyenne(const int*, int);
void echangerCases(int*, int, int);
int* dupliquerTableau(int*, int);

int main()
{
    cout << "\n********** Question 1 **********";
    int taille;
    cout << "\nEntrez la taille du tableau : ";
    cin >> taille;

    // Création du tableau 1D
    int* tableau = creationTableau(taille);

    // Afficher le tableau
    cout << "\n********** Question 2 **********";
    afficherTableau(tableau, taille);

    // Affiche l'indice de la valeur minimale
    cout << "\n********** Question 4 **********";
    cout << "\nIndice de la valeur minimale : " << trouverIndiceValeurMin(tableau, taille) << endl;

    // Affiche la moyenne des valeurs du tableau
    cout << "\n********** Question 5 **********";
    cout << "\nMoyenne : " << calculerMoyenne(tableau, taille) << endl;

    // Echange l'emplacement de 2 valeurs
    cout << "\n********** Question 6 **********";
    echangerCases(tableau, 4, 5);
    afficherTableau(tableau, taille);

    // Création d'un nouveau tableau (duplication)
    cout << "\n********** Question 7 **********";
    int* nvtableau = dupliquerTableau(tableau, taille);
    afficherTableau(nvtableau, taille);

    delete[] tableau;
    
    return 0;
}

int* creationTableau(int taille) {
    int* tableau = new int[taille];

    for (int i = 0; i < taille; ++i) {
        tableau[i] = rand() % 101;
    }

    return tableau;
}

void afficherTableau(const int* tableau, int taille) {
    cout << "\n" << tableau[0];
    for (int i = 1; i < taille; ++i) {
        cout << " , " << tableau[i];
    }
    cout << endl;
}

int trouverIndiceValeurMin(const int* tableau, int taille) {
    int indiceMin = 0;
    int valeurMin = tableau[0];

    for (int i = 1; i < taille; ++i) {
        if (tableau[i] < valeurMin) {
            valeurMin = tableau[i];
            indiceMin = i;
        }
    }

    return indiceMin;
}

double calculerMoyenne(const int* tableau, int taille) {
    int somme = 0;

    for (int i = 0; i < taille; ++i) {
        somme += tableau[i];
    }

    return (double)somme / taille;
}

void echangerCases(int* tableau, int indice1, int indice2) {
    int temp = tableau[indice1];
    tableau[indice1] = tableau[indice2];
    tableau[indice2] = temp;
}

int* dupliquerTableau(int* tableau, int taille) {
    int* nouveauTableau = creationTableau(taille);
    
    for (int i = 0; i < taille; i++) {
        nouveauTableau[i] = tableau[i];
    }

    return nouveauTableau;
}

/*
.\a.out
********** Question 1 **********
Entrez la taille du tableau : 10

********** Question 2 **********
41 , 85 , 72 , 38 , 80 , 69 , 65 , 68 , 96 , 22

********** Question 4 **********
Indice de la valeur minimale : 9

********** Question 5 **********
Moyenne : 63.6

********** Question 6 **********
41 , 85 , 72 , 38 , 69 , 80 , 65 , 68 , 96 , 22

********** Question 7 **********
41 , 85 , 72 , 38 , 69 , 80 , 65 , 68 , 96 , 22
*/
