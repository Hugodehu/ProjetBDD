#pragma once
#include "pch.h"

namespace NS_BDD
{
    ref class Authentification
    {
    private:
        System::String^ email;
        System::String^ mdp;
        System::String^ Id;

    public:
        System::String^ Check();
        System::String^ CheckSupp();
        System::String^ Afficher(void);
        System::String^ Ajouter(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

        void setId(System::String^);
        void setEmail(System::String^);
        void setMdp(System::String^);

        System::String^ getId(void);
        System::String^ getEmail(void);
        System::String^ getMdp(void);
    };
}

