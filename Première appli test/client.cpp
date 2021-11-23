#include "pch.h"
#include "client.h"
#include <iostream>

System::String^ NS_client::client::Select()
{
    return "SELECT BDDP6.id, email, mdp  FROM BDDP6;";
}
System::String^ NS_client::client::Check(System::String^ attribut, System::String^ var)
{
    return "Use BDDP6; SELECT " + attribut + " FROM dbo.Table1p6 WHERE" + attribut + " ='" + var + "';";
}
NS_client::client::client() {
    this->Id = 1;
    this->email = "kylian.renault@viacesi.fr";
    this->mdp = "kylian";
}

void NS_client::client::setId(int Id) { this->Id = Id; }
void NS_client::client::setemail(System::String^ email) { this->email = email; }
void NS_client::client::setmdp(System::String^ mdp) { this->mdp = mdp; }


int NS_client::client::getId(void) { return this->Id; }
System::String^ NS_client::client::getemail(void) { return this->email; }
System::String^ NS_client::client::getmdp(void) { return this->mdp; }