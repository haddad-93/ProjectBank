#pragma once
#include <iostream>
#include<string>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUsers.h"
#include"clsScreenAddClient.h"
#include"clsScreenListClient.h"
#include"clsScreenUpdateClient.h"
#include"lsScreenDeleteClient.h"
#include"clsScreenFindClient.h"
#include"clsScreenTransaction.h"
#include"clsScreenMainUser.h"
#include"globalCurrent.h"
#include "clsScreenRegisterLogin.h"
#include "clsScreenMainCurrency.h"




using namespace std;

class clsScreenMainMenue : protected clsScreen
{
private:
     enum enMainMenueOptions { enList = 1, enAdd = 2, enDelete = 3, enUpdate = 4, enFind = 5, 
           enTransactions = 6, enManager = 7, enRegisterLog = 8 , enCurrency = 9 , enLogout = 10 };

    static void _CoBackToMainMenue()
    {

        cout << "\n\n" << Space() << "Press any key to continue Main Menue......";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ListClient()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pList))
        {
            return;
        }
        clsScreenListClient::ShowClientList();
    }
    
    static void _AddClient()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pAdd))
        {
            return;
        }
        clsScreenAddClient::ShowAddClient();
    }
    
    static void _DeletClient()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pDelet))
        {
            return;
        }
        lsScreenDeleteClient::ShowDeleteClient();
    }
    
    static void _UpdateClient()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pUpdete))
        {
            return;
        }
        clsScreenUpdateClient::ShowUpdeteClient();
    }
    
    static void _FindClient()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pSearch))
        {
            return;
        }
        clsScreenFindClient::ShowFindClient();
    }
    
    static void _Transactions()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pTrsnsaction))
        {
            return;
        }
        clsScreenTransaction::ShowTransaction();
        
    }
    
    static void _UserManager()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pManageUser))
        {
            return;
        }
        clsScreenMainUser::ShowScreenUsers();
    }

    static void _RegisterLogin()
    {
        if (!PermissionCorrect(clsUsers::enPermissions::pManageUser))
        {
            return;
        }
        clsScreenRegisterLogin::ShowListRehisterLogin();
    }

    static void _Currency()
    {
        clsScreenMainCurrency::ShowScreenCurrency();
    }

    static void _Logout()
    {
        CurrentUser = clsUsers::isFind("", "");
    }
    
    static void  _PerfromMainMenueOption(enMainMenueOptions Option)
    {
        switch (Option)
        {
        case clsScreenMainMenue::enList:
            system("cls");
            _ListClient();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enAdd:
            system("cls");
            _AddClient();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enDelete:
            system("cls");
            _DeletClient();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enUpdate:
            system("cls");
            _UpdateClient();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enFind:
            system("cls");
            _FindClient();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enTransactions:
            system("cls");
            _Transactions();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enManager:
            system("cls");
            _UserManager();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enRegisterLog : 
            system("cls");
            _RegisterLogin();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enCurrency:
            system("cls");
            _Currency();
            _CoBackToMainMenue();
            break;
        case clsScreenMainMenue::enLogout:
            _Logout();
            break;
        default:
            break;
        }
    }

public:

	static void ShowMainMenue()
	{
        system("cls");
        _DrawHeaderScreen("Screen Main Menue");
        cout << Space() << "===================================================\n";
        cout << Space() << "|                     Main Menue                  |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|       [1] List Client                           |\n";
        cout << Space() << "|       [2] Add Client                            |\n";
        cout << Space() << "|       [3] Delet Client                          |\n";
        cout << Space() << "|       [4] Update Client                         |\n";
        cout << Space() << "|       [5] Find Client                           |\n";
        cout << Space() << "|       [6] Transaction                           |\n";
        cout << Space() << "|       [7] Manage User                           |\n";
        cout << Space() << "|       [8] Register Login                        |\n";
        cout << Space() << "|       [9] Currency Exchange                     |\n";
        cout << Space() << "|      [10] logout                                |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        double Number = clsIOProcessor::NumberBetween(1, 10);
        _PerfromMainMenueOption(enMainMenueOptions(Number));
	}
};

