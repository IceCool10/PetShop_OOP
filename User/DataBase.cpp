#include "DataBase.h"
#include <iostream>
#include "UserAttempt.h"
#include "Util.h"

DataBase* DataBase::instance = 0;

DataBase::DataBase()
{
    std::fstream in("database.in", ios::in | ios::out | ios::app);

    string username;
    string password;
    string date;

    while(getline(in, username), getline(in, password), getline(in, date))
            Load_Accounts(username, password, this, date);

    in.close();
}

DataBase::~DataBase()
{
    Admins.clear();
}

//adauga un User nou in vectorul de Useri
void DataBase::Add_New_User(User* X)
{
    Admins.push_back(X);
}

//verifica daca un User exista in vectorul Useri si, in caz ca il gaseste, retine indicele la care l-a gasit
int DataBase::Search_for(UserAttempt* X, int &ind)
{
    int i;
    for(i=0; i<Admins.size(); i++)
    {
        if(*X == *Admins[i])
        {
            ind=i;
            return 1;
        }
    }
    return 0;
}

//functie care returneaza User-ul de la pozitia indice
User* DataBase::Get_User(int indice)
{
    return Admins[indice];
}
