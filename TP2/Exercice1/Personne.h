#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include <string>

class Personne
{
    private:
        std::string nom;
        std::string prenom;
        int age;

    public:
        ~Personne();

        Personne (const std::string &, const std::string &, int);
        Personne ();
        Personne (const Personne &);

        void affiche() const;
        std::string getNom() const;
        std::string getPrenom() const;
        int getAge() const;
        void setNom(const std::string &);
        void setPrenom(const std::string &);
        void setAge(int);
};

bool compare(Personne, Personne);
void affiche(const Personne &);

#endif
