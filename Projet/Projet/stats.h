#pragma once
#include "pch.h"
#include <iostream>
#include <string>

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Stats(void)
		{
			InitializeComponent();
		}

	protected:
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ box_choix_stat;
	private: System::Windows::Forms::Label^ label_titre;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Label^ label_sous_titre;
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::ComboBox^ box_choix_sec;
	private: System::Windows::Forms::TextBox^ box_affichage;

	private: int mois;


#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->box_choix_stat = (gcnew System::Windows::Forms::ComboBox());
			   this->label_titre = (gcnew System::Windows::Forms::Label());
			   this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->label_sous_titre = (gcnew System::Windows::Forms::Label());
			   this->box_affichage = (gcnew System::Windows::Forms::TextBox());
			   this->box_choix_sec = (gcnew System::Windows::Forms::ComboBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // box_choix_stat
			   // 
			   this->box_choix_stat->FormattingEnabled = true;
			   this->box_choix_stat->Items->AddRange(gcnew cli::array< System::Object^  >(9) { L"Calcul du panier moyen", L"Calcul du chiffre d affaire", L"Produits sous le seuil de reapprovisionnement", L"Montant total des achats d\'un client", L"10 articles les plus vendus", L"10 articles les moins vendus", L"Valeur commerciale du stock", L"Valeur deachat du stock", L"Simulation" });
			   this->box_choix_stat->Location = System::Drawing::Point(12, 65);
			   this->box_choix_stat->Name = L"box_choix_stat";
			   this->box_choix_stat->Size = System::Drawing::Size(333, 28);
			   this->box_choix_stat->TabIndex = 0;
			   this->box_choix_stat->SelectedIndexChanged += gcnew System::EventHandler(this, &Stats::comboBox_SelectedIndexChanged);
			   // 
			   // label_titre
			   // 
			   this->label_titre->AutoSize = true;
			   this->label_titre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label_titre->Location = System::Drawing::Point(406, 9);
			   this->label_titre->Name = L"label_titre";
			   this->label_titre->Size = System::Drawing::Size(347, 32);
			   this->label_titre->TabIndex = 1;
			   this->label_titre->Text = L"Gestion des Statistiques";
			   // 
			   // dataGridView
			   // 
			   this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView->Location = System::Drawing::Point(379, 65);
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->RowHeadersWidth = 62;
			   this->dataGridView->RowTemplate->Height = 28;
			   this->dataGridView->Size = System::Drawing::Size(686, 193);
			   this->dataGridView->TabIndex = 2;
			   // 
			   // label_sous_titre
			   // 
			   this->label_sous_titre->AutoSize = true;
			   this->label_sous_titre->Location = System::Drawing::Point(638, 286);
			   this->label_sous_titre->Name = L"label_sous_titre";
			   this->label_sous_titre->Size = System::Drawing::Size(0, 20);
			   this->label_sous_titre->TabIndex = 3;
			   this->label_sous_titre->Visible = false;
			   // 
			   // box_affichage
			   // 
			   this->box_affichage->Location = System::Drawing::Point(651, 322);
			   this->box_affichage->Name = L"box_affichage";
			   this->box_affichage->ReadOnly = true;
			   this->box_affichage->Size = System::Drawing::Size(148, 26);
			   this->box_affichage->TabIndex = 14;
			   this->box_affichage->Visible = false;
			   // 
			   // box_choix_sec
			   // 
			   this->box_choix_sec->FormattingEnabled = true;
			   this->box_choix_sec->Location = System::Drawing::Point(412, 322);
			   this->box_choix_sec->Name = L"box_choix_sec";
			   this->box_choix_sec->Size = System::Drawing::Size(148, 28);
			   this->box_choix_sec->TabIndex = 15;
			   this->box_choix_sec->Visible = false;
			   this->box_choix_sec->SelectedIndexChanged += gcnew System::EventHandler(this, &Stats::box_choix_sec_SelectedIndexChanged);
			   // 
			   // Stats
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1089, 390);
			   this->Controls->Add(this->box_choix_sec);
			   this->Controls->Add(this->label_sous_titre);
			   this->Controls->Add(this->dataGridView);
			   this->Controls->Add(this->label_titre);
			   this->Controls->Add(this->box_choix_stat);
			   this->Controls->Add(this->box_affichage);
			   this->Name = L"Stats";
			   this->Text = L"Stats";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   void hide() {
			   this->label_sous_titre->Visible = false;
			   this->box_affichage->Visible = false;
			   this->box_affichage->Text = "";
			   this->box_choix_sec->Visible = false;
			   this->box_choix_sec->Items->Clear();

		   }

	private: System::Void box_choix_sec_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (box_choix_stat->SelectedIndex == 1) {
			array<System::String^>^ listmois = gcnew array<System::String^>(12) { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };
			mois = box_choix_sec->SelectedIndex;
			this->label_sous_titre->Text = L"Le chiffre d'affaire du mois de " + listmois[mois] + L" est de :";
			this->box_affichage->Text = "2";  //Ajouter requete chiffre affaire en fonction du mois
		}
		else if (box_choix_stat->SelectedIndex == 3) {

			System::String^ client = "NomClient";
			this->label_sous_titre->Text = L"Le montant total du client " + client + " est de :";
			this->box_affichage->Text = "4"; //Ajouter requete montant chat total client
		}
	}

	private: System::Void comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		if (box_choix_stat->SelectedIndex == 0) {
			hide();
			this->label_sous_titre->Text = L"Le panier moyen est de :";
			this->label_sous_titre->Visible = true;
			this->box_affichage->Text = "1";  //Ajouter requete Panier moyen
			this->box_affichage->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 1) {
			hide();
			this->box_choix_sec->Items->AddRange(gcnew cli::array< System::Object^  >(12) { L"Janvier", L"Fevrier", L"Mars", L"Avril", L"Mai", L"Juin", L"Juillet", L"Aout", L"Septembre", L"Octobre", L"Novembre", L"Decembre" });
			this->label_sous_titre->Text = L"Choisissez un mois:";

			this->label_sous_titre->Visible = true;
			this->box_affichage->Visible = true;
			this->box_choix_sec->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 2) {
			hide();
			this->label_sous_titre->Text = L"Les produits sous le seuil d'approvisionnement sont :";
			this->label_sous_titre->Visible = true;
			this->dataGridView->Refresh();
			//Inserer donnees dans la DGV
			this->box_affichage->Text = "3";
			this->box_affichage->Visible = true;

		}

		else if (box_choix_stat->SelectedIndex == 3) {
			hide();
			this->box_choix_sec->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Client1", L"Client2", L"Client3" });

			this->label_sous_titre->Text = L"Choisissez un client:";
			this->label_sous_titre->Visible = true;
			this->box_affichage->Visible = true;
			this->box_choix_sec->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 4) {
			hide();
			this->label_sous_titre->Text = L"Les 10 articles les plus vendus sont :";
			this->label_sous_titre->Visible = true;
			this->dataGridView->Refresh();
			//Inserer donnees dans la DGV
			this->box_affichage->Text = "5";
			this->box_affichage->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 5) {
			hide();
			this->label_sous_titre->Text = L"Les 10 articles les moins vendus sont :";
			this->label_sous_titre->Visible = true;
			this->dataGridView->Refresh();
			//Inserer donnees dans la DGV
			this->box_affichage->Text = "6";
			this->box_affichage->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 6) {
			hide();

			this->label_sous_titre->Text = L"La valeur commerciale du stock est de";
			this->label_sous_titre->Visible = true;

			this->box_affichage->Text = "7";//Inserer donnee
			this->box_affichage->Visible = true;
		}

		else if (box_choix_stat->SelectedIndex == 7) {
			hide();

			this->label_sous_titre->Text = L"La valeur d'achat du stock est de";
			this->label_sous_titre->Visible = true;

			this->box_affichage->Text = "8";//Inserer donnee
			this->box_affichage->Visible = true;
		}
	}

	};

}


