#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


int main() {
    char titre[MAX][50];
    char auteur[MAX][50];
    float prix[MAX];
    int quantite[MAX];
    int nombreLivres = 0;
    int choix;

    do {
          printf("\n****** Menu ******\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres\n");
        printf("0. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        if(choix == 1) {
              printf("Entrez le titre du livre: ");
            scanf("%s", titre[nombreLivres]);
            printf("Entrez l'auteur du livre: ");
            scanf("%s", auteur[nombreLivres]);
            printf("Entrez le prix du livre: ");
            scanf("%f", &prix[nombreLivres]);
            printf("Entrez la quantité de livres: ");
            scanf("%d", &quantite[nombreLivres]);
            nombreLivres++;
        } else if (choix == 2) {
            if(nombreLivres == 0) {
                printf("Aucun livre en stock.\n");
            } else {
                for (int i = 0; i < nombreLivres; i++) {
                    printf("\nLivre %d:\n", i + 1);
                    printf("Titre: %s\n", titre[i]);
                    printf("Auteur: %s\n", auteur[i]);
                    printf("Prix: %.2f\n", prix[i]);
                    printf("Quantite: %d\n", quantite[i]);
                }
            }
        } else if (choix == 3) { 
            char titreRecherche[50];
            printf("Entrer le titre du livre a rechercher: ");
            scanf("%s", &titreRecherche);

            int trouve = 0;
            for(int i = 0; i < nombreLivres;i++) {
                if(strcmp(titreRecherche, titre[i]) == 0) {
                     printf("\nLivre trouve: \n");
                        printf("Titre: %s\n", titre[i]);
                        printf("Auteur: %s\n", auteur[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantite: %d\n", quantite[i]);
                        trouve = 1;
                        break;
                } else {
                    printf("Livre non trouve.\n");
                }
            }
        } else if (choix == 4) {
            char titreRecherche[50];
                int nouvelleQuantite;
                printf("Entrer le titre du livre a mettre a jour: ");
                scanf("%s", titreRecherche);
            
            int trouve = 0;
            for(int i = 0; i < nombreLivres; i++) {
                if(strcmp(titreRecherche, titre[i]) == 0) {
                    printf("%d", &nouvelleQuantite);
                        scanf("%d", &nouvelleQuantite);
                        quantite[i] = nouvelleQuantite;
                        printf("Quantite mise a jour.\n");
                        trouve = 1;
                        break;
                } else {
                    printf("Livre non trouve.\n");
                }
            }
        } else if (choix == 5) {
            char titreRecherche[50];
            printf("Entrer le titre de livre a supprimer: ");
            scanf("%s", titreRecherche);

            int trouve = 0;
            for(int i = 0; i < nombreLivres; i++) {
                if(strcmp(titreRecherche, titre[i]) == 0) {
                    for(int j = i; j < nombreLivres - 1; j++) {
                        strcpy(titre[j], titre[j + 1]);
                                strcpy(auteur[j], auteur[j + 1]);
                                prix[j] = prix[j + 1];
                                quantite[j] = quantite[j + 1];
                    } nombreLivres--;
                    printf("Livre supprime.\n");
                    trouve = 1;
                    break;
                } else {
                    printf("Livre non trouve.\n");
                }
            }
        } else if (choix == 6) {
            int total = 0;
            for(int i = 0; i < nombreLivres; i++) {
                total += quantite[i];
            } 
        printf("Nombre total de livres en stock: %d\n", total);
        }
    }while (choix != 0);
    printf("Quitter....");
    return 0;
}

