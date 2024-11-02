#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include "clsPerson.h"
using namespace std;

class clsBankClient  : public clsPerson 

{
private:
    enum enMode { EmptyMode = 0, UpdqteMode =1 , AddNweClient =2 };
    enMode _Mode;

    string _AccountNumber ;
    string _PinCode ;
    double _AccountBalanse = 0;
    bool _MarkForDelete = true;

    static vector <string> _Splite(string line, string Separate = "#//#")
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

    static clsBankClient _ConvertLineToClientObject(string line)
    {
        vector <string> vClientData;
        vClientData = _Splite(line);
        return clsBankClient(enMode::UpdqteMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
            vClientData[5], vClientData[6], vClientData[7], vClientData[8], vClientData[9], vClientData[10], vClientData[11], stod(vClientData[12]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode,"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0);
    }

    static string _convertObjectToLineString(clsBankClient cl , string Seperator = "#//#")
    {
        string line;
        line = cl.ID + Seperator;
        line += cl.FirstName + Seperator;
        line += cl.LastName + Seperator;
        line += cl.BirthDate + Seperator;
        line += cl.Gendar + Seperator;
        line += cl.NumberPhone + Seperator;
        line += cl.Email + Seperator;
        line += cl.Country + Seperator;
        line += cl.City + Seperator;
        line += cl.Address + Seperator;
        line += cl.getAccountNumber() + Seperator;
        line += cl.PinCode + Seperator;
        line += to_string(cl.AccountBalanse);
        return line;
    }        

    static vector <clsBankClient> _LoadDataFromFile()
    {
        fstream myFile;
        vector <clsBankClient> vCline;
        string line;

        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            while (getline(myFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                vCline.push_back(client);
            }
            myFile.close();
        }
        return vCline;
    }

    static clsBankClient _AddClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNweClient,"","", "", "", "","", "", "", "", "", AccountNumber, "", 0);
    }

    void _SaveDataToFileByVector(vector <clsBankClient> vLoad)
    {
       fstream myFile;
       string line;
       myFile.open("Clients.txt", ios::out);
       if (myFile.is_open())
       {
           for (clsBankClient & clnt : vLoad)
           {
               if (clnt.MarketForDelete())
               {
                   line = _convertObjectToLineString(clnt);
                   myFile << line << endl;
               }
           }
           myFile.close();
       }
    }

    void _SaveDataToFile(clsBankClient Save)
    {
        fstream myFile;
        string line;
        myFile.open("Clients.txt", ios::out | ios::app );
        if (myFile.is_open())
        {    
            line = _convertObjectToLineString(Save);
            myFile << line << endl;
            myFile.close();
        }
    }

