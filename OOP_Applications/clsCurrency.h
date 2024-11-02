#pragma once
#include<iostream>
#include<string>
#include"clsIOProcessor.h"
#include <vector>
#include <fstream>

using namespace std;
class clsCurrency
{
private : 
	enum enMode { EmptyMode = 0 , UpdeteMode =1 };

    enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
    
    static clsCurrency _ConvertLineToOpjectCurrency(string line)
    {
        vector <string> vCurr = clsIOProcessor::Splite(line);
        return clsCurrency(enMode::UpdeteMode, vCurr[0], vCurr[1], vCurr[2], stof(vCurr[3]));
    }

    static vector <clsCurrency> _getAllCurrency()
    {
        fstream MyFile;
        string Line;
        vector <clsCurrency> vCrrny;
        MyFile.open("Currencies.txt", ios::in);
        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToOpjectCurrency(Line);
                vCrrny.push_back(Currency);
            }
            MyFile.close();
        }
        return vCrrny;
    }

    static clsCurrency getEmptyOpject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

    static string _ConvertOpjectToLine(clsCurrency cls, string Separate = "#//#")
    {
        string line = "";
        line = cls.getCountry() + Separate + cls.getCurrencyCode() + Separate + cls.getCurrencyName() + Separate + to_string(cls.getRate());
        return line;
    }

    void _SaveUpdete(vector <clsCurrency>  vCurrency)
    {
        fstream MyFile;
        string line;
        MyFile.open("Currencies.txt", ios::out);
        if (MyFile.is_open())
        {
            for (clsCurrency cls : vCurrency)
            {
                line = _ConvertOpjectToLine(cls);
                MyFile << line << endl;
            }
            MyFile.close();
        }
    }
    
    void _Updete()
    {
        vector <clsCurrency> vCurrency = _getAllCurrency();
      
            for (clsCurrency & Currency : vCurrency)
            {
                if (Currency.getCurrencyCode() == getCurrencyCode())
                {
                    Currency = *this;
                    break;
                }
            }
            _SaveUpdete(vCurrency);
    }

public:

    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    string getCountry()
    {
        return _Country;
    }

    string getCurrencyCode()
    {
        return _CurrencyCode;
    }

    string getCurrencyName()
    {
        return _CurrencyName;
    }

    void setRate(float Rate)
    {
        _Rate = Rate;
        _Updete();
    }

    float getRate()
    {
        return _Rate;
    }

    static vector <clsCurrency> getAllCurrency()
    {
        return _getAllCurrency();
    }

    static clsCurrency FindCurrencyCode(string CurrencyCode)
    {

       string crnc = clsIOProcessor::CapitalLetters(CurrencyCode);

        vector <clsCurrency> vCurrency = _getAllCurrency();
        for (clsCurrency & Currency : vCurrency)
        {
            if (Currency.getCurrencyCode() == crnc)
            {
                return Currency;
            }
        }
        return getEmptyOpject();
    }

    static clsCurrency FindCurrencyName(string CurrencyName)
    {
        CurrencyName = clsIOProcessor::CapitalLetters(CurrencyName);

        vector <clsCurrency> vCurrency = _getAllCurrency();
        for (clsCurrency& Currency : vCurrency)
        {
            if (clsIOProcessor::CapitalLetters(Currency.getCurrencyName()) == CurrencyName)
            {
                return Currency;
            }
        }
        return getEmptyOpject();
    }

    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static bool isExistingCode(string Code)
    {
        clsCurrency cls = clsCurrency::FindCurrencyCode(Code);
        return !cls.isEmpty();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / getRate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);
        if (Currency2.getCurrencyCode() == "USD")
        {
            return AmountInUSD;
        }
        return (float)(AmountInUSD * Currency2.getRate());
    }
};

