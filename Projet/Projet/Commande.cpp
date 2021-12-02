#include "Commande.h"
#include "pch.h"

void NS_BDD::Commande::set_id_commande(System::String^ id_commande) { this->id_commande = id_commande; }
void NS_BDD::Commande::set_reference(System::String^ reference) { this->reference = reference; }
void NS_BDD::Commande::set_date_livraison(System::String^ date_livraison) { this->date_livraison = date_livraison; }
void NS_BDD::Commande::set_date_emission(System::String^ date_emission) { this->date_emission = date_emission; }
void NS_BDD::Commande::set_prix_HT(System::String^ prix_HT) { this->prix_HT = prix_HT; }
void NS_BDD::Commande::set_prix_TTC(System::String^ prix_TTC) { this->prix_TTC = prix_TTC; }
void NS_BDD::Commande::set_TVA(System::String^ TVA) { this->TVA = TVA; }
void NS_BDD::Commande::set_remise(System::String^ remise) { this->remise = remise; }
void NS_BDD::Commande::set_prix_final(System::String^ prix_final) { this->prix_final = prix_final; }
void NS_BDD::Commande::set_quantité(System::String^ quantite) { this->quantite = quantite; }

System::String^ NS_BDD::Commande::get_id_commande(void) { return this->id_commande; }
System::String^ NS_BDD::Commande::get_reference(void) { return this->reference; }
System::String^ NS_BDD::Commande::get_date_livraison(void) { return this->date_livraison; }
System::String^ NS_BDD::Commande::set_date_emission(void) { return this->date_emission; }
System::String^ NS_BDD::Commande::get_prix_HT(void) { return this->prix_HT; }
System::String^ NS_BDD::Commande::get_prix_TTC(void) { return this->prix_TTC; }
System::String^ NS_BDD::Commande::get_TVA(void) { return this->TVA; }
System::String^ NS_BDD::Commande::get_remise(void) { return this->remise; }
System::String^ NS_BDD::Commande::get_prix_final(void) { return this->prix_final; }
System::String^ NS_BDD::Commande::get_quantite(void) { return this->quantite; }

System::String^ NS_BDD::Commande::Ajouter(void)
{
    return "";
}

System::String^ NS_BDD::Commande::Afficher(void)
{
    return "SELECT Client.nom, Client.prenom, Commande.reference, Commande.date_livraison, Commande.date_emission, Article.nom as Nom_Article, Contenir.Quantite, Commande.prix_HT, Commande.prix_TTC, Commande.TVA, Commande.remise, Commande.prix_final FROM Commande INNER JOIN Contenir ON Commande.id_commande = Contenir.id_commande INNER JOIN Article ON Contenir.id_article = Article.id_article INNER JOIN Client ON Commande.id_client = Client.id_client WHERE (Commande.reference = '" + this->get_reference() + "')";
};

System::String^ NS_BDD::Commande::Modifier(void)
{
    return "";
};

System::String^ NS_BDD::Commande::Supprimer(void) {
    return "";
};