//
//  main.c
//  TP1 - Tableaux
//
//  Created by Med Ayoub on 11/12/2013.
//  Copyright (c) 2013 Med Ayoub. All rights reserved.
//

// Déclaration des librairies
#include <stdio.h>
#include <stdlib.h>
#include "Tableaux.h"

int main()
{
    Tableau tableau = Creer_tableau(100);
    Remplire_tableau(&tableau);
    
    int reponse = 1;
    while( reponse >= 1 && reponse <= 5)
    {
        
        printf("--------------------------------------------\n"
               "Que voulez vous faire ?\n"
               "1 - Afficher le tableau.\n"
               "2 - Ajouter un element au tableau. \n"
               "3 - Suprimmer un element du tableau.\n"
               "4 - Chercher un élément dans le tableau.\n"
               "5 - Faire une recherche dichotomique.\n"
               "0 - Quitter\n"
               "Votre choix :");
        scanf("%d",&reponse);
        
        switch (reponse) {
            case 1:
                Afficher_tableau(tableau);
                break;
            case 2:
            {
                // Tableau remplie ?
                if(tableau.dernier_element + 1 >= tableau.taille_max)
                {
                    printf("Taille maximale atteinte\n");
                    break;
                }
                int indice = -1;
                printf("Entrez l'indice: ");
                scanf("%d", &indice);
                if(indice < 0 || indice >= tableau.taille_max)
                {
                    printf("Indice invalide");
                    break;
                }
                int valeur = 0;
                printf("Entrez la valeur: ");
                scanf("%d", &valeur);
                Ajout_tableau(&tableau, valeur, indice);
                break;
            }
            case 3:
            {
                int indice = -1;
                printf("Entrez l'indice: ");
                scanf("%d", &indice);
                if(indice < 0 || indice > tableau.dernier_element)
                {
                    printf("Indice invalide");
                    break;
                }
                Suppression_tableau(&tableau, indice);
                break;
            }
            case 4:
            {
                int valeur = 0;
                printf("Entrez la valeur rechercée: ");
                scanf("%d", &valeur);
                Tableau resultat = Recherche_tableau(tableau, valeur);
                if(resultat.dernier_element == -1)
                    printf("Aucune occurence trouvée.\n");
                else
                {
                    printf("Occurences trouvées: \n");
                    Afficher_tableau(resultat);
                }
                Detruire_tableau(&resultat);
                break;
            }
            case 5:
            {
                int valeur = 0;
                printf("Entrez la valeur rechercée: ");
                scanf("%d", &valeur);
                Tableau resultat = Recherche_dichotomique_tableau(tableau,
                                                                  valeur, 0, tableau.dernier_element);
                if(resultat.dernier_element == -1)
                    printf("Aucune occurence trouvée");
                else
                {
                    printf("Occurences trouvées: \n");
                    Afficher_tableau(resultat);
                }
                Detruire_tableau(&resultat);
                break;
            }
        }
    }
    Detruire_tableau(&tableau);
    getchar();
    return 0;
}

