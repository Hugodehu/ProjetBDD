#include "pch.h"
#include "statistiques.h"

void NS_BDD::statistique::set_mois(System::String^ mois) { this->mois = mois; }
void NS_BDD::statistique::set_nom(System::String^ nom) { this->nom = nom; }
void NS_BDD::statistique::set_prenom(System::String^ prenom) { this->prenom = prenom; }
void NS_BDD::statistique::set_id(System::String^ id) { this->prenom = id; }
void NS_BDD::statistique::set_TVA(System::String^ tva) { this->TVA = tva; }
void NS_BDD::statistique::set_marge(System::String^ marge) { this->marge = marge; }
void NS_BDD::statistique::set_remise(System::String^ remise) { this->remise = remise; }
void NS_BDD::statistique::set_demarque(System::String^ demarque) { this->demarque = demarque; }

System::String^ NS_BDD::statistique::get_mois() { return this->mois; }
System::String^ NS_BDD::statistique::get_nom() { return this->nom; }
System::String^ NS_BDD::statistique::get_prenom() { return this->prenom; }
System::String^ NS_BDD::statistique::get_id() { return this->id; }
System::String^ NS_BDD::statistique::get_TVA() { return this->TVA; }
System::String^ NS_BDD::statistique::get_marge() { return this->marge; }
System::String^ NS_BDD::statistique::get_remise() { return this->remise; }
System::String^ NS_BDD::statistique::get_demarque() { return this->demarque; }

System::String^ NS_BDD::statistique::panier_moy() {
	return "SELECT SUM(prix_TTC-remise)/max(id_commande) AS Panier_moyen FROM Commande;";
}

System::String^ NS_BDD::statistique::chiffre_affaire() {
	return "SELECT SUM(Quantite * solde) AS Chiffre_affaire_sur_un_mois FROM Paiement, Contenir WHERE(month(date_paiement) =" + this->get_mois() + ")";
}

System::String^ NS_BDD::statistique::seuil_appro() {
	return "SELECT Article.nom AS A_reapprovisionner FROM Article WHERE (Article.quantite_stock < Article.seuil_reapprovisionnement)";
}

System::String^ NS_BDD::statistique::montant_total_achat() {
	return "SELECT Client.nom, Client.prenom, SUM(Commande.prix_final) AS Montant_des_achats FROM Client FULL JOIN Commande ON Client.id_client = Commande.id_client WHERE (Client.id_client = " + this->get_id() + " AND Client.nom = '" + this->get_nom() + "' AND Client.prenom = '" + this->get_prenom() + "') GROUP BY Client.id_client, Client.nom, Client.prenom";
}

System::String^ NS_BDD::statistique::arcticle_plus_vendu() {
	return "SELECT TOP 10 Article.nom Articles_les_plus_vendus, SUM(Quantite) Qte FROM Article INNER JOIN Contenir ON Article.id_article = Contenir.id_article GROUP BY Article.nom ORDER BY Qte DESC";
}

System::String^ NS_BDD::statistique::article_moins_vendu() {
	return "SELECT TOP 10 Article.nom Articles_les_moins_vendus, SUM(Quantite) Qte FROM Article INNER JOIN Contenir ON Article.id_article = Contenir.id_article GROUP BY Article.nom ORDER BY Qte ASC";
}

System::String^ NS_BDD::statistique::val_com_stock() {
	return "SELECT SUM(quantite_stock * (((TVA*prix_HT)/100)+prix_HT)) AS Valeur_commerciale_du_stock FROM Article";
}

System::String^ NS_BDD::statistique::val_achat_stock() {
	return "SELECT SUM(quantite_stock * prix_HT) AS Valeur_achat_du_stock FROM Article";
}

System::String^ NS_BDD::statistique::simulation() {
	return "SELECT SUM(prix_ht) - SUM(prix_ht)*" + this->get_TVA() + " + SUM(prix_ht)*" + this->get_marge() + " - SUM(prix_ht)*" + this->get_remise() + " - SUM(prix_ht)*" + this->get_demarque() + "AS Simulation FROM Article;";
}