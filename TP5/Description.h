#ifndef __DESCRIPTION_H__
#define __DESCRIPTION_H__

#include <iostream>
#include <stdexcept>
#include <string>

class Description
{
  private:
    unsigned int taille;
    std::string * elements; // Allocation dynamique

  public :
    Description (const Description &);
    ~Description ();
    Description & operator= (const Description &);

    Description(const std::string &) throw (std::invalid_argument);

    void affiche(std::ostream &) const;
    bool operator== (const Description &) const;
};

bool estValide(const std::string &);
unsigned int nbElements(const std::string &);
std::ostream & operator<< (std::ostream &, const Description &);

#endif
