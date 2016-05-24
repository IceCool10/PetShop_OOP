#pragma once
#ifndef SUPERCLIENT_H
#define SUPERCLIENT_H
#include <iostream>
#include "Client.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "animal.h"
#include "sarpe.h"
#include "iguana.h"
#include "caine.h"
#include "Pisica.h"
#include "Iepure.h"
#include "caracatita.h"
#include "corb.h"
#include "papagal.h"
#include "foca.h"
#include "peste.h"
#include "porumbel.h"
#include "testoasa.h"
#include <unordered_map>
class SuperClient
{
    public:
        SuperClient();
        virtual void IncarcareNume(){};
   //     virtual std::string GenerareNumar()=0;
        virtual ~SuperClient();
    protected:
    private:
};

#endif // SUPERCLIENT_H
