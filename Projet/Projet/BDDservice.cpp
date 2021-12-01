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
    
    return this->oCad->getRows(check);
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
    
    return this->oCad->getRows(check);
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
    
    return this->oCad->getRows(result);

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
    
    result = this->oPersonnel->Ajouter();
    this->oCad->actionRows(result);

    result = this->oAuth->Ajouter();
    this->oCad->actionRows(result);

    result = this->oAdresse->Ajouter();
    this->oCad->actionRows(result);

    result = this->oVille->Ajouter();
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

    result = this->oAuth->Modifier();
    this->oCad->actionRows(result);

    result = this->oAdresse->Modifier();
    this->oCad->actionRows(result);

    result = this->oVille->Modifier();
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

    return this->oCad->getRows(result);
}

void NS_BDDservice::service_Client::Ajouter_client(System::String^ Nom, System::String^ Prenom, System::String^ Date_de_naissance, System::String^ Date_premiere_commande, System::String^ rue_livraison, System::String^ ville_livraison, System::String^ Code_postal_livraison, System::String^ rue_facturation, System::String^ Ville_facturation, System::String^ code_postal_facturation)
{
    System::String^ result;
    
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
    
    result = this->oClient->Ajouter();
    this->oCad->actionRows(result);

    result = this->oVille->Ajouter();
    this->oCad->actionRows(result);

    result = this->oAdresse->Ajouter();
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
   
    result = this->oClient->Modifier();
    this->oCad->actionRows(result);
    result = this->oVille->Modifier();
    this->oCad->actionRows(result);
    result = this->oAdresse->Modifier();
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
}

System::Data::DataSet^ NS_BDDservice::service_Commande::Afficher_commande(System::String^ Reference)
{
    System::String^ result;

    this->oCommande->set_reference(Reference);

    result = this->oCommande->Afficher();
    this->oCad->actionRows(result);

    return this->oCad->getRows(result);
}

void NS_BDDservice::service_Commande::Ajouter_commande(System::String^ Nom, System::String^ Quantité, System::String^ Couleur, System::String^ tva, System::String^ remise, System::String^ moyen_paiement, System::String^ Nbr_paiement, System::String^ Date_prem_paiment, System::String^ Date_paiement)
{
    System::String^ result;
    
    this->oArticle->set_nom(Nom);
    this->oCommande->set_quantité(Quantité);
    this->oArticle->set_couleur(Couleur);
    this->oCommande->set_TVA(tva);
    this->oCommande->set_remise(remise);
    this->oPaiement->set_moyen(moyen_paiement);
    this->oPaiement->set_solde(Nbr_paiement);
    this->oPaiement->set_date_emission(Date_prem_paiment);
    this->oPaiement->set_date_paiement(Date_paiement);

    result = this->oCommande->Ajouter();
    this->oCad->actionRows(result);

    result = this->oPaiement->Ajouter();
    this->oCad->actionRows(result);

    result = this->oArticle->Ajouter();
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

    result = this->oArticle->Modifier();
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

System::Data::DataSet^ NS_BDDservice::service_Article::Afficher_article(System::String^ Nom,System::String^ couleur)
{
    System::String^ result;

    this->oArticle->set_nom(Nom);
    this->oArticle->set_couleur(couleur);

    result = this->oArticle->Afficher();
    this->oCad->actionRows(result);

    return this->oCad->getRows(result);
}

void NS_BDDservice::service_Article::Ajouter_article(System::String^ nom,System::String^ Nature, System::String^ PrixHT, System::String^ TVA, System::String^ quantitéstock, System::String^ couleur, System::String^ Seuilrea)
{
    System::String^ result;

    this->oArticle->set_nom(nom);
    this->oArticle->set_nature(Nature);
    this->oArticle->set_nature(PrixHT);
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
    this->oArticle->set_nature(PrixHT);
    this->oArticle->set_TVA(TVA);
    this->oArticle->set_quantite_stock(quantitéstock);
    this->oArticle->set_couleur(couleur);
    this->oArticle->set_seuil(Seuilrea);

    result = this->oArticle->Modifier();
    this->oCad->actionRows(result);
}

void NS_BDDservice::service_Article::effacer_article(System::String^ nom, System::String^ couleur)
{
    System::String^ result;
    
    this->oArticle->set_nom(nom);
    this->oArticle->set_couleur(couleur);

    result = this->oArticle->Supprimer();
    this->oCad->actionRows(result);
}