#include "BDDservice.h"
#include "pch.h"
#include <iostream>
#include <string>

//
//Authentification
//
NS_BDDservice::Service_Authentification::Service_Authentification()
{
    oCad = gcnew  NS_load::CLload;
    oAuth = gcnew NS_BDD::Authentification;
}

System::Data::DataSet^ NS_BDDservice::Service_Authentification::CheckAuthentification(System::String^ email, System::String^ mdp)
{
    System::String^ check;

    this->oAuth->setEmail(email);
    this->oAuth->setMdp(mdp);
    
    check = this->oAuth->Check();
    this->oCad->actionRows(check);
    
    return this->oCad->getRows(check, "Authentification");
}

System::Data::DataSet^ NS_BDDservice::Service_Authentification::CheckSup(System::String^ email, System::String^ mdp)
{    
    System::String^ check;
    oCad = gcnew  NS_load::CLload;
    oAuth = gcnew NS_BDD::Authentification;	

    this->oAuth->setEmail(email);
    this->oAuth->setMdp(mdp);
    check = this->oAuth->CheckSupp();
    this->oCad->actionRows(check);
    
    return this->oCad->getRows(check, "Authentification");
}
//
//Personnel
//
NS_BDDservice::service_Personnel::service_Personnel()
{
    oCad = gcnew  NS_load::CLload;
    oPersonnel = gcnew NS_BDD::Personnel;
    oAdresse = gcnew NS_BDD::Adresse;
    oAuth = gcnew NS_BDD::Authentification;
    oVille = gcnew NS_BDD::Ville;
}

System::Data::DataSet^ NS_BDDservice::service_Personnel::Afficher_personnel(System::String^ Nom, System::String^ Prenom) {
   
    System::String^ result;
   
    
    this->oPersonnel->set_nom(Nom);
    this->oPersonnel->set_prenom(Prenom);
    
    result = this->oPersonnel->Afficher();
    this->oCad->actionRows(result);
    
    return this->oCad->getRows(result, "Personnel");

}

void NS_BDDservice::service_Personnel::Ajouter_personnel(System::String^ Nom, System::String^ Prenom, System::String^ Date_embauche, System::String^ superieur, System::String^ id_sup, System::String^ email, System::String^ mdp, System::String^ rue, System::String^ Ville, System::String^ code_postal)
{
       System::String^ result;
    oPersonnel = gcnew NS_BDD::Personnel;
   

    this->oPersonnel->set_nom(Nom);
    this->oPersonnel->set_prenom(Prenom);
    this->oPersonnel->set_date_embauche(Date_embauche);
    this->oPersonnel->set_superieur(superieur);
    this->oPersonnel->set_id_superieur(id_sup);
    this->oAuth->setEmail(email);
    this->oAuth->setMdp(mdp);
    this->oAdresse->set_rue(rue);
    this->oVille->set_nom(Ville);
    this->oVille->set_code_postal(code_postal);
    
   
    result = this->oAuth->Ajouter();
    this->oCad->actionRows(result);
    result = this->oAdresse->Ajouter(this->oVille->get_nom());
    this->oCad->actionRows(result);
    result = this->oPersonnel->Ajouter(this->oAuth->getEmail(), this->oAdresse->get_rue());
    this->oCad->actionRows(result);
    
}

