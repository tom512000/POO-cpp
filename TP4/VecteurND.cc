#include "VecteurND.h"
#include <iostream>
using namespace std;

VecteurND::VecteurND ()
{
    this->dim = 0;
    this->coord = NULL;
}

VecteurND::VecteurND (unsigned int dim)
{
    this->dim = dim;
    
    for (int i = 0; i < dim; i++)
    {
        
    }
    
}


VecteurND::VecteurND (unsigned int dim, double coord)
{
    
}


VecteurND::VecteurND (unsigned int dim, const double * coord)
{

}
