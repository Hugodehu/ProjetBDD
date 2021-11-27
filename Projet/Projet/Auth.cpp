#include "pch.h"
#include "Auth.h"
#include <iostream>

System::String^ NS_BDD::Authentification::Check(){
    return "Use BDD_Projet_POO; SELECT CASE WHEN EXISTS (SELECT * FROM Authentification WHERE email = '" + this->getEmail() + "' and mot_de_passe = '" + this->getMdp() + "') THEN CAST(1 AS BIT) ELSE CAST(0 AS BIT) END;";
}
System::String^ NS_BDD::Authentification::CheckSup() {
    return "SELECT Superieur FROM Personnel INNER JOIN auth ON Personnel.id = auth.id WHERE email = '" + this->getEmail() + "' and mot_de_passe = '" + this->getMdp() + "';";
}
void NS_BDD::Authentification::setId(int Id) { this->Id = Id; }
void NS_BDD::Authentification::setEmail(System::String^ email) { this->email = email; }
void NS_BDD::Authentification::setMdp(System::String^ mdp) { this->mdp = mdp; }


int NS_BDD::Authentification::getId(void) { return this->Id; }
System::String^ NS_BDD::Authentification::getEmail(void) { return this->email; }
System::String^ NS_BDD::Authentification::getMdp(void) { return this->mdp; }