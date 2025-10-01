#include <stdio.h>
#include <string.h>

#define TAILLE      30
#define TAILLE_EMAIL     50
#define TAILLE_DESC      100

typedef struct Client
{
    int idClient;
    char nom[TAILLE];
    char prenom[TAILLE];
    char email[TAILLE_EMAIL];
    float solde;
    int profilCree; // 0 = pas créé, 1 = créé
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
    int choixSolde;
    float montant;
    
    Client client = {0};

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
            case 1: // Menu Profil
                do {
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
                                printf("Le compte n'est pas encore créé, impossible de le modifier !\n");
                            else {
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
                                printf("Le compte n'est pas encore créé.\n");
                            else {
                                printf("Les informations du client sont: \n");
                                printf(" Nom : %s\n", client.nom);
                                printf(" Prenom : %s\n", client.prenom);
                                printf(" Email : %s\n", client.email);
                                printf(" Solde actuel : %.2f MAD\n", client.solde);
                            }
                            break;

                        case 0:
                            printf("Retour au menu principal.\n");
                            break;

                        default:
                            printf("Choix invalide !\n");
                            break;
                    }
                } while (choixProfil != 0);
                break;

            case 2: // Menu Solde
                do {
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
                            printf("Retour au menu principal.\n");
                            break;

                        default:
                            printf("Choix invalide !\n");
                            break;
                    }
                } while (choixSolde != 0);
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
