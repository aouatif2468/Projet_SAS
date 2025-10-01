#include <stdio.h>
#include <string.h>

#define TAILLE 30
#define TAILLE_EMAIL 50
#define TAILLE_DESC 100
#define N_PRODUITS 4

typedef struct Client
{
       int idClient;
       char nom[TAILLE];
       char prenom[TAILLE];
       char email[TAILLE_EMAIL];
       float solde;
       int profilCree;
} Client;

typedef struct Produit
{
       int idProduit;
       char nom[TAILLE];
       char categorie[TAILLE];
       float prix;
       int stock;
       char description[TAILLE_DESC];
} Produit;

Client gererProfil(Client client)
{
       int choixProfil;
       do
       {
              printf("\n***************** Gestion du profil client *****************\n");
              printf("1. Saisie du profil \n");
              printf("2. Modification du profil \n");
              printf("3. Consultation du profil \n");
              printf("0. Retour au menu principal \n");
              printf("Votre Choix : ");
              scanf("%d", &choixProfil);

              switch (choixProfil)
              {
              case 1:
                     printf("Veuillez saisir votre prenom : ");
                     scanf("%s", client.prenom);
                     printf("Veuillez saisir votre nom: ");
                     scanf("%s", client.nom);
                     sprintf(client.email, "%s.%s@client.com", client.prenom, client.nom);
                     printf("Votre email genere est : %s\n", client.email);
                     client.idClient = 1;
                     client.solde = 0.00;
                     client.profilCree = 1;
                     break;

              case 2:
                     if (!client.profilCree)
                            printf("Le compte n'est pas encore cree, impossible de le modifier !\n");
                     else
                     {
                            printf("Veuillez entrer votre nouveau prenom : ");
                            scanf("%s", client.prenom);
                            printf("Veuillez entrer votre nouveau nom : ");
                            scanf("%s", client.nom);
                            sprintf(client.email, "%s.%s@client.com", client.prenom, client.nom);
                            printf("Le profil est mis a jour.\n");
                            printf("Pour confirmation, votre email est : %s\n", client.email);
                     }
                     break;

              case 3:
                     if (!client.profilCree)
                            printf("Le compte n'est pas encore cree.\n");
                     else
                     {
                            printf("Les informations du client sont: \n");
                            printf(" Nom : %s\n", client.nom);
                            printf(" Prenom : %s\n", client.prenom);
                            printf(" Email : %s\n", client.email);
                            printf(" Solde actuel : %.2f MAD\n", client.solde);
                     }
                     break;

              case 0:
                     break;

              default:
                     printf("Choix invalide !\n");
                     break;
              }
       } while (choixProfil != 0);

       return client;
}

Client gererSolde(Client client)
{
       int choixSolde;
       float montant;

       do
       {
              printf("\n***************** Gestion du solde virtuel *****************\n");
              printf("1. Consultation du solde \n");
              printf("2. Depot d'argent \n");
              printf("3. Verification \n");
              printf("0. Retour au menu principal \n");
              printf("Votre Choix : ");
              scanf("%d", &choixSolde);

              switch (choixSolde)
              {
              case 1:
                     printf("Votre solde actuel est : %.2f MAD\n", client.solde);
                     break;

              case 2:
                     printf("Entrez le montant a deposer : ");
                     scanf("%f", &montant);
                     if (montant > 0)
                     {
                            client.solde += montant;
                            printf("Depot effectue. Nouveau solde : %.2f MAD\n", client.solde);
                     }
                     else
                            printf("Montant invalide.\n");
                     break;

              case 3:
                     printf("Entrez le montant a verifier : ");
                     scanf("%f", &montant);
                     if (client.solde >= montant)
                            printf("Solde suffisant (%.2f MAD) pour couvrir %.2f MAD.\n", client.solde, montant);
                     else
                            printf("Solde insuffisant : %.2f MAD disponible, %.2f MAD necessaire.\n", client.solde, montant);
                     break;

              case 0:
                     break;

              default:
                     printf("Choix invalide !\n");
                     break;
              }
       } while (choixSolde != 0);

       return client;
}

void afficherCatalogue(Produit produits[], int n)
{
       printf("\n==== Liste des produits disponibles ====\n");
       for (int i = 0; i < n; i++)
       {
              printf("%d. %s | %s | Prix: %.2f MAD | Stock: %d\n   -> %s\n",
                     produits[i].idProduit, produits[i].nom, produits[i].categorie,
                     produits[i].prix, produits[i].stock, produits[i].description);
       }
}

void rechercherProduit(Produit produits[], int n)
{
       char nomRecherche[TAILLE];
       printf("Entrez le nom du produit a rechercher : ");
       scanf("%s", nomRecherche);

       int trouve = 0;
       for (int i = 0; i < n; i++)
       {
              if (strcasecmp(produits[i].nom, nomRecherche) == 0)
              {
                     printf("\nProduit trouve :\n");
                     printf("%d. %s | Categorie : %s | Prix : %.2f MAD | Stock : %d\n   -> %s\n",
                            produits[i].idProduit, produits[i].nom, produits[i].categorie,
                            produits[i].prix, produits[i].stock, produits[i].description);
                     trouve = 1;
                     break;
              }
       }
       if (!trouve)
       {
              printf("Produit introuvable.\n");
       }
}

void TriProduit(Produit produits[], int n)
{
       int Tmp;
       for (int i = 0; i < n - 1; i++)
       {
              for (int j = 0; j < n - 1 - i; j++)
              {
                     if (produits[j].prix > produits[j + 1].prix)
                     {
                            Tmp = produits[j].prix;
                            produits[j].prix = produits[j + 1].prix;
                            produits[j + 1].prix = Tmp;
                     }
              }
       }

       printf("\n==== Produits tries par prix croissant ====\n");
       for (int i = 0; i < n; i++)
       {
              printf("%d. %s | Prix : %.2f MAD | Stock : %d\n",
                     produits[i].idProduit,
                     produits[i].nom,
                     produits[i].prix,
                     produits[i].stock);
       }
}

void consultationProduits(Produit produits[], int n)
{
       int choixConsultation;
       do
       {
              printf("\n***************** Consultation des produits *****************\n");
              printf("1. Affichage catalogue \n");
              printf("2. Recherche produits \n");
              printf("3. Tri des produits \n");
              printf("0. Retour au menu principal \n");
              printf("Votre Choix : ");
              scanf("%d", &choixConsultation);

              switch (choixConsultation)
              {
              case 1:
                     afficherCatalogue(produits, n);
                     break;

              case 2:
                     rechercherProduit(produits, n);
                     break;
              case 3:
                    TriProduit(produits, n);

              case 0:
                     break;

              default:
                     printf("Choix invalide !\n");
                     break;
              }
       } while (choixConsultation != 0);
}

int main()
{
       int choixMenu;
       Client client = {0};

       Produit produits[N_PRODUITS] = {
           {1, "Ordinateur", "Electronique", 7500.0, 5, "PC portable Core i7"},
           {2, "Smartphone", "Electronique", 3000.0, 10, "Telephone Android"},
           {3, "Livre", "Education", 120.0, 20, "Roman interessant"},
           {4, "Clavier", "Electronique", 45.0, 20, "HP"}};

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
                     client = gererProfil(client);
                     break;

              case 2:
                     client = gererSolde(client);
                     break;

              case 3:
                     consultationProduits(produits, N_PRODUITS);
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
