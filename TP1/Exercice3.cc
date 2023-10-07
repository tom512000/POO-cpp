#include <string>
#include <iostream>
using namespace std;

bool estPalindrome(const string &);

int main()
{
    string chaine;

    cout << "Entrez une chaine de caracteres : ";
    cin >> chaine;

    if (estPalindrome(chaine)) {
        cout << "La chaine est un palindrome." << endl;
    } else {
        cout << "La chaine n'est pas un palindrome." << endl;
    }

    return 0;
}

bool estPalindrome(const string & str) {
    int taille = str.length();
    bool res = true;
    
    // On parcours la moitié de la chaîne
    for (int i = 0; i < taille / 2; ++i) {
        // On compare les caractères de chaque côté
        if (str[i] != str[taille - i - 1]) {
            res = false;
        }
    }
    
    return res;
}

/*
./a.out
Entrez une chaine de caracteres : kayak
La chaine est un palindrome.
*/

/*
Entrez une chaine de caracteres : maison
La chaine n'est pas un palindrome.
*/
