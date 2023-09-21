#include <iostream>
#include "Personne.h"

using namespace std;

Personne::Personne (const string & nom, const string & prenom, int age)
{
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    cout << "Personne( " << this->nom;
    cout << " , " << this->prenom << " , " << this->age << " ) : " << this << endl;
}

Personne::Personne ()
{
    this->nom = "";
    this->prenom = "";
    this->age = 0;
    cout << "Personne() : " << this << endl;
}

Personne::Personne (const Personne & p)
{
    (*this).nom = p.nom;
    (*this).prenom = p.prenom;
    (*this).age = p.age;
    cout << "Personne( " << &p << " ) : " << this << endl;
}

void Personne::affiche() const
{
    cout << "Nom    : " << this->nom << endl;
    cout << "Prenom : " << this->prenom << endl;
    cout << "Age    : " << this->age << endl;
}

string Personne::getNom() const
{
    return this->nom;
}

string Personne::getPrenom() const
{
    return this->prenom;
}

int Personne::getAge() const
{
    return this->age;
}

void Personne::setNom(const string & nom)
{
    this->nom = nom;
}

void Personne::setPrenom(const string & prenom)
{
    this->prenom = prenom;
}

void Personne::setAge(int age)
{
    this->age = age;
}

Personne::~Personne()
{
    cout << "~Personne() : " << this << endl;
}

bool compare(Personne P1, Personne P2)
{
    if (P1.getNom() == P2.getNom() && 
            P1.getPrenom() == P2.getPrenom() &&
            P1.getAge() == P2.getAge())
        return true;
    return false;
}

int affiche(const Personne & P1)
{
    cout << "Nom    : " << P1.getNom() << endl;
    cout << "Prenom : " << P1.getPrenom() << endl;
    cout << "Age    : " << P1.getAge() << endl;
    return 0;
}
