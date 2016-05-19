#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "User.h"

using namespace std;

class UserAttempt;

class DataBase
{
    private:
        vector <User*> Admins;
        DataBase(){}
    public:
        ~DataBase();
        void Add_New_User(User* X);
        int Search_for(UserAttempt* X, int& ind);
        friend void New_User(User* X, DataBase Y);
        User* Get_User(int indice);
        static DataBase * create()
        {
            static DataBase obj;
            return &obj;
        }
};

#endif // DATABASE_H
