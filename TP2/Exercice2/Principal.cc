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
    Objet objet4 (objet3);

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
    cin >> objet1;

    // Test méthode operator== (objet3 et objet4)
    cout << "Ces objets sont-ils identiques ? " << objet3.operator==(objet4) << endl;

    // Création des instances de la classe Carton
    Carton carton1 (1, 1);
    Carton carton2 (carton1);

    // Test méthode contient (carton3)
    

    return 0;
}
