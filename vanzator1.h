#ifndef VANZATOR_H_INCLUDED
#define VANZATOR_H_INCLUDED
#include <iostream>
#include "animal.h"
class Vanzator {
private:
    unsigned long total;
    static int animale_vandute;

public:
    Vanzator() : total(0) { }
    void AdaugaAnimal(animal* anim);
    unsigned long getTotal();
    int getAnimaleVandute();
    void reset();
    friend ostream& operator<<(ostream& out,Vanzator& x) {
        out << "S-au vandut in total " << x.getAnimaleVandute() << " animale cu un profit de " << x.getTotal() << "\n";
        return out;
    }
};

#endif // VANZATOR_H_INCLUDED
