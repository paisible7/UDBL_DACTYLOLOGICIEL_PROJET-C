void menu(){
    int choix;

    do{
        printf("\n1. Demarrer\n");
        printf("\n2. Cofigurer\n");
        printf("\n3. Aide\n");
        printf("\n4. Quitter le jeu\n");
        printf("\nSelectionner une option : ");
        scanf("%d", &choix);

    }
    
    while(choix !=0);
}