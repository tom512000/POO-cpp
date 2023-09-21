#include <string>
#include <iostream>
using namespace std;

class Personne
{
    private:
        string nom;
        string prenom;
        int age;

    public :
        Personne (const string & nom, const string & prenom, int age)
        {
            this->nom = nom;
            this->prenom = prenom;
            this->age = age;
            cout << "Personne( " << this->nom;
            cout << " , " << this->prenom << " , " << this->age << " ) : " << this << endl;
        }

        Personne ()
        {
            this->nom = "";
            this->prenom = "";
            this->age = 0;
            cout << "Personne() : " << this << endl;
        }
        
        Personne (const Personne & p)
        {
            (*this).nom = p.nom;
            (*this).prenom = p.prenom;
            (*this).age = p.age;
            cout << "Personne( " << &p << " ) : " << this << endl;
        }

        void affiche() const
        {
            cout << "Nom    : " << this->nom << endl;
            cout << "Prenom : " << this->prenom << endl;
            cout << "Age    : " << this->age << endl;
        }

        string getNom() const
        {
            return this->nom;
        }

        string getPrenom() const
        {
            return this->prenom;
        }

        int getAge() const
        {
            return this->age;
        }

        void setNom(const string & nom)
        {
            this->nom = nom;
        }

        void setPrenom(const string & prenom)
        {
            this->prenom = prenom;
        }

        void setAge(int age)
        {
            this->age = age;
        }

        // Cette méthode permet de détruire une instance de la classe Personne.
        // Il n'y a pas besoin de l'appeller explicitement.
        // Il n'est pas obligatoire de la définir dans la classe Personne.
        ~Personne()
        {
            cout << "~Personne() : " << this << endl;
        }
};

// Cette fonction compare le nom, prenom et age de 2 instances de la classe Personne.
// Si ces instances sont identiques, la fonction renvoie true, sinon la fonction renvoie false.
// La fonction créé une copie des instances en paramètres (const & manquant)
bool compare(Personne P1, Personne P2)
{
    if (P1.getNom() == P2.getNom() && 
            P1.getPrenom() == P2.getPrenom() &&
            P1.getAge() == P2.getAge())
        return true;
    return false;
}

int affiche(const Personne & P1)
{
    cout << "Nom    : " << P1.getNom() << endl;
    cout << "Prenom : " << P1.getPrenom() << endl;
    cout << "Age    : " << P1.getAge() << endl;
    return 0;
}

int main()
{
    // Création des instances de la classe Personne (p1, p2 et p3)
    Personne p1 ("Dupont", "Gaston", 36);
    p1.affiche();

    Personne p2;
    p2.affiche();

    Personne p3 (p1);
    p3.affiche();

    // Test des accesseurs (p1)
    cout << "Nom (p1)    : " << p1.getNom() << endl;
    cout << "Prenom (p1) : " << p1.getPrenom() << endl;
    cout << "Age (p1)    : " << p1.getAge() << endl;

    // Test des modificateurs (p2)
    p2.setNom("Sikora");
    p2.setPrenom("Tom");
    p2.setAge(19);
    p2.affiche();

    // Test fonction compare (p1 et p3)
    cout << "Comparaison de p1 et p3 : ";
    if (compare(p1, p3)) {
        cout << "Les instances sont identiques\n";
    } else {
        cout << "Les instances sont différentes\n";
    }

    // Test fonction afficherPersonne (p2)
    affiche(p2);
    
    return 0;
}

/*
./a.out 
Personne( Dupont , Gaston , 36 ) : 0x7ffc11063b90
Nom    : Dupont
Prenom : Gaston
Age    : 36
Personne() : 0x7ffc11063be0
Nom    : 
Prenom : 
Age    : 0
Personne( 0x7ffc11063b90 ) : 0x7ffc11063c30
Nom    : Dupont
Prenom : Gaston
Age    : 36
Nom (p1)    : Dupont
Prenom (p1) : Gaston
Age (p1)    : 36
Nom    : Sikora
Prenom : Tom
Age    : 19
Comparaison de p1 et p3 : Personne( 0x7ffc11063c30 ) : 0x7ffc11063cd0
Personne( 0x7ffc11063b90 ) : 0x7ffc11063c80
~Personne() : 0x7ffc11063c80
~Personne() : 0x7ffc11063cd0
egaux
Nom    : Sikora
Prenom : Tom
Age    : 19
~Personne() : 0x7ffc11063c30
~Personne() : 0x7ffc11063be0
~Personne() : 0x7ffc11063b90
*/