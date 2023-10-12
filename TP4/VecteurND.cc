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
    
    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];
}

VecteurND::VecteurND (unsigned int dim, double valeur)
{
    this->dim = dim;
    
    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];

    for (int i = 0; i < dim; i++)
        this->coord[i] = valeur;
}

VecteurND::VecteurND (unsigned int dim, const double * tab)
{
    this->dim = dim;
    
    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];

    for (int i = 0; i < dim; i++)
        this->coord[i] = tab[i];
}

VecteurND::VecteurND (const VecteurND & v)
{
    this->dim = v.dim;

    if (dim == 0) 
        this->coord = NULL;
    else 
        this->coord = new double [dim];
    
    for (int i = 0; i < v.dim; i++)
        this->coord[i] = v.coord[i];
}

VecteurND::~VecteurND ()
{
    if (this->coord != NULL)
        delete[] this->coord;
}

VecteurND & VecteurND::operator= (const VecteurND & v)
{
    if (this->dim != v.dim)
        if (this->coord != NULL) {
            delete[] this->coord ;
            this->coord = NULL;
        }

    if (v.coord == NULL)
        this->coord == NULL;
    else {
        if (this->coord == NULL) {
            this->coord = new double [v.dim];
            for (int i = 0; i <= v.dim ; i++)
                this->coord[i] = v.coord[i];
        }
    }
    this->dim = v.dim;

    return *this ;
}

unsigned int VecteurND::getDimension() const
{
    return this->dim;
}

ostream & VecteurND::afficher(ostream & out) const
{
    out << "Dimension   : " << this->dim << endl;
    out << "Coordonnées : " << endl;
    
    if (this->coord != NULL) {
        out << "[ " << this->coord[0];
        for (int i = 1; i < dim; i++)
            out << " ," << this->coord[i];
        out << " ]" << endl;
    }
    else
        out << "  NULL" << endl;

    return out;
}
