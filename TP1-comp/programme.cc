#include "variables.h"
//#include "variables.h"
#include <iostream>

int main()
{
    // commentaire
    int a;
    a = V1;
    return 0;
}

/* Etape 1 - Question 1
Lors de la compilation avec l'option -save-temps, g++ produira plusieurs fichiers intermédiaires. Ces fichiers incluent le préprocesseur, l'assembleur, et l'objet.

Étapes de création des fichiers :
- programmme.ii : Fichier produit après la précompilation (étape du préprocesseur).
- programmme.s : Fichier produit après l'assemblage (étape de l'assembleur).
- programmme.o : Fichier objet produit après la compilation (étape du compilateur).
*/

/* Question 2
- -E : Cette option demande au compilateur de s'arrêter après la phase de précompilation (préprocesseur) et d'afficher le résultat.
- -S : Cette option demande au compilateur de s'arrêter après la phase de compilation et d'optimisation du code source, générant le code assembleur.
- -c : Cette option demande au compilateur de s'arrêter après la phase d'assemblage, produisant un fichier objet .o qui peut être lié ultérieurement.
*/

/* Question 3
Le fichier produit par le préprocesseur (fichier .ii) est le résultat de la précompilation.

Les commentaires sont supprimés lors de la phase de précompilation, car ils ne sont pas nécessaires pour l'étape suivante du processus de compilation.

Les lignes vides peuvent résulter de la précompilation lorsque des lignes entières sont des commentaires ou que du texte a été supprimé, laissant des lignes vides.
*/

/* Etape 2 - Question 4
Le programme modifié contient une utilisation de la variable V1 sans qu'elle ait été déclarée ou définie au préalable. Cela provoquera une erreur de compilation,
car le compilateur ne saura pas comment interpréter cette référence.
*/

/* Question 5
Lorsque je compile avec l'option -save-temps, le compilateur produira les fichiers intermédiaires comme dans la précédente étape (fichiers .ii, .s et .o).
Cependant, cette fois-ci, le fichier .ii contiendra des différences par rapport à l'étape précédente :
- programmme.ii : V1 sera remplacé par le texte auquel il fait référence.
*/

/* Etape 3 - Question 6
Lorsque je compile avec l'option -save-temps, le compilateur produira les fichiers intermédiaires, y compris le fichier produit par le préprocesseur (programmme.ii).
Les différences dans ce fichier seront liées à l'inclusion du contenu du fichier variables.h, ce qui permettra d'identifier et d'utiliser correctement les variables V1 et V2.

Le fichier généré par le préprocesseur (.ii) montrera l'expansion de la directive #include, où le contenu du fichier variables.h sera inséré à l'emplacement de l'inclusion.
Cela permettra au compilateur de reconnaître les variables V1 et V2 lors de la compilation.
*/

/* Etape 4 - Question 7
Lorsque je double le #include dans le fichier programme.cc pour inclure "variables.h" deux fois, cela peut entraîner des erreurs de double définition de variables lors de la
compilation. Chaque inclusion répétée du même fichier peut causer des conflits et des erreurs.
*/

/* Question 8
Pour éviter les erreurs de double inclusion, je peux utiliser les directives de précompilation #ifndef et #define.
- #ifndef : Cette directive vérifie si le symbole donné n'est pas défini (VARIABLES_H).
- #define : Si le symbole n'est pas défini, cette directive définit le symbole (VARIABLES_H) et permet l'inclusion du code.

La première fois que le fichier est inclus, "VARIABLES_H" n'est pas défini et est défini par la directive #define, ce qui permet l'inclusion du contenu du fichier.
Lors des inclusions suivantes, "VARIABLES_H" est déjà défini, donc le contenu est ignoré.
*/

/*  Question 9
L'observation des fichiers produits par la compilation avec l'option -save-temps après avoir inclus la bibliothèque iostream à partir du fichier programme.cc nous
permet de tirer quelques conclusions sur les inclusions inutiles :
- Augmentation de la taille des fichiers intermédiaires : L'inclusion inutile de bibliothèques ou de fichiers peut entraîner une augmentation de la taille des fichiers
intermédiaires générés par le compilateur.
- Impact sur la compilation : L'inclusion inutile peut rallonger le temps de compilation, car le compilateur doit traiter et préparer du code qui ne contribue pas
réellement à la fonctionnalité ou au comportement du programme.
- Ressources système : L'inclusion inutile peut également affecter les ressources système utilisées pendant la compilation.
*/
