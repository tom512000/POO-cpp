#include "Mets.h"
#include <string>
using namespace std;

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
