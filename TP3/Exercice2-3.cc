#include <iostream>
#include <string>
using namespace std;

void decouvertePointeurs();
void initialisePointeur(int *);
void initialisePointeur(int **);
int* initialisePointeur();


int main()
{
    decouvertePointeurs();

    return 0;
}

void initialisePointeur(int * ptr)
{
    cout << "Valeur : " << ptr << " Adresse : " << &ptr << " Valeur (pointeur) : " << *ptr << endl;
    ptr = new int (5);
    cout << "Valeur : " << ptr << " Adresse : " << &ptr << " Valeur (pointeur) : " << *ptr << endl;
    delete ptr;
}


void initialisePointeur(int * *ptr)
{
    cout << "Valeur : " << *ptr << " Adresse : " << &*ptr << " Valeur (pointeur) : " << **ptr << endl;
    *ptr = new int (5);
    cout << "Valeur : " << *ptr << " Adresse : " << &*ptr << " Valeur (pointeur) : " << **ptr << endl;
}

int * initialisePointeur()
{
    int *ptr = new int (5);
    cout << "Valeur : " << ptr << " Adresse : " << &ptr << " Valeur (pointeur) : " << *ptr << endl;
    
    return ptr;
}

void decouvertePointeurs()
{
    cout << "\n********** Exercice 2 - Question 1";
    int i = -1;
    unsigned int ui = 1;
    string s = "Hello";
    double d = 3.14159;
    long double ld = 2.75e-3;

    cout << "\nValeur : " << i << " Adresse : " << &i << " Taille : " << sizeof(i) << endl;
    cout << "Valeur : " << ui << " Adresse : " << &ui << " Taille : " << sizeof(ui) << endl;
    cout << "Valeur : " << s << " Adresse : " << &s << " Taille : " << sizeof(s) << endl;
    cout << "Valeur : " << d << " Adresse : " << &d << " Taille : " << sizeof(d) << endl;
    cout << "Valeur : " << ld << " Adresse : " << &ld << " Taille : " << sizeof(ld) << endl;

    cout << "\n********** Exercice 2 - Question 2";
    int *pi = &i;
    unsigned int *pui = &ui;
    string *ps = &s;
    double *pd = &d;
    long double *pld = &ld;

    cout << "\nValeur : " << pi << " Adresse : " << &pi << " Taille : " << sizeof(pi) << endl;
    cout << "Valeur : " << pui << " Adresse : " << &pui << " Taille : " << sizeof(pui) << endl;
    cout << "Valeur : " << ps << " Adresse : " << &ps << " Taille : " << sizeof(ps) << endl;
    cout << "Valeur : " << pd << " Adresse : " << &pd << " Taille : " << sizeof(pd) << endl;
    cout << "Valeur : " << pld << " Adresse : " << &pld << " Taille : " << sizeof(pld) << endl;
    // La valeur contenue dans les pointeurs est l'adresse de la variable à laquelle elle fait référence.

    cout << "\n********** Exercice 2 - Question 3";
    *ps = "Hi";
    cout << "\nValeur : " << s << endl;
    cout << "Valeur : " << *ps << endl;

    // Exercice 2 - Question 4
    // Pas de new donc pas de delete[]

    cout << "\n********** Exercice 3 - Question 2";
    cout << "\n********** void initialisePointeur(int *);";
    cout << "\nValeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    initialisePointeur(pi);
    cout << "Valeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    
    cout << "\n********** void initialisePointeur(int **);";
    cout << "\nValeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    initialisePointeur(&pi);
    cout << "Valeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    delete pi;
    
    cout << "\n********** int* initialisePointeur();";
    pi = &i;
    cout << "\nValeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    pi = initialisePointeur();
    cout << "Valeur : " << pi << " Adresse : " << &pi << " Valeur (pointeur) : " << *pi << endl;
    delete pi;

    // Exercice 3 - Question 3
    // Lorsqu'on utilise l'allocation dynamique avec new,
    // il faut impérativement utiliser delete.
}

/*
./a.out
********** Exercice 2 - Question 1
Valeur : -1 Adresse : 0x7ffe553916c8 Taille : 4
Valeur : 1 Adresse : 0x7ffe553916cc Taille : 4
Valeur : Hello Adresse : 0x7ffe55391710 Taille : 32
Valeur : 3.14159 Adresse : 0x7ffe553916d0 Taille : 8
Valeur : 0.00275 Adresse : 0x7ffe55391700 Taille : 16

********** Exercice 2 - Question 2
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Taille : 8
Valeur : 0x7ffe553916cc Adresse : 0x7ffe553916e0 Taille : 8
Valeur : 0x7ffe55391710 Adresse : 0x7ffe553916e8 Taille : 8
Valeur : 0x7ffe553916d0 Adresse : 0x7ffe553916f0 Taille : 8
Valeur : 0x7ffe55391700 Adresse : 0x7ffe553916f8 Taille : 8

********** Exercice 2 - Question 3
Valeur : Hi
Valeur : Hi

********** Exercice 3 - Question 2
********** void initialisePointeur(int *);
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Valeur (pointeur) : -1
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916a8 Valeur (pointeur) : -1
Valeur : 0x55b891b712c0 Adresse : 0x7ffe553916a8 Valeur (pointeur) : 5
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Valeur (pointeur) : -1

********** void initialisePointeur(int **);
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Valeur (pointeur) : -1
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Valeur (pointeur) : -1
Valeur : 0x55b891b712c0 Adresse : 0x7ffe553916d8 Valeur (pointeur) : 5
Valeur : 0x55b891b712c0 Adresse : 0x7ffe553916d8 Valeur (pointeur) : 5

********** int* initialisePointeur();
Valeur : 0x7ffe553916c8 Adresse : 0x7ffe553916d8 Valeur (pointeur) : -1
Valeur : 0x55b891b712c0 Adresse : 0x7ffe553916a0 Valeur (pointeur) : 5
Valeur : 0x55b891b712c0 Adresse : 0x7ffe553916d8 Valeur (pointeur) : 5
*/
