#include "Header.h"
#include "pch.h"


void NS_BDD::Adresse::set_id_adresse(System::String^ id_adresse) { this->id_adresse = id_adresse; }
void NS_BDD::Adresse::set_rue(System::String^ rue) { this->rue = rue; }

System::String^ NS_BDD::Adresse::get_id_adresse(void) { return this->id_adresse; }
System::String^ NS_BDD::Adresse::get_rue(void) { return this->rue; }

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
