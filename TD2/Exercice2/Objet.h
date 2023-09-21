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
};

#endif