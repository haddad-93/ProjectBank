#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
using namespace std;

class clsScreenFindUser : protected clsScreen
{
private:

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
		}
		else
		{
			_Paragraph("\n");
			_Paragraph(" User is Empty");
		}
	}
public:

	static void ShowFindUser()
	{
		_DrawHeaderScreen("Screen Find User");

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

