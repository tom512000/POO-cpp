#ifndef __METS_H__
#define __METS_H__

#include "Item.h"
#include <string>

class Mets
{
  private:
    std::string type;

  public:
    virtual bool operator== (const Item *) const;
    virtual std::string getType() const;
};

#endif
