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
            cout << "Personne( " << this->nom;
            cout << " , " << this->prenom << " , " << this->age << " ) : " << this << endl;
        }
        
        Personne (const Personne & p)
        {
            (*this).nom = p.nom;
            (*this).prenom = p.prenom;
            (*this).age = p.age;
            cout << "Personne( " << this->nom;
            cout << " , " << this->prenom << " , " << this->age << " ) : " << this << endl;
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
bool compare(Personne P1, Personne P2)
{
    if (P1.getNom() == P2.getNom() && 
            P1.getPrenom() == P2.getPrenom() &&
            P1.getAge() == P2.getAge())
        return true;
    return false;
}

int main()
{
    // Création des instances de la classe Personne (constructeur)
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
    cout << compare(p1, p3) << endl;
    
    return 0;
}
