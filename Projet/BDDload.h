#pragma once
#include "pch.h"

namespace NS_load
{
    ref class CLload
    {
    private:
        System::String^ sSql;
        System::String^ sCnx;
        System::Data::SqlClient::SqlConnection^ oCnx;
        System::Data::SqlClient::SqlCommand^ oCmd;
        System::Data::SqlClient::SqlDataAdapter^ oDA;
        System::Data::DataSet^ oDs;

    public:
        CLload(void);
        System::Data::DataSet^ getRows(System::String^, System::String^);
        void actionRows(System::String^);
    };
}