#include "Client.h"
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

System::String^ NS_BDD::Client::Ajouter(System::String^ rue_fact, System::String^ ville_fact, System::String^ rue_livr, System::String^ ville_livr )
{
	return "INSERT INTO Client (nom, prenom, date_naissance, date_premiere_commande) Values('" + this->get_nom() + "', '" + this->get_prenom() + "', '" + this->get_date_naissance() + "', '" + this->get_date_premiere_commande() + "') INSERT INTO Adresse(rue, id_ville, id_client) select '" + rue_fact + "', Ville.id_ville, Client.id_client FROM Ville, Client WHERE Ville.nom = '" + ville_fact + "' and Client.nom = '" + this->get_nom() + "' and Client.prenom = '" + this->get_prenom() + "' INSERT INTO Adresse(rue, id_ville, id_client_Livrer) select '" + rue_livr + "', Ville.id_ville, Client.id_client FROM Ville, Client WHERE Ville.nom = '" + ville_livr + "' and Client.nom = '" + this->get_nom() + "' and Client.prenom = '" + this->get_prenom() + "'; ";
	//ICI
}

System::String^ NS_BDD::Client::Afficher()
{
	return "SELECT Client.id_client, Client.nom, Client.prenom, Ville.nom Nom_de_la_ville, Ville.code_postal, Adresse.rue FROM Client INNER JOIN Adresse ON Adresse.id_client = Client.id_client OR Adresse.id_client_Livrer = Client.id_client INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE ( (Adresse.id_client = Client.id_client AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "') OR Adresse.id_client_Livrer = Client.id_client AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "'); ";
	//ICI
}

System::String^ NS_BDD::Client::Modifier(System::String^ rue, System::String^ ville, System::String^ code_poste)
{
	return "UPDATE Adresse SET Adresse.rue = '" + rue + "', Adresse.id_ville = Ville.id_ville FROM Adresse INNER JOIN Client ON Client.id_client = Adresse.id_client INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE Adresse.id_client = Client.id_client AND Client.id_Client = '" + this->get_id_client() + "' AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "' AND Ville.nom = '" + ville + "' AND Ville.code_postal = '" + code_poste + "' UPDATE Client SET Client.nom = '" + this->get_nom() + "', Client.prenom = '" + this->get_prenom() + "', Client.date_naissance = '" + this->get_date_naissance() + "', Client.date_premiere_commande = '" + this->get_date_premiere_commande() + "' FROM CLient INNER JOIN Adresse ON Adresse.id_client = Client.id_client OR Adresse.id_client_Livrer = Client.id_client INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE Adresse.id_client = Client.id_client AND Client.id_Client = '" + this->get_id_client() + "' AND Client.nom = '" + this->get_nom() + "' AND prenom = '" + this->get_prenom() + "' AND Ville.nom = '" + ville + "' AND Ville.code_postal = '" + code_poste + "'";
	//ICI
}

System::String^ NS_BDD::Client::Supprimer()
{
	return "DELETE FROM Adresse WHERE Adresse.id_client IN(SELECT Client.id_client FROM Client WHERE Client.id_client = '" + this->get_id_client() + "' AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "') OR id_client_Livrer IN(SELECT Client.id_client FROM Client WHERE Client.id_client = '" + this->get_id_client() + "' AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "') DELETE FROM Client WHERE Client.id_client IN(SELECT  Client.id_client FROM Client WHERE Client.id_client = '" + this->get_id_client() + "'  AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "')";
	//ICI
}
