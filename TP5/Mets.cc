#include "Mets.h"
#include "Item.h"
#include "Boisson.h"

#include <stdexcept>
#include <typeinfo>
#include <string>
using namespace std;

Mets::Mets(const string & nom, double prix, const string & type, const string & chaine) throw (std::invalid_argument): Item(nom, prix, chaine)
{
  if (type != "Entree" && type != "Plat" && type != "Dessert")
    throw invalid_argument("Type inconnu");

  this->type = type;
}

bool Mets::operator==(const Item * I) const
{
  if(typeid(*I) == typeid(Mets))
  {
    Mets m = *dynamic_cast<const Mets *> (I);
    return Item::operator==(I) && type == m.type;
  }

  return false;
}

string Mets::getType() const
{
  return type;
}

bool Mets::operator<(const Item * I) const
{
  if (typeid(*I) == typeid(Boisson))
    return false;

  Mets m = *dynamic_cast<const Mets *> (I);
  if (this->type == "Entree" && m.type != "Entree")
    return true;

  if (this->type == "Plat" && m.type == "Dessert")
    return true;

  if(this->type == m.type)
    return true;

  return false;
}
