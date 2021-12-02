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
    return "SELECT Personnel.superieur FROM Personnel INNER JOIN Authentification ON Authentification.id_authentification = Personnel.id_authentification WHERE email = '" + this->getEmail() + "' and mot_de_passe = '" + this->getMdp() + "';";
}

System::String^  NS_BDD::Authentification::Ajouter() {
    return "INSERT INTO Authentification (email, mot_de_passe) VALUES('" +this->getEmail() +"', '" + this->getMdp()+"')";
}

System::String^ NS_BDD::Authentification::Afficher() {
    return "";
}

System::String^ NS_BDD::Authentification::Modifier(System::String^ id_perso, System::String^ nomPerso, System::String^ prenomPerso) {
    return "UPDATE Authentification SET Authentification.email = '" + this->getEmail() + "', mot_de_passe = '" + this->getMdp() + "' FROM Authentification INNER JOIN Personnel ON Personnel.id_authentification = Authentification.id_authentification WHERE Authentification.id_authentification = Personnel.id_authentification AND Personnel.id_personnel = '" + id_perso +"' AND Personnel.nom = '" + nomPerso + "' AND Personnel.prenom = '" + prenomPerso + "'";
}

System::String^ NS_BDD::Authentification::Supprimer(System::String^ id, System::String^ nom, System::String^ prenom) {
    return "DELETE FROM Authentification WHERE id_authentification IN(SELECT DeletePersonnel.id_authentification FROM DeletePersonnel WHERE DeletePersonnel.Id = " + id + " AND DeletePersonnel.nom = '" + nom + "' AND DeletePersonnel.prenom = '" + prenom + "')";
}