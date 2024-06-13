#include <stdio.h>
#include <stdlib.h>



int main()
{
    int choix:

    do
    {
        printf("\nACCUEIL\n\n");
        printf("\n1. Demarrer\n");
        printf("\n2. Configurer\n");
        printf("\n3. aide\n");
        printf("\nSelectionner une option : ");
        scanf("%d", &choix);

        switch(choix)
        {

        case 1:
            system("clear");
            printf("\nDEMARRER\n");

        case 2:
            system("clear");
            printf("\nCONFIGURATION\n");
            
            

            break;

        case 3:
            system("clear");
            printf("\nAIDE\n");
            printf("\nDactylogiciel ameliore la vitesse de saisie au clavier\n");
            printf("Version : 1.0\n");
            printf("Conçu par Augustin K. Dévéloppeur web Full satck, Gloria K. Patricia K. et Deborah K.\n");
            printf("Production : %s\n", __DATE__);
            break;

        default :
            system("clear");
            printf("Goog bye");
            break;
        }
    }
    while(choix != 0);


    return 0;
}
