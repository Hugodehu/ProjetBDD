#pragma once
#include "Auth.h"
#include "BDDload.h"
namespace NS_BDDservice
{
    ref class BDDservice
    {
    private:
        NS_load::CLload^ oCad;
        NS_BDD::Authentification^ oMappTB;
    public:
        BDDservice(void);
        System::Data::DataSet^ CheckAuthentification(System::String^,System::String^);
        System::Data::DataSet^ CheckSup();
        System::Data::DataSet^ Afficher();
    };
    /*
    ref class service_Personnel
    {
    private:
        NS_load::CLload^ oCad;
        NS_BDD::Personnel^ oPersonnel;
    public:
        System::Data::DataSet^ Ajouter_personnel(System::String^,System::String^,System::String^,bool);
        void Modifier_personnel(System::String^,System::String^,System::String^,bool);
        void effacer_personnel(System::String^,System::String^,System::String^,b)ol;
        System::Data::DataSet^ Afficher_personnel(System::String^,System::String^);
    };

    ref class service_Client
    {
    private: 
        NS_load::CLload^ oCad;
        NS_BDD::Client^  oClient;
    public:
        System::Data::DataSet^ Ajouter_client(System::String^,System::String^,System::String^, System::String^);
        void Modifier_client(System::String^,System::String^,System::String^, System::String^);
        void effacer_client(System::String^,System::String^,System::String^);
        System::Data::DataSet^ Afficher_client(System::String^,System::String^);
    };

    ref class service_Article
    {
    private:
        NS_load::CLload^ oCad;
        NS_BDD::Article^  oArticle;
    public:
        System::Data::DataSet^ Ajouter_article(System::String^,System::String^,System::String^, float^, int^, float^, System::String^);
        void Modifier_article(System::String^,System::String^);
        void effacer_article(System::String^,System::String^);
        System::Data::DataSet^ Afficher_article(System::String^,System::String^);
    };

    ref class service_Commande
    {
    private:
        NS_load::CLload^ oCad;
        NS_BDD::Commande^  oCommande;
    public:
        System::Data::DataSet^ Ajouter_commande(System::String^,System::String^,System::String^, float^, float^, float^, float^, float^);
        void Modifier_commande(System::String^,System::String^, System::String^);
        void effacer_commande(System::String^,System::String^, System::String^);
        System::Data::DataSet^ Afficher_commande(System::String^,System::String^, System::String^);
    }
    */

}

