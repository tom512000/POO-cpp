#include "Personne.h"

#include <iostream>
using namespace std;

int main()
{
    // Création des instances de la classe Personne (p1, p2 et p3)
    Personne p1 ("Dupont", "Gaston", 36);
    p1.affiche();

    Personne p2;
    p2.affiche();

    Personne p3 (p1);
    p3.affiche();

    // Test des accesseurs (p1)
    cout << "Nom (p1)    : " << p1.getNom() << endl;
    cout << "Prenom (p1) : " << p1.getPrenom() << endl;
    cout << "Age (p1)    : " << p1.getAge() << endl;

    // Test des modificateurs (p2)
    p2.setNom("Sikora");
    p2.setPrenom("Tom");
    p2.setAge(19);
    p2.affiche();

    // Test fonction compare (p1 et p3)
    cout << "Comparaison de p1 et p3 : ";
    if (compare(p1, p3))
        cout << "Les instances sont identiques\n";
    else
        cout << "Les instances sont différentes\n";

    // Test fonction afficherPersonne (p2)
    affiche(p2);

    return 0;
}

/*
./a.out
Personne( Dupont , Gaston , 36 ) : 0x7ffc11063b90
Nom    : Dupont
Prenom : Gaston
Age    : 36
Personne() : 0x7ffc11063be0
Nom    :
Prenom :
Age    : 0
Personne( 0x7ffc11063b90 ) : 0x7ffc11063c30
Nom    : Dupont
Prenom : Gaston
Age    : 36
Nom (p1)    : Dupont
Prenom (p1) : Gaston
Age (p1)    : 36
Nom    : Sikora
Prenom : Tom
Age    : 19
Comparaison de p1 et p3 : Personne( 0x7ffc11063c30 ) : 0x7ffc11063cd0
Personne( 0x7ffc11063b90 ) : 0x7ffc11063c80
~Personne() : 0x7ffc11063c80
~Personne() : 0x7ffc11063cd0
egaux
Nom    : Sikora
Prenom : Tom
Age    : 19
~Personne() : 0x7ffc11063c30
~Personne() : 0x7ffc11063be0
~Personne() : 0x7ffc11063b90
*/
