#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsScreenAddUser.h"
#include"clsScreenListUsers.h"
#include"clsScreenDeleteUser.h"
#include"clsScreenUpdateUser.h"
#include"clsScreenFindUser.h"
using namespace std;

class clsScreenMainUser : protected clsScreen
{
private:

    enum enManageUser { enListUser = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdetUser = 4, enFindUser = 5, enMainMenu = 6 };

    static void _CoBackToMainMenue()
    {
        
        system("pause>0");
        ShowScreenUsers();
        cout << "\n\n" << Space() << "Press any key to continue Main Menue......";
    }
    
    static void _ListUser()
    {
        clsScreenListUsers::ShowListUser();
    }

    static void _addUser()
    {
        clsScreenAddUser::ShowAddUser();
    }
    
    static void _DeleteUser()
    {
        clsScreenDeleteUser::ShowDeleteUser();
    }

    static void _UpdetUser() 
    {
        clsScreenUpdateUser::ShowUpdateUser();
    }

    static void _FindUser()
    {
        clsScreenFindUser::ShowFindUser();
    }
    
    static void _MainMenu()
    {
        //cout << "\n\n" << Space() << "Press any key to continue Main Menue......";
    }

    static void _PerfromMainUsers(enManageUser User)
    {
        switch (User)
        {
        case clsScreenMainUser::enListUser:
            system("cls");
            _ListUser();
            _CoBackToMainMenue();
            break;
        case clsScreenMainUser::enAddNewUser:
            system("cls");
            _addUser();
            _CoBackToMainMenue();
            break;
        case clsScreenMainUser::enDeleteUser:
            system("cls");
            _DeleteUser();
            _CoBackToMainMenue();
            break;
        case clsScreenMainUser::enUpdetUser:
            system("cls");
            _UpdetUser();
            _CoBackToMainMenue();
            break;
        case clsScreenMainUser::enFindUser:
            system("cls");
            _FindUser();
            _CoBackToMainMenue();
            break;
        case clsScreenMainUser::enMainMenu:
            _MainMenu();
            break;
        default:
            break;
        }
        
    }
public:

    static void ShowScreenUsers()
    {
        system("cls");
        _DrawHeaderScreen("Screen Maine Users");
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|                  Main Users                     |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|       [1] List User                             |\n";
        cout << Space() << "|       [2] AddNew User                           |\n";
        cout << Space() << "|       [3] Delete User                           |\n";
        cout << Space() << "|       [4] Updet User                            |\n";
        cout << Space() << "|       [5] Find User                             |\n";
        cout << Space() << "|       [6] Main Menu                             |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        int num = clsIOProcessor::NumberBetween(1, 6);
        _PerfromMainUsers(enManageUser(num));
    }
};

