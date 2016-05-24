#pragma once
#include "vanzator.h"
#include "animal.h"
#include <iostream>
using namespace std;


int Vanzator::animale_vandute = 0;

unsigned long Vanzator::getTotal() {
    return total;
}

void Vanzator::AdaugaAnimal(animal* anim) {
    total += anim->getPret();
    animale_vandute++;
}

int Vanzator::getAnimaleVandute() {
    return animale_vandute;
}

void Vanzator::reset() {
    total = 0;
    animale_vandute = 0;
}
