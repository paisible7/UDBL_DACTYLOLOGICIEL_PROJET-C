#include <stdio.h>
#include <stdlib.h>



int main()
{
    char texte ;
    FILE* fichier = NULL;

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
            fichier = fopen("bdd.txt", "a");

            if (fichier != NULL)
            {

                printf("Entrer les mots ");
                scanf("%s", &texte);

                fprintf(fichier, "%s", texte);

                fclose(fichier);
            }
            

            break;

        case 3:
            system("clear");
            printf("\nAIDE\n");

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
