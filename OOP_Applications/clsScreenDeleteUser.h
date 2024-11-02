#pragma once
#include <iostream>
#include <string>
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsIOProcessor.h"
using namespace std;


class clsScreenDeleteUser : protected clsScreen
{

public:
	static void ShowDeleteUser()
	{
		_DrawHeaderScreen("Screen Delet User");

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
		
		clsUsers user = clsUsers::isFind(UserName, Id);

		char ansewr;

		if (user.isFound(UserName , Id))
		{
			user = clsUsers::isFind(UserName, Id);
			InformationUser();
			PrintInformationDataUser(user);
			_Paragraph("\n");
			_Paragraph("Do you Delete this User [Y/n] ? : ");
			cin >> ansewr;
			if (ansewr == 'y' || ansewr == 'Y')
			{
				user.Delete();
				_Paragraph("\n");
				_Paragraph("User is Delete");
			}
			else
			{
				_Paragraph("\n");
				_Paragraph("  User is Not Delete");
			}
			
		}
		else
		{
			_Paragraph("\n");
			_Paragraph(" User is Empty");
		}
		
	}
};

