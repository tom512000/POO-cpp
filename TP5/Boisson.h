#ifndef __BOISSON_H__
#define __BOISSON_H__

#include "Item.h"

#include <string>
#include <stdexcept>

class Boisson : public Item
{
  private:
    bool alcool;

  public:
    Boisson(const std::string &, double, bool, const std::string & = "") throw (std::invalid_argument);

    virtual void affiche(std::ostream &) const;
};

#endif
