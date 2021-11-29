#include "pch.h"
#include "Commande.h"

void NS_BDD::Commande::set_id_commande(System::String^ id_commande) { this->id_commande = id_commande; };
void NS_BDD::Commande::set_reference(System::String^ reference) { this->reference = reference; };
void NS_BDD::Commande::set_date_livraison(System::String^ date_livraison) { this->date_livraison = date_livraison; };
void NS_BDD::Commande::set_date_emission(System::String^ date_emission) { this->date_emission = date_emission; };
void NS_BDD::Commande::set_prix_HT(float^ prix_HT) { this->prix_HT = prix_HT; };
void NS_BDD::Commande::set_prix_TTC(float^ prix_TTC) { this->prix_TTC = prix_TTC; };
void NS_BDD::Commande::set_TVA(float^ TVA) { this->TVA = TVA; };
void NS_BDD::Commande::set_remise(float^ remise) { this->remise = remise; };
void NS_BDD::Commande::set_prix_final(float^ prix_final) { this->prix_final = prix_final; };

System::String^ NS_BDD::Commande::get_id_commande(void) { return this->id_commande; };
System::String^ NS_BDD::Commande::get_reference(void) { return this->reference; };
System::String^ NS_BDD::Commande::get_date_livraison(void) { return this->date_livraison; };
System::String^ NS_BDD::Commande::set_date_emission(void) { return this->date_emission; };
float^ NS_BDD::Commande::get_prix_HT(void) { return this->prix_HT; };
float^ NS_BDD::Commande::get_prix_TTC(void) { return this->prix_TTC; };
float^ NS_BDD::Commande::get_TVA(void) { return this->TVA; };
float^ NS_BDD::Commande::get_remise(void) { return this->remise; };
float^ NS_BDD::Commande::get_prix_final(void) { return prix_final; };

System::String^ NS_BDD::Commande::Ajouter(void) {

};
System::String^ NS_BDD::Commande::Afficher(void) {

};

System::String^ NS_BDD::Commande::Modifier(void) {

};

System::String^ NS_BDD::Commande::Supprimer(void) {

};