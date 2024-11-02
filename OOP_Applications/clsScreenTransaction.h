#pragma once
#include <iostream>
#include <string>
#include "clsIOProcessor.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsScreenMainMenue.h"
#include "clsScreenTransfer.h"

using namespace std;

class clsScreenTransaction : protected clsScreen
{
private :
    enum enTransactions { enDeposit = 1, enWithdraw = 2, enTotal = 3, enTransfer = 4, enMainMenue = 5 };

    static void _Deposit()
    {
        string AccountNumber;
        _DrawHeaderScreen("Screen Deposit Cliant ");
        _Paragraph("Enter Account Number : ");
        AccountNumber = clsIOProcessor::RaedText();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            _Paragraph("no found This Client Ente new Account Number : ");
            AccountNumber = clsIOProcessor::RaedText();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        PrintClient(Client);
        
        _Paragraph("Enter Amount Deposit : ");
        double Amount = clsIOProcessor::ReadNumber();
        Client.Deposit(Amount);
        _Paragraph("Your Balansac is : " , Client.AccountBalanse);

    }

    static void _WithDraw()
    {
        string AccountNumber;
        _DrawHeaderScreen("Screen withDrow");
        _Paragraph("Enter Account Number : ");
        AccountNumber = clsIOProcessor::RaedText();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            _Paragraph("no found This Client Ente new Account Number : ");
            AccountNumber = clsIOProcessor::RaedText();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        PrintClient(Client);

        _Paragraph("Enter Amount withDraw : ");
        double Amount = clsIOProcessor::ReadNumber();
        if (Client.WithDraw(Amount))
        {
            _Paragraph("Your Balansac is : ", Client.AccountBalanse);
        }
        else
        {
            _Paragraph("cannot withDraw more : ", Client.getAccountBalanse());
        }
       
    }

    static void _TotalBalansace()
    {
        _DrawHeaderScreen("Screen Total Balancase ");
        InformationBalances();
        double Total = 0;
        vector <clsBankClient> vTl = clsBankClient::GetAllClient();
        for (clsBankClient& cls : vTl)
        {
            ShowBalances(cls);
            Total += cls.AccountBalanse;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        _Paragraph("Tatal Balancase : ", Total);
    }

    static void _Transfer()
    {
        clsScreenTransfer::ShowTransfer();
    }

    static void _MainMenue()
    {
        //cout << "\n\n" << Space() << "Press any key to continue Main Menue......";
    }

    static void _TransactionClient(enTransactions transction)
    {
        switch (transction)
        {
        case clsScreenTransaction::enDeposit:
            system("cls");
            _Deposit();
            system("pause>0");
            ShowTransaction();
            
            break;
        case clsScreenTransaction::enWithdraw:
            system("cls");
            _WithDraw();
            system("pause>0");
            ShowTransaction();
            break;
        case clsScreenTransaction::enTotal:
            system("cls");
            _TotalBalansace();
            system("pause>0");
            ShowTransaction();
            break;
        case clsScreenTransaction::enTransfer :
            system("cls");
            _Transfer();
            system("pause>0");
            ShowTransaction();
            break;
        case clsScreenTransaction::enMainMenue:
            _MainMenue();
            break;
        default:
            break;
        }
    }

public :
	static void ShowTransaction()
	{
        system("cls");
        _DrawHeaderScreen("Screen Menue Transaction");
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|         Transaction  screen                     |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|       [1] Deposit                               |\n";
        cout << Space() << "|       [2] Withdraw                              |\n";
        cout << Space() << "|       [3] Total                                 |\n";
        cout << Space() << "|       [4] Transfer                              |\n";
        cout << Space() << "|       [5] Main Menue                            |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        _TransactionClient(enTransactions(clsIOProcessor::NumberBetween(1, 5)));
	}
};

