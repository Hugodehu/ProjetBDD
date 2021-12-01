#pragma once
#include "pch.h"

namespace NS_BDD
{
    ref class Client
    {
    private:
        System::String^ id_client;
        System::String^ nom;
        System::String^ prenom;
        System::String^ date_naissance;
        System::String^ Date_premiere_commande;


    public:
        void set_id_client(System::String^);
        void set_nom(System::String^);
        void set_prenom(System::String^);
        void set_date_naissance(System::String^);
        void set_date_premiere_commande(System::String^);

        System::String^ get_id_client();
        System::String^ get_nom();
        System::String^ get_prenom();
        System::String^ get_date_naissance();
        System::String^ get_date_premiere_commande();

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };

}