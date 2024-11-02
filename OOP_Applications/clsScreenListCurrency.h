#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>  // this library stored the std::setw
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsScreenListCurrency : protected clsScreen
{
private :
	static void PrintHeader()
	{
		cout << "=========================================================================================================================\n";
		cout << "                          <<<<<<<<<>>>>>>>>  Information Currency  <<<<<<<<<>>>>>>>>" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		cout << "                  Country                   |   CurrencyCode    |         CurrencyName            | Rates $  \n";
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	}
	static void _Print(clsCurrency cls)
	{
		cout << " " << left << setw(43)  << cls.getCountry();
		cout << "|" << left << setw(19)  << cls.getCurrencyCode();
		cout << "|" << left << setw(33) << cls.getCurrencyName();
		cout << "|" << left << setw(29) << cls.getRate();
	}
public :
	static void ShowCurrencyList()
	{
		_DrawHeaderScreen("Screen List Currency");
		PrintHeader();
		vector <clsCurrency> vCurrency = clsCurrency::getAllCurrency();
		for (clsCurrency& cls : vCurrency)
		{
			_Print(cls);
		}
	}
};

