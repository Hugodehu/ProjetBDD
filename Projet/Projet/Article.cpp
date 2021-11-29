#include "pch.h"
#include "Article.h"


void NS_BDD::Article::set_id_article(System::String^ id_article) {
	this->id_article = id_article;
};
void NS_BDD::Article::set_nom(System::String^ nom) {
	this->nom = nom;
};
void NS_BDD::Article::set_nature(System::String^ nature) {
	this->nature = nature;
};
void NS_BDD::Article::set_prix_HT(float^ prix_HT) {
	this->prix_HT = prix_HT;
};
void NS_BDD::Article::set_quantite_stock(int^ quantite) {
	this->quantite_stock = quantite;
};
void NS_BDD::Article::set_TVA(float^ TVA) {
	this->TVA = TVA;
};
void NS_BDD::Article::set_couleur(System::String^ couleur) {
	this->couleur = couleur;
};

System::String^ NS_BDD::Article::get_id_article(void ) {
	return this->id_article;
};
System::String^ NS_BDD::Article::get_nom(void) {
	return this->nom;
};
System::String^ NS_BDD::Article::get_nature(void) {
	return this->nature;
};
float^ NS_BDD::Article::get_prix_HT(void) {
	return this->prix_HT;
};
int^ NS_BDD::Article::get_quantite_stock(void) {
	return this->quantite_stock;
};
float^ NS_BDD::Article::get_TVA(void) {
	return this->TVA;
};
System::String^ NS_BDD::Article::get_couleur(void) {
	return this->couleur;
};

System::String^ NS_BDD::Article::Ajouter(void) {

};
System::String^ NS_BDD::Article::Afficher(void) {

};
System::String^ NS_BDD::Article::Modifier(void) {

};
System::String^ NS_BDD::Article::Supprimer(void) {

};