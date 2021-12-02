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

        System::String^ Ajouter(System::String^, System::String^);
        //ICI
        System::String^ Afficher(void);
        //ICI
        System::String^ Modifier(System::String^, System::String^, System::String^);
        System::String^ Supprimer(void);
    };

}