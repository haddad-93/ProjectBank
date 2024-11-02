#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsIOProcessor.h"
#include"clsScreen.h"
using namespace std;

class clsScreenFindClient:protected clsScreen
{
public:
    static void ShowFindClient()
    {
        string AccountNumber;
        _DrawHeaderScreen("Screen Find Cliant ");
        _Paragraph("Enter Account Number : ");
        AccountNumber = clsIOProcessor::RaedText();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            _Paragraph("no found This Client Ente new Account Number : ");
            AccountNumber = clsIOProcessor::RaedText();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
       
        PrintClient(Client);
    }
};

