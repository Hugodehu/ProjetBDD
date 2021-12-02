#include "pch.h"
#include "Adresse.h"


void NS_BDD::Adresse::set_id_adresse(System::String^ id_adresse) { this->id_adresse = id_adresse; }
void NS_BDD::Adresse::set_rue(System::String^ rue) { this->rue = rue; }

System::String^ NS_BDD::Adresse::get_id_adresse(void) { return this->id_adresse; }
System::String^ NS_BDD::Adresse::get_rue(void) { return this->rue; }

System::String^ NS_BDD::Adresse::Ajouter(System::String^ nomVille)
{
    return "INSERT INTO Adresse(rue, id_ville) Select '"+ this->get_rue() + "', Ville.id_ville FROM Ville WHERE nom = '" + nomVille +"'; ";
}

System::String^ NS_BDD::Adresse::Afficher(System::String^ Id, System::String^  nom, System::String^ prenom)
{
    return "SELECT id_personnel, Personnel.nom, prenom, Ville.nom Nom_de_la_ville, Ville.code_postal, Adresse.rue, date_embauche, superieur FROM Personnel INNER JOIN Adresse ON Adresse.id_adresse = Personnel.id_adresse INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE(Adresse.id_adresse = Personnel.id_adresse AND Personnel.id_personnel = '" + Id + "' AND Personnel.nom = '" + nom + "' AND Personnal.prenom = '" + prenom + "');";
}

System::String^ NS_BDD::Adresse::Modifier(System::String^ id_perso, System::String^ nomPerso, System::String^ prenomPerso, System::String^ nomVille, System::String^ codeposteVille)
{
    return "UPDATE Adresse SET Adresse.rue = '"+ this->get_rue() +"',Adresse.id_ville = Ville.id_ville FROM Adresse INNER JOIN Personnel ON Personnel.id_adresse = Adresse.id_ville INNER JOIN Ville ON Ville.id_ville = Adresse.id_ville WHERE Adresse.id_adresse = Personnel.id_adresse AND Personnel.id_personnel = '" + id_perso + "' AND Personnel.nom = '" + nomPerso + "' AND Personnel.prenom = '" + prenomPerso + "' AND Ville.nom = '" + nomVille + "' AND Ville.code_postal = '" + codeposteVille + "'";
}

System::String^ NS_BDD::Adresse::Supprimer(System::String^ id, System::String^ nom, System::String^ prenom)
{
    return "DELETE FROM Adresse WHERE id_adresse IN(SELECT DeletePersonnel.id_adresse FROM DeletePersonnel WHERE DeletePersonnel.Id = "+ id +" AND DeletePersonnel.nom = '"+ nom +"' AND DeletePersonnel.prenom = '"+ prenom +"'); DROP TABLE DeletePersonnel";
}
