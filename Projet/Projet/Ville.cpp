#include "Header.h"
#include "pch.h"

void NS_BDD::Ville::set_id_ville(System::String^ id_ville) { this->id_ville = id_ville; }
void NS_BDD::Ville::set_nom(System::String^ nom) { this->nom = nom; }
void NS_BDD::Ville::set_code_postal(System::String^ code_postal) { this->code_postal = code_postal; }

System::String^ NS_BDD::Ville::get_id_ville(void) { return this->id_ville; }
System::String^ NS_BDD::Ville::get_nom(void) {return this->nom;}
System::String^ NS_BDD::Ville::get_code_postal(void) {return this->code_postal;}

System::String^ NS_BDD::Ville::Ajouter(void)
{
    return "";
}

System::String^ NS_BDD::Ville::Afficher(void)
{
    return "";
}

System::String^ NS_BDD::Ville::Modifier(void)
{
    return "";
}

System::String^ NS_BDD::Ville::Supprimer(void)
{
    return "";
}
