#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsIOProcessor.h"
#include"clsScreen.h"
using namespace std;

class lsScreenDeleteClient : protected clsScreen
{
public:
	static void ShowDeleteClient()
	{
        string AccountNumber;
        _DrawHeaderScreen("Screen Updete Client");
        _Paragraph("Enter Account Number : ");
        AccountNumber = clsIOProcessor::RaedText();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            _Paragraph(" Account Number is not found  : ");
            AccountNumber = clsIOProcessor::RaedText();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        PrintClient(client);
        char ansewr;
        
        _Paragraph("Do you want Delete this Client [Y/n]? : ");
       
        cin >> ansewr;
        if (ansewr == 'y' || ansewr == 'Y')
        {
            if (client.Delete())
            {
                _Paragraph(" Client is Delete \n");
                PrintClient(client);
            }
            else
            {
                _Paragraph(" no delet Client \n");
            }
        }
	}

};

