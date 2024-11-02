#pragma once
#include <iostream>
#include <string>
#include<iomanip>  // this library stored the std::setw
#include"clsScreen.h"
#include"clsScreenListCurrency.h"
#include"clsFindCurrency.h"
#include"clsUpdeteCurrency.h"
#include "clsCalculatorCurrency.h"



class clsScreenMainCurrency : protected clsScreen
{
private:
    enum enCurrency{ enList = 1 , enFind = 2 , enUpdete = 3 , enCurrencyCalculator = 4 , enMainMenue = 5};

    static enCurrency InputOption()
    {
        int num = clsIOProcessor::NumberBetween(1, 5);
        return enCurrency(num);
    }

    static void _GoBack()
    {
        cout << "\n\n" << Space() << "Press any key to continue Main Menue......";
        system("pause>0");
        ShowScreenCurrency();
    }

    static void _ListCurrency()
    {
        system("cls");
        clsScreenListCurrency::ShowCurrencyList();
    }

    static void _FindCurrency()
    {
        system("cls");
        clsFindCurrency::ShowFindCurrency();
    }

    static void _UpdeteCurrency()
    {
        system("cls");
        clsUpdeteCurrency::ShowUpdeteCurrency();
    }

    static void _CurrencyCalculrtor()
    {
        system("cls");
        clsCalculatorCurrency::ShowCalcullatorCurrency();
    }

    static void _MainMenue()
    {
        system("cls");
        cout << Space() << "|       [5] Main Menue                            |\n";
    }

    static void _PerfromMainCurrency( enCurrency Currency)
    {
        switch (Currency)
        {
        case clsScreenMainCurrency::enList:
            _ListCurrency();
            _GoBack();
            break;
        case clsScreenMainCurrency::enFind:
            _FindCurrency();
            _GoBack();
            break;
        case clsScreenMainCurrency::enUpdete:
            _UpdeteCurrency();
            _GoBack();
            break;
        case clsScreenMainCurrency::enCurrencyCalculator:
            _CurrencyCalculrtor();
            _GoBack();
            break;
        case clsScreenMainCurrency::enMainMenue:
            _MainMenue();
            break;
        default:
            break;
        }
    }
public:
	static void ShowScreenCurrency()
	{
        system("cls");
		_DrawHeaderScreen("Currancy Exhange Main Screen");
        cout << Space() << "===================================================\n";
        cout << Space() << "|                     Main Menue                  |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << Space() << "|       [1] List Currencies                       |\n";
        cout << Space() << "|       [2] Find Currency                         |\n";
        cout << Space() << "|       [3] Update Rate                           |\n";
        cout << Space() << "|       [4] Currency Calculator                   |\n";
        cout << Space() << "|       [5] Main Menue                            |\n";
        cout << Space() << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

        enCurrency cr = InputOption();
        _PerfromMainCurrency(cr);
	}
};

