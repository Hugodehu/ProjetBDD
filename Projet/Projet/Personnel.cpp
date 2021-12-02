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

System::String^ NS_BDD::Personnel::Afficher(/*System::String^*/) {
    return "SELECT id_personnel, Personnel.nom, prenom, Ville.nom Nom_de_la_ville, Ville.code_postal, Adresse.rue, date_embauche, superieur FROM Personnel INNER JOIN Adresse ON Adresse.id_adresse = Personnel.id_adresse INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE(Adresse.id_adresse = Personnel.id_adresse  AND Personnel.nom = '"+this->get_nom()+"' AND prenom = '"+this->get_prenom()+"');";
}
//test

System::String^ NS_BDD::Personnel::Modifier() {
    return "UPDATE Personnel SET Personnel.nom = '" + this->get_nom() + "', Personnel.prenom = '" + this->get_prenom() + "',  Personnel.date_embauche = '" + this->get_date_embauche() + "', Personnel.superieur = '" + this->get_superieur() + "' FROM Personnel WHERE Personnel.id_personnel = '" + this->get_id_personnel() + "';";
}

System::String^ NS_BDD::Personnel::Ajouter(System::String^ email, System::String^ rue) {

    return "INSERT INTO Personnel (nom, prenom, date_embauche, superieur, id_personnel_Encadre_par, id_adresse, id_authentification) select '" + this->get_nom() + "', '" + this->get_prenom() + "', '" + this->get_date_embauche() + "', '" + this->get_superieur() + "', '" + this->get_id_sup() + "', Adresse.id_adresse, Authentification.id_authentification from Adresse, Authentification where Adresse.rue = '" + rue + "' and Authentification.email = '" + email + "';";
}

System::String^ NS_BDD::Personnel::Supprimer() {
    return "CREATE TABLE dbo.DeletePersonnel(Id int Not NULL primary key, Id_authentification int NOT NULL, Id_adresse int NOT NULL, nom char (30), prenom char(30)) INSERT INTO dbo.DeletePersonnel SELECT Personnel.id_personnel, Personnel.id_authentification, Personnel.id_adresse , Personnel.nom, Personnel.prenom from Personnel WHERE(id_personnel = "+ this->get_id_personnel()+" AND nom = '"+ this->get_nom()+"' AND prenom = '"+this->get_prenom() + "')  DELETE FROM Personnel WHERE id_personnel = (SELECT DeletePersonnel.Id FROM dbo.DeletePersonnel WHERE DeletePersonnel.Id = '" + this->get_id_personnel() + "'  AND DeletePersonnel.nom = '" + this->get_nom() + "' AND DeletePersonnel.prenom = '" + this->get_prenom() + "')";
}