#include <iostream>
#include <string>
using namespace std;

int decouvertePointeurs();

int main()
{
    decouvertePointeurs();

    return 0;
}

int decouvertePointeurs()
{

    int i = -1;
    unsigned int ui = 1;
    string s = "Hello";
    double d = 3.14159;
    long double ld = 2.75e-3;

    cout << "Valeur : " << i << " Adresse : " << &i << " Taille : " << sizeof(i) << endl;
    cout << "Valeur : " << ui << " Adresse : " << &ui << " Taille : " << sizeof(ui) << endl;
    cout << "Valeur : " << s << " Adresse : " << &s << " Taille : " << sizeof(s) << endl;
    cout << "Valeur : " << d << " Adresse : " << &d << " Taille : " << sizeof(d) << endl;
    cout << "Valeur : " << ld << " Adresse : " << &ld << " Taille : " << sizeof(ld) << endl;

    int * pi = &i;
    unsigned int * pui = &ui;
    string * ps = &s;
    double * pd = &d;
    long double * pld = &ld;

    cout << "Valeur : " << pi << " Adresse : " << &pi << " Taille : " << sizeof(pi) << endl;
    cout << "Valeur : " << pui << " Adresse : " << &pui << " Taille : " << sizeof(pui) << endl;
    cout << "Valeur : " << ps << " Adresse : " << &ps << " Taille : " << sizeof(ps) << endl;
    cout << "Valeur : " << pd << " Adresse : " << &pd << " Taille : " << sizeof(pd) << endl;
    cout << "Valeur : " << pld << " Adresse : " << &pld << " Taille : " << sizeof(pld) << endl;
    // La valeur contenue dans les pointeurs est l'adresse de la variable à laquelle elle fait référence.

    return 0;
}
