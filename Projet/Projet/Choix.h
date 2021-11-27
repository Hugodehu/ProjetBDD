#pragma once
#include "pch.h"
#include "Adresse.h"
#include "BDDload.h"
#include "Commande.h"
#include "Client.h"
namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Choix : public System::Windows::Forms::Form
	{
	public:
		Choix(void)
		{
			InitializeComponent();
		}

	protected:

		~Choix()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ Ajouter;
	private: System::Windows::Forms::Button^ Modifier;
	private: System::Windows::Forms::Button^ Supprimer;
	private: System::Windows::Forms::Button^ Afficher;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: NS_BDDservice::BDDservice^ authentification;
	private: System::Data::DataSet^ result;
	private: bool superieur;
	private: short valider;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->Ajouter = (gcnew System::Windows::Forms::Button());
			   this->Modifier = (gcnew System::Windows::Forms::Button());
			   this->Supprimer = (gcnew System::Windows::Forms::Button());
			   this->Afficher = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->AllowDrop = true;
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				   L"Personnel", L"Clients", L"Commandes", L"Stock",
					   L"Statistiques"
			   });
			   this->comboBox1->Location = System::Drawing::Point(12, 174);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(243, 27);
			   this->comboBox1->TabIndex = 0;
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Choix::comboBox1_SelectedIndexChanged);
			   // 
			   // Ajouter
			   // 
			   this->Ajouter->Location = System::Drawing::Point(372, 228);
			   this->Ajouter->Name = L"Ajouter";
			   this->Ajouter->Size = System::Drawing::Size(316, 91);
			   this->Ajouter->TabIndex = 1;
			   this->Ajouter->Text = L"Ajouter";
			   this->Ajouter->UseVisualStyleBackColor = true;
			   this->Ajouter->Visible = false;
			   // 
			   // Modifier
			   // 
			   this->Modifier->Location = System::Drawing::Point(12, 341);
			   this->Modifier->Name = L"Modifier";
			   this->Modifier->Size = System::Drawing::Size(316, 86);
			   this->Modifier->TabIndex = 2;
			   this->Modifier->Text = L"Modifier";
			   this->Modifier->UseVisualStyleBackColor = true;
			   this->Modifier->Visible = false;
			   // 
			   // Supprimer
			   // 
			   this->Supprimer->Location = System::Drawing::Point(372, 341);
			   this->Supprimer->Name = L"Supprimer";
			   this->Supprimer->Size = System::Drawing::Size(316, 86);
			   this->Supprimer->TabIndex = 3;
			   this->Supprimer->Text = L"Supprimer";
			   this->Supprimer->UseVisualStyleBackColor = true;
			   this->Supprimer->Visible = false;
			   // 
			   // Afficher
			   // 
			   this->Afficher->Location = System::Drawing::Point(12, 228);
			   this->Afficher->Name = L"Afficher";
			   this->Afficher->Size = System::Drawing::Size(316, 91);
			   this->Afficher->TabIndex = 4;
			   this->Afficher->Text = L"Afficher";
			   this->Afficher->UseVisualStyleBackColor = true;
			   this->Afficher->Visible = false;
			   this->Afficher->Click += gcnew System::EventHandler(this, &Choix::Afficher_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(12, 12);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->Size = System::Drawing::Size(676, 156);
			   this->dataGridView1->TabIndex = 5;
			   // 
			   // Choix
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(700, 437);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->Afficher);
			   this->Controls->Add(this->Supprimer);
			   this->Controls->Add(this->Modifier);
			   this->Controls->Add(this->Ajouter);
			   this->Controls->Add(this->comboBox1);
			   this->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Choix";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"BDD service";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Choix::MyForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &Choix::Choix_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void Choix_Load(System::Object^ sender, System::EventArgs^ e) {
		authentification = gcnew NS_BDDservice::BDDservice;
		result = gcnew Data::DataSet;
		this->result = this->authentification->CheckSup();
		bool superieur;
		if (this->result->Tables[0]->Select()[0][0]->ToString() == "1") {
			superieur = 1;
		}
		else {
			superieur = 0;
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		e->Cancel = MessageBox::Show("Vous, êtes sûr le point de quitter la page, êtes-vous sûr de ce choix ?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes;
	}
	private: System::Void Validation_Click(System::Object^ sender, System::EventArgs^ e) {
	};
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedIndex == 0) {
			if (superieur == 0) {
				this->Ajouter->Visible = true;
				this->Supprimer->Visible = true;
				this->Modifier->Visible = true;
				this->Afficher->Visible = true;
			}
			else {
				MessageBox::Show("Vous n'avez pas les droits pour effectuer des modifications sur le personnel", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			}
		}
		else if (comboBox1->SelectedIndex == 1) { //Personnel
			this->Ajouter->Visible = true;
			this->Supprimer->Visible = true;
			this->Modifier->Visible = true;
			this->Afficher->Visible = true;
		}
		else if (comboBox1->SelectedIndex == 2) {
			this->Ajouter->Visible = true;
			this->Supprimer->Visible = true;
			this->Modifier->Visible = true;
			this->Afficher->Visible = true;
		}
		else if (comboBox1->SelectedIndex == 3) {
			this->Ajouter->Visible = true;
			this->Supprimer->Visible = true;
			this->Modifier->Visible = true;
			this->Afficher->Visible = true;
		}
		else if (comboBox1->SelectedIndex == 4) {
			this->Ajouter->Visible = false;
			this->Supprimer->Visible = false;
			this->Modifier->Visible = false;
			this->Afficher->Visible = false;
		}
	}
	private: System::Void Afficher_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}