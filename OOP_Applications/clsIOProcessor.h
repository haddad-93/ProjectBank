#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class clsIOProcessor
{
public:

    static string Space(short space = 6)
    {
        string tab = "";
        for (short i = 1; i < space; i++)
        {
            tab += "\t";
        }
        return tab;
    }

    static double ReadNumber()
    {
        double Number;
        cin >> Number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Space() << " Input Only Number : ";
            Number = ReadNumber();
        }
        return double(Number);
    }

    static double NumberBetween(double num1, double num2)
    {
        double number;
        cout << Space() << " Enter Number from " << num1 << " to " << num2 << " : ";
        number = ReadNumber();
        while (number < num1 || number > num2)
        {
            cout << Space() << " Enter Number from " << num1 << " to " << num2 << " : ";
            number = ReadNumber();
        }
        return number;
    }

    static string RaedText()
    {
        string text = "";
        getline(cin >> ws, text);
        return text;
    }

    static char ReadCHAR()
    {
        char ch ;
        
        cin >> ch;
        return ch;
    }

    static string CapitalLetters(string input)
    {
        string result = input;
        for (char & c : result)
        {
            c = toupper(c);
        }
        return result;
    }

    static string SmallLetters(string input)
    {
        string result = input;
        for (char& c : result)
        {
            c = tolower(c);
        }
        return result;
    }

    static vector <string> Splite(string line, string Separate = "#//#")
    {
        string word = "";
        int pos = 0;
        vector <string> vLine = vLine;
        while ((pos = line.find(Separate)) != std::string::npos)
        {
            word = line.substr(0, pos);
            if (word != "")
            {
                vLine.push_back(word);
            }
            line.erase(0, pos + Separate.length());
        }
        if (line != "")
        {
            vLine.push_back(line);
        }
        return vLine;
    }

    static string DateTime()
    {
        time_t t = time(0); // get time now 
        tm* now = localtime(&t);

        string Date = "";

        Date = to_string(now->tm_year + 1900);
        Date += "/" + to_string(now->tm_mon + 1);
        Date += "/" + to_string(now->tm_mday);
        Date += " | " + to_string(now->tm_hour);
        Date += ":" + to_string(now->tm_min);
        Date += ":" + to_string(now->tm_sec);

        return Date;
    }
};

