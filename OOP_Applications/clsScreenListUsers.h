#pragma once
#include<vector>
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
using namespace std;

class clsScreenListUsers : protected clsScreen
{
public:
	static void ShowListUser()
	{
		_DrawHeaderScreen("Screen List Users");

		InformationUser();
		vector <clsUsers> _vUser = clsUsers::GetAllUsers();
		
		for (clsUsers& clsU : _vUser)
		{
			PrintInformationDataUser(clsU);
		}
	}
};

