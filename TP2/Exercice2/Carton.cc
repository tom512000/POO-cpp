#include "Carton.h"
#include "Objet.h"

#include <iostream>
#include <stdexcept>
#include <vector>
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

/*Carton & Carton::operator= (const Carton & crt)
{
    this->volumeMax = crt.volumeMax;
    this->poidsMax = crt.poidsMax;
    this->nbObjets = crt.nbObjets;
    this->volumeReel = crt.volumeReel;
    this->poidsReel = crt.poidsReel;
    this->contenu = crt.contenu;
    return *this;
}*/

int Carton::contient(const Objet & obj) const
{
    int indice = -1;
    
    for (int i = 0; i < this->contenu.size(); i++) {
        if (this->contenu[i] == obj)
            indice = i;
    }
    
    return indice;
}

void Carton::ajouteObjet(const Objet & obj) throw (invalid_argument)
{
    if (obj.estVide())
        throw std::invalid_argument("L'objet est vide.");

    if (this->nbObjets >= Carton::max_Objets)
        throw std::invalid_argument("Le carton est plein.");

    if (this->poidsReel + obj.getPoids() > this->poidsMax)
        throw std::invalid_argument("Le poids maximal du carton serait dépassé.");

    if (this->volumeReel + obj.getVolume() > this->volumeMax)
        throw std::invalid_argument("Le volume maximal du carton serait dépassé.");

    contenu[this->nbObjets] = obj;
    this->nbObjets += 1;
    this->poidsReel += obj.getPoids();
    this->volumeReel += obj.getVolume();
}

Carton & Carton::operator+=(const Objet & obj)
{
    ajouteObjet(obj);
    
    return *this;
}

const Objet & Carton::operator[](int index) const
{
    if (index < 0 || index >= nbObjets)
        throw std::out_of_range("Index hors limites");
    
    return contenu[index];
}

ostream & Carton::afficher(ostream & o) const
{
    o << endl << "Contenu du carton : " << endl;
    for (int i = 0; i < nbObjets ; i++)
        o << "Objet n*" << i+1 << " : \n" << (*this)[i] << endl;
    
    return o;
}

ostream & operator<<(ostream & o, const Carton & c)
{
    return c.afficher(o);
}

void Carton::operator-=(const Objet & o) throw (std::invalid_argument)
{
    int index = contient(o);
    
    if (index == -1)
        throw std::invalid_argument("L'objet n'est pas dans le carton.");

    for (int i = index; i < nbObjets - 1; i++)
        contenu[i] = contenu[i + 1];

    this->nbObjets -= 1;
    this->poidsReel -= o.getPoids();
    this->volumeReel -= o.getVolume();
}
