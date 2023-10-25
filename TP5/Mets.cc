#include "Mets.h"
#include <string>
using namespace std;

Mets::Mets(const string & nom, double prix, const string & type, const string & chaine) throw (std::invalid_argument): Item(nom, prix, chaine)
{
  if (type != "Entree" && type != "Plat" && type != "Dessert")
    throw invalid_argument("Type inconnu");

  this->type = type;
}

bool Mets::operator== (const Item * I) const
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

/*bool Mets::operator< (const Item * I) const
{
  if (typeid(*this) == typeid(I)) {
    //return this < &I;

  } else if (typeid(*this) == typeid(Boisson)) {
    // Une Boisson est inférieure à un Mets
    //return true;

  } else if (typeid(*this) == typeid(Entree)) {
    // Une Entree est inférieure à un Plat
    return true;

  } else if (typeid(*this) == typeid(Plat) && typeid(I) != typeid(Boisson) && typeid(I) != typeid(Entree)) {
    // Un Plat est inférieur à un Dessert
    return true;

  } else
    //return false;
}*/
