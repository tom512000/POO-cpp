#ifndef __OBJET_H__
#define __OBJET_H__
#include <string>
#include <stdexcept>

class Objet
{
    private:
        std::string nom;
        int volume;
        int poids;

    public:
        // Objet ();
        Objet (const std::string & = "", int = 0, int = 0) throw(std::invalid_argument);

        int getVolume() const;
        int getPoids() const;

        void setNom(const std::string &);
        void setPoids(int);

        bool estVide() const;
        std::ostream & afficher(std::ostream &) const;
        std::istream & saisir(std::istream &);
        bool operator== (const Objet &) const;
};

std::ostream & operator<<(std::ostream &, const Objet &);
std::istream & operator>>(std::istream &, Objet &);

#endif