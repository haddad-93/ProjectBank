#pragma warning(disable : 4996)
#include <iostream>
#include<string>
#include"clsScreenLogin.h"
#include "clsScreenMainCurrency.h"


using namespace std;

int main()
{


    while (true)
    {
        if (clsScreenLogin::ShowLogin())
        {
            break;
        }
    }

    system("pause>0");
    return 0;
}