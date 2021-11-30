#include "Header.h"
#include "pch.h"

void NS_BDD::Client::set_id_client(System::String^ id_client) { this->id_client = id_client; }
void NS_BDD::Client::set_nom(System::String^ nom) { this->nom = nom; }
void NS_BDD::Client::set_prenom(System::String^ prenom) { this->prenom = prenom; }
void NS_BDD::Client::set_date_naissance(System::String^ date_naissance) { this->date_naissance = date_naissance; }
void NS_BDD::Client::set_date_premiere_commande(System::String^ Premiere_commande) { this->Date_premiere_commande = Premiere_commande; }


System::String^ NS_BDD::Client::get_id_client() { return this->id_client; }
System::String^ NS_BDD::Client::get_nom() { return this->nom; }
System::String^ NS_BDD::Client::get_prenom() { return this->prenom; }
System::String^ NS_BDD::Client::get_date_naissance() { return this->date_naissance;}
System::String^ NS_BDD::Client::get_date_premiere_commande() { return this->Date_premiere_commande; }

System::String^ NS_BDD::Client::Ajouter(void)
{
	return "INSERT INTO";
}

System::String^ NS_BDD::Client::Afficher(void)
{
	return "";
}

System::String^ NS_BDD::Client::Modifier(void)
{
	return "";
}

System::String^ NS_BDD::Client::Supprimer(void)
{
	return "";
}
