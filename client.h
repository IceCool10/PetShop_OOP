#pragma once
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
#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

class Client {
private:
    int id_animal;
    static int idclient;
    animal* anim;
public:
    int getIdClient();
    static void increment();
    static void decrement();
    animal* getAnimal();
 void Generate() {
    srand(time(NULL));
    id_animal = rand() % 12; /// generam efectiv un animal
    switch (id_animal) {
        case 0 : {anim = new Caine();  break;}

        case 1 : {anim = new Pisica(); break;}

        case 2 : {anim = new Iepure(); break;}

        case 3 : {anim = new Sarpe();  break;}

        case 4 : {anim = new Iguana(); break;}

        case 5 : {anim = new Testoasa();break;}

        case 6 : {anim = new Papagal();break;}

        case 7 : {anim = new Porumbel();break;}

        case 8 : {anim = new Corb();break;}

        case 9 : {anim = new Peste();break;}

        case 10 : {anim = new Foca();break;}

        case 11 : {anim = new Caracatita();break;}
    }
}
};

#endif // CLIENT_H_INCLUDED
