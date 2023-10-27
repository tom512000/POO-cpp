#include "VecteurND.h"

#include <math.h>
#include <stdexcept>
#include <iostream>
using namespace std;

VecteurND::VecteurND()
{
    this->coord.clear();
}

VecteurND::VecteurND(unsigned int dim)
{
    this->coord = vector<double>(dim);
}

VecteurND::VecteurND(unsigned int dim, double valeur)
{
    this->coord = vector<double>(dim);

    for (int i = 0; i < dim; i++)
        this->coord[i] = valeur;
}

VecteurND::VecteurND(unsigned int dim, const double * tab)
{
    this->coord = vector<double>(dim);

    for (int i = 0; i < dim; i++)
        this->coord[i] = tab[i];
}

VecteurND::VecteurND(const VecteurND & v)
{
    this->coord = v.coord;
}

VecteurND::~VecteurND()
{
}

VecteurND & VecteurND::operator=(const VecteurND & v)
{
    if (this->coord.size() != v.coord.size())
        if (!this->coord.empty()) {
            this->coord.clear();
        }

    if (v.coord.empty())
        this->coord.clear();
    else {
        if (this->coord.empty()) {
            if (this->coord.size() != v.coord.size())
                this->coord.resize(v.coord.size());
            
            for (int i = 0; i < v.coord.size(); i++)
                this->coord[i] = v.coord[i];
        }
    }

    return *this;
}

unsigned int VecteurND::getDimension() const
{
    return this->coord.size();
}

ostream & VecteurND::afficher(ostream & out) const
{
    out << "Dimension   : " << this->coord.size() << endl;
    out << "Coordonnees : ";

    if (!this->coord.empty()) {
        out << "[ " << this->coord[0];
        for (int i = 1; i < this->coord.size(); i++)
            out << ", " << this->coord[i];
        out << " ]" << endl;
    }
    else
        out << "NULL" << endl;

    return out;
}

istream & VecteurND::saisir(istream & in)
{
    for (int i = 0; i < this->coord.size(); i++)
        in >> this->coord[i];

    return in;
}

double VecteurND::calculerNorme() const
{
    double result = 0;

    if (!coord.empty())
        for (int i = 0; i < this->coord.size(); i++)
            result += this->coord[i] * this->coord[i];

    return sqrt(result);
}

double VecteurND::calculerProdScalaire(const VecteurND & v) const throw(invalid_argument)
{
    if (this->coord.size() != v.coord.size())
        throw invalid_argument("Les dimensions sont differentes !");

    double result = 0;
    for (int i = 0; i < this->coord.size(); i++)
        result += this->coord[i] * v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator+(const VecteurND &v) const
{
    if (this->coord.size() != v.coord.size())
        throw invalid_argument("Les dimensions sont différentes !");

    VecteurND result(this->coord.size());
    for (int i = 0; i < this->coord.size(); i++)
        result.coord[i] = this->coord[i] + v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator-(const VecteurND & v) const
{
    if (this->coord.size() != v.coord.size())
        throw invalid_argument("Les dimensions sont différentes !");

    VecteurND result(this->coord.size());
    for (int i = 0; i < this->coord.size(); i++)
        result.coord[i] = this->coord[i] - v.coord[i];
    
    return result;
}

VecteurND VecteurND::operator*(double produit) const
{
    VecteurND result(this->coord.size());
    for (int i = 0; i < this->coord.size(); i++)
        result.coord[i] = this->coord[i] * produit;

    return result;
}

bool VecteurND::operator<(const VecteurND & v) const
{
    return this->calculerNorme() < v.calculerNorme();
}

double & VecteurND::operator[](int index)
{
    if (index >= this->coord.size())
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
