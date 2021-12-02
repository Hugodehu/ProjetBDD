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

	private: System::ComponentModel::Container^ components;
	private: NS_BDDservice::service_Stat^ stat;
	private: System::Data::DataSet^ result;
	private: int mois;

	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::Label^ label_titre;
	private: System::Windows::Forms::Label^ label_mois;
	private: System::Windows::Forms::Label^ label_nom;
	private: System::Windows::Forms::Label^ label_prenom;
	private: System::Windows::Forms::Label^ label_TVA;
	private: System::Windows::Forms::Label^ label_marge;
	private: System::Windows::Forms::Label^ label_remise;
	private: System::Windows::Forms::Label^ label_demarque;

	private: System::Windows::Forms::ComboBox^ comboBox_stat;
	private: System::Windows::Forms::ComboBox^ comboBox_mois;
	private: System::Windows::Forms::ComboBox^ comboBox_TVA;
	private: System::Windows::Forms::ComboBox^ comboBox_marge;
	private: System::Windows::Forms::ComboBox^ comboBox_remise;
	private: System::Windows::Forms::ComboBox^ comboBox_demarque;
	private: System::Windows::Forms::TextBox^ textBox_nom;
	private: System::Windows::Forms::TextBox^ textBox_prenom;
	private: System::Windows::Forms::TextBox^ textBox_id;
	private: System::Windows::Forms::Label^ label_id;


	private: System::Windows::Forms::Button^ button_valider;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stats::typeid));
			   this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->label_titre = (gcnew System::Windows::Forms::Label());
			   this->label_mois = (gcnew System::Windows::Forms::Label());
			   this->label_nom = (gcnew System::Windows::Forms::Label());
			   this->label_prenom = (gcnew System::Windows::Forms::Label());
			   this->label_TVA = (gcnew System::Windows::Forms::Label());
			   this->label_marge = (gcnew System::Windows::Forms::Label());
			   this->label_remise = (gcnew System::Windows::Forms::Label());
			   this->label_demarque = (gcnew System::Windows::Forms::Label());
			   this->comboBox_stat = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox_mois = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox_TVA = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox_marge = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox_demarque = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox_remise = (gcnew System::Windows::Forms::ComboBox());
			   this->textBox_nom = (gcnew System::Windows::Forms::TextBox());
			   this->textBox_prenom = (gcnew System::Windows::Forms::TextBox());
			   this->button_valider = (gcnew System::Windows::Forms::Button());
			   this->textBox_id = (gcnew System::Windows::Forms::TextBox());
			   this->label_id = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // dataGridView
			   // 
			   this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView->Location = System::Drawing::Point(359, 15);
			   this->dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->ReadOnly = true;
			   this->dataGridView->RowHeadersWidth = 62;
			   this->dataGridView->RowTemplate->Height = 28;
			   this->dataGridView->Size = System::Drawing::Size(358, 175);
			   this->dataGridView->TabIndex = 2;
			   // 
			   // label_titre
			   // 
			   this->label_titre->AutoSize = true;
			   this->label_titre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label_titre->Location = System::Drawing::Point(64, 9);
			   this->label_titre->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label_titre->Name = L"label_titre";
			   this->label_titre->Size = System::Drawing::Size(232, 24);
			   this->label_titre->TabIndex = 1;
			   this->label_titre->Text = L"Gestion des Statistiques";
			   // 
			   // label_mois
			   // 
			   this->label_mois->AutoSize = true;
			   this->label_mois->Location = System::Drawing::Point(5, 79);
			   this->label_mois->Name = L"label_mois";
			   this->label_mois->Size = System::Drawing::Size(29, 13);
			   this->label_mois->TabIndex = 29;
			   this->label_mois->Text = L"Mois";
			   this->label_mois->Visible = false;
			   // 
			   // label_nom
			   // 
			   this->label_nom->AutoSize = true;
			   this->label_nom->Location = System::Drawing::Point(5, 131);
			   this->label_nom->Name = L"label_nom";
			   this->label_nom->Size = System::Drawing::Size(29, 13);
			   this->label_nom->TabIndex = 18;
			   this->label_nom->Text = L"Nom";
			   this->label_nom->Visible = false;
			   // 
			   // label_prenom
			   // 
			   this->label_prenom->AutoSize = true;
			   this->label_prenom->Location = System::Drawing::Point(141, 131);
			   this->label_prenom->Name = L"label_prenom";
			   this->label_prenom->Size = System::Drawing::Size(43, 13);
			   this->label_prenom->TabIndex = 19;
			   this->label_prenom->Text = L"Prenom";
			   this->label_prenom->Visible = false;
			   // 
			   // label_TVA
			   // 
			   this->label_TVA->AutoSize = true;
			   this->label_TVA->Location = System::Drawing::Point(5, 199);
			   this->label_TVA->Name = L"label_TVA";
			   this->label_TVA->Size = System::Drawing::Size(28, 13);
			   this->label_TVA->TabIndex = 21;
			   this->label_TVA->Text = L"TVA";
			   this->label_TVA->Visible = false;
			   // 
			   // label_marge
			   // 
			   this->label_marge->AutoSize = true;
			   this->label_marge->Location = System::Drawing::Point(178, 199);
			   this->label_marge->Name = L"label_marge";
			   this->label_marge->Size = System::Drawing::Size(37, 13);
			   this->label_marge->TabIndex = 22;
			   this->label_marge->Text = L"Marge";
			   this->label_marge->Visible = false;
			   // 
			   // label_remise
			   // 
			   this->label_remise->AutoSize = true;
			   this->label_remise->Location = System::Drawing::Point(2, 280);
			   this->label_remise->Name = L"label_remise";
			   this->label_remise->Size = System::Drawing::Size(42, 13);
			   this->label_remise->TabIndex = 25;
			   this->label_remise->Text = L"Remise";
			   this->label_remise->Visible = false;
			   // 
			   // label_demarque
			   // 
			   this->label_demarque->AutoSize = true;
			   this->label_demarque->Location = System::Drawing::Point(178, 279);
			   this->label_demarque->Name = L"label_demarque";
			   this->label_demarque->Size = System::Drawing::Size(56, 13);
			   this->label_demarque->TabIndex = 26;
			   this->label_demarque->Text = L"Demarque";
			   this->label_demarque->Visible = false;
			   // 
			   // comboBox_stat
			   // 
			   this->comboBox_stat->AllowDrop = true;
			   this->comboBox_stat->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_stat->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_stat->FormattingEnabled = true;
			   this->comboBox_stat->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				   L"Calcul du panier moyen", L"Calcul du chiffre d\'affaire",
					   L"Produits sous le seuil de reapprovisionnement", L"Montant total des achats d\'un client", L"10 articles les plus vendus", L"10 articles les moins vendus",
					   L"Valeur commerciale du stock", L"Valeur d\'achat du stock", L"Simulation"
			   });
			   this->comboBox_stat->Location = System::Drawing::Point(8, 42);
			   this->comboBox_stat->Margin = System::Windows::Forms::Padding(2);
			   this->comboBox_stat->Name = L"comboBox_stat";
			   this->comboBox_stat->Size = System::Drawing::Size(347, 21);
			   this->comboBox_stat->TabIndex = 0;
			   this->comboBox_stat->SelectedIndexChanged += gcnew System::EventHandler(this, &Stats::comboBox_SelectedIndexChanged);
			   // 
			   // comboBox_mois
			   // 
			   this->comboBox_mois->AllowDrop = true;
			   this->comboBox_mois->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_mois->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_mois->FormattingEnabled = true;
			   this->comboBox_mois->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				   L"Janvier", L"Fevrier", L"Mars", L"Avril",
					   L"Mai", L"Juin", L"Juillet", L"Aout", L"Septembre", L"Octobre", L"Novembre", L"Decembre"
			   });
			   this->comboBox_mois->Location = System::Drawing::Point(8, 94);
			   this->comboBox_mois->Margin = System::Windows::Forms::Padding(2);
			   this->comboBox_mois->Name = L"comboBox_mois";
			   this->comboBox_mois->Size = System::Drawing::Size(85, 21);
			   this->comboBox_mois->TabIndex = 15;
			   this->comboBox_mois->Visible = false;
			   this->comboBox_mois->SelectedIndexChanged += gcnew System::EventHandler(this, &Stats::comboBox_mois_SelectedIndexChanged);
			   // 
			   // comboBox_TVA
			   // 
			   this->comboBox_TVA->AllowDrop = true;
			   this->comboBox_TVA->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_TVA->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_TVA->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L" ", L"Taux normal (20%)", L"Taux intermediaire (10%)",
					   L"Taux reduit (5.5%)"
			   });
			   this->comboBox_TVA->Location = System::Drawing::Point(5, 215);
			   this->comboBox_TVA->Name = L"comboBox_TVA";
			   this->comboBox_TVA->Size = System::Drawing::Size(145, 21);
			   this->comboBox_TVA->TabIndex = 23;
			   this->comboBox_TVA->Visible = false;
			   // 
			   // comboBox_marge
			   // 
			   this->comboBox_marge->AllowDrop = true;
			   this->comboBox_marge->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_marge->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_marge->FormattingEnabled = true;
			   this->comboBox_marge->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L" ", L"Marge commerciale de 5%", L"Marge commerciale de 10%",
					   L"Marge commerciale de 15%"
			   });
			   this->comboBox_marge->Location = System::Drawing::Point(181, 215);
			   this->comboBox_marge->Name = L"comboBox_marge";
			   this->comboBox_marge->Size = System::Drawing::Size(145, 21);
			   this->comboBox_marge->TabIndex = 24;
			   this->comboBox_marge->Visible = false;
			   // 
			   // comboBox_demarque
			   // 
			   this->comboBox_demarque->AllowDrop = true;
			   this->comboBox_demarque->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_demarque->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_demarque->FormattingEnabled = true;
			   this->comboBox_demarque->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L" ", L"Demarque inconnue de 2%", L"Demarque inconnue de 3%",
					   L"Demarque inconnue de 5%"
			   });
			   this->comboBox_demarque->Location = System::Drawing::Point(181, 296);
			   this->comboBox_demarque->Name = L"comboBox_demarque";
			   this->comboBox_demarque->Size = System::Drawing::Size(145, 21);
			   this->comboBox_demarque->TabIndex = 27;
			   this->comboBox_demarque->Visible = false;
			   // 
			   // comboBox_remise
			   // 
			   this->comboBox_remise->AllowDrop = true;
			   this->comboBox_remise->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_remise->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox_remise->FormattingEnabled = true;
			   this->comboBox_remise->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L" ", L"Remise commerciale de 5%", L"Remise commerciale de 6%" });
			   this->comboBox_remise->Location = System::Drawing::Point(5, 296);
			   this->comboBox_remise->Name = L"comboBox_remise";
			   this->comboBox_remise->Size = System::Drawing::Size(145, 21);
			   this->comboBox_remise->TabIndex = 28;
			   this->comboBox_remise->Visible = false;
			   // 
			   // textBox_nom
			   // 
			   this->textBox_nom->Location = System::Drawing::Point(8, 147);
			   this->textBox_nom->Name = L"textBox_nom";
			   this->textBox_nom->Size = System::Drawing::Size(130, 20);
			   this->textBox_nom->TabIndex = 16;
			   this->textBox_nom->Visible = false;
			   // 
			   // textBox_prenom
			   // 
			   this->textBox_prenom->Location = System::Drawing::Point(144, 147);
			   this->textBox_prenom->Name = L"textBox_prenom";
			   this->textBox_prenom->Size = System::Drawing::Size(119, 20);
			   this->textBox_prenom->TabIndex = 17;
			   this->textBox_prenom->Visible = false;
			   // 
			   // button_valider
			   // 
			   this->button_valider->Location = System::Drawing::Point(359, 226);
			   this->button_valider->Name = L"button_valider";
			   this->button_valider->Size = System::Drawing::Size(358, 75);
			   this->button_valider->TabIndex = 20;
			   this->button_valider->Text = L"Valider";
			   this->button_valider->UseVisualStyleBackColor = true;
			   this->button_valider->Click += gcnew System::EventHandler(this, &Stats::valider_Click);
			   // 
			   // textBox_id
			   // 
			   this->textBox_id->Location = System::Drawing::Point(280, 147);
			   this->textBox_id->Name = L"textBox_id";
			   this->textBox_id->Size = System::Drawing::Size(75, 20);
			   this->textBox_id->TabIndex = 30;
			   this->textBox_id->Visible = false;
			   // 
			   // label_id
			   // 
			   this->label_id->AutoSize = true;
			   this->label_id->Location = System::Drawing::Point(277, 131);
			   this->label_id->Name = L"label_id";
			   this->label_id->Size = System::Drawing::Size(16, 13);
			   this->label_id->TabIndex = 31;
			   this->label_id->Text = L"Id";
			   this->label_id->Visible = false;
			   // 
			   // Stats
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(738, 335);
			   this->Controls->Add(this->label_id);
			   this->Controls->Add(this->textBox_id);
			   this->Controls->Add(this->dataGridView);
			   this->Controls->Add(this->label_titre);
			   this->Controls->Add(this->label_mois);
			   this->Controls->Add(this->label_nom);
			   this->Controls->Add(this->label_prenom);
			   this->Controls->Add(this->label_TVA);
			   this->Controls->Add(this->label_marge);
			   this->Controls->Add(this->label_remise);
			   this->Controls->Add(this->label_demarque);
			   this->Controls->Add(this->comboBox_stat);
			   this->Controls->Add(this->comboBox_mois);
			   this->Controls->Add(this->comboBox_TVA);
			   this->Controls->Add(this->comboBox_marge);
			   this->Controls->Add(this->comboBox_remise);
			   this->Controls->Add(this->comboBox_demarque);
			   this->Controls->Add(this->textBox_nom);
			   this->Controls->Add(this->textBox_prenom);
			   this->Controls->Add(this->button_valider);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Stats";
			   this->Text = L"Stats";
			   this->Load += gcnew System::EventHandler(this, &Stats::Stats_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   void hide() {
			   this->label_mois->Visible = false;
			   this->label_nom->Visible = false;
			   this->label_prenom->Visible = false;
			   this->label_TVA->Visible = false;
			   this->label_marge->Visible = false;
			   this->label_remise->Visible = false;
			   this->label_demarque->Visible = false;
			   this->label_id->Visible = false;

			   this->comboBox_mois->Visible = false;
			   this->comboBox_TVA->Visible = false;
			   this->comboBox_marge->Visible = false;
			   this->comboBox_remise->Visible = false;
			   this->comboBox_demarque->Visible = false;

			   this->textBox_nom->Visible = false;
			   this->textBox_prenom->Visible = false;
			   this->textBox_id->Visible = false;
		   }
	private: System::Void Stats_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->stat = gcnew NS_BDDservice::service_Stat();
	}

	private: System::Void comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{	
		this->dataGridView->ClearSelection();
		hide();

		if (comboBox_stat->SelectedIndex == 1) // Chiffre d'affaire (selon le mois)
		{
			this->label_mois->Visible = true;
			this->comboBox_mois->Visible = true;
		}

		else if (comboBox_stat->SelectedIndex == 3) // Montant total des achats pour un client
		{
			this->label_nom->Visible = true;
			this->label_prenom->Visible = true;
			this->label_id->Visible = true;
			
			this->textBox_nom->Visible = true;
			this->textBox_prenom->Visible = true;
			this->textBox_id->Visible = true;
		}

		else if (comboBox_stat->SelectedIndex == 8) // Simulation
		{
			this->label_TVA->Visible = true;
			this->label_marge->Visible = true;
			this->label_remise->Visible = true;
			this->label_demarque->Visible = true;

			this->comboBox_TVA->Visible = true;
			this->comboBox_marge->Visible = true;
			this->comboBox_remise->Visible = true;
			this->comboBox_demarque->Visible = true;
		}
	}

	private: System::Void comboBox_mois_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		mois = comboBox_mois->SelectedIndex;
	}

	private: System::Void valider_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (comboBox_stat->SelectedIndex == 0) //Panier moyen
		{
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->panier_moy();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 1) // Chiffre d'affaire (selon le mois)
		{
			if (comboBox_mois->SelectedIndex != -1)
			{
				this->dataGridView->Refresh();
				this->dataGridView->DataSource = this->stat->chiffre_affaire((mois+1).ToString());
				this->dataGridView->DataMember = "Article";
			}
		}

		else if (comboBox_stat->SelectedIndex == 2) // Produits sous le seuil de reapprovisionnement
		{
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->seuil_appro();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 3) // Montant total des achats pour un client
		{
			if (this->textBox_id->TextLength != 0 && this->textBox_nom->TextLength != 0 && this->textBox_prenom->TextLength != 0)
			{
				this->dataGridView->Refresh();
				this->dataGridView->DataSource = this->stat->montant_total_achat(this->textBox_id->Text ,this->textBox_nom->Text, this->textBox_prenom->Text);
				this->dataGridView->DataMember = "Article";
			}
		}

		else if (comboBox_stat->SelectedIndex == 4) // 10 articles les plus vendu
		{
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->arcticle_plus_vendu();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 5) // 10 articles les moins vendu
		{
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->article_moins_vendu();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 6) // Valeur commerciale du stock
		{
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->val_com_stock();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 7) // Valeur achat du stock
		{	
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->val_achat_stock();
			this->dataGridView->DataMember = "Article";
		}

		else if (comboBox_stat->SelectedIndex == 8) // Simulation
		{
			System::String^ TVA = "0";
			System::String^ marge = "0";
			System::String^ remise = "0";
			System::String^ demarque = "0";

			if (comboBox_TVA->SelectedIndex == 0) { TVA = "0"; }
			else if (comboBox_TVA->SelectedIndex == 1) { TVA = "0.2"; }
			else if (comboBox_TVA->SelectedIndex == 2) { TVA = "0.1"; }
			else if (comboBox_TVA->SelectedIndex == 3) { TVA = "0.055"; }

			if (comboBox_marge->SelectedIndex == 0) { marge = "0"; }
			else if (comboBox_marge->SelectedIndex == 1) { marge = "0.05"; }
			else if (comboBox_marge->SelectedIndex == 2) { marge = "0.1"; }
			else if (comboBox_marge->SelectedIndex == 3) { marge = "0.15"; }

			if (comboBox_remise->SelectedIndex == 0) { remise = "0"; }
			else if (comboBox_remise->SelectedIndex == 1) { remise = "0.05"; }
			else if (comboBox_remise->SelectedIndex == 2) { remise = "0.06"; }

			if (comboBox_demarque->SelectedIndex == 0) { demarque = "0"; }
			else if (comboBox_demarque->SelectedIndex == 1) { demarque = "0.02"; }
			else if (comboBox_demarque->SelectedIndex == 2) { demarque = "0.03"; }
			else if (comboBox_demarque->SelectedIndex == 3) { demarque = "0.05"; }

			this->dataGridView->Refresh();
			this->dataGridView->DataSource = this->stat->simulation(TVA, marge, remise, demarque);
			this->dataGridView->DataMember = "Article";		
		}
	}
};
}