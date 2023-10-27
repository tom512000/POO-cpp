#ifndef __VECTEURND_H__
#define __VECTEURND_H__

#include <stdexcept>
#include <iostream>
#include <vector>

class VecteurND
{
    private:
        std::vector<double> coord;

    public:
        VecteurND (const VecteurND &);
        ~VecteurND ();
        VecteurND & operator=(const VecteurND &);

        VecteurND ();
        VecteurND (unsigned int);
        VecteurND (unsigned int, double);
        VecteurND (unsigned int, const double *);

        unsigned int getDimension() const;
        std::ostream & afficher(std::ostream &) const;
        std::istream & saisir(std::istream &);
        double calculerProdScalaire(const VecteurND &) const throw (std::invalid_argument);
        double calculerNorme() const;
        VecteurND operator+(const VecteurND &) const;
        VecteurND operator-(const VecteurND &) const;
        VecteurND operator*(double produit) const;
        bool operator<(const VecteurND &) const;
        double & operator[](int);
};

std::ostream & operator<<(std::ostream &, const VecteurND &);
std::istream & operator>>(std::istream &, VecteurND &);

#endif
