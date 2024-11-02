#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
#include"clsScreenMainMenue.h"
#include"globalCurrent.h"
using namespace std;

class clsScreenLogin : protected clsScreen
{
private:

	static bool _Login()
	{
		short counter = 3;
		string UserName, Id;
		bool logFail = true;

		do 
		{
			if (!logFail)
			{
				counter--;
				if (counter == 0)
				{
					cout << endl << Space() << "Tray Again in an hour \n\n";
					return true;
				}
				cout << endl << Space() << "No found This User Enter Another User \n";
				cout << endl << Space() << "        You Have " << counter << " Try \n\n";
			}
			_Paragraph(" Entet User Name        : ");
			UserName = clsIOProcessor::RaedText();

			_Paragraph(" Enter ID or CIN        : ");
			Id = clsIOProcessor::RaedText();

			CurrentUser = clsUsers::isFind(UserName, Id);

			logFail = CurrentUser.isFound(UserName, Id);
			
		} while (!logFail);
		CurrentUser.SaveLoginUser();
    	clsScreenMainMenue::ShowMainMenue();
		return false;
	}
public:

	static bool ShowLogin()
	{
		system("cls");

		_DrawHeaderScreen(" Screen Login ");

		 return _Login();
	}
};

