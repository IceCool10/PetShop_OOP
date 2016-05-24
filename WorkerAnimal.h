#pragma once
#ifndef WORKERANIMAL_H
#define WORKERANIMAL_H
#include "SuperClient.h"
class WorkerAnimal:public SuperClient
{
    public:
        static WorkerAnimal* GetInstance();
        virtual ~WorkerAnimal();
        animal* GenerareAnimal();
        int GenerarePret();

    protected:
    public:
        WorkerAnimal();
        static WorkerAnimal* Instance;
        void IncarcareNume();
        string GenerareNume();
        static vector<string> Nume;
        static int IdAnimal;

};

#endif // WORKERANIMAL_H
