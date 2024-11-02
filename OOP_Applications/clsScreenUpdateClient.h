#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsIOProcessor.h"
#include"clsScreen.h"
using namespace std;

class clsScreenUpdateClient : protected clsScreen
{
private:
	static clsBankClient _InputDataClient(clsBankClient client)
	{
		_Paragraph(" Enter ID OR CIN        : ");
		client.ID = clsIOProcessor::RaedText();

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

		_Paragraph(" Enter Pin Code         : ");
		client.PinCode = clsIOProcessor::RaedText();

		_Paragraph(" Enter Account Balanse  : ");
		client.AccountBalanse = clsIOProcessor::ReadNumber();

		return client;
	}
public:
	static void ShowUpdeteClient()
	{
		string AccountNumber = "";
		_DrawHeaderScreen("Screen Updete Client");
		_Paragraph("Enter Account Number : ");
		AccountNumber = clsIOProcessor::RaedText();

		while (!clsBankClient::isClientExist(AccountNumber))
		{
			cout << Space() << "no found this Account Number  : ";
			AccountNumber = clsIOProcessor::RaedText();
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		PrintClient(client);

		cout << endl;
		_DrawHeaderScreen("Input New Data");
		client = _InputDataClient(client);
		PrintClient(client);

		char Answer;
		_Paragraph("Do you want Save this Client [Y/n]? : ");
		Answer = clsIOProcessor::ReadCHAR();

		if (Answer == 'y' || Answer == 'Y')
		{
			clsBankClient::enSaveRuselt Save;

			Save = client.Save();

			switch (Save)
			{
			case clsBankClient::svObjectEmpty:
				cout << clsScreen::Space() << "Object is Empty " << endl;
				break;
			case clsBankClient::svSuccuded:
				cout << clsScreen::Space() << "Object is Updet " << endl;
				break;
			case clsBankClient::svAddClient:
				cout << clsScreen::Space() << " Client is Add To File " << endl;
				break;
			default:
				break;
			}

		}
	}
};

