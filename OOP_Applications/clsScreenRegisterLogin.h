#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include"clsUsers.h"
class clsScreenRegisterLogin : protected clsScreen
{
private :
	static void _PrintHeader()
	{ 
      cout << "=========================================================================================================================\n";
      cout << "                             <<<<<<<<<>>>>>>>>  Data login  <<<<<<<<<>>>>>>>>" << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------\n";
      cout << "      Date Time                 |     UserName   |     ID      |          Full Name                |         Permissions \n";
      cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	}
    static void _Print(clsUsers::stRegisterLogin rgl)
    {
        cout << "  " << left << setw(29) << rgl.Date << " | ";
        cout << left << setw(14) << rgl.UserName << " | ";
        cout << left << setw(11) << rgl.ID <<" | ";
        cout << left << setw(33) << rgl.FullName << " | ";
        cout << left << setw(27) << rgl.Pirmissions ;
    }
public :
    static void ShowListRehisterLogin()
    {
        _DrawHeaderScreen("List Register Login");
        vector <clsUsers::stRegisterLogin> vLG = clsUsers::GetRegisterLogin();
        _PrintHeader();
        for (clsUsers::stRegisterLogin& st : vLG)
        {
            _Print(st);
        }
        
    }

};


