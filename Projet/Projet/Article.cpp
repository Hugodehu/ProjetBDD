#include "Header.h"
#include "pch.h"

void NS_BDD::Article::set_id_article(System::String^ id_article) { this->id_article = id_article; }
void NS_BDD::Article::set_nom(System::String^ nom) { this->nom = nom; }
void NS_BDD::Article::set_nature(System::String^ nature) { this->nature = nature; }
void NS_BDD::Article::set_prix_HT(System::String^ prix_HT) { this->prix_HT = prix_HT; }
void NS_BDD::Article::set_quantite_stock(System::String^ quantite) { this->quantite_stock = quantite; }
void NS_BDD::Article::set_TVA(System::String^ TVA) { this->TVA = TVA; }
void NS_BDD::Article::set_couleur(System::String^ couleur) { this->couleur = couleur; }
void NS_BDD::Article::set_seuil(System::String^ seuil) { this->seuil = seuil; }

System::String^ NS_BDD::Article::get_id_article(void) { return this->id_article; }
System::String^ NS_BDD::Article::get_nom(void) { return this->nom; }
System::String^ NS_BDD::Article::get_nature(void) { return this->nature; }
System::String^ NS_BDD::Article::get_prix_HT(void) { return this->prix_HT; }
System::String^ NS_BDD::Article::get_quantite_stock(void) { return this->quantite_stock; }
System::String^ NS_BDD::Article::get_TVA(void) { return this->TVA; }
System::String^ NS_BDD::Article::get_couleur(void) { return this->couleur; }
System::String^ NS_BDD::Article::get_seuil(void) { return this->seuil; }

System::String^ NS_BDD::Article::Ajouter(void)
{
    return "";
}

System::String^ NS_BDD::Article::Afficher(void)
{
    return "";
}

System::String^ NS_BDD::Article::Modifier(void)
{
    return "";
}

System::String^ NS_BDD::Article::Supprimer(void)
{
    return "";
}