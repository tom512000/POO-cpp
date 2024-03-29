#include <iostream>
using namespace std;

bool saisieDonnees(int &, char &, int &);
int calcul(int, char, int, bool &);

int main()
{

    int nbr1, nbr2, calc;
    char oper;
    bool booleen;

    if (saisieDonnees(nbr1, oper, nbr2)) {
        calc = calcul(nbr1, oper, nbr2, booleen);
        if (!booleen) {
            cout << "Opération impossible" << endl;
            saisieDonnees(nbr1, oper, nbr2);
            calc = calcul(nbr1, oper, nbr2, booleen);
        }
        cout << nbr1 << oper << nbr2 << '=' << calc << endl;
    }

    return 0;
}

// Etape 1
bool saisieDonnees(int & nbr1, char & oper, int & nbr2)
{
    int res;
    do {
        cout << "Souhaitez vous saisir des données ? (0-non, 1-oui) ";
        cin >> res;
    }
    while (res != 0 && res != 1);

    if (res == 1) {
        
        // Saisie du premier opérande
        cout << "Entrez l'opérande 1 (entier) : ";
        cin >> nbr1;

        // Saisie du deuxième opérande
        cout << "Entrez l'opérande 2 (entier) : ";
        cin >> nbr2;

        // Saisie de l'opérateur
        do {
            cout << "Entrez l'opérateur (+, -, *, / ou %) : ";
            cin >> oper;
        }
        while ((oper != '+') && (oper != '-') && (oper != '*') && (oper != '/') && (oper != '%'));
    }
    
    return res == 1;
}

// Etape 2
int calcul(int nbr1, char oper, int nbr2, bool & booleen)
{
    int res;
    
    if (nbr2 != 0) {
        booleen = true;
        if (oper == '+') {
            res = nbr1 + nbr2;
        } else if (oper == '-') {
            res = nbr1 - nbr2;
        } else if (oper == '*') {
            res = nbr1 * nbr2;
        } else if (oper == '/') {
            res = nbr1 / nbr2;
        } else if (oper == '%') {
            res = nbr1 % nbr2;
        }
    } else
        booleen = false;

    return res;
}

/*
./a.out
Souhaitez vous saisir des données ? (0-non, 1-oui) 1
Entrez l'opérande 1 (entier) : 6
Entrez l'opérande 2 (entier) : 0
Entrez l'opérateur (+, -, *, / ou %) : /
Opération impossible
Souhaitez vous saisir des données ? (0-non, 1-oui) 1
Entrez l'opérande 1 (entier) : 6
Entrez l'opérande 2 (entier) : 2
Entrez l'opérateur (+, -, *, / ou %) : /
6/2=3
*/
