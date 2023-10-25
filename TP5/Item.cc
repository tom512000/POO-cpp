#include "Item.h"

#include <stdexcept>
#include <string>
#include <ostream>
using namespace std;

Item::Item(const string & nom, double prix, const string & chaine) throw (invalid_argument): ingredients(chaine), nom(nom), prix(prix)
{
  //this->nom = nom;
  //this->prix = prix;
}

Item::~Item()
{
}

void Item::affiche(ostream & out) const
{
  out << this->nom << "     " << this->prix << endl;
  out << "      " << this->ingredients << endl;
}

bool Item::operator== (const Item * i) const
{
  return this->nom == i->nom && this->prix == i->prix && this->ingredients == i->ingredients;
}

ostream & operator<<(ostream & o, const Item & e)
{
  e.affiche(o);
  return o;
}
