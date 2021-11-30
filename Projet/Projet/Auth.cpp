#include "Auth.h"
#include "pch.h"
#include <iostream>

void NS_BDD::Authentification::setId(System::String^ Id) { this->Id = Id; }
void NS_BDD::Authentification::setEmail(System::String^ email) { this->email = email; }
void NS_BDD::Authentification::setMdp(System::String^ mdp) { this->mdp = mdp; }

System::String^ NS_BDD::Authentification::getId(void) { return this->Id; }
System::String^ NS_BDD::Authentification::getEmail(void) { return this->email; }
System::String^ NS_BDD::Authentification::getMdp(void) { return this->mdp; }

System::String^ NS_BDD::Authentification::Check()
{
    return "Use BDD_Projet_POO; SELECT CASE WHEN EXISTS (SELECT * FROM Authentification WHERE email = '" + this->getEmail() + "' and mot_de_passe = '" + this->getMdp() + "') THEN CAST(1 AS BIT) ELSE CAST(0 AS BIT) END;";
}

System::String^ NS_BDD::Authentification::CheckSupp()
{
    return "SELECT superieur FROM Personnel INNER JOIN Authentification ON Personnel.id_personnel = Authentication.id_authentification WHERE email = '" + this->getEmail() + "' and mot_de_passe = '" + this->getMdp() + "';";
}

System::String^  NS_BDD::Authentification::Ajouter() {
    return "";
}

System::String^ NS_BDD::Authentification::Afficher() {
    return "";
}

System::String^ NS_BDD::Authentification::Modifier() {
    return "";
}

System::String^ NS_BDD::Authentification::Supprimer() {
    return "";
}