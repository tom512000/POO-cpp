#include "VecteurND.h"

#include <math.h>
#include <stdexcept>
#include <iostream>
using namespace std;

VecteurND::VecteurND()
{
    this->dim = 0;
    this->coord = NULL;
}

VecteurND::VecteurND(unsigned int dim)
{
    this->dim = dim;

    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];
}

VecteurND::VecteurND(unsigned int dim, double valeur)
{
    this->dim = dim;

    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];

    for (int i = 0; i < dim; i++)
        this->coord[i] = valeur;
}

VecteurND::VecteurND(unsigned int dim, const double * tab)
{
    this->dim = dim;

    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];

    for (int i = 0; i < dim; i++)
        this->coord[i] = tab[i];
}

VecteurND::VecteurND(const VecteurND & v)
{
    this->dim = v.dim;

    if (dim == 0)
        this->coord = NULL;
    else
        this->coord = new double [dim];

    for (int i = 0; i < v.dim; i++)
        this->coord[i] = v.coord[i];
}

VecteurND::~VecteurND()
{
    if (this->coord != NULL)
        delete[] this->coord;
}

VecteurND & VecteurND::operator=(const VecteurND & v)
{
    if (this->dim != v.dim)
        if (this->coord != NULL) {
            delete[] this->coord;
            this->coord = NULL;
        }

    if (v.coord == NULL)
        this->coord = NULL;
    else {
        if (this->coord == NULL) {
            this->coord = new double [v.dim];
            for (int i = 0; i < v.dim ; i++)
                this->coord[i] = v.coord[i];
        }
    }
    this->dim = v.dim;

    return *this;
}

unsigned int VecteurND::getDimension() const
{
    return this->dim;
}

ostream & VecteurND::afficher(ostream & out) const
{
    out << "Dimension   : " << this->dim << endl;
    out << "Coordonnees : ";

    if (this->coord != NULL) {
        out << "[ " << this->coord[0];
        for (int i = 1; i < dim; i++)
            out << ", " << this->coord[i];
        out << " ]" << endl;
    }
    else
        out << "NULL" << endl;

    return out;
}

istream & VecteurND::saisir(istream & in)
{
    for (int i = 0; i < this->dim; i++)
        in >> this->coord[i];

    return in;
}

double VecteurND::calculerNorme() const
{
    double result = 0;

    if (this->dim != 0)
        for (int i = 0; i < this->dim; i++)
            result += this->coord[i] * this->coord[i];

    return sqrt(result);
}

double VecteurND::calculerProdScalaire(const VecteurND & v) const throw(invalid_argument)
{
    if (this->dim != v.dim)
        throw invalid_argument("Les dimensions sont differentes !");

    double result = 0;
    for (int i = 0; i < this->dim; i++)
        result += this->coord[i] * v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator+(const VecteurND &v) const
{
    if (this->dim != v.dim)
        throw invalid_argument("Les dimensions sont différentes !");

    VecteurND result(dim);
    for (int i = 0; i < dim; i++)
        result.coord[i] = this->coord[i] + v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator-(const VecteurND & v) const
{
    if (this->dim != v.dim)
        throw invalid_argument("Les dimensions sont différentes !");

    VecteurND result(dim);
    for (int i = 0; i < dim; i++)
        result.coord[i] = this->coord[i] - v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator*(double produit) const
{
    VecteurND result(dim);
    
    for (int i = 0; i < dim; i++)
        result.coord[i] = this->coord[i] * produit;

    return result;
}

bool VecteurND::operator<(const VecteurND & v) const
{
    return this->calculerNorme() < v.calculerNorme();
}

double & VecteurND::operator[](int index)
{
    if (index >= dim)
        throw invalid_argument("Index supérieur à la dimension !");
    
    return this->coord[index];
}

ostream & operator<<(ostream & out, const VecteurND & v)
{
    return v.afficher(out);
}

istream & operator>>(istream & in, VecteurND & v)
{
    return v.saisir(in);
}
