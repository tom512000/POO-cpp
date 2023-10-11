#ifndef __CARTON_H__
#define __CARTON_H__
#include <string>
#include <stdexcept>
#include <vector>
#include "Objet.h"

class Carton
{
    private:
        // L'attribut max_Objets est une constante car il est
        // identique pour chaque instance de la classe Carton.
        // Cette attribut étant identique pour chaque instance
        // de la classe Carton, il est initialisé à 10 dans le
        // fichier Carton.cc.
        static const int max_Objets;
        unsigned int nbObjets;
        int volumeMax;
        int volumeReel;
        int poidsMax;
        int poidsReel;
        std::vector<Objet> contenu;
        
    public:
        Carton(int, int) throw (std::invalid_argument);
        Carton & operator= (const Carton &);
        int contient(const Objet &) const;
        void ajouteObjet(const Objet &) throw (std::invalid_argument);
};

#endif