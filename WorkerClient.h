#pragma once
#ifndef WORKERCLIENT_H
#define WORKERCLIENT_H
#include "SuperClient.h"
class WorkerClient : public SuperClient
{
    public:
        static WorkerClient* GetInstance();
        virtual ~WorkerClient();
        Client* GenerareClient();
        WorkerClient();
    protected:
    private:
        static WorkerClient* Instance;
        int GenerareAnimal();
        void IncarcareNume();
        string GenerareNume();
        static vector<string> Nume;
        static int IdClient;
};

#endif // WORKERCLIENT_H
