#include <stdio.h>
#include <stdlib.h>
void afficherMenuAide()
{
    printf("Menu aide\n");

    printf("Description de l'application:
     une application de dactylogiciel c'est un logiciel d'aide a l'amelioration de la saisie rapide au clavier\n"
     );
     printf("version du jeu: 2.0\n");

     printf("concrepteurs:Deborah , Patricia , Gloria , Augustin\n");
     printf("Date de conception : 10 mai 2024\n");
     printf("Autres information: cette application a été developpée en c avec l'intrface graphique.\n");
}
int main()
{
    // Appel de la fonction pour afficher le menu d'aide

    afficherMenuAide();
    
    return 0;
}
