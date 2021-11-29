#include "pch.h"
#include "Client.h"

void NS_BDD::Client::set_id_client(System::String^ id_client) {
	this->id_client = id_client;
};

void NS_BDD::Client::set_nom(System::String^ nom) {
	this->nom = nom;
};

void NS_BDD::Client::set_prenom(System::String^ prenom) {
	this->prenom = prenom;
};

void NS_BDD::Client::set_date_naissance(System::String^ date_naissance) {
	this->date_naissance = date_naissance;
};

void NS_BDD::Client::set_date_premiere_commande(System::String^ date_premiere_commande) {
	this->date_premiere_commande = date_premiere_commande;
};

System::String^ NS_BDD::Client::get_id_client(void) {
	return this->id_client;
};

System::String^ NS_BDD::Client::get_nom(void) {
	return this->nom;
};

System::String^ NS_BDD::Client::get_prenom(void) {
	return this->prenom;
};

System::String^ NS_BDD::Client::get_date_naissance(void) {
	return this->date_naissance;
};

System::String^ NS_BDD::Client::get_date_premiere_commande(void) {
	return this->date_premiere_commande;
};

System::String^ NS_BDD::Client::Ajouter(void) {

};

System::String^ NS_BDD::Client::Afficher(void){

};

System::String^ NS_BDD::Client::Modifier(void) {

};

System::String^ NS_BDD::Client::Supprimer(void) {

};
