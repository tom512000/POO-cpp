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

    // Affichage des instances de VecteurND
    cout << "   vecteur1 : " << endl;
    vecteur1.afficher(cout);
    cout << "   \nvecteur2 : " << endl;
    vecteur2.afficher(cout);
    cout << "   \nvecteur3 : " << endl;
    vecteur3.afficher(cout);
    cout << "   \nvecteur4 : " << endl;
    vecteur4.afficher(cout);
    cout << "   \nvecteur5 : " << endl;
    vecteur5.afficher(cout);

    // Test accesseur getDimension (vecteur2)
    cout << "\nDimension (vecteur2) : " << vecteur2.getDimension() << endl;

    // Test opérateur = (vecteur1 et vecteur3)
    cout << "\nOpérateur = avec vecteur1 et vecteur3" << endl;
    vecteur1 = vecteur3;
    vecteur1.afficher(cout);

    // Test calculerNorme (vecteur4)
    cout << "\nNorme (vecteur4) : " << vecteur4.calculerNorme() << endl;

    return 0;
}
