#include "BDDload.h"
#include "pch.h"
NS_load::CLload::CLload(void)
{
    //this->sCnx = "Data Source=KYLIAN;Initial Catalog=projet;Integrated Security=True";
    this->sCnx = "Data Source=serveur-projet-poo.database.windows.net;Initial Catalog=BDD_Projet_POO;User ID=Application;Password=3zj4z6JWM";
    this->sSql = "Rien";
 
    this->oCnx = gcnew System::Data::SqlClient::SqlConnection(this->sCnx);
    this->oCmd = gcnew System::Data::SqlClient::SqlCommand(this->sSql, this->oCnx);
    this->oDA = gcnew System::Data::SqlClient::SqlDataAdapter();
    this->oDs = gcnew System::Data::DataSet();

    this->oCmd->CommandType = System::Data::CommandType::Text;
}
System::Data::DataSet^ NS_load::CLload::getRows(System::String^ sSql)
{
    this->oDs->Clear();
    this->sSql = sSql;
    this->oCmd->CommandText = this->sSql;
    this->oDA->SelectCommand = this->oCmd;
    this->oDA->Fill(this->oDs);

    return this->oDs;
}
void NS_load::CLload::actionRows(System::String^ sSql){
    //try {
        this->sSql = sSql;
        this->oCmd->CommandText = this->sSql;
        this->oDA->SelectCommand = this->oCmd;
        this->oCnx->Open();
        this->oCmd->ExecuteNonQuery();
        this->oCnx->Close();
    //}
    //catch (const std::exception&) {
       // this->oCnx->Close();
   // }
}