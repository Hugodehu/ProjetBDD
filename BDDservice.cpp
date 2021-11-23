#include "pch.h"
#include "BDDservice.h"
#include <iostream>
#include <string>

NS_BDDservice::BDDservice::BDDservice(void)
{
    this->oCad = gcnew NS_load::CLload();
    this->oMappTB = gcnew NS_client::client();
}
System::Data::DataSet^ NS_BDDservice::BDDservice::selectionnerToutesLesPersonnes(System::String^ table)
{
    System::String^ sql;

    sql = this->oMappTB->Select();
    return this->oCad->getRows(sql, table);
}
void NS_BDDservice::BDDservice::CheckAuthentification(System::String^ email, System::String^ mdp)
{
    System::String^ sql;

    this->oMappTB->setemail(email); //erreur 'La référence d'objet n'est pas définie à une instance d'un objet.'
    this->oMappTB->setmdp(mdp); //erreur'La référence d'objet n'est pas définie à une instance d'un objet.'
    try {
       sql = this->oMappTB->Check("email", email);
        this->oCad->actionRows(sql);
    }

    catch (std::string const& chaine) { std::cout << "Echec" << std::endl; }

    sql = this->oMappTB->Check("mdp", mdp);
    this->oCad->actionRows(sql);
}

