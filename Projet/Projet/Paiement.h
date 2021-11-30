#pragma once
#include "pch.h"

namespace NS_BDD
{
    ref class Paiement {
    private:
        System::String^ id_paiement;
        System::String^ solde;
        System::String^ date_emission;
        System::String^ date_paiement;
        System::String^ moyen;
        System::String^ date_embauche;

    public:
        void set_id_paiement(System::String^);
        void set_solde(System::String^);
        void set_date_emission(System::String^);
        void set_date_paiement(System::String^);
        void set_moyen(System::String^);

        System::String^ Afficher(void); 
        System::String^ Ajouter(void); 
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

        System::String^ get_id_paiement(void);
        System::String^ get_solde(void);
        System::String^ get_date_emission(void);

        System::String^ get_date_paiement(void);
        System::String^ get_moyen(void);
    };
}
