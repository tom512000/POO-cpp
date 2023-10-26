#include "Item.h"
#include "Boisson.h"

#include <stdexcept>
#include <string>
using namespace std;

Boisson::Boisson(const string & nom, double prix, bool alcool, const string & chaine) throw (std::invalid_argument): Item(nom, prix, chaine)
{
  this->alcool = alcool;
}

void Boisson::affiche(ostream & out) const
{
  
}
