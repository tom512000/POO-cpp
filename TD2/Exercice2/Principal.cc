#include "Objet.h"
#include "Carton.h"
#include <iostream>
using namespace std;

int main()
{
    // Création des instances de la classe Objet
    Objet objet1;
    Objet objet2 ("Chaussure", 1, 5);
    Objet objet3 (objet2);

    // Test des accesseurs (objet2)
    cout << "Volume (objet2) : " << objet2.getVolume() << endl;
    cout << "Poids (objet2)  : " << objet2.getPoids() << endl;

    // Test des modificateurs (objet2)
    objet2.setNom("Botte");
    objet2.setPoids(3);
    cout << "Poids (objet2)  : " << objet2.getPoids() << endl;

    // Test méthode estVide (objet1)
    cout << "objet1 est-il vide ? " << objet1.estVide() << endl;

    // Test méthode afficher (objet2)
    cout << objet2 << endl;
    
    // Test méthode saisir (objet1)
    cin >> obj;

    return 0;
}