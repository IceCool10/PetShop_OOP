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
        DataBase();
        DataBase(DataBase const&);
        void operator=(DataBase const&);
        static DataBase* instance;
    public:
        ~DataBase();
        void Add_New_User(User* X);
        int Search_for(UserAttempt* X, int& ind);
        User* Get_User(int indice);
        static DataBase* Get_Instance()
        {
            if(instance == NULL)
                instance = new DataBase;
            return instance;
        }
};

#endif // DATABASE_H
