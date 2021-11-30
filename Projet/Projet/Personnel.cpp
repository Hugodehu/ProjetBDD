#include "Personnel.h"
#include "pch.h"
#include <iostream>

void NS_BDD::Personnel::set_id_personnel(System::String^ Id_personnel) { this->id_personnel = Id_personnel; }
void NS_BDD::Personnel::set_id_superieur(System::String^ id_sup) {this->id_sup = id_sup;}
void NS_BDD::Personnel::set_prenom(System::String^ prenom) { this->prenom = prenom; }
void NS_BDD::Personnel::set_nom(System::String^ nom) { this->nom = nom; }
void NS_BDD::Personnel::set_superieur(System::String^ superieur) { this->superieur = superieur; }
void NS_BDD::Personnel::set_date_embauche(System::String^ date) { this->date_embauche = date; }
//void NS_BDD::Personnel::set_test(System::Data::DataSet^ test) { this->test = test; }

System::String^ NS_BDD::Personnel::get_id_personnel() { return this->id_personnel; }
System::String^ NS_BDD::Personnel::get_id_sup() { return this->id_sup; }
System::String^ NS_BDD::Personnel::get_nom() { return this->nom; }
System::String^ NS_BDD::Personnel::get_prenom() { return this->prenom; }
System::String^ NS_BDD::Personnel::get_superieur() { return this->superieur; }
System::String^ NS_BDD::Personnel::get_date_embauche() { return this->date_embauche; }

System::String^ NS_BDD::Personnel::Afficher() {
    return "";//USE DB_test; SELECT id_personnel, nom, prenom, date_embauche, superieur FROM Personnel WHERE nom = '" + this->get_nom() + "' AND prenom = '" + this->get_prenom() + "';";
}

System::String^ NS_BDD::Personnel::Modifier() {
    return "USE DB_test; UPDATE Personnel SET Personnel.nom = 'henni', Personnel.prenom = 'mohammed' WHERE (Personnel.id_personnel = '" + this->get_id_personnel() + "');";
}

System::String^ NS_BDD::Personnel::Ajouter() {
    return "USE DB_test; INSERT INTO Personnel(Personnel.nom, Personnel.prenom, Personnel.date_embauche, Personnel.superieur) VALUES ('" + this->get_nom() + "', '" + this->get_prenom() + "', '" + this->get_date_embauche() + "', '" + this->get_superieur() + "');";
}

System::String^ NS_BDD::Personnel::Supprimer() {
    return "";
}