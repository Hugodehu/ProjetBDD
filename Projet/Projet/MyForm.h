#pragma once
#include "Choix.h"
#include "BDDload.h"
#include "Auth.h"
#include "BDDservice.h"
#include <string>
#include <iostream>
namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button_auth;
	private: System::Windows::Forms::TextBox^ txt_email;
	private: System::Windows::Forms::TextBox^ txt_mdp;

	private: System::Windows::Forms::PictureBox^ img_lock;
	private: System::Windows::Forms::Label^ label_email;
	private: System::Windows::Forms::Label^ label_mdp;
	private: NS_BDDservice::BDDservice^ authentification;
	private: System::Data::DataSet^ result;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_auth = (gcnew System::Windows::Forms::Button());
			this->txt_email = (gcnew System::Windows::Forms::TextBox());
			this->txt_mdp = (gcnew System::Windows::Forms::TextBox());
			this->img_lock = (gcnew System::Windows::Forms::PictureBox());
			this->label_email = (gcnew System::Windows::Forms::Label());
			this->label_mdp = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_lock))->BeginInit();
			this->SuspendLayout();
			// 
			// button_auth
			// 
			this->button_auth->Location = System::Drawing::Point(218, 166);
			this->button_auth->Name = L"button_auth";
			this->button_auth->Size = System::Drawing::Size(75, 23);
			this->button_auth->TabIndex = 0;
			this->button_auth->Text = L"Connexion";
			this->button_auth->UseVisualStyleBackColor = true;
			this->button_auth->Click += gcnew System::EventHandler(this, &MyForm::button_auth_Click);
			// 
			// txt_email
			// 
			this->txt_email->Location = System::Drawing::Point(143, 97);
			this->txt_email->Name = L"txt_email";
			this->txt_email->Size = System::Drawing::Size(150, 20);
			this->txt_email->TabIndex = 1;
			// 
			// txt_mdp
			// 
			this->txt_mdp->Location = System::Drawing::Point(143, 138);
			this->txt_mdp->Name = L"txt_mdp";
			this->txt_mdp->Size = System::Drawing::Size(150, 20);
			this->txt_mdp->TabIndex = 2;
			this->txt_mdp->UseSystemPasswordChar = true;
			// 
			// img_lock
			// 
			this->img_lock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_lock.Image")));
			this->img_lock->Location = System::Drawing::Point(143, 12);
			this->img_lock->Name = L"img_lock";
			this->img_lock->Size = System::Drawing::Size(150, 65);
			this->img_lock->TabIndex = 3;
			this->img_lock->TabStop = false;
			// 
			// label_email
			// 
			this->label_email->AutoSize = true;
			this->label_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label_email->Location = System::Drawing::Point(95, 97);
			this->label_email->Name = L"label_email";
			this->label_email->Size = System::Drawing::Size(42, 17);
			this->label_email->TabIndex = 4;
			this->label_email->Text = L"Email";
			// 
			// label_mdp
			// 
			this->label_mdp->AutoSize = true;
			this->label_mdp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label_mdp->Location = System::Drawing::Point(44, 141);
			this->label_mdp->Name = L"label_mdp";
			this->label_mdp->Size = System::Drawing::Size(93, 17);
			this->label_mdp->TabIndex = 5;
			this->label_mdp->Text = L"Mot de passe";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 201);
			this->Controls->Add(this->label_mdp);
			this->Controls->Add(this->label_email);
			this->Controls->Add(this->img_lock);
			this->Controls->Add(this->txt_mdp);
			this->Controls->Add(this->txt_email);
			this->Controls->Add(this->button_auth);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Authentification";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_lock))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void button_auth_Click(System::Object^ sender, System::EventArgs^ e) {
		authentification = gcnew NS_BDDservice::BDDservice;
		result = gcnew Data::DataSet;
		this->result = this->authentification->CheckAuthentification(this->txt_email->Text, this->txt_mdp->Text);
		if (this->result->Tables[0]->Select()[0][0]->ToString() == "True") //Merci Tristan <3
		{ 
			this->Hide();
			Projet::Choix form;
			form.ShowDialog();
			this->Show();
		}
		else 
		{
			MessageBox::Show("Email ou mot de passe incorrect", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	
};
}
