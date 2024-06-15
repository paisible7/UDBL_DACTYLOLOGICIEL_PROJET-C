#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char nom[50];
    double temps;
} Joueur;

void start()
{
    sleep(1);
    printf("\n\n*****   *****   UDBL - DACTYLOGICIEL *****   *****\n\n");
    sleep(2);
    printf("\nKALONJI MWINSHI AUGUSTIN\n");
    sleep(1);
    printf("\nKANGAJ AKAWAW GLORIA\n");
    sleep(1);
    printf("\nKAPINGA MBAYA PATRICIA\n");
    sleep(1);
    printf("\nKANYEBA TSHIMBALANGA DEBORAH\n");
    sleep(4);
    system("clear");
}

void afficherAide()
{
    FILE* aide = NULL;
    int txt = 0;
    aide = fopen("aide.txt", "r");
    if (aide == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier d'aide.\n");
        return;
    }

    while ((txt = fgetc(aide)) != EOF)
    {
        printf("%c", txt);
    }
    printf("\n");
    fclose(aide);
}

void configurer()
{
    int nombre_mots, i;
    char mot[100];
    FILE* fichier = fopen("mots.txt", "w");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier pour la configuration.\n");
        return;
    }

    printf("Combien de mots voulez-vous entrer ? ");
    scanf("%d", &nombre_mots);
    getchar(); // Pour supprimer le retour à la ligne laissé par scanf

    for (i = 0; i < nombre_mots; i++)
    {
        printf("Entrez le mot %d : ", i + 1);
        fgets(mot, sizeof(mot), stdin);
        fprintf(fichier, "%s", mot);
    }

    fclose(fichier);
    printf("Les phrases ont été enregistrés dans le fichier 'phrases.txt'.\n");
}

int jeu()
{
    char** mots = NULL; // Tableau de pointeurs pour les mots
    int nb_mots = 0;
    char input[100];
    int nombre_joueurs, i, j;
    Joueur temp;

    // Lecture des mots depuis le fichier
    FILE* fichier = fopen("phrases.txt", "r");
    if (fichier == NULL)
    {
        printf("Erreur : impossible de charger les phrases.\n");
        return 1;
    }

    // Allocation dynamique pour le tableau de pointeurs
    mots = malloc(100 * sizeof(char*));
    if (mots == NULL)
    {
        printf("Erreur d'allocation mémoire pour les mots.\n");
        fclose(fichier);
        return 1;
    }

    // Lecture des mots et stockage dans le tableau
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fichier))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        mots[nb_mots] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(mots[nb_mots], buffer);
        nb_mots++;
    }
    fclose(fichier);

    printf("Entrez le nombre de joueurs : ");
    scanf("%d", &nombre_joueurs);
    getchar(); // pour supprimer le retour à la ligne

    Joueur joueurs[nombre_joueurs];

    for (i = 0; i < nombre_joueurs; i++)
    {
        printf("Entrez le nom du joueur %d : ", i + 1);
        fgets(joueurs[i].nom, sizeof(joueurs[i].nom), stdin);
        joueurs[i].nom[strcspn(joueurs[i].nom, "\n")] = '\0'; // Enlever le retour àla ligne à la fin du nom

        printf("Prêt ? Allez !\n");

        // Sélection aléatoire d'une phrase non encore utilisé
        srand(time(NULL)); // generateur des nombres aléatoires
        int index_mot;
        do
        {
            index_mot = rand() % nb_mots; // selection aleatoire
        }
        while (mots[index_mot] == NULL);   // Verification du phrase si déà utilisé ou pas

        printf("Tapez le mot suivant : %s\n", mots[index_mot]);

        time_t debut, fin;
        double temps_saisie;
        time(&debut); // début du chronomètre

        do
        {
            fgets(input, sizeof(input), stdin); // saisie de l'utilisateur
            input[strcspn(input, "\n")] = '\0'; // supprimé le retour à la ligne à la fin de la phrases

            if (strcmp(input, mots[index_mot]) != 0)
            {
                printf("Désolé, vous n'avez pas tapé la phrases correctement. Réessayez : ");
            }
        }
        while (strcmp(input, mots[index_mot]) != 0);

        time(&fin); // fin du chronomètre

        temps_saisie = difftime(fin, debut);
        joueurs[i].temps = temps_saisie;
        printf("Bravo %s ! Vous avez tapé la phrase en %.2f secondes.\n", joueurs[i].nom, joueurs[i].temps);

        // Marquer le mot comme utilisé en le libérant
        free(mots[index_mot]);
        mots[index_mot] = NULL;
    }

    // Libérer la mémoire allouée pour les mots
    for (i = 0; i < nb_mots; i++)
    {
        if (mots[i] != NULL)
        {
            free(mots[i]);
        }
    }
    free(mots);

    // Tri des joueurs par temps en utilisant le tri à bulles
    for (i = 0; i < nombre_joueurs - 1; i++)
    {
        for (j = 0; j < nombre_joueurs - i - 1; j++)
        {
            if (joueurs[j].temps > joueurs[j + 1].temps)
            {
                temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    // Affichage des scores des joueurs en ordre croissant de temps
    printf("\nScores :\n");
    for (i = 0; i < nombre_joueurs; i++)
    {
        printf("%s : %.2f secondes\n", joueurs[i].nom, joueurs[i].temps);
    }

    return 0;
}

int main()
{
    int choix;
    start();

    do
    {
        printf("\n\t===========================\n");
        printf("\t     MENU PRINCIPAL\n");
        printf("\t===========================\n\n");
        printf("\n\t\t1. Démarrer\n");
        printf("\n\t\t2. Configurer\n");
        printf("\n\t\t3. Aide\n");
        printf("\n\t\t0. Quitter\n");
        printf("\n\tSélectionner une option : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' laissé par scanf

        switch (choix)
        {
        case 1:
            system("clear");
            printf("\nDÉMARRER\n");
            jeu();
            break;

        case 2:
            system("clear");
            printf("\n\t===========================\n");
            printf("\t       CONFIGURATION\n");
            printf("\t===========================\n\n");
            configurer();
            break;

        case 3:
            system("clear");

            printf("\n\t===========================\n");
            printf("\t               AIDE\n");
            printf("\t===========================\n\n");
            afficherAide();
            break;

        case 0:
            system("clear");
            printf("\n\t\t\t------------------------\n");
            printf("\t\t\tVOUS AVEZ QUITTÉ LE JEU\n");
            printf("\t\t\t------------------------\n\n");
            printf("\t\t     APPUYER SUR ENTRER POUR FERMER\n");
            printf("\t\t\t------------------------\n");
            break;

        default:
            system("clear");
            printf("\nVeuillez suivre les instructions et choisir une option valide\n");
            printf("\n_____________________________________________________________\n\n");
            break;
        }
    }
    while (choix != 0);

    return 0;
}
