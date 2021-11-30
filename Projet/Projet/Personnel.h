#pragma once
#include "pch.h"

namespace NS_BDD
{
    ref class Personnel {
    private:
        System::String^ id_personnel;
        System::String^ nom;
        System::String^ prenom;
        System::String^ date_embauche;
        System::String^ superieur;
        System::String^ id_sup;
       // System::Data::DataSet^ test;

    public:
        void set_id_personnel(System::String^);
        void set_nom(System::String^);
        void set_prenom(System::String^);
        void set_date_embauche(System::String^);
        void set_superieur(System::String^);
        void set_id_superieur(System::String^);
        //void set_test(System::Data::DataSet^);


        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

        System::String^ get_id_personnel(void);
        System::String^ get_nom(void);
        System::String^ get_prenom(void);
        System::String^ get_date_embauche(void);
        System::String^ get_superieur(void);
        System::String^ get_id_sup(void);
        //System::Data::DataSet^ get_test(System::Data::DataSet^);

    };
}
