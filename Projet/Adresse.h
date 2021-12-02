#pragma once
#include "pch.h"
namespace NS_BDD
{
    ref class Adresse
    {
    private:
        System::String^ id_adresse;
        System::String^ rue;

    public:
        void set_id_adresse(System::String^);
        void set_rue(System::String^);

        System::String^ get_id_adresse(void);
        System::String^ get_rue(void);

        System::String^ Ajouter(System::String^);
        System::String^ Afficher(System::String^ , System::String^ , System::String^ );
        System::String^ Modifier(System::String^, System::String^ , System::String^ , System::String^ , System::String^);
        System::String^ Supprimer(System::String^, System::String^, System::String^);

    };
}