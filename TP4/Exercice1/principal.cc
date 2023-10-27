#include "VecteurND.h"

#include <iostream>
using namespace std;

int main()
{
    // Création des instances de la classe VecteurND à partir des 5 constructeurs.
    VecteurND vecteur1;
    VecteurND vecteur2 (10);
    VecteurND vecteur3 (10, 5);
    double Tab[] = {1.8, 3.4, 2.6, 1.2, 3.5, 2.2, 1.7, 3.4, 2.5, 8.9};
    VecteurND vecteur4 (10, Tab);
    VecteurND vecteur5 (vecteur3);
    double Tab2[] = {0.4, 0.7, 0.1, 0.5, 0.8, 0.2, 0.6, 0.9, 0.3, 0.7};
    VecteurND vecteur6 (10, Tab2);

    // Affichage des instances de VecteurND
    cout << "********** Question 1" << endl;
    cout << "   vecteur1 : " << endl;
    vecteur1.afficher(cout);
    cout << "\n   vecteur2 : " << endl;
    vecteur2.afficher(cout);
    cout << "\n   vecteur3 : " << endl;
    vecteur3.afficher(cout);
    cout << "\n   vecteur4 : " << endl;
    vecteur4.afficher(cout);
    cout << "\n   vecteur5 : " << endl;
    vecteur5.afficher(cout);

    // Test accesseur getDimension (vecteur2)
    cout << "\nDimension (vecteur2) : " << vecteur2.getDimension() << endl;

    // Test méthode calculerNorme (vecteur4)
    cout << "\nNorme (vecteur4) : " << vecteur4.calculerNorme() << endl;

    // Test méthode calculerProdScalaire (vecteur4 et vecteur6)
    cout << "\nProduit scalaire (vecteur4 et vecteur6) : " << vecteur4.calculerProdScalaire(vecteur6) << endl;

    // Test méthode operator= (vecteur1 et vecteur3)
    cout << "\n********** Question 2" << endl;
    cout << "Operateur = avec vecteur1 et vecteur3" << endl;
    vecteur1 = vecteur3;
    vecteur1.afficher(cout);

    // Test méthode operator+ (addition)
    VecteurND addition = vecteur2 + vecteur3;
    cout << "\nAddition : \n" << addition << endl;
    
    // Test méthode operator- (soustraction)
    VecteurND soustraction = vecteur4 - vecteur5;
    cout << "Soustraction : \n" << soustraction << endl;

    // Test méthode operator* (multiplication)
    VecteurND multiplication = vecteur3 * 3.0;
    cout << "Multiplication : \n" << multiplication << endl;

    // Test méthode operator< (vecteur4 et vecteur6)
    cout << "vecteur4 est-il inferieur au vecteur6 : " << (vecteur4 < vecteur6) << endl;
    
    // Test méthode operator[] (vecteur1)
    vecteur1[0] = 4.0;
    cout << "\nvecteur1 apres modification : " << vecteur1 << endl;

    return 0;
}

/*
./a.out
********** Question 1
   vecteur1 :
Dimension   : 0
Coordonnees : NULL

   vecteur2 :
Dimension   : 10
Coordonnees : [ 4.81086e-304, 9.17243e+170, 2.72744e-310, 6.47995e-310, 4.81086e-304, 6.48122e-310, 4.81072e-304, -3.26471e+192, -1.50058e+231, -7.58128e+269 ]

   vecteur3 :
Dimension   : 10
Coordonnees : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ]

   vecteur4 :
Dimension   : 10
Coordonnees : [ 1.8, 3.4, 2.6, 1.2, 3.5, 2.2, 1.7, 3.4, 2.5, 8.9 ]

   vecteur5 :
Dimension   : 10
Coordonnees : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ]

Dimension (vecteur2) : 10

Norme (vecteur4) : 11.8322

Produit scalaire (vecteur4 et vecteur6) : 18.26

********** Question 2
Operateur = avec vecteur1 et vecteur3
Dimension   : 10
Coordonnees : [ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ]

Addition : Dimension   : 10
Coordonnees : [ 5, 9.17243e+170, 5, 5, 5, 5, 5, -3.26471e+192, -1.50058e+231, -7.58128e+269 ]

Soustraction : Dimension   : 10
Coordonnees : [ -3.2, -1.6, -2.4, -3.8, -1.5, -2.8, -3.3, -1.6, -2.5, 3.9 ]

Multiplication : Dimension   : 10
Coordonnees : [ 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 ]

vecteur4 est-il inferieur au vecteur6 : 0
vecteur1 apres modification : Dimension   : 10
Coordonnees : [ 4, 5, 5, 5, 5, 5, 5, 5, 5, 5 ]
*/
