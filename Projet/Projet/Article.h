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
        float^ prix_HT;
        int^ quantite_stock;
        float^ TVA;
        System::String^ couleur;
    public:
        void set_id_article(System::String^);
        void set_nom(System::String^);
        void set_nature(System::String^);
        void set_prix_HT(float^);
        void set_quantite_stock(int^);
        void set_TVA(float^);
        void set_couleur(System::String^);

        System::String^ get_id_article(void);
        System::String^ get_nom(void);
        System::String^ get_nature(void);
        float^ get_prix_HT(void);
        int^ get_quantite_stock(void);
        float^ get_TVA(void);
        System::String^ get_couleur(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);
    };
}