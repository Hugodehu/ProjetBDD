#pragma once
#include "pch.h"
namespace NS_client
{
    ref class client
    {
    private:
        System::String^ email;
        System::String^ mdp;
        int Id;
    public:
        client();
        System::String^ Select();
        System::String^ Check(System::String^,System::String^);

        void setId(int);
        void setemail(System::String^);
        void setmdp(System::String^);


        int getId(void);
        System::String^ getemail(void);
        System::String^ getmdp(void);
    };

    ref class personnel {

    };
}

