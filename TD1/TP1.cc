#include <iostream>
using namespace std;

bool saisieDonnees(int &, char &, int &);


// Fonction principale
int main()
{

    int nbr1, nbr2;
    char oper;

    if (saisieDonnees(nbr1, oper, nbr2)) {
        cout << "Opération demandée : " << nbr1 << ' ' << oper << ' ' << nbr2 << endl;
    }

    return 0;
}

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
        do {
            cout << "Entrez l'opérande 1 (entier) : ";
            cin >> nbr1;
        }
        while (!isdigit(nbr1));

        // Saisie du deuxième opérande
        do {
            cout << "Entrez l'opérande 2 (entier) : ";
            cin >> nbr2;
        }
        while (!isdigit(nbr2));

        // Saisie de l'opérateur
        do {
            cout << "Entrez l'opérateur (+, -, *, / ou %) : ";
            cin >> oper;
        }
        while (oper != '+' && oper != '-' && oper != '*' && oper != '/' && oper != '%');
    }

   return res == 1;
}