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
System::String^ NS_BDD::Commande::get_date_emission(void) { return this->date_emission; }
System::String^ NS_BDD::Commande::get_prix_HT(void) { return this->prix_HT; }
System::String^ NS_BDD::Commande::get_prix_TTC(void) { return this->prix_TTC; }
System::String^ NS_BDD::Commande::get_TVA(void) { return this->TVA; }
System::String^ NS_BDD::Commande::get_remise(void) { return this->remise; }
System::String^ NS_BDD::Commande::get_prix_final(void) { return this->prix_final; }
System::String^ NS_BDD::Commande::get_quantite(void) { return this->quantite; }

System::String^ NS_BDD::Commande::Ajouter2(System::String^ nomArticle, System::String^ nature, System::String^ couleur, System::String^ solde, System::String^ datePaiement, System::String^ moyen) {
    return "insert into Contenir(id_commande, id_article, Quantite) select Commande.id_commande, Article.id_article, '" + this->get_quantite() + "' from Commande, Article where(Commande.reference = '" + this->get_reference() + "' and Article.nom = '" + nomArticle + "' and Article.nature = '" + nature + "' and Article.couleur = '" + couleur + "') update Commande set prix_HT = (select(Contenir.Quantite * Article.prix_HT) from Contenir, Article, Commande where(Contenir.id_article = Article.id_article and Contenir.id_commande = Commande.id_commande and Commande.reference = '" + this->get_reference() + "' and Article.nom = '" + nomArticle + "' and Article.nature = '" + nature + "' and Article.couleur = '" + couleur + "')) where Commande.reference = '"+this->get_reference()+"' update Commande set Prix_TTC = (select(Commande.prix_HT + Commande.prix_HT * Article.TVA) from Commande, Article, Contenir where (Contenir.id_commande = Commande.id_commande and Contenir.id_article = Article.id_article and Commande.reference = '" + this->get_reference() + "' and Article.nom = '" + nomArticle + "' and Article.nature = '" + nature + "' and Article.couleur = '" + couleur + "')) where Commande.reference = '" + this->get_reference() + "' update Commande set Commande.TVA = (select Article.TVA from Article, Contenir, Commande where (Contenir.id_commande = Commande.id_commande and Contenir.id_article = Article.id_article and Commande.reference = '" + this->get_reference() + "' and Article.nom = '" + nomArticle + "' and Article.nature = '" + nature + "' and Article.couleur = '" + couleur + "')) where Commande.reference = '" + this->get_reference() + "' update Commande set prix_final = (select(prix_TTC + (prix_TTC * remise) / 100) from Commande where Commande.reference = '" + this->get_reference() + "') where Commande.reference = '" + this->get_reference() + "' Insert into Paiement(solde, date_emission, date_paiement, moyen, id_commande) select Commande.prix_final, Commande.date_emission, '" + datePaiement + "', '" + moyen + "', Commande.id_commande from Commande where(Commande.reference = '" + this->get_reference() + "')";

}
System::String^ NS_BDD::Commande::Ajouter(System::String^ nom, System::String^ prenom, System::String^ idClient )
{
    return "Insert into Commande (reference, date_livraison, date_emission, prix_HT, prix_TTC, TVA, remise, prix_final,  id_client) select '0', '" + this->get_date_livraison() + "', '" + this->get_date_emission() + "', '0', '0', '" + this->get_TVA() + "', '" + this->get_remise() + "', '0', Client.id_client from Client where(Client.nom = '" + nom + "' and Client.prenom = '" + prenom + "' and Client.id_client = '" + idClient + "')";
}

System::String^ NS_BDD::Commande::Afficher(void)
{
    return "SELECT Client.nom, Client.prenom, Commande.reference, Commande.date_livraison, Commande.date_emission, Article.nom as Nom_Article, Contenir.Quantite, Commande.prix_HT, Commande.prix_TTC, Commande.TVA, Commande.remise, Commande.prix_final FROM Commande INNER JOIN Contenir ON Commande.id_commande = Contenir.id_commande INNER JOIN Article ON Contenir.id_article = Article.id_article INNER JOIN Client ON Commande.id_client = Client.id_client WHERE (Commande.reference = '" + this->get_reference() + "');";
};

System::String^ NS_BDD::Commande::Modifier(void)
{
    return "";
};

System::String^ NS_BDD::Commande::Supprimer(void) {
    return "DELETE FROM Contenir WHERE Contenir.id_commande IN(SELECT Commande.id_commande FROM Commande WHERE Commande.reference = '" + this->get_reference() + "') DELETE FROM Paiement WHERE Paiement.id_commande IN(SELECT Commande.id_commande FROM Commande WHERE Commande.reference = '" + this->get_reference() + "') DELETE FROM Commande WHERE(Commande.reference = '" + this->get_reference() + "'); ";
};