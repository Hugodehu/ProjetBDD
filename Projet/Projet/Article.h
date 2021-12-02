#pragma once
#include "pch.h"

namespace NS_BDD
{
    ref class Article
    {
    private:
        System::String^ id_article;
        System::String^ nom;
        System::String^ nature;
        System::String^ prix_HT;
        System::String^ quantite_stock;
        System::String^ TVA;
        System::String^ couleur;
        System::String^ seuil;
    public:
        void set_id_article(System::String^);
        void set_nom(System::String^);
        void set_nature(System::String^);
        void set_prix_HT(System::String^);
        void set_quantite_stock(System::String^);
        void set_TVA(System::String^);
        void set_couleur(System::String^);
        void set_seuil(System::String^);

        System::String^ get_id_article(void);
        System::String^ get_nom(void);
        System::String^ get_nature(void);
        System::String^ get_prix_HT(void);
        System::String^ get_quantite_stock(void);
        System::String^ get_TVA(void);
        System::String^ get_couleur(void);
        System::String^ get_seuil(void);

        System::String^ Ajouter();
        System::String^ Afficher(void);
        System::String^ Modifier();
        System::String^ Supprimer(void);
    };
}