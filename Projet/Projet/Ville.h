#pragma once
#include "pch.h"
namespace NS_BDD
{
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
}