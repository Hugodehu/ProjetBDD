#pragma once
#include "client.h"
#include "BDDload.h"
namespace NS_BDDservice
{
    ref class BDDservice
    {
    private:
        NS_load::CLload^ oCad;
        NS_client::client^ oMappTB;
    public:
        BDDservice(void);
        System::Data::DataSet^ selectionnerToutesLesPersonnes(System::String^);
        void CheckAuthentification(System::String^,System::String^);
    };
}

