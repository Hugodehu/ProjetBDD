#pragma once
namespace NS_BDD {
	ref class statistique{
	private:
		System::String^ mois;
		System::String^ nom;
		System::String^ prenom;
		System::String^ id;
		System::String^ TVA;
		System::String^ marge;
		System::String^ remise;
		System::String^ demarque;

	public:
		System::String^ get_mois();
		System::String^ get_nom();
		System::String^ get_prenom();
		System::String^ get_id();
		System::String^ get_TVA();
		System::String^ get_marge();
		System::String^ get_remise();
		System::String^ get_demarque();

		void set_mois(System::String^);
		void set_nom(System::String^);
		void set_id(System::String^);
		void set_prenom(System::String^);
		void set_TVA(System::String^);
		void set_marge(System::String^);
		void set_remise(System::String^);
		void set_demarque(System::String^);
		
		System::String^ panier_moy(void);
		System::String^ chiffre_affaire(void);
		System::String^ seuil_appro(void);
		System::String^ montant_total_achat(void);
		System::String^ arcticle_plus_vendu(void);
		System::String^ article_moins_vendu(void);
		System::String^ val_com_stock(void);
		System::String^ val_achat_stock(void);
		System::String^ simulation(void);
	};
	

	
}

