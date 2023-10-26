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
    Objet objet5 ("Chaussette", 1, 2);

    // Test des accesseurs (objet2)
    cout << "\n********** Question 1" << endl;
    cout << "Volume (objet2) : " << objet2.getVolume() << endl;
    cout << "Poids (objet2)  : " << objet2.getPoids() << endl;

    // Test des modificateurs (objet2)
    objet2.setNom("Botte");
    objet2.setPoids(3);
    cout << "Poids (objet2)  : " << objet2.getPoids() << endl;

    // Test méthode estVide (objet1)
    cout << "\n********** Question 3" << endl;
    cout << "objet1 est-il vide ? " << objet1.estVide() << endl;

    // Test méthode afficher (objet2)
    cout << "\n********** Question 4" << endl;
    cout << objet2 << endl;

    // Test méthode saisir (objet1)
    cout << "********** Question 5" << endl;
    cin >> objet1;

    // Test méthode operator== (objet3 et objet4)
    cout << "\n********** Question 6" << endl;
    cout << "Ces objets sont-ils identiques ? " << (objet3 == objet4) << endl;

    // Création des instances de la classe Carton
    Carton carton1 (1, 1);
    Carton carton2 (carton1);
    Carton carton3 (10, 10);

    // Test méthode contient (carton3)
    cout << "\n********** Question 10" << endl;
    cout << "carton3 contient-il l'objet2 ? " << carton3.contient(objet2) << endl;

    // Test méthode ajouteObjet (carton3)
    cout << "\n********** Question 11" << endl;
    carton3.ajouteObjet(objet2);
    cout << "carton3 contient-il l'objet2 ? " << carton3.contient(objet2) << endl;

    // Test méthode operator+= (carton3 et objet2)
    carton3 += objet5;
    cout << "carton3 contient-il l'objet5 ? " << carton3.contient(objet5) << endl;

    // Test méthode operator[] (C)
    cout << "\n********** Question 12" << endl;
    Carton C(1000,1000);
    C += Objet("Lampe", 5 , 50);
    C[0].afficher(cout);

    // Test méthode afficher (C)
    C.afficher(cout);

    // Test fonction operator<< (carton3)
    cout << carton3 << endl;

    // Test méthode operator-= (carton3 et objet2)
    cout << "********** Question 13" << endl;
    carton3 -= objet2;
    cout << "carton3 contient-il l'objet2 ? " << carton3.contient(objet2) << endl;

    return 0;
}

/*
./a.out
********** Question 1
Volume (objet2) : 1
Poids (objet2)  : 5
Poids (objet2)  : 3

********** Question 3
objet1 est-il vide ? 1

********** Question 4
Nom    : Botte
Volume : 1
Poids  : 3

********** Question 5
Nom    : oui
Volume : 5
Poids  : 5

********** Question 6
Ces objets sont-ils identiques ? 1

********** Question 10
carton3 contient-il l'objet2 ? -1

********** Question 11
carton3 contient-il l'objet2 ? 0
carton3 contient-il l'objet5 ? 1

********** Question 12
Nom    : Lampe
Volume : 5
Poids  : 50

Contenu du carton :
Objet n*1 :
Nom    : Lampe
Volume : 5
Poids  : 50

Contenu du carton :
Objet n*1 :
Nom    : Botte
Volume : 1
Poids  : 3

Objet n*2 :
Nom    : Chaussette
Volume : 1
Poids  : 2

********** Question 13
carton3 contient-il l'objet2 ? -1
*/
