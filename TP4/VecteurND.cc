#include "VecteurND.h"
#include <stdexcept>
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
    out << "Coordonnées : ";

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

double VecteurND::calculerNorme() const
{
    double res;

    if (this->dim == 0)
        res = 0.0;
    else {
        for (int i = 0; i < dim; ++i)
            res += coord[i] * coord[i];
        res = sqrt(res);
    }

    return res;
}

/*VecteurND operator+(const VecteurND& other) const {
      if (dim != other.dim)
          throw std::invalid_argument("Vector dimensions mismatch.");

      VecteurND result(dim);
      for (unsigned int i = 0; i < dim; ++i)
          result.coord[i] = coord[i] + other.coord[i];

      return result;
  }

  // Opérateur de soustraction de vecteurs
  VecteurND operator-(const VecteurND& other) const {
      if (dim != other.dim)
          throw std::invalid_argument("Vector dimensions mismatch.");

      VecteurND result(dim);
      for (unsigned int i = 0; i < dim; ++i)
          result.coord[i] = coord[i] - other.coord[i];

      return result;
  }

  // Opérateur unaire (-)
  VecteurND operator-() const {
      VecteurND result(dim);
      for (unsigned int i = 0; i < dim; ++i)
          result.coord[i] = -coord[i];

      return result;
  }

  // Opérateur de multiplication par un scalaire
  VecteurND operator*(double scalar) const {
      VecteurND result(dim);
      for (unsigned int i = 0; i < dim; ++i)
          result.coord[i] = coord[i] * scalar;

      return result;
  }

  // Opérateur de comparaison par la norme (>)
  bool operator>(const VecteurND& other) const {
      return this->getNorm() > other.getNorm();
  }

  // Opérateur d'affichage (<<)
  friend std::ostream& operator<<(std::ostream& out, const VecteurND& vec) {
      vec.afficher(out);
      return out;
  }

  // Opérateur d'entrée (>>)
  friend std::istream& operator>>(std::istream& in, VecteurND& vec) {
      unsigned int newDim;
      in >> newDim;

      if (vec.dim != newDim) {
          if (vec.coord != nullptr)
              delete[] vec.coord;
          vec.dim = newDim;

          if (vec.dim == 0)
              vec.coord = nullptr;
          else
              vec.coord = new double[vec.dim];
      }

      for (unsigned int i = 0; i < vec.dim; ++i)
          in >> vec.coord[i];

      return in;
  }

  // Opérateur d'indexation ([])
  double& operator[](unsigned int index) {
      if (index >= dim)
          throw std::out_of_range("Index out of range.");

      return coord[index];
  }

  const double& operator[](unsigned int index) const {
      if (index >= dim)
          throw std::out_of_range("Index out of range.");

      return coord[index];
  }

private:
  // ... (autres membres et méthodes de la classe)

  // Méthode privée pour calculer la norme du vecteur
  double getNorm() const {
      double norm = 0.0;
      for (unsigned int i = 0; i < dim; ++i)
          norm += coord[i] * coord[i];

      return std::sqrt(norm);
}
*/
