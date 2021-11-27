#pragma once
#include "pch.h"
namespace NS_BDD
{
    ref class Authentification
    {
    private:
        System::String^ email;
        System::String^ mdp;
        int Id;

    public:
        System::String^ Check();
        System::String^ CheckSup();

        void setId(int);
        void setEmail(System::String^);
        void setMdp(System::String^);

        int getId(void);
        System::String^ getEmail(void);
        System::String^ getMdp(void);
    };

    /*
    ref class requete
    {
    public:
        virtual System::String^ Ajouter() = 0;
        virtual System::String^ Modifier() = 0;
        virtual System::String^ Supprimer() = 0;
        virtual System::String^ Afficher() = 0;
    };
    ref class Personnel  {
    private:
        System::String^ id_personnel;
        System::String^ nom;
        System::String^ prenom;
        System::String^ date_embauche;
        bool superieur;
    public:
        void set_id_personnel(System::String^);
        void set_nom(System::String^);
        void set_prenom(System::String^);
        void set_date_embauche(System::String^);
        void set_superieur(bool);

        System::String^ get_id_personnel(void);
        System::String^ get_nom(void);
        System::String^ get_prenom(void);
        System::String^ get_date_embauche(void);
        bool get_superieur(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };

    ref class Client
    {
    private:
        System::String^ id_client;
        System::String^ nom;
        System::String^ prenom;
        System::String^ date_naissance;
        System::String^ date_premiere_commande;
    public:
        void set_id_client(System::String^);
        void set_nom(System::String^);
        void set_prenom(System::String^);
        void set_date_naissance(System::String^);
        void set_date_premiere_commande(System::String^);

        System::String^ get_id_client(void);
        System::String^ get_nom(void);
        System::String^ get_prenom(void);
        System::String^ get_date_naissance(void);
        System::String^ get_date_premiere_commande(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };
    
    ref class Article
    {
    private:
        System::String^ id_article;
        System::String^ nom;
        System::String^ nature;
        float^ prix_HT;
        int^ quantite_stock;
        float^ TVA;
        System::String^ couleur;
    public:
        void set_id_article(System::String^);
        void set_nom(System::String^);
        void set_nature(System::String^);
        void set_prix_HT(float^);
        void set_quantite_stock(int^);
        void set_TVA(float^);
        void set_couleur(System::String^);

        System::String^ get_id_article(void);
        System::String^ get_nom(void);
        System::String^ get_nature(void);
        System::String^ get_prix_HT(void);
        System::String^ get_quantite_stock(void);
        System::String^ get_TVA(void);
        System::String^ get_couleur(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };

    ref class Adresse 
    {
    private:
        System::String^ id_adresse;
        System::String^ rue;
        System::String^ nrue;
    public:
        void set_id_adresse(System::String^);
        void set_rue(System::String^);
        void set_nrue(System::String^);

        System::String^ get_id_adresse(void);
        System::String^ get_rue(void);
        System::String^ get_nrue(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };

    ref class Paiement
    {
    private:
        System::String^ id_paiement;
        float^ solde;
        System::String^ date_emission;
        System::String^ date_paiement;
        System::String^ moyen;
    public:
        void set_id_paiement(System::String^);
        void set_solde(float^);
        void set_date_emission(System::String^);
        void set_date_paiement(System::String^);
        void set_moyen(System::String^);

        System::String^ get_id_paiement(void);
        float^ get_solde(void);
        System::String^ get_date_emission(void);
        System::String^ get_date_paiement(void);
        System::String^ get_moyen(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };

    ref class Commande
    {
    private:
        System::String^ id_commande;
        System::String^ reference;
        System::String^ date_livraison;
        System::String^ date_emission;
        float^ prix_HT;
        float^ prix_TTC;
        float^ TVA;
        float^ remise;
        float^ prix_final;
    public:
        void set_id_commande(System::String^);
        void set_reference(System::String^);
        void set_date_livraison(System::String^);
        void set_date_emission(System::String^);
        void set_prix_HT(float^); 
        void set_prix_TTC(float^);
        void set_TVA(float^);
        void set_remise(float^);
        void set_prix_final(float^);

        System::String^ get_id_commande(void);
        System::String^ get_reference(void);
        System::String^ get_date_livraison(void);
        System::String^ set_date_emission(void);
        float^ set_prix_HT(void); 
        float^ set_prix_TTC(void);
        float^ set_TVA(void);
        float^ set_remise(void);
        float^ set_prix_final(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };

    ref class Ville
    {
    private:
        System::String^ id_ville;
        System::String^ nom;
        System::String^ code_postal;
    public:
        void set_id_ville(System::String^);
        void set_nom(System::String^);
        void set_code_postal(System::String^);

        System::String^ get_id_ville(void);
        System::String^ get_nom(void);
        System::String^ get_code_postal(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };
    */ 
}

