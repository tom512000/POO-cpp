#include <iostream>
#include <stdexcept>
#include "Objet.h"

using namespace std;

/*
// Le constructeur par copie, le destructeur et l'opérateur ne sont pas nécessaire.
Objet::Objet ()
{
    this->nom = "";
    this->volume = 0;
    this->poids = 0;
}
*/

Objet (const string & nom, int volume, int poids) throw(invalid_argument)
{
    if (volume < 0 || poids < 0) {
        throw invalid_argument("Un ou plusieurs attributs sont négatifs.");
    } else {
        this->nom = nom;
        this->volume = volume;
        this->poids = poids;
    }
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