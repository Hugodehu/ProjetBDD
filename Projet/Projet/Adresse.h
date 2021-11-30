#pragma once
#include "Header.h"

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

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };
}