#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
using namespace std;

class clsScreenUpdateUser : protected clsScreen
{
private :
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

	static void _InputDataClient(clsUsers& client)
	{
		char ansawr;

		_Paragraph("\n");
		_Paragraph("Do you Update First Name   [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter First Name       : ");
			client.FirstName = clsIOProcessor::RaedText();
		}

		_Paragraph("\n");
		_Paragraph("Do you Update Last Name   [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter Last Name            : ");
			client.LastName = clsIOProcessor::RaedText();
		}

		_Paragraph("\n");
		_Paragraph("Do you Update BirthDate  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" EnterBirthDate        : ");
			client.BirthDate = clsIOProcessor::RaedText();
		}

		_Paragraph("\n");
		_Paragraph("Do you Update Gendar  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter Gendar        : ");
			client.Gendar = clsIOProcessor::RaedText();
		}

		_Paragraph("\n");
		_Paragraph("Do you Update Country  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter Country        : ");
			client.Country = clsIOProcessor::RaedText();
		}
		
		_Paragraph("\n");
		_Paragraph("Do you Update City  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter City        : ");
			client.City = clsIOProcessor::RaedText();
		}
		
		_Paragraph("\n");
		_Paragraph("Do you Update Address  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter Address        : ");
			client.Address = clsIOProcessor::RaedText();
		}
		
		_Paragraph("\n");
		_Paragraph("Do you Update Email  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter Email        : ");
			client.Email = clsIOProcessor::RaedText();
		}
		
		_Paragraph("\n");
		_Paragraph("Do you Update NumberPhone  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			_Paragraph(" Enter NumberPhone        : ");
			client.NumberPhone = clsIOProcessor::RaedText();
		}

		_Paragraph("\n");
		_Paragraph("Do you Update Acsses Permissions  [Y/n]? : ");
		cin >> ansawr;
		if (ansawr == 'y' || ansawr == 'Y')
		{
			client.Permissions = _ReadPermissins();
		}
	}

	static void _Update(string UserName, string Id)
	{
		system("cls");
		clsUsers user = clsUsers::isFind(UserName, Id);

		char ansewr;

		if (user.isFound(UserName, Id))
		{
			user = clsUsers::isFind(UserName, Id);
			InformationUser();
			PrintInformationDataUser(user);
			_Paragraph("\n\n");
			_InputDataClient(user);
			system("cls");
			_DrawHeaderScreen(" New Data User");
			InformationUser();
			PrintInformationDataUser(user);

			_Paragraph("\n");
			_Paragraph("Do you Update User [Y/n] ? : ");
			cin >> ansewr;
			if (ansewr == 'y' || ansewr == 'Y')
			{

				user.Updete();
				_Paragraph("\n");
				_Paragraph("User is Update");
			}
			else
			{
				_Paragraph("\n");
				_Paragraph("  User is Not Update");
			}

		}
		else
		{
			_Paragraph("\n");
			_Paragraph(" User is Empty");
		}
	}
public:

	static void ShowUpdateUser()
	{
		_DrawHeaderScreen("Screen Update User");

		string UserName, Id;
		_Paragraph(" Entet User Name        : ");
		UserName = clsIOProcessor::RaedText();

		_Paragraph(" Enter ID or CIN        : ");
		Id = clsIOProcessor::RaedText();

		while (!clsUsers::isFound(UserName, Id))
		{
			_Paragraph(" User is not found \n");

			_Paragraph(" Entet User Name        : ");
			UserName = clsIOProcessor::RaedText();

			_Paragraph(" Enter ID or CIN        : ");
			Id = clsIOProcessor::RaedText();
		}

		_Update(UserName, Id);
	}
};

