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
    if (compare(p1, p3)) {
        cout << "Les instances sont identiques\n";
    } else {
        cout << "Les instances sont différentes\n";
    }

    // Test fonction afficherPersonne (p2)
    affiche(p2);
    
    return 0;
}