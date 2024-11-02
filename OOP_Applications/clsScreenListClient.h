#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"clsBankClient.h"

class clsScreenListClient : protected clsScreen
{
public:
	static void ShowClientList()
	{
		_DrawHeaderScreen("Screen List Clients");
		Information();
		vector <clsBankClient> vCline = clsBankClient::GetAllClient();
		for (clsBankClient& cls : vCline)
		{
			PrintInformationDataClient(cls);
		}
	}
};

