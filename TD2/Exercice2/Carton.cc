#include <iostream>
#include <stdexcept>
#include <vector>
#include "Carton.h"
#include "Objet.h"

using namespace std;

const int Carton::max_Objets = 10;

// Le constructeur par copie, le destructeur et l'opérateur= ne sont pas nécessaires.
// L'un des attributs de la classe ne pointe pas sur une adresse dynamiquement.
Carton::Carton (int volumeMax, int poidsMax) throw(invalid_argument)
{
    if (volumeMax <= 0 || poidsMax <= 0)
        throw invalid_argument("Un ou plusieurs attributs sont négatifs ou nuls.");
    this->volumeMax = volumeMax;
    this->poidsMax = poidsMax;
    this->contenu = vector<Objet>(Carton::max_Objets);
    this->nbObjets = 0;
    this->volumeReel = 0;
    this->poidsReel = 0;
}

/*
Carton & Carton::operator= (const Carton & crt)
{
    this->volumeMax = crt.volumeMax;
    this->poidsMax = crt.poidsMax;
    this->nbObjets = crt.nbObjets;
    this->volumeReel = crt.volumeReel;
    this->poidsReel = crt.poidsReel;
    this->contenu = crt.contenu;
    return *this;
}
*/

int Carton::contient(const Objet & obj) const
{
    int indice = -1;
    for (int i = 0; i < this->contenu.size(); i++)
    {
        if (this->contenu[i] == obj) {
            indice = i;
        }
    }
    return indice;
}

void ajouteObjet(const Objet & obj) throw (invalid_argument)
{
    if (obj.estVide() || (this->poidsReel > this->poidsMax) || (this->volumeReel > this->volumeReel) || (this->nbObjets == Carton::max_Objets))
        throw invalid_argument("Une ou plusieurs conditions ne sont pas respectées !");
    this->nbObjets += 1;
    this->volumeReel += obj->getVolume();
    this->poidsReel += obj->getPoids();
    
    while ()
    {
        /* code */
    }
    
    for (int i = 0; i < this->contenu.size(); i++)
    {
        if (this->contenu[i].estVide()) {
            this->contenu[i] = obj;
        }
    }
}
