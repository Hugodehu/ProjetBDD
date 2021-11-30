#pragma once
#include "Header.h"
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
        System::String^ Afficher(void);
        System::String^ Ajouter(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

        void setId(int);
        void setEmail(System::String^);
        void setMdp(System::String^);

        int getId(void);
        System::String^ getEmail(void);
        System::String^ getMdp(void);
    };
}

