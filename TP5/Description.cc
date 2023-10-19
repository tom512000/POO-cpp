#include "Description.h"
using namespace std;

Description::Description(const string & chaine)throw (invalid_argument)
{
  if(!estValide(chaine))
    throw invalid_argument("Description non valide");
  this->taille = nbElements(chaine);
  if(this->taille==0)
      this->elements = NULL;
  else
  {
      elements = new string [this->taille];
      int debut = 0;
      int fin = 0;
      for(int i = 0 ; i<this->taille ; i++)
        {
          fin = chaine.find('/',debut);
          if(fin==-1)
        elements[i] = chaine.substr(debut);
          else
        elements[i] = chaine.substr(debut,fin-debut);
          debut = fin+1;
        }
  }
}

Description::Description (const Description & d)
{
  this->taille = d.taille;

  if (this->taille == 0)
    this->elements = NULL;
  else
    this->elements = new string [this->taille];
    for (int i = 0; i < this->taille; i++)
      this->elements[i] = d.elements[i];
}

Description::~Description ()
{
  if (this->elements != NULL)
    delete[] this->elements;
}

Description & Description::operator= (const Description & d)
{
    if (this->taille != d.taille)
        if (this->elements != NULL) {
            delete[] this->elements ;
            this->elements = NULL;
        }

    if (d.elements == NULL)
        this->elements == NULL;
    else {
        if (this->elements == NULL) {
            this->elements = new string [d.taille];
            for (int i = 0; i <= d.taille ; i++)
                this->elements[i] = d.elements[i];
        }
    }
    this->taille = d.taille;

    return *this ;
}

bool estValide(const std::string & chaine)
{
  int taille = chaine.size();
  for(int i = 0 ; i<taille ; i++)
    if(!(chaine[i] >= 'a' && chaine[i] <= 'z' || chaine[i] >= 'A' && chaine[i] <= 'Z' || chaine[i] == ' ' || chaine[i] == '/'))
      return false;
  return true;
}

unsigned int nbElements(const std::string & chaine)
{
  int ind = 0;
  int cpt = 0;
  while((ind=chaine.find('/',ind)+1)!=0)
    cpt++;
  return cpt+1;
}


void Description::affiche(std::ostream & o) const
{
  for(int i = 0 ; i < this->taille-1 ; i++)
    o << this->elements[i] << ", ";
  if(this->taille!=0)
    o <<  this->elements[this->taille-1];
}

ostream & operator<< (ostream & o, const Description & d)
{
  d.affiche(o);
  return o;
}

bool Description::operator== (const Description & d) const
{
  if(this->taille != d.taille)
    return false;
  for(int i = 0 ; i < this->taille ; i++)
    if(this->elements[i]!=d.elements[i])
      return false;
  return true;
}
