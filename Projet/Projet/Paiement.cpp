#include "Paiement.h"
#include "pch.h"

void NS_BDD::Paiement::set_id_paiement(System::String^ id_paiement) { this->id_paiement = id_paiement; }
void NS_BDD::Paiement::set_solde(System::String^ solde) { this->solde = solde; }
void NS_BDD::Paiement::set_date_emission(System::String^ date_emission) { this->date_emission = date_emission; }
void NS_BDD::Paiement::set_date_paiement(System::String^ date_paiement) { this->date_paiement = date_paiement ; }
void NS_BDD::Paiement::set_moyen(System::String^ moyen) { this->moyen = moyen; }

System::String^ NS_BDD::Paiement::get_id_paiement(void) { return this->id_paiement; }
System::String^ NS_BDD::Paiement::get_solde(void) { return this->solde; }
System::String^ NS_BDD::Paiement::get_date_emission(void) { return this->date_emission; }
System::String^ NS_BDD::Paiement::get_date_paiement(void) { return this->date_paiement; }
System::String^ NS_BDD::Paiement::get_moyen(void) { return this->moyen; }

System::String^ NS_BDD::Paiement::Afficher(void)
{
    return "";
}

System::String^ NS_BDD::Paiement::Ajouter(System::String^ nb_paiement, System::String^ reference)
{
    return "INSERT INTO Paiement Paiement (solde, date_emission, date_paiement, moyen, id_commande) select Commande.prix_final/"+nb_paiement+", Commande.date_emission, " + this->get_date_paiement() + ", '" + this->get_moyen() + "', Commande.id_commande from Commande where (Commande.reference = '" + reference + "')";
}

System::String^ NS_BDD::Paiement::Modifier(void)
{
    return "USE BDD_Projet_POO; UPDATE Paiement (solde, date_emission, date_paiement, moyen) VALUES ('" + this->get_solde() + "','" + this->get_date_emission() + "','" + this->get_moyen() + "');";
}

System::String^ NS_BDD::Paiement::Supprimer(void)
{
    return "USE BDD_Projet_POO; DELETE FROM Paiement WHERE i";
}


