#ifndef __ITEM_H__
#define __ITEM_H__

#include "Description.h"
#include <stdexcept>
#include <string>
#include <iostream>

class Item // classe abstraite (virtual)
{
  private:
    std::string nom;
    double prix;
    Description ingredients;

  public :
    Item(const std::string &, double, const std::string & = "") throw (std::invalid_argument);

    virtual void affiche(std::ostream &) const;
    virtual bool operator== (const Item *) const;
    virtual bool operator< (const Item *) const = 0;
    virtual std::string getType() const = 0;
};

std::ostream & operator<< (std::ostream &, const Item &);

#endif
