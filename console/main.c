#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Macros pour les codes d'échappement ANSI qui va permettre de mettre la couleur
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_YELLOW "\033[0;33m"
#define ANSI_COLOR_BLUE "\033[0;55m"
#define ANSI_COLOR_CYAN "\033[0;36m"

typedef struct {
    char nom[50];
    double temps;
} Joueur;

void start() {
    sleep(1);
    printf("\n\n\t\t" ANSI_COLOR_BLUE "*****\t*****\tUDBL - DACTYLOGICIEL\t*****\t*****\n\n" ANSI_COLOR_RESET);
    sleep(2);

    const char* noms[] = {
        "KALONJI MWINSHI AUGUSTIN\n\t\t\t>>\t@m.paisible7",
        "KANGAJ AKAWAW GLORIA",
        "KAPINGA MBAYA PATRICIA",
        "KANYEBA TSHIMBALANGA DEBORAH"
    };

    for (int i = 0; i < 4; i++) { // une boucle qui va permettre d'afficher les noms des participants chaque 2 secondes
        printf("\n\t\t\t" ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, noms[i]);
        printf("\t\t\t============================\n" ANSI_COLOR_RESET);
        sleep(2);
    }

    sleep(2);
    system("clear");
}

void afficherAide() {
    FILE* aide = fopen("aide.txt", "r");//fonction qui ouvre le fichier aide.txt pour affiche l'aide
    if (aide == NULL) {
        printf(ANSI_COLOR_RED "\t\t\tErreur lors de l'ouverture du fichier d'aide.\n" ANSI_COLOR_RESET);
        return;
    }

    int txt;
    while ((txt = fgetc(aide)) != EOF) {//pour detecter la fin de,ligne du fichier >> End Of File
        putchar(txt);
    }
    printf("\n");
    fclose(aide);
}

void configurer() {
    int nombre_mots;
    char mot[100];
    FILE* fichier = fopen("phrases.txt", "a");

    if (fichier == NULL) {
        printf(ANSI_COLOR_RED "\t\t\tErreur lors de l'ouverture du fichier pour la configuration.\n" ANSI_COLOR_RESET);
        return;
    }

    printf("\t\t\tCombien de mots voulez-vous entrer ? ");
    scanf("%d", &nombre_mots);
    getchar(); // Pour supprimer le retour à la ligne laissé par scanf

    for (int i = 0; i < nombre_mots; i++) {
        printf("\n\t\t\tEntrez le mot %d : ", i + 1);
        fgets(mot, sizeof(mot), stdin);
        fprintf(fichier, "%s", mot);
    }

    fclose(fichier);
    if(nombre_mots == 1){
        printf(ANSI_COLOR_GREEN "\n\t\t\tLa phrase a été enregistrée avec succès !.\n" ANSI_COLOR_RESET);

    }
    printf(ANSI_COLOR_GREEN "\n\t\t\tLes phrases ont été enregistrées avec succès !.\n" ANSI_COLOR_RESET);
}

