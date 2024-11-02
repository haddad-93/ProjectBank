#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsIOProcessor.h"
#include"clsScreen.h"
using namespace std;

class clsScreenTransfer : protected clsScreen
{
private:
    static string _AccountNumber()
    {
        string AccountNumber;
        AccountNumber = clsIOProcessor::RaedText();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            _Paragraph("no found This Client Ente new Account Number : ");
            AccountNumber = clsIOProcessor::RaedText();
        }
        return AccountNumber;
    }

public:
    static void ShowTransfer()
    {
        _DrawHeaderScreen("Screen Transfer Amount ");

        _Paragraph("Enter Source Account Number : ");
        clsBankClient Source = clsBankClient::Find(_AccountNumber());
        Information();
        PrintInformationDataClient(Source);

        cout << "\n\n";
        _Paragraph("Enter Destination Account Number : ");
        clsBankClient Destination = clsBankClient::Find(_AccountNumber());

        Information();
        PrintInformationDataClient(Destination);
        
        cout << "\n\n\n";
        _Paragraph("Enter Amount  : ");

        float Amount = clsIOProcessor::ReadNumber();

        if (Source.Transfer(Amount, Destination))
        {
            cout << "\n\nSource      : " << Source.AccountBalanse << "\n\n";
            cout << "Destination : " << Destination.AccountBalanse << "\n\n";
        }

    }

};

