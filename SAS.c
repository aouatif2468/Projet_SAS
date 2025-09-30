#include <stdio.h>

int main()
{
       int choixMenu;

       typedef struct Client
       {
              int idClient;
              char nom[30];
              char prenom[30];
              char email[50];
              float solde;
       } Client;

       do
       {

              printf("==============  SYSTEME D'ACHAT CLIENT  ============= \n");
              printf("1. Gestion du profil client  \n");
              printf("2. Gestion du solde virtuel  \n");
              printf("3. Consultation des produits  \n");
              printf("4. Effectuer un achat  \n");
              printf("5. Mes statistiques  \n");

              printf("Votre Choix ! ");
              scanf("%d", &choixMenu);

              switch (choixMenu)
              {

              case 1:
                     break;
              case 2:
                     break;
              case 3:
                     break;
              case 4:
                     break;
              case 5:
                     break;
              default:
                     printf("Quitter l'application. ");
                     break;
              }

       } while (choixMenu != 0);

       return 0;
}
