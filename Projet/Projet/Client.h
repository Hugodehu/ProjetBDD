#pragma once

namespace NS_BDD
{
    ref class Client
    {
    private:
        System::String^ id_client;
        System::String^ nom;
        System::String^ prenom;
        System::String^ date_naissance;
        System::String^ date_premiere_commande;
    public:
        void set_id_client(System::String^);
        void set_nom(System::String^);
        void set_prenom(System::String^);
        void set_date_naissance(System::String^);
        void set_date_premiere_commande(System::String^);

        System::String^ get_id_client(void);
        System::String^ get_nom(void);
        System::String^ get_prenom(void);
        System::String^ get_date_naissance(void);
        System::String^ get_date_premiere_commande(void);

        System::String^ Ajouter(void);
        System::String^ Afficher(void);
        System::String^ Modifier(void);
        System::String^ Supprimer(void);

    };

}