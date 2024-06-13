#include <stdio.h>
#include <stdlib.h>

void dnomJrs(char nomJrs[][15], int nbJrs)
{
    for (int i = 0; i < nbJrs; i++)
    {
        printf("\nEntrez le nom du joueur %d : ", i + 1);
        scanf("%s", nomJrs[i]);
    }
}


int dnbJrs()
{
    int nbJrs;

    do
    {
        printf("\nEntrer le nombre de joueurs (1 à 4) : ");
        scanf("%d", &nbJrs);
        if (nbJrs >= 1 && nbJrs <= 4)
        {
            system("clear");
            printf("La partie peut commencer !\n");
        }
        else if (nbJrs == 0)
        {
            system("clear");
            printf("\nSoyez un peu plus sérieux, s'il vous plaît.\n");
        }
        else
        {
            system("clear");
            printf("\nDésolé, le nombre maximal est de 4 joueurs seulement.\n");
        }
    }
    while (nbJrs < 1 || nbJrs > 4);

    return nbJrs;
}




int main()
{
    int choix, nbJrs;
    char nomJrs[4][15];

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

            nbJrs = dnbJrs();

            if (nbJrs <= 0 || nbJrs > 4)
            {
                system("clear");
                printf("\nDésolé, le nombre maximal est de 4 joueurs seulement.\n");
            }
            else
            {
                dnomJrs(nomJrs, nbJrs);
                system("clear");
                printf("\nDebut du jeu avec : \n");
                for (int i = 0 ; i < nbJrs; i++)
                {
                    printf("\n%s\n", nomJrs[i]);
                }
            }
            break;

        case 2:
            system("clear");
            printf("\nCONFIGURATION\n");

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
