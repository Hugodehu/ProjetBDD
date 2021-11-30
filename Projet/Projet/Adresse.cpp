#include "pch.h"
#include "Adresse.h"


void NS_BDD::Adresse::set_id_adresse(System::String^ id_adresse) { this->id_adresse = id_adresse; }
void NS_BDD::Adresse::set_rue(System::String^ rue) { this->rue = rue; }

System::String^ NS_BDD::Adresse::get_id_adresse(void) { return this->id_adresse; }
System::String^ NS_BDD::Adresse::get_rue(void) { return this->rue; }

System::String^ NS_BDD::Adresse::Ajouter(void)
{
    return "";
}

System::String^ NS_BDD::Adresse::Afficher(void)
{
    return "";
}

System::String^ NS_BDD::Adresse::Modifier(void)
{
    return "";
}

System::String^ NS_BDD::Adresse::Supprimer(void)
{
    return "";
}
