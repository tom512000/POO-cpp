#include <iostream>
using namespace std;

bool saisieDonnees(int *, char *, int *);
int calcul(int, char, int, bool *);

int main()
{

    int nbr1 = 0, nbr2 = 0, calc = 0;
    char oper;
    bool booleen;

    if (saisieDonnees(& nbr1, & oper, & nbr2)) {
        calc = calcul(nbr1, oper, nbr2, & booleen);
        if (booleen) {
            cout << nbr1 << oper << nbr2 << '=' << calc << endl;
        } else {
            cout << "Operation impossible" << endl;
            saisieDonnees(& nbr1, & oper, & nbr2);
            calc = calcul(nbr1, oper, nbr2, & booleen);
            cout << nbr1 << oper << nbr2 << '=' << calc << endl;
        }
    }

    return 0;
}

bool saisieDonnees(int * nbr1, char * oper, int * nbr2)
{
    int res = 0;
    
    do {
        cout << "Souhaitez vous saisir des donnees ? (0-non, 1-oui) ";
        cin >> res;
    }
    while (res != 0 && res != 1);

    if (res == 1) {

        // Saisie du premier operande
        cout << "Entrez l'operande 1 (entier) : ";
        cin >> *nbr1;

        // Saisie du deuxième operande
        cout << "Entrez l'operande 2 (entier) : ";
        cin >> *nbr2;

        // Saisie de l'operateur
        do {
            cout << "Entrez l'operateur (+, -, *, / ou %) : ";
            cin >> *oper;
        }
        while ((*oper != '+') && (*oper != '-') && (*oper != '*') && (*oper != '/') && (*oper != '%'));
    }

   return res == 1;
}

int calcul(int nbr1, char oper, int nbr2, bool * booleen)
{
    int res;
    
    if (nbr2 != 0) {
        *booleen = true;
        if (oper == '+')
            res = nbr1 + nbr2;
        else if (oper == '-')
            res = nbr1 - nbr2;
        else if (oper == '*')
            res = nbr1 * nbr2;
        else if (oper == '/')
            res = nbr1 / nbr2;
        else if (oper == '%')
            res = nbr1 % nbr2;
    } else
        *booleen = false;
    
    return res;
}

/*
./a.out
Souhaitez vous saisir des donnees ? (0-non, 1-oui) 1
Entrez l'operande 1 (entier) : 5
Entrez l'operande 2 (entier) : 0
Entrez l'operateur (+, -, *, / ou %) : /
Operation impossible
Souhaitez vous saisir des donnees ? (0-non, 1-oui) 1
Entrez l'operande 1 (entier) : 5
Entrez l'operande 2 (entier) : 5
Entrez l'operateur (+, -, *, / ou %) : +
5+5=10
*/
