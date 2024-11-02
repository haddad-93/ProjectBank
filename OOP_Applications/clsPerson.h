#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
using namespace std;

class clsPerson 
{
private:
    string _ID ;
    string _FirstName ;
    string _LastName ;
    string _BirthDate ;
    string _Gendar ;
    string _NumberPhone ;
    string _Email ;
    string _Country ;
    string _City ;
    string _Address ;
public:
    static string SpaceP(short space = 6)
    {
        string tab = "";
        for (short i = 1; i < space; i++)
        {
            tab += "\t";
        }
        return tab;
    }
    /*clsPerson()
    {
        _ID = "NULL";
        _FirstName = "NULL";
        _LastName = "NULL";
        _BirthDate = "NULL";
        _Gendar = "NULL";
        _NumberPhone = "NULL";
        _Email = "NULL";
        _Country = "NULL";
        _City = "NULL";
        _Address = "NULL";
    }*/


    clsPerson(string ID, string firstName, string lastName, string birthDate, string Gendar,
        string Phone, string Email, string Country, string City, string Address)
    {
        _ID = ID;
        _FirstName = firstName;
        _LastName = lastName;
        _BirthDate = birthDate;
        _Gendar = Gendar;
        _NumberPhone = Phone;
        _Email = Email;
        _Country = Country;
        _City = City;
        _Address = Address;
    }


    void setID(const string id) { _ID = id; }
    string getID() { return _ID; }
    __declspec(property(get = getID, put = setID)) string ID;

    void setFirstName(string FirstName) { _FirstName = FirstName; }
    string getFirstName() { return _FirstName; }
    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

    void setLastName(string LastName) { _LastName = LastName; }
    string getLastName() { return _LastName; }
    __declspec(property(get = getLastName, put = setLastName)) string LastName;

    void setBirthDate(short day, short month, short year)
    {
        _BirthDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
    void setBirthDate(string BirthDate)
    {
        _BirthDate = BirthDate;
    }
    string getBirthDate() { return _BirthDate; }
    __declspec(property(get = getBirthDate, put = setBirthDate)) string BirthDate;

    void setGendar(string Gendar) { _Gendar = Gendar; }
    string getGendar() { return _Gendar; }
    __declspec(property(get = getGendar, put = setGendar)) string Gendar;

    void setNumberPhone(string NumberPhone) { _NumberPhone = NumberPhone; }
    string getNumberPhone() { return _NumberPhone; }
    __declspec(property(get = getNumberPhone, put = setNumberPhone)) string NumberPhone;

    void setEmail(string Email) { _Email = Email; }
    string getEmail() { return _Email; }
    __declspec(property(get = getEmail, put = setEmail)) string Email;

    void setCountry(string Country) { _Country = Country; }
    string getCountry() { return _Country; }
    __declspec(property(get = getCountry, put = setCountry)) string Country;

    void setCity(string Ctiy) { _City = Ctiy; }
    string getCity() { return _City; }
    __declspec(property(get = getCity, put = setCity)) string City;

    void setAddress(string Address) { _Address = Address; }
    string getAddress() { return _Address; }
    __declspec(property(get = getAddress, put = setAddress)) string Address;

    string FullName()
    {
        return getFirstName() + " " + getLastName();
    }

    void SendEmail(string Subject, string Describe)
    {
        cout << SpaceP() << "hello my Dear : " << FullName() << endl;
        cout << SpaceP() << Subject << endl;
        cout << SpaceP() << Describe << endl;
        cout << SpaceP() << "Send Email To : " << getEmail() << endl;
    }

    void SendSMS(string message)
    {
        cout << SpaceP() << "hello my Dear : " << FullName() << endl;
        cout << SpaceP() << message << endl;
        cout << SpaceP() << "Send SMS to : " << getNumberPhone() << endl;
    }

    void PrintPerson()
    {
        cout << endl;
        cout << SpaceP() << "-------------------------------------------\n";
        cout << SpaceP() << "|           Information Person            |\n";
        cout << SpaceP() << "-------------------------------------------\n";
        cout << SpaceP() << "  Id CIN      : " << getID() << endl;
        cout << SpaceP() << "  FirstName   : " << getFirstName() << endl;
        cout << SpaceP() << "  LastName    : " << getLastName() << endl;
        cout << SpaceP() << "  Birth Date  : " << getBirthDate() << endl;
        cout << SpaceP() << "  Gendar      : " << getGendar() << endl;
        cout << SpaceP() << "  NumberPhone : " << getNumberPhone() << endl;
        cout << SpaceP() << "  Email       : " << getEmail() << endl;
        cout << SpaceP() << "  Country     : " << getCountry() << endl;
        cout << SpaceP() << "  Ctiy        : " << getCity() << endl;
        cout << SpaceP() << "  Address     : " << getAddress() << endl;
        cout << SpaceP() << "-------------------------------------------\n";
    }
    
    
};

