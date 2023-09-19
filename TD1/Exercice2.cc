#include <string>
#include <iostream>
using namespace std;

string extrait(const string &, int, char);
string normalise(const string &, int, char);
string compacte(const string &, char = ' ');

int main()
{
    cout << extrait("Quelle surprise", 7, 'i') << endl;
    cout << extrait("Quelle surprise", 7, 'a') << endl;
    
    cout << normalise("Quelle surprise", 6, 'e') << endl;
    cout << normalise("Quelle surprise", 20, 'X') << endl;
    
    cout << compacte("Quelllle surprise", 'l') << endl;
    cout << compacte("     Quelllle     surprise     ") << endl;
   
   return 0;
}

// Question 1
string extrait(const string & chaine, int position, char terminaison)
{
    string res;
    int poslet = chaine.find(terminaison, position);

    if (poslet != -1) {
        res = chaine.substr(position, poslet - position);
    } else {
        res = chaine.substr(position);
    }
    return res;
}

// Question 2
string normalise(const string & chaine, int longueur, char c)
{
    string res = chaine;
    if (res.length() < longueur) {
        res.append(longueur - res.length(), c);
    } else if (res.length() > longueur) {
        res = res.substr(0, longueur);
    }
    return res;
}

// Question 3
string compacte(const string & s, char c = ' ')
{
    string resultat = "" + s[0];

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != c || (s[i] == c && s[i - 1] != c)) {
            resultat += s[i];
        }
    }

    return resultat;
}
