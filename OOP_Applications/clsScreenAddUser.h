#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
using namespace std;

class clsScreenAddUser : protected clsScreen
{
	static int _ReadPermissins()
	{
		int prm = 0;
		char ansawr;

		_Paragraph("Do you give all Acsses the user? [Y/n] : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { return clsUsers::enPermissions::pAll; }

		_Paragraph("give Acsses List Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pList; }


		_Paragraph("give Acsses Find Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pSearch; }


		_Paragraph("give Acsses Add new Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pAdd; }


		_Paragraph("give Acsses Updete Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pUpdete; }


		_Paragraph("give Acsses Delete Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pDelet; }

		_Paragraph("give Acsses Trsnsaction Client [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pTrsnsaction; }

		_Paragraph("give Acsses Manage User [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pManageUser; }

		_Paragraph("give Acsses Show List Register Login [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y') { prm += clsUsers::enPermissions::pRegisterLogin; }

		return prm;
	}

	static void _InputDataClient(clsUsers & client)
	{
		_Paragraph(" Enter First Name       : ");
		client.FirstName = clsIOProcessor::RaedText();

		_Paragraph(" Enter Last Name        : ");
		client.LastName = clsIOProcessor::RaedText();

		_Paragraph(" Enter BirthDate        : ");
		client.BirthDate = clsIOProcessor::RaedText();

		_Paragraph(" Enter Gendar           : ");
		client.Gendar = clsIOProcessor::RaedText();

		_Paragraph(" Enter Country          : ");
		client.Country = clsIOProcessor::RaedText();

		_Paragraph(" Enter Ctiy             : ");
		client.City = clsIOProcessor::RaedText();

		_Paragraph(" Enter Address          : ");
		client.Address = clsIOProcessor::RaedText();

		_Paragraph(" Enter Email            : ");
		client.Email = clsIOProcessor::RaedText();

		_Paragraph(" Enter NumberPhone      : ");
		client.NumberPhone = clsIOProcessor::RaedText();

		cout << endl;
		_Paragraph(" Acsses Permissions \n");
		client.Permissions = _ReadPermissins();
	}
public:
	static void ShowAddUser()
	{
		_DrawHeaderScreen("Screen Add New User");

		string UserName, Id;

		_Paragraph(" Entet User Name        : ");
		UserName = clsIOProcessor::RaedText();

		_Paragraph(" Enter ID or CIN        : ");
		Id = clsIOProcessor::RaedText();

		while (clsUsers::isFound(UserName, Id))
		{

			_Paragraph(" User Name or Id Usless agine \n");

			_Paragraph(" Entet User Name        : ");
			UserName = clsIOProcessor::RaedText();

			_Paragraph(" Enter ID or CIN        : ");
			Id = clsIOProcessor::RaedText();
		}
		clsUsers user = clsUsers::AddUser(Id,UserName);

		_InputDataClient(user);

		user.Save(user);

	}
};

