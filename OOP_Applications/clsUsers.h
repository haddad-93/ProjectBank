#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include"clsScreen.h"
#include "clsPerson.h"
#include"clsIOProcessor.h"
const string FileUers = "User.txt";

using namespace std;

class clsUsers : public clsPerson 
{
private:
    string _UserName;
    int _Permissions;
    string _DateTime ;
    bool _MarkForDelete = true;
    bool _isFound = false;

    struct  stRegisterLogin;

    static string _convertObjectToLineString(clsUsers cl, string Seperator = "#//#")
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
        line += cl.getUserName() += Seperator;
        line += to_string(cl.getPermissions());
        return line;
    }

    string _convertObjectUserLoginToLine(string Seperator = "#//#")
    {
        string line = "";
        line += clsIOProcessor::DateTime() + Seperator;
        line += getUserName() + Seperator;
        line += ID + Seperator;
        line += FullName() + Seperator;
        line += to_string(getPermissions());

        return line;
    }

    static void _SaveDataToFile(clsUsers Save)
    {
        fstream myFile;
        string line;
        myFile.open("User.txt", ios::out | ios::app);
        if (myFile.is_open())
        {
            line = _convertObjectToLineString(Save);
            myFile << line << endl;
            myFile.close();
        }
    }

    void _SaveDataToFileByVector(vector <clsUsers> vLoad)
    {
        fstream myFile;
        string line;
        myFile.open("User.txt", ios::out);
        if (myFile.is_open())
        {
            for (clsUsers & clnt : vLoad)
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

    static clsUsers _ConvertLineToUserObject(string line)
    {
        vector <string> vClientData = _Splite(line);

        return clsUsers(vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
            vClientData[5], vClientData[6], vClientData[7], vClientData[8], vClientData[9], vClientData[10], stoi(vClientData[11]));
    }

    static vector <clsUsers> _LoadDataUserFromFile()
    {
        fstream myFile;
        vector <clsUsers> vCline;
        string line;

        myFile.open("User.txt", ios::in);
        if (myFile.is_open())
        {
            while (getline(myFile, line))
            {
                clsUsers client = _ConvertLineToUserObject(line);
                vCline.push_back(client);
            }
            myFile.close();
        }
        return vCline;
    }

    static clsUsers _AddUser(string Id, string UserName)
    {
       return clsUsers(Id, "", "", "", "", "", "", "", "", "", UserName,0);
    }

    static clsUsers _getEmptyObject()
    {
        return clsUsers("", "", "", "", "", "", "", "", "", "", "",0);
    }

    static stRegisterLogin _ConvertLineToUserLogin(string line)
    {
        stRegisterLogin rgl;
        vector <string> vLine = _Splite(line);
        rgl.Date = vLine[0];
        rgl.UserName = vLine[1];
        rgl.ID = vLine[2];
        rgl.FullName = vLine[3];
        rgl.Pirmissions = stoi(vLine[4]);
        return rgl;
    }

public:
    
    struct stRegisterLogin
    {
        string Date;
        string UserName;
        string ID;
        string FullName;
        int Pirmissions = 0;
    };

    enum enPermissions { pAll = -1, pList = 1, pSearch = 2, pAdd = 4, pUpdete = 8, pDelet = 16, pTrsnsaction = 32, pManageUser = 64 , pRegisterLogin = 128 };

    clsUsers(string ID, string firstName, string lastName, string birthDate, string Gendar,
        string Phone, string Email, string Country, string City, string Address, string UserName , int Permissions):
        clsPerson (ID, firstName, lastName, birthDate, Gendar, Phone, Email, Country, City, Address)
    {
        _UserName = UserName;
        _Permissions = Permissions;
    }
    
    static vector <stRegisterLogin> GetRegisterLogin()
    {
        fstream myFile;
        vector <stRegisterLogin> vLogin;
        string line;
        stRegisterLogin log;
        myFile.open("LoginUser.txt", ios::in);
        if (myFile.is_open())
        {

            while (getline(myFile, line))
            {
                log = _ConvertLineToUserLogin(line);
                vLogin.push_back(log);
            }
            myFile.close();
        }
        return vLogin;
    }

    string getUserName()
    {
        return _UserName;
    }

    void setPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int getPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = getPermissions, put = setPermissions)) int Permissions;

    bool MarketForDelete()
    {
        return _MarkForDelete;
    }

    static bool isFound(string UserName , string Id)
    {
        clsUsers user = clsUsers::isFind(UserName, Id);
        return user._isFound;
    }

    static clsUsers isFind(string UserName, string ID)
    {
        vector <clsUsers> vUser = _LoadDataUserFromFile();

        for (clsUsers& us : vUser)
        {
            if (us.getID() == ID && us.getUserName() == UserName)
            {
                us._isFound = true;
                return us;
            }
        }
        return _getEmptyObject();
    }

    static vector <clsUsers> GetAllUsers()
    {
        return _LoadDataUserFromFile();
    }

    bool Delete()
    {
        vector <clsUsers> vLoad = _LoadDataUserFromFile();
        for (clsUsers & cls : vLoad)
        {
            if (cls.getUserName() == getUserName())
            {
                cls._MarkForDelete = false;
                break;
            }
        }
        _SaveDataToFileByVector(vLoad);
        return true;
    }

    void Updete()
    {
        vector <clsUsers> vLoad = _LoadDataUserFromFile();
        for (clsUsers & clnt : vLoad)
        {
            if (clnt.getUserName() == getUserName())
            {
                clnt = *this;
                break;
            }
        }
        _SaveDataToFileByVector(vLoad);
    }

    static clsUsers AddUser(string Id, string UserName)
    {
        return _AddUser(Id, UserName);
    }

    static bool Save(clsUsers user )
    {
        
        if (user.getUserName() != "" && user.getID() != "")
        {
            _SaveDataToFile(user);
            return true;
        }
        return false;
    }

    bool CheckAcssesPermissions(enPermissions Permissions)
    {
        if (_Permissions == enPermissions::pAll)
            return true;
        if ((_Permissions & Permissions) == Permissions)
            return true;
        return false;
    }

    void SaveLoginUser()
    {
        fstream myFile;
        string line;
        myFile.open("LoginUser.txt", ios::out | ios::app);
        if (myFile.is_open())
        {
            line = _convertObjectUserLoginToLine();
            myFile << line << endl;
            myFile.close();
        }
    }

	
};

