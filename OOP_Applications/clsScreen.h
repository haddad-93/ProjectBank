#pragma once
#include <iostream>
#include <string>
#include<iomanip>  // this library stored the std::setw
#include"clsBankClient.h"
#include"clsUsers.h"
#include"globalCurrent.h"
#include"clsIOProcessor.h"

using namespace std;

class clsScreen 
{
public:
    static string Space(short space = 6)
    {
        string tab = "";
        for (short i = 1; i < space; i++)
        {
            tab += "\t";
        }
        return tab;
    }

    
    
protected:

    /*static string Space(short space = 6)
    {
        string tab = "";
        for (short i = 1; i < space; i++)
        {
            tab += "\t";
        }
        return tab;
    }*/

    static bool PermissionCorrect(clsUsers::enPermissions Permission)
    {
        if (!CurrentUser.CheckAcssesPermissions(Permission))
        {
            cout << endl;
            cout << Space() << "===================================================\n";
            cout << Space() << "    You do not have Access ! Contact Admin "  << endl;
            cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-\n";
            return false;
        }
        return true;
    }

    static void _DrawHeaderScreen(string Titel)
    {
        cout << endl;
        cout << Space() << "===================================================\n";
        cout << Space() << "                  " << Titel << endl;
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-\n";

        _Paragraph(" UserName : "); cout<<CurrentUser.getUserName()<<endl;
        _Paragraph(" FullName : "); cout << CurrentUser.FullName() << endl;
        _Paragraph(" "+clsIOProcessor::DateTime() + "\n\n");
    }

    static void InformationBalances()
    {
        cout << "=========================================================================================================================\n";
        cout << "                          <<<<<<<<<>>>>>>>>  Information Data Client  <<<<<<<<<>>>>>>>>" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << "    Account Number           |                    Full Name                     |         Account Balances \n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }

    static void ShowBalances(clsBankClient client)
    {
        cout << "  " << left << setw(26) << client.getAccountNumber() << " | ";
        cout << left << setw(48) << client.FullName() << " | ";
        cout << left << setw(22) << client.getAccountBalanse() << "\n";
    }

    static void _Paragraph(string Short , double n = -0.1)
    {
        cout << Space() << Short;
        if (n != -0.1)
        {
            cout << n;
        }
    }

    static void PrintClient(clsBankClient cln)
    {
        cout << endl;
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << Space(5) << "                  Information Client            \n";
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << Space() << "  Id CIN          : " << cln.getID() << endl;
        cout << Space() << "  FirstName       : " << cln.getFirstName() << endl;
        cout << Space() << "  LastName        : " << cln.getLastName() << endl;
        cout << Space() << "  Birth Date      : " << cln.getBirthDate() << endl;
        cout << Space() << "  Gendar          : " << cln.getGendar() << endl;
        cout << Space() << "  NumberPhone     : " << cln.getNumberPhone() << endl;
        cout << Space() << "  Email           : " << cln.getEmail() << endl;
        cout << Space() << "  Country         : " << cln.getCountry() << endl;
        cout << Space() << "  Ctiy            : " << cln.getCity() << endl;
        cout << Space() << "  Address         : " << cln.getAddress() << endl;
        cout << Space() << "  Account Number  : " << cln.getAccountNumber() << endl;
        cout << Space() << "  Pin Code        : " << cln.getPinCode() << endl;
        cout << Space() << "  Account Balance : " << cln.getAccountBalanse() << endl;
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << endl;
    }
    
    static void PrintPerson(clsPerson Prs)
    {
        cout << endl;
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << Space(5) << "                  Information Person            \n";
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << Space() << "  Id CIN      : " << Prs.getID() << endl;
        cout << Space() << "  FirstName   : " << Prs.getFirstName() << endl;
        cout << Space() << "  LastName    : " << Prs.getLastName() << endl;
        cout << Space() << "  Birth Date  : " << Prs.getBirthDate() << endl;
        cout << Space() << "  Gendar      : " << Prs.getGendar() << endl;
        cout << Space() << "  NumberPhone : " << Prs.getNumberPhone() << endl;
        cout << Space() << "  Email       : " << Prs.getEmail() << endl;
        cout << Space() << "  Country     : " << Prs.getCountry() << endl;
        cout << Space() << "  Ctiy        : " << Prs.getCity() << endl;
        cout << Space() << "  Address     : " << Prs.getAddress() << endl;
        cout << Space(5) << "-------------------------------------------------------\n";
        cout << endl;
    }

    static void  Information()
    {
        cout << "=========================================================================================================================\n";
        cout << "                          <<<<<<<<<>>>>>>>>  Information Data Client  <<<<<<<<<>>>>>>>>" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << " A.N | P.C | Id CIN  |   Full Name      | BirthDay  |G |NumberPhone|       Email     |Country| City |  Address    |A.B\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }

    static void PrintInformationDataClient(clsBankClient Client)
    {
        cout <<" " << left << setw(4) << Client.getAccountNumber();
        cout << "|" << left << setw(5) << Client.PinCode;
        cout << "|" << left << setw(9) << Client.getID();
        cout << "|" << left << setw(18) << Client.FullName();
        cout << "|" << left << setw(11) << Client.BirthDate;
        cout << "|" << left << setw(2) << Client.Gendar;
        cout << "|" << left << setw(11) << Client.NumberPhone;
        cout << "|" << left << setw(17) << Client.Email;
        cout << "|" << left << setw(7) << Client.Country;
        cout << "|" << left << setw(6) << Client.City;
        cout << "|" << left << setw(13) << Client.Address;
        cout << "|" << left << setw(13) << Client.AccountBalanse;
    }

    static void  InformationUser()
    {
        cout << "=========================================================================================================================\n";
        cout << "                          <<<<<<<<<>>>>>>>>  Information Data Users  <<<<<<<<<>>>>>>>>" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| Id CIN | User Name |  Full Name       | BirthDay  |G |NumberPhone |       Email     |Country | City |  Address |Acsses|\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }
    
    static void PrintInformationDataUser(clsUsers Client)
    {
        cout << "|" << left << setw(8) << Client.getID();
        cout << "|" << left << setw(11) << Client.getUserName();
        cout << "|" << left << setw(18) << Client.FullName();
        cout << "|" << left << setw(11) << Client.BirthDate;
        cout << "|" << left << setw(2) << Client.Gendar;
        cout << "|" << left << setw(12) << Client.NumberPhone;
        cout << "|" << left << setw(17) << Client.Email;
        cout << "|" << left << setw(8) << Client.Country;
        cout << "|" << left << setw(6) << Client.City;
        cout << "|" << left << setw(10) << Client.Address;
        cout << "|" << left << setw(14) << Client.Permissions;
    }

    
};

