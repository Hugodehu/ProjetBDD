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
        float^ prix_HT;
        float^ prix_TTC;
        float^ TVA;
        float^ remise;
        float^ prix_final;
    public:
        void set_id_commande(System::String^);
        void set_reference(System::String^);
        void set_date_livraison(System::String^);
        void set_date_emission(System::String^);
        void set_prix_HT(float^);
        void set_prix_TTC(float^);
        void set_TVA(float^);
        void set_remise(float^);
        void set_prix_final(float^);

        System::String^ get_id_commande(void);
        System::String^ get_reference(void);
        System::String^ get_date_livraison(void);
        System::String^ set_date_emission(void);
        float^ get_prix_HT(void);
        float^ get_prix_TTC(void);
        float^ get_TVA(void);
        float^ get_remise(void);
        float^ get_prix_final(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };
}