int jeu() {
    char** mots = NULL;
    int nb_mots = 0;
    char input[100];
    int nombre_joueurs;
    Joueur temp;


    FILE* fichier = fopen("phrases.txt", "r");// Lecture des mots depuis le fichier des phrases
    if (fichier == NULL) {
        printf(ANSI_COLOR_RED "\t\t\tErreur : impossible de charger les phrases.\n" ANSI_COLOR_RESET);
        return 1;
    }


    mots = malloc(100 * sizeof(char*));
    if (mots == NULL) {
        printf(ANSI_COLOR_RED "\t\t\tErreur d'allocation mémoire pour les mots.\n" ANSI_COLOR_RESET);
        fclose(fichier);
        return 1;
    }


    char buffer[100];// Lecture des mots et stockage dans le tableau
    while (fgets(buffer, sizeof(buffer), fichier)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        mots[nb_mots] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(mots[nb_mots], buffer);
        nb_mots++;
    }
    fclose(fichier);


    printf("\n\t\t\tEntrez le nombre de joueurs : ");
    scanf("%d", &nombre_joueurs);
    getchar(); // Pour supprimer le retour à la ligne

    Joueur joueurs[nombre_joueurs];

    for (int i = 0; i < nombre_joueurs; i++) {
        // Saisie du nom du joueur
        printf("\n\t\t\tEntrez le nom du joueur %d : ", i + 1);
        fgets(joueurs[i].nom, sizeof(joueurs[i].nom), stdin);
        joueurs[i].nom[strcspn(joueurs[i].nom, "\n")] = '\0'; // Enlever le retour à la ligne à la fin du nom

        printf("\n\t\t\tPrêt ? Allez !\n");

        // Sélection aléatoire d'une phrase non encore utilisée
        srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
        int index_mot;
        do {
            index_mot = rand() % nb_mots; // Sélection aléatoire
        } while (mots[index_mot] == NULL); // Vérification si la phrase a déjà été utilisée

        printf("\t\t\tTapez le mot suivant : %s%s%s\n\n\t\t\t", ANSI_COLOR_GREEN, mots[index_mot], ANSI_COLOR_RESET);

        time_t debut, fin;
        double temps_saisie;
        time(&debut); // Début du chronomètre

        // Saisie et vérification de la phrase
        do {
            fgets(input, sizeof(input), stdin); // Saisie de l'utilisateur
            input[strcspn(input, "\n")] = '\0'; // Suppression du retour à la ligne à la fin de la phrase

            if (strcmp(input, mots[index_mot]) != 0) {
                printf(ANSI_COLOR_RED "\t\t\tDésolé, vous n'avez pas tapé la phrase correctement.\n\n\t\t\t"ANSI_COLOR_YELLOW"Réessayez : " ANSI_COLOR_RESET);
            }
        } while (strcmp(input, mots[index_mot]) != 0);

        time(&fin); // Fin du chronomètre

        temps_saisie = difftime(fin, debut);
        joueurs[i].temps = temps_saisie;
        printf(ANSI_COLOR_GREEN "\t\t\tBravo %s ! Vous avez tapé la phrase en %.2f secondes.\n" ANSI_COLOR_RESET, joueurs[i].nom, joueurs[i].temps);

        // Marquer le mot comme utilisé en le libérant
        free(mots[index_mot]);
        mots[index_mot] = NULL;
    }

    // Libération de la mémoire allouée pour les mots
    for (int i = 0; i < nb_mots; i++) {
        if (mots[i] != NULL) {
            free(mots[i]);
        }
    }
    free(mots);

    // Tri des joueurs par temps en utilisant le tri à bulles
    for (int i = 0; i < nombre_joueurs - 1; i++) {
        for (int j = 0; j < nombre_joueurs - i - 1; j++) {
            if (joueurs[j].temps > joueurs[j + 1].temps) {
                temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    // Affichage des scores des joueurs en ordre croissant de temps
    printf("\n" ANSI_COLOR_YELLOW "\t\t\tScores :\n" ANSI_COLOR_RESET);
    for (int i = 0; i < nombre_joueurs; i++) {
        printf(ANSI_COLOR_YELLOW "\t\t\t%s : %.2f secondes\n" ANSI_COLOR_RESET, joueurs[i].nom, joueurs[i].temps);
    }

    return 0;
}

int main() {
    int choix;
    start();

    do {
        // Affichage du menu principal
        printf("\n\t\t\t" ANSI_COLOR_CYAN "===========================\n");
        printf("\t\t\t||\tMENU PRINCIPAL \t ||\n");
        printf("\t\t\t===========================\n\n" ANSI_COLOR_RESET);
        printf("\n\t\t\t||\t1. Démarrer\t ||\n");
        printf("\n\t\t\t||\t2. Configurer\t ||\n");
        printf("\n\t\t\t||\t3. Aide\t\t ||\n");
        printf("\n\t\t\t||" ANSI_COLOR_RED "\t0. Quitter\t"ANSI_COLOR_RESET" ||\n" );
        printf("\n\t\t\tSélectionner une option : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' laissé par scanf

        // Gestion des options du menu
        switch (choix) {
            case 1:
                system("clear");
                printf("\n\t\t\t"ANSI_COLOR_CYAN"===========================\n");
                printf("\t\t\t||\tDACTYLOGICIEL\t ||\n");
                printf("\t\t\t===========================\n\n" ANSI_COLOR_RESET);
                jeu();
                break;

            case 2:
                system("clear");
                printf("\n\t\t\t"ANSI_COLOR_CYAN"===========================\n");
                printf("\t\t\t||\tCONFIGURATION \t ||\n");
                printf("\t\t\t===========================\n\n" ANSI_COLOR_RESET);
                configurer();
                break;

            case 3:
                system("clear");
                printf("\n\t\t\t"ANSI_COLOR_CYAN"===========================\n");
                printf("\t\t\t||\t   AIDE\t\t ||\n");
                printf("\t\t\t===========================\n\n" ANSI_COLOR_RESET);
                afficherAide();
                break;

            case 0:
                system("clear");
                printf("\n\t\t\t"ANSI_COLOR_RED"------------------------\n");
                printf("\t\t\tVOUS AVEZ QUITTÉ LE JEU\n");
                printf("\t\t\t------------------------\n\n" ANSI_COLOR_RESET);
                printf("\t\t     " ANSI_COLOR_CYAN "APPUYER SUR ENTRER POUR FERMER\n");
                printf("\t\t\t" ANSI_COLOR_RED "------------------------\n" ANSI_COLOR_RESET);
                break;

            default:
                system("clear");
                printf("\n" ANSI_COLOR_RED "Veuillez suivre les instructions et choisir une option valide\n" ANSI_COLOR_RESET);
                printf("\n_____________________________________________________________\n\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
