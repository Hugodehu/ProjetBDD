#pragma once
#include "pch.h"
namespace NS_BDD
{
    ref class Commande
    {
    private:
        System::String^ id_commande;
        System::String^ reference;
        System::String^ date_livraison;
        System::String^ date_emission;
        System::String^ prix_HT;
        System::String^ prix_TTC;
        System::String^ TVA;
        System::String^ remise;
        System::String^ prix_final;
        System::String^ quantite;

    public:
        void set_id_commande(System::String^);
        void set_reference(System::String^);
        void set_date_livraison(System::String^);
        void set_date_emission(System::String^);
        void set_prix_HT(System::String^);
        void set_prix_TTC(System::String^);
        void set_TVA(System::String^);
        void set_remise(System::String^);
        void set_prix_final(System::String^);
        void set_quantité(System::String^);

        System::String^ get_id_commande(void);
        System::String^ get_reference(void);
        System::String^ get_date_livraison(void);
        System::String^ get_date_emission(void);
        System::String^ get_prix_HT(void);
        System::String^ get_prix_TTC(void);
        System::String^ get_TVA(void);
        System::String^ get_remise(void);
        System::String^ get_prix_final(void);
        System::String^ get_quantite(void);
        System::String^ Ajouter2(System::String^, System::String^, System::String^, System::String^, System::String^, System::String^);
        System::String^ Ajouter(System::String^ , System::String^ , System::String^ );
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };
}