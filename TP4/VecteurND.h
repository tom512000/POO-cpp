#ifndef __VECTEURND_H__
#define __VECTEURND_H__
#include <ostream>

class VecteurND
{
    private:
        unsigned int dim;
        double * coord;

    public:
        // 2)
        VecteurND (const VecteurND &);
        ~VecteurND ();
        VecteurND & operator=(const VecteurND &);

        // 1)
        VecteurND ();
        VecteurND (unsigned int);
        VecteurND (unsigned int, double);
        VecteurND (unsigned int, const double *);

        // 3)
        unsigned int getDimension() const;
        std::ostream & afficher(std::ostream &) const;
        double calculerProdScalaire(const VecteurND &) const /**/; // u = (Ux, Uy) et v = (Vx, Vy), u.v = Ux.Vx + Uy.Vy
        double calculerNorme() const; // √(x² + y²)
};

#endif