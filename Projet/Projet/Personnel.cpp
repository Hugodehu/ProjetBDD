#include "pch.h"
#include "Personnel.h"
#include <iostream>

System::String^ NS_BDD::Personnel::Afficher() {
    return "USE DB_test; SELECT id_personnel, nom, prenom, date_embauche, superieur FROM Personnel WHERE nom = '" + this->getNom() + "' AND prenom = '" + this->getPrenom() + "';";
}

System::String^ NS_BDD::Personnel::Modifier() {
    return "USE DB_test; UPDATE Personnel SET Personnel.nom = 'henni', Personnel.prenom = 'mohammed' WHERE (Personnel.id_personnel = '" + this->getIdpersonnel() + "');";
}

System::String^ NS_BDD::Personnel::Ajouter() {
    return "USE DB_test; INSERT INTO Personnel(Personnel.nom, Personnel.prenom, Personnel.date_embauche, Personnel.superieur) VALUES ('" + this->getNom() + "', '" + this->getPrenom + "', '" + this->getDate + "', '" + this->getSuperieur + "');";
}
void NS_BDD::Authentification::setId(int Id) { this->Id = Id; }
void NS_BDD::Authentification::setEmail(System::String^ email) { this->email = email; }
void NS_BDD::Authentification::setMdp(System::String^ mdp) { this->mdp = mdp; }


int NS_BDD::Authentification::getId(void) { return this->Id; }
System::String^ NS_BDD::Authentification::getEmail(void) { return this->email; }
System::String^ NS_BDD::Authentification::getMdp(void) { return this->mdp; }