    void _Updete()
    {
      vector <clsBankClient> vLoad = _LoadDataFromFile();
       for (clsBankClient & clnt : vLoad)
       {
           if(clnt.getAccountNumber() == getAccountNumber())
           {
               clnt = *this;
               break;
           }
       }
       _SaveDataToFileByVector(vLoad);
    }


public:
    /*clsBankClient()
    {
        _AccountNumber = "NULL";
        _PinCode = "NULL";
        _AccountBalanse = 0;
        _Mode = enMode::EmptyMode;
    }*/
    clsBankClient(enMode Mode , string ID, string firstName, string lastName, string birthDate, string Gendar, string Phone, string Email,
        string Country, string City, string Address, string AccountNumber, string PinCode, double AccountBalanse) :
        clsPerson(ID, firstName, lastName, birthDate, Gendar, Phone, Email, Country, City, Address)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalanse = AccountBalanse;
    }

   // void setAccountNumber(string AccountNumber) { _AccountNumber = AccountNumber; }

    string getAccountNumber() { return _AccountNumber;}
   //__declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;


    void setPinCode(string PinCode) { _PinCode = PinCode;}
    string getPinCode() {return _PinCode;}
    __declspec(property(get = getPinCode, put = setPinCode)) string PinCode;


    void setAccountNumber(double AccountBalanse) {_AccountBalanse = AccountBalanse;}
    double getAccountBalanse() { return _AccountBalanse; }
    __declspec(property(get = getAccountBalanse, put = setAccountNumber)) double AccountBalanse;

    bool MarketForDelete()
    {
        return _MarkForDelete;
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream myFile;
        vector <clsBankClient> vClient;
        string Line;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            while (getline(myFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.getAccountNumber() == AccountNumber)
                {
                    myFile.close();
                    return Client;
                }
                vClient.push_back(Client);
            }
            myFile.close();
        }
        return _GetEmptyClientObject();
    }

    bool isEmpty()
    {
        return (_Mode == enMode::UpdqteMode);
    }


    static bool isClientExist(string AccountNamber)
    {
       clsBankClient client =  clsBankClient::Find(AccountNamber);
       return(client.isEmpty());
    }
    static vector <clsBankClient> GetAllClient()
    {
        return _LoadDataFromFile();
    }
    static clsBankClient setAddNewClient(string AccountNumber)
    {
        return _AddClient(AccountNumber);
    }

    void Deposit(double Amount)
    {
        _AccountBalanse += Amount;
        _Updete();
    }

    bool WithDraw(double Amount)
    {
        if (AccountBalanse > Amount)
        {
            AccountBalanse -= Amount;
            _Updete();
            return true;
            
        }
        return false;
    }

    static double TotalBalinsace()
    {
        double Total = 0;

        vector <clsBankClient> vTl = _LoadDataFromFile();
        for (clsBankClient& cls : vTl)
        {
            Total += cls.AccountBalanse;
        }
        return Total;
    }
   
    bool Delete()
    {
        vector <clsBankClient> vLoad = _LoadDataFromFile();
        for (clsBankClient & cls : vLoad)
        {
            if (cls.getAccountNumber() == getAccountNumber())
            {
                cls._MarkForDelete = false;
                break;
            }
        }
        _SaveDataToFileByVector(vLoad);
        *this = _GetEmptyClientObject();
        return true;
    }

    enum enSaveRuselt { svObjectEmpty = 0, svSuccuded = 1 , svAddClient = 2};

    enSaveRuselt Save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
            return clsBankClient::enSaveRuselt::svObjectEmpty;
            break;
        case clsBankClient::UpdqteMode:
            _Updete();
            return clsBankClient::enSaveRuselt::svSuccuded;
            break;
        case clsBankClient::AddNweClient:
            _SaveDataToFile(*this);
            return clsBankClient::enSaveRuselt::svAddClient;
            break;
        default:
            break;
        }
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient)
    {
        if (AccountBalanse > Amount )
        {
            DestinationClient.Deposit(Amount);
            WithDraw(Amount);
            return true;
        }
        return false;
    }

    /*void Print()
    {
        cout << endl;
        cout << Space() << "-------------------------------------------\n";
        cout << Space() << "|           Information Client            |\n";
        cout << Space() << "-------------------------------------------\n";
        cout << Space() << "  Id CIN          : " << getID() << endl;
        cout << Space() << "  FirstName       : " << getFirstName() << endl;
        cout << Space() << "  LastName        : " << getLastName() << endl;
        cout << Space() << "  Birth Date      : " << getBirthDate() << endl;
        cout << Space() << "  Gendar          : " << getGendar() << endl;
        cout << Space() << "  NumberPhone     : " << getNumberPhone() << endl;
        cout << Space() << "  Email           : " << getEmail() << endl;      
        cout << Space() << "  Country         : " << getCountry() << endl;
        cout << Space() << "  Ctiy            : " << getCity() << endl;
        cout << Space() << "  Address         : " << getAddress() << endl;
        cout << Space() << "  Account Number  : " << getAccountNumber() << endl;
        cout << Space() << "  Pin Code        : " << getPinCode() << endl;
        cout << Space() << "  Account Balance : " << getAccountBalanse() << endl;
        cout << Space() << "-------------------------------------------\n";
    }*/
};