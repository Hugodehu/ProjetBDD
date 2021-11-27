#include "pch.h"
#include "BDDservice.h"
#include <iostream>
#include <string>

NS_BDDservice::BDDservice::BDDservice(void)
{
    this->oCad = gcnew NS_load::CLload();
    this->oMappTB = gcnew NS_BDD::Authentification();
}
System::Data::DataSet^ NS_BDDservice::BDDservice::CheckAuthentification(System::String^ email, System::String^ mdp)
{
    System::Data::DataSet^ result;
    System::String^ check;
    this->oMappTB->setEmail(email);
    this->oMappTB->setMdp(mdp);
    check = this->oMappTB->Check();
    this->oCad->actionRows(check);
    result = this->oCad->getRows(check);
    return result;
}

System::Data::DataSet^ NS_BDDservice::BDDservice::CheckSup() {
    System::Data::DataSet^ result;
    System::String^ check;
    check = this->oMappTB->CheckSup();
    this->oCad->actionRows(check);
    result = this->oCad->getRows(check);
    return result;
}


