#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>  // this library stored the std::setw
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;

class clsCalculatorCurrency : protected clsScreen
{
private:
	static void _PrintHeader()
	{
		cout << "=========================================================================================================================\n";
		cout << "                          <<<<<<<<<>>>>>>>>  Information Currency  <<<<<<<<<>>>>>>>>" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
		cout << "                  Country                   |   CurrencyCode    |         CurrencyName            |  Rates $ \n";
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

	static float _Dollar()
	{
		clsCurrency Currency = clsCurrency::FindCurrencyCode("USD");
		return Currency.getRate();
	}

public:

	static void ShowCalcullatorCurrency()
	{
		
		_DrawHeaderScreen("Screen Calculator Currency");
		char Ansewr = 'y';

		while (Ansewr == 'y')
		{
			_Paragraph("Enter Currency1 Code : ");
			clsCurrency CurrencyTo = _FindCurrency();
			_PrintHeader();
			_Print(CurrencyTo);


			cout << "\n\n\n";
			_Paragraph("Enter Currency2 Code : ");
			clsCurrency CurrencyFrom = _FindCurrency();
			_PrintHeader();
			_Print(CurrencyFrom);

			cout << "\n\n\n";

			_Paragraph("Enter Amount : ");
			float Amount = clsIOProcessor::ReadNumber();

			_Paragraph(to_string(Amount)+ " "+CurrencyTo.getCurrencyName() + " = " +to_string(CurrencyTo.ConvertToUSD(Amount))+ " USD");

			cout << "\n";
			_Paragraph(to_string(Amount) + " " + CurrencyTo.getCurrencyName() + " = " + 
		      to_string(CurrencyTo.ConvertToOtherCurrency(Amount,CurrencyFrom)) + " "+CurrencyFrom.getCurrencyName());

			
			cout << "\n\n";
			_Paragraph("Do you want Again Calculator ? : ");
			Ansewr = clsIOProcessor::ReadCHAR();
		}

		
		

		
		
		
		
	}
};