void NS_BDDservice::service_Personnel::Modifier_personnel(System::String^ id, System::String^ Nom, System::String^ Prenom, System::String^ Date_embauche, System::String^ superieur, System::String^ id_sup, System::String^ email, System::String^ mdp, System::String^ rue, System::String^ Ville, System::String^ code_postal)
{
    System::String^ result;
   
    this->oPersonnel->set_id_personnel(id);
    this->oPersonnel->set_nom(Nom);
    this->oPersonnel->set_prenom(Prenom);
    this->oPersonnel->set_date_embauche(Date_embauche);
    this->oPersonnel->set_superieur(superieur);
    this->oPersonnel->set_id_superieur(id_sup);
    this->oAuth->setEmail(email);
    this->oAuth->setMdp(mdp);
    this->oAdresse->set_rue(rue);
    this->oVille->set_nom(Ville);
    this->oVille->set_code_postal(code_postal);

    result = this->oPersonnel->Modifier();
    this->oCad->actionRows(result);
    result = this->oAuth->Modifier(this->oPersonnel->get_id_personnel(), this->oPersonnel->get_nom(), this->oPersonnel->get_prenom());
    this->oCad->actionRows(result);
    result = this->oAdresse->Modifier(this->oPersonnel->get_id_personnel(), this->oPersonnel->get_nom(), this->oPersonnel->get_prenom(), this->oVille->get_nom(), this->oVille->get_code_postal());
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Personnel::effacer_personnel(System::String^ id, System::String^ Nom, System::String^ Prenom)
{
    System::String^ result;
   
    this->oPersonnel->set_nom(Nom);
    this->oPersonnel->set_prenom(Prenom);
    this->oPersonnel->set_id_personnel(id);
   
    result = this->oPersonnel->Supprimer();
    this->oCad->actionRows(result);
    result = this->oAuth->Supprimer(this->oPersonnel->get_id_personnel(), this->oPersonnel->get_nom(), this->oPersonnel->get_prenom());
    this->oCad->actionRows(result);
    result = this->oAdresse->Supprimer(this->oPersonnel->get_id_personnel(), this->oPersonnel->get_nom(), this->oPersonnel->get_prenom());
    this->oCad->actionRows(result);
}
//
//Client
//
NS_BDDservice::service_Client::service_Client() {
    oClient = gcnew NS_BDD::Client;
    oAdresse = gcnew NS_BDD::Adresse;
    oVille = gcnew NS_BDD::Ville;
    oCad = gcnew  NS_load::CLload;
}

System::Data::DataSet^ NS_BDDservice::service_Client::Afficher_client(System::String^ Nom, System::String^ Prenom)
{
    System::String^ result;

    this->oClient->set_nom(Nom);
    this->oClient->set_prenom(Prenom);
    
    result = this->oClient->Afficher();
    this->oCad->actionRows(result);

    return this->oCad->getRows(result, "Client");
}

void NS_BDDservice::service_Client::Ajouter_client(System::String^ Nom, System::String^ Prenom, System::String^ Date_de_naissance, System::String^ Date_premiere_commande, System::String^ rue_livraison, System::String^ ville_livraison, System::String^ Code_postal_livraison, System::String^ rue_facturation, System::String^ Ville_facturation, System::String^ code_postal_facturation)
{
    
    System::String^ result;
    

    this->oClient->set_date_premiere_commande(Date_premiere_commande);
    this->oClient->set_nom(Nom);
    this->oClient->set_prenom(Prenom);
    this->oClient->set_date_naissance(Date_de_naissance);
    this->oVille->set_code_postal(Code_postal_livraison);
    this->oAdresse->set_rue(rue_facturation);
    this->oVille->set_nom(ville_livraison);
    this->oVille->set_code_postal(code_postal_facturation);
    
    result = this->oClient->Ajouter(rue_facturation, Ville_facturation, rue_livraison, ville_livraison);
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Client::Modifier_client(System::String^ id, System::String^ Nom, System::String^ Prenom, System::String^ Date_de_naissance, System::String^ Date_premiere_commande, System::String^ rue_livraison, System::String^ ville_livraison, System::String^ Code_postal_livraison, System::String^ rue_facturation, System::String^ Ville_facturation, System::String^ code_postal_facturation) {
    
    System::String^ result;
    
    this->oClient->set_id_client(id);
    this->oClient->set_date_premiere_commande(Date_premiere_commande);
    this->oClient->set_nom(Nom);
    this->oClient->set_prenom(Prenom);
    this->oClient->set_date_naissance(Date_de_naissance);
    this->oAdresse->set_rue(rue_livraison);
    this->oVille->set_nom(ville_livraison);
    this->oVille->set_code_postal(Code_postal_livraison);
    this->oAdresse->set_rue(rue_facturation);
    this->oVille->set_nom(ville_livraison);
    this->oVille->set_code_postal(code_postal_facturation);
   
    result = this->oClient->Modifier(this->oAdresse->get_rue(), this->oVille->get_id_ville(), this->oVille->get_code_postal());
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Client::effacer_client(System::String^ id, System::String^ Nom, System::String^ Prenom) {
    
     System::String^ result;
    
    this->oClient->set_nom(Nom);
    this->oClient->set_prenom(Prenom);
    this->oClient->set_id_client(id);
    
    result = this->oClient->Supprimer();
    this->oCad->actionRows(result);


}
//
// Commande
//
NS_BDDservice::service_Commande::service_Commande()
{
    oCad = gcnew  NS_load::CLload;
    oArticle = gcnew NS_BDD::Article;
    oCommande = gcnew NS_BDD::Commande;
    oPaiement = gcnew NS_BDD::Paiement;
    oClient = gcnew NS_BDD::Client;
    //ICI
}

System::Data::DataSet^ NS_BDDservice::service_Commande::Afficher_commande(System::String^ Reference)
{
    System::String^ result;

    this->oCommande->set_reference(Reference);

    result = this->oCommande->Afficher();
    this->oCad->actionRows(result);

    return this->oCad->getRows(result, "Commande");
}

void NS_BDDservice::service_Commande::Ajouter_commande(System::String^ id, System::String^ Nomclient, System::String^ Prenomclient, System::String^ Nomart, System::String^ Quantité, System::String^ Couleur, System::String^ tva, System::String^ remise, System::String^ moyen_paiement, System::String^ Nbr_paiement, System::String^ Date_prem_paiment, System::String^ Date_paiement)
{
    System::String^ result;
    System::String^ sql;
    this->oArticle->set_nom(Nomart); 
    this->oCommande->set_quantité(Quantité);
    this->oArticle->set_couleur(Couleur);
    this->oCommande->set_TVA(tva);
    this->oCommande->set_remise(remise);
    this->oPaiement->set_moyen(moyen_paiement);
    this->oPaiement->set_solde(Nbr_paiement);
    this->oPaiement->set_date_emission(Date_prem_paiment);
    this->oPaiement->set_date_paiement(Date_paiement);
    this->oClient->set_id_client(id);
    this->oClient->set_nom(Nomclient);
    this->oClient->set_prenom(Prenomclient);

sql ="update Commande set Commande.reference = (select concat(LEFT(upper(Client.prenom), 2), '', LEFT(upper(Client.nom), 2), '', YEAR(Commande.date_emission), '', LEFT(upper(Ville.nom), 3), '', Commande.id_commande)) from Commande Full join Client on Commande.id_client = Client.id_client Full join Adresse on Adresse.id_client_Livrer = Client.id_client Full join Ville on Ville.id_ville = Adresse.id_ville where(Commande.id_client = '"+this->oClient->get_id_client()+"' and Commande.date_emission = '"+this->oCommande->get_date_emission()+"' and Commande.date_livraison = '"+this->oCommande->get_date_livraison()+"') ;";
    
result = this->oCommande->Ajouter(this->oClient->get_nom(), this->oClient->get_prenom(), this->oClient->get_id_client());
    this->oCad->actionRows(result);
    this->oCad->actionRows(sql);
    sql = "Select Commande.reference from Commande where (id_client = '" + this->oClient->get_id_client() + "' and Commande.date_emission = '" + this->oCommande->get_date_emission() + "' and Commande.date_livraison = '" + this->oCommande->get_date_livraison() + "');";
    this->oCommande->set_reference(this->oCad->getRows(sql, "Commande")->ToString());
    result = this->oCommande->Ajouter2(this->oArticle->get_nom(), this->oArticle->get_nature(), this->oArticle->get_couleur(), this->oPaiement->get_solde(), this->oPaiement->get_date_paiement(), this->oPaiement->get_moyen());
    this->oCad->actionRows(result);

}

void NS_BDDservice::service_Commande::Modifier_commande(System::String^ Reference, System::String^ Nom, System::String^ Quantité, System::String^ Couleur, System::String^ tva, System::String^ remise, System::String^ moyen_paiement, System::String^ Nbr_paiement, System::String^ Date_prem_paiment, System::String^ Date_paiement)
{
    System::String^ result;

    this->oCommande->set_reference(Reference);
    this->oArticle->set_nom(Nom);
    this->oCommande->set_quantité(Quantité);
    this->oArticle->set_couleur(Couleur);
    this->oCommande->set_TVA(tva);
    this->oCommande->set_remise(remise);
    this->oPaiement->set_moyen(moyen_paiement);
    this->oPaiement->set_solde(Nbr_paiement);
    this->oPaiement->set_date_emission(Date_prem_paiment);
    this->oPaiement->set_date_paiement(Date_paiement);

    result = this->oCommande->Modifier();
    this->oCad->actionRows(result);
    result = this->oPaiement->Modifier();
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Commande::effacer_commande(System::String^ Reference)
{
    System::String^ result;

    this->oCommande->set_reference(Reference);
    result = this->oCommande->Supprimer();
    this->oCad->actionRows(result);
}
//
// Article
//
NS_BDDservice::service_Article::service_Article()
{
    oArticle = gcnew NS_BDD::Article;
    oCad = gcnew  NS_load::CLload;
}

System::Data::DataSet^ NS_BDDservice::service_Article::Afficher_article(System::String^ nature, System::String^ Nom,System::String^ couleur)
{
    System::String^ result;
    this->oArticle->set_nature(nature);
    this->oArticle->set_nom(Nom);
    this->oArticle->set_couleur(couleur);

    result = this->oArticle->Afficher();
    this->oCad->actionRows(result);

    return this->oCad->getRows(result, "Article");
}

void NS_BDDservice::service_Article::Ajouter_article(System::String^ nom,System::String^ Nature, System::String^ PrixHT, System::String^ TVA, System::String^ quantitéstock, System::String^ couleur, System::String^ Seuilrea)
{
   System::String^ result;
   
    this->oArticle->set_nom(nom);
    this->oArticle->set_nature(Nature);
    this->oArticle->set_prix_HT(PrixHT);
    this->oArticle->set_TVA(TVA);
    this->oArticle->set_quantite_stock(quantitéstock);
    this->oArticle->set_couleur(couleur);
    this->oArticle->set_seuil(Seuilrea);
    result = this->oArticle->Ajouter();
    
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Article::Modifier_article(System::String^ Id, System::String^ nom,System::String^ Nature, System::String^ PrixHT, System::String^ TVA, System::String^ quantitéstock, System::String^ couleur, System::String^ Seuilrea)
{
    System::String^ result;
    

    this->oArticle->set_id_article(Id);
    this->oArticle->set_nom(nom);
    this->oArticle->set_nature(Nature);
    this->oArticle->set_prix_HT(PrixHT);
    this->oArticle->set_TVA(TVA);
    this->oArticle->set_quantite_stock(quantitéstock);
    this->oArticle->set_couleur(couleur);
    this->oArticle->set_seuil(Seuilrea);
    result = this->oArticle->Modifier();
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Article::effacer_article(System::String^ nature, System::String^ nom, System::String^ couleur)
{
    System::String^ result;
    

    this->oArticle->set_nom(nom);
    this->oArticle->set_couleur(couleur);

    result = this->oArticle->Supprimer();
    this->oCad->actionRows(result);
}
//
//Statistiques
//
NS_BDDservice::service_Stat::service_Stat(){
    oCad = gcnew  NS_load::CLload;
    oStats = gcnew NS_BDD::statistique;
}

System::Data::DataSet^ NS_BDDservice::service_Stat::panier_moy() {
    System::String^ result;

    result = this->oStats->panier_moy();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result, "Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::chiffre_affaire(System::String^ mois) {
    System::String^ result;

    this->oStats->set_mois(mois);
    result = this->oStats->chiffre_affaire();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result,"Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::seuil_appro() {
    System::String^ result;

    result = this->oStats->seuil_appro();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result,"Article");
}


System::Data::DataSet^ NS_BDDservice::service_Stat::montant_total_achat(System::String^ id,System::String^ nom, System::String^ prenom) {
    System::String^ result;

    this->oStats->set_nom(nom);
    this->oStats->set_prenom(prenom);
    this->oStats->set_id(id);
    result = this->oStats->montant_total_achat();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result,"Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::arcticle_plus_vendu() {
    System::String^ result;

    result = this->oStats->arcticle_plus_vendu();
    this->oCad->actionRows(result);
   return this->oCad->getRows(result,"Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::article_moins_vendu() {
    System::String^ result;

    result = this->oStats->article_moins_vendu();
    this->oCad->actionRows(result);
   return this->oCad->getRows(result, "Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::val_com_stock() {
    System::String^ result;

    result = this->oStats->val_com_stock();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result,"Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::val_achat_stock() {
    System::String^ result;

    result = this->oStats->val_achat_stock();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result,"Article");
}

System::Data::DataSet^ NS_BDDservice::service_Stat::simulation(System::String^ TVA, System::String^ marge, System::String^ remise, System::String^ demarque) {
    System::String^ result;

    this->oStats->set_TVA(TVA);
    this->oStats->set_marge(marge);
    this->oStats->set_remise(remise);
    this->oStats->set_demarque(demarque);
    result = this->oStats->simulation();
    this->oCad->actionRows(result);
    return this->oCad->getRows(result, "Article");
}