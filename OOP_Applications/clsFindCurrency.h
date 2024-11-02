#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>  // this library stored the std::setw
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsFindCurrency : protected clsScreen
{
private :
	static void _PrintHeader()
	{
		cout << "=========================================================================================================================\n";
		cout << "                          <<<<<<<<<>>>>>>>>  Information Currency  <<<<<<<<<>>>>>>>>" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		cout << "                  Country                   |   CurrencyCode    |         CurrencyName            |  Rates $  \n";
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	}

	static void _Print(clsCurrency cls)
	{
		cout << " " << left << setw(43) << cls.getCountry();
		cout << "|" << left << setw(19) << cls.getCurrencyCode();
		cout << "|" << left << setw(33) << cls.getCurrencyName();
		cout << "|" << left << setw(29) << cls.getRate();
	}

	static clsCurrency _FindCurrency()
	{
		_Paragraph("Enter Currency Code : ");
		string CurrencyCode = clsIOProcessor::RaedText();
		while (!clsCurrency::isExistingCode(CurrencyCode))
		{
			_Paragraph("No Found Currency Agiane Enter Currency Code\n\n");
			_Paragraph("Enter Currency Code : ");
			CurrencyCode = clsIOProcessor::RaedText();
		}
		clsCurrency Currency = clsCurrency::FindCurrencyCode(CurrencyCode);
		return Currency;
	}
public:
	static void ShowFindCurrency()
	{
		_DrawHeaderScreen("Screen Find Currency");
		clsCurrency CUrrency = _FindCurrency();
		_PrintHeader();
		_Print(CUrrency);
	}
		
};

