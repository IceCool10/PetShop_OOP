#pragma once
#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED
#include "animal.h"
#include "reptile.h"
#include "sarpe.h"
#include "iguana.h"
#include "Mamifer.h"
#include "Iepure.h"
#include "Caine.h"
#include "Pisica.h"
#include "casier.h"
#include "testoasa.h"
#include "aqua.h"
#include "caracatita.h"
#include "foca.h"
#include "corb.h"
#include "papagal.h"
#include "pasari.h"
#include "peste.h"
#include "porumbel.h"
#include <ctime>
#include <stdlib.h>
class Worker {
    static const char *alphanum;
    int id_animal;
    int x;
public:
    virtual animal* Generate() {
    char charStr[100];
    srand (time(NULL));
    x = rand() % 500 + 100;
    int length = rand() % 8 + 3; ///generam o lungime random pentru nume
    for (int i = 0; i < length; ++i) {
        ///generam un nume random de lungime length
        charStr[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    charStr[length] = 0; /// punem caracterul NULL pe ultima pozitie
    id_animal = rand() % 12; /// generam efectiv un animal
    switch (id_animal) {
        case 0 : return new Caine(std::string (charStr),x);

        case 1 : return new Pisica(std::string (charStr),x);

        case 2 : return new Iepure(std::string (charStr),x);

        case 3 : return new Sarpe(std::string (charStr),x);

        case 4 : return new Iguana(std::string (charStr),x);

        case 5 : return new Papagal(std::string (charStr),x);

        case 6 : {return new Papagal(std::string (charStr),x);break;}

        case 7 : {return new Porumbel(std::string (charStr),x);break;}

        case 8 : {return new Corb(std::string (charStr),x);break;}

        case 9 : {return new Peste(std::string (charStr),x);break;}

        case 10 : {return new Foca(std::string (charStr),x);break;}

        case 11 : {return new Caracatita(std::string (charStr),x);break;}
    }
}

};

#endif // WORKER_H_INCLUDED
