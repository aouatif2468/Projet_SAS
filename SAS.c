#include <stdio.h>

typedef struct Client
{
       int idClient;
       char nom[30];
       char prenom[30];
       char email[50];
       float solde;
} Client;

typedef struct Produit
{
       int idProduit;
       char nom[30];
       char categorie[30];
       float prix;
       int stock;
       char description[100]; // tableau de caractères
} Produit;

typedef struct Date
{
       int jour;
       int mois;
       int annee;
} Date;

int main()
{
       int choixMenu;
       int choixProfil;
       Client client;

       do
       {
              printf("\n==============  SYSTEME D'ACHAT CLIENT  ============= \n");
              printf("1. Gestion du profil client  \n");
              printf("2. Gestion du solde virtuel  \n");
              printf("3. Consultation des produits  \n");
              printf("4. Effectuer un achat  \n");
              printf("5. Mes statistiques  \n");
              printf("0. Quitter \n");

              printf("Votre Choix : ");
              scanf("%d", &choixMenu);

              switch (choixMenu)
              {
              case 1:
                     printf("1. Saisie du profil \n");
                     printf("2. Modification du profil   \n");
                     printf("3. Consultation du profil   \n");
                     printf("0. Retour au menu principal  \n");

                     printf("Votre Choix : ");
                     scanf("%d", &choixProfil);

                     switch (choixProfil)
                     {
                     case 1:
                            printf("Veuillez saisir votre prenom : ");
                            scanf("%s", client.prenom);
                            printf("Veuillez saisir votre nom: ");
                            scanf("%s", client.nom);
                            printf("%s.%s@gmail.com", client.prenom, client.nom);
                            client.idClient = 0;
                            client.solde = 100;
                            break;
                     case 2:
                            
                            printf("Veuillez entrer votre nouveau prenom : ");
                            scanf("%s", client.prenom);
                            printf("Veuillez entrer votre nouveau nom : ");
                            scanf("%s", client.nom);     
                            printf("Le profil est mis a jour.");
                            printf(" Pour la confirmation, votre email est  %s.%s@gmail.com", client.prenom, client.nom);
                            break;
                     case 3:
                            printf("les informations de client sont: \n");
                            printf(" Nom : %s\n", client.nom);
                            printf(" Prenom : %s\n", client.prenom);   
                            printf(" Email : %s\n", client.email);   
                            break;
                     default:
                            printf("Retour au menu principal.\n");
                            break;
                     }
                     break;

              case 2:
                     printf("Gestion du solde virtuel \n");
                     break;
              case 3:
                     printf("Consultation des produits \n");
                     break;
              case 4:
                     printf("Effectuer un achat \n");
                     break;
              case 5:
                     printf("Mes statistiques \n");
                     break;
              case 0:
                     printf("Quitter l'application.\n");
                     break;
              default:
                     printf("Choix invalide !\n");
              }
       } while (choixMenu != 0);

       return 0;
}
