#include <iostream>
using namespace std;

string extrait(const string &, int, char);
string normalise(const string &, int, char);

int main()
{
   cout << extrait("Quelle surprise", 7, 'i') << endl;
   cout << extrait("Quelle surprise", 7, 'a') << endl;

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
string normalise(const string & chaine, int longueur, char c = ' ')
{
    string res;
    if (chaine.length() > longueur) {
        res = chaine.substr(longueur);
    }
}