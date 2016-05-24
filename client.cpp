#include "client.h"
using namespace std;

int Client::idclient = 1;

int Client::getIdClient() {
    return idclient;
}

void Client::increment() {
    idclient++;
}

void Client::decrement() {
    idclient--;
}

animal* Client::getAnimal() {
    return anim;
}
