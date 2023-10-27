#include "Objet.h"

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/* Le constructeur par copie, le destructeur et l'opérateur ne sont pas nécessaire.
Objet::Objet ()
{
    this->nom = "";
    this->volume = 0;
    this->poids = 0;
}*/

Objet::Objet (const string & nom, int volume, int poids) throw(invalid_argument)
{
    if (volume < 0 || poids < 0)
        throw invalid_argument("Un ou plusieurs attributs sont négatifs.");
    
    this->nom = nom;
    this->volume = volume;
    this->poids = poids;
}

int Objet::getVolume() const
{
    return this->volume;
}

int Objet::getPoids() const
{
    return this->poids;
}

void Objet::setNom(const string & nom)
{
    this->nom = nom;
}

void Objet::setPoids(int poids)
{
    this->poids = poids;
}

bool Objet::estVide() const
{
    bool res = false;

    if ((this->volume == 0) || (this->poids == 0) || (this->nom == ""))
        res = true;

    return res;
}

ostream & Objet::afficher(ostream & out) const
{
    out << "Nom    : " << this->nom << endl;
    out << "Volume : " << this->volume << endl;
    out << "Poids  : " << this->poids << endl;
    
    return out;
}

ostream & operator<<(ostream & out, const Objet & obj)
{
    return obj.afficher(out);
}

istream & Objet::saisir(istream & in)
{
    cout << "Nom    : ";
    in >> this->nom;
    cout << "Volume : ";
    in >> this->volume;
    cout << "Poids  : ";
    in >> this->poids;
    
    return in;
}

istream & operator>>(istream & in, Objet & obj)
{
    return obj.saisir(in);
}

bool Objet::operator== (const Objet & obj) const
{
    return this->nom == obj.nom && this->volume == obj.volume && obj.poids == this->poids;
}
