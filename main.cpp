#include <iostream>
#include "reptile.h"
#include "sarpe.h"
#include "iguana.h"
#include "Mamifer.h"
#include "Iepure.h"
#include "Caine.h"
#include "Pisica.h"
#include "client.h"
#include "casier.h"
#include "testoasa.h"
#include "animal.h"
#include "aqua.h"
#include "caracatita.h"
#include "vanzator.h"
#include "foca.h"
#include "corb.h"
#include "papagal.h"
#include "pasari.h"
#include "peste.h"
#include "porumbel.h"
#include "worker.h"
#include <ctime>
#include <queue>
#include <chrono>
#include <mutex>
#include <atomic>
#include <thread>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <typeinfo> /// pentru typeid()
#include <UserAttempt.h>
#include <list>
#include "Util.h"
#include <windows.h>
using namespace std;

static int idclient = 1;
mutex m;
queue <Client> Q; /// coada de clienti
list <animal*> lista_animale;
animal* a; /// animalul primit la x secunde
int x_secunde, y_secunde; /// x_secunde ---> inserare animal
                          /// y_secunde ---> aparitie client (scoatem un animal)
int opt;
Worker worker1;
Vanzator vanzator;

void close_program() {

while(opt != 3)
    if(GetAsyncKeyState(VK_ESCAPE))
    {
        opt = 3;
    }
}
void push() {
std::lock_guard<std::mutex> lock(m);

        lista_animale.push_back(worker1.Generate());
        if(typeid(*lista_animale.back()) == typeid(Caracatita)) {
                    cout << "\nInserare " << typeid(*lista_animale.back()).name()+2 << "\n";
                }
                else {
                    cout << "\nInserare " << typeid(*lista_animale.back()).name()+1 << "\n";
                }




    for (int i = 0; i < Q.size(); i++) {
        bool vandut = false;
        for (std::list<animal*>::iterator it = lista_animale.begin(); it != lista_animale.end(); ++it) {
            if(typeid(*Q.front().getAnimal()).name() + 1  ==  typeid(*(*it)).name() + 1) {

                vanzator.AdaugaAnimal(*it);
                if(typeid(*Q.front().getAnimal()) == typeid(Caracatita)) {
                    cout << "\n=================================================\n";
                    cout << "\nVandut " << typeid(*Q.front().getAnimal()).name() + 1 + 1 << " cu pretul : " << (*it)->getPret() << " lei\n";
                    cout << "\n=================================================\n\n";
                }
                else {
                    cout << "\n=================================================\n";
                    cout << "\nVandut " << typeid(*Q.front().getAnimal()).name() + 1 << " cu pretul : " << (*it)->getPret() << " lei\n";
                    cout << "\n=================================================\n\n";
                }
                ///cout << vanzator;
                lista_animale.erase(it);
                vandut = true;
                break;
            }

        }
        if(vandut) {
            Client::decrement();
            Q.pop();
        }
        else {
            Q.push(Q.front());
            Q.pop();

        }
    }

}

Client client;

void pop() {
            ///  main-ul asteapta threadurile !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

std::lock_guard<std::mutex> lock(m);

    client.Generate();

    Q.push(client);
    if(typeid(*Q.back().getAnimal()) == typeid(Caracatita)) {
                    cout << "\nClientul " << client.getIdClient() << " doreste un/o " << typeid(*client.getAnimal()).name()+2 << "\n";
                }
                else {
                    cout << "\nClientul " << client.getIdClient() << " doreste un/o " << typeid(*client.getAnimal()).name()+1 << "\n";
                }


    Client::increment();
        for (int i = 0; i < Q.size(); i++) {
            bool vandut = false;

            for (std::list<animal*>::iterator it = lista_animale.begin(); it != lista_animale.end(); ++it) {
                if(typeid(*Q.front().getAnimal()).name() + 1  ==  typeid(*(*it)).name() + 1) {

                    vanzator.AdaugaAnimal(*it);
                    if(typeid(*Q.front().getAnimal()) == typeid(Caracatita)) {
                        cout << "\n=================================================\n";
                        cout << "\nVandut " << typeid(*Q.front().getAnimal()).name() + 2 << " cu pretul : " << (*it)->getPret() << " lei\n";
                        cout << "\n=================================================\n\n";
                    }
                    else {
                        cout << "\n=================================================\n";
                        cout << "\nVandut " << typeid(*Q.front().getAnimal()).name() + 1 << " cu pretul : " << (*it)->getPret() << " lei\n";
                        cout << "\n=================================================\n\n";
                    }
                    ///cout << vanzator;
                    lista_animale.erase(it);
                    vandut = true;
                    break;
                }

            }
            if(vandut) {
                Client::decrement();
                Q.pop();
            }
            else {
                Q.push(Q.front());
                Q.pop();

            }
        }



               /// this_thread::sleep_for(std::chrono::seconds(y_secunde));
    ///----------------------------- Verificare  inserare "client" in queue ------------------------------------
    ///cout <<"\nQ.front() = " << typeid(*Q.front()).name()+1 << "  Q.back() = " << typeid(*Q.back()).name()+1 << "\n";
    ///----------------------------- Verificare Generare Animal pentru client -------------------
    ///cout << "\n" << typeid(*Q.front()).name()+1 << "\n";

}

void generare_thread1() {
    thread thread_stop(close_program); ///Treadul care opreste celelalte threaduri
    thread_stop.detach();             /// Acest thread nu trebuie sincronizat cu celelalte threaduri , nici cu main-ul
                                      /// Prin urmare ii dam detach
    while(opt != 3) {  ///inchidere magazin  op = 3 => in meniu
        thread t1(push); /// ---------- parametru la o functie -----
        if (t1.joinable())
            t1.join();

        this_thread::sleep_for(std::chrono::seconds(x_secunde));
    }

}

void generare_thread2() {
    while(opt != 3) {  ///inchidere magazin ---> opt = 3 => in meniu
        thread t2(pop);
        if (t2.joinable())
            t2.join();
        /**while(!ready) {
            std::this_thread::yield();
        }*/
        this_thread::sleep_for(std::chrono::seconds(y_secunde));
        ///inchidere();
    }

}

void tranzactii() {
    srand (time(NULL));
    x_secunde = rand() % 4 + 2; /// random secunde inserare
    y_secunde = rand() % 4 + 2; /// random secunde client

    if(x_secunde > y_secunde) { ///daca dureaza mai mult inserarea facem swap
                                /// ca sa nu ramanem la un moment dat fara animale
        swap(x_secunde,y_secunde);
    }

///          Verificare generare secunde
    cout << "x_secunde = " << x_secunde << " secunde\n";
    cout << "y_secunde = " << y_secunde << " secunde\n";

    ///threadul start1 --> genereaza threadul de inserare
    thread start1(generare_thread1); ///facem 2 threaduri care genereaza alte 2
                                     /// threaduri (inserarea unui animal si aparitia
                                     /// unui client trebuie sa mearga in paralel)
    ///threadul start2 --> genereaza aparitia unui client
    thread start2;
    start2 = std::thread(generare_thread2);
    if (start1.joinable())
        start1.join();
    if (start2.joinable())
        start2.join();
}

int main() {
    fstream in("database.in", ios::in | ios::out | ios::app);



    DataBase *PetShop = DataBase::create();     ///singleton
  //  ptr=&PetShop;
    string username;
    string password;
    string date;
    string stop_program;
    UserAttempt *X;

    while(getline(in, username), getline(in, password), getline(in, date))
            Load_Accounts(username, password, PetShop, date);

    do{

        system("cls");


        cout<<"==============================================================================";
        cout<<"\nBine ati venit la PetShop-ul nostru!\n";
        /**

        */

        if(vanzator.getAnimaleVandute() > 0) {
            cout << "\n\nLa ultima tranzactie s-au vandut " << vanzator.getAnimaleVandute()
                 << " animale . Profitul este de " << vanzator.getTotal() << "\n\n";
            vanzator.reset();
        }
        cout<<"\nAlegeti una dintre urnatoarele optiuni pentru a continua:";
        cout<<"\n     1 - Autentificare";
        cout<<"\n     2 - Creare cont nou";
        cout<<"\n     3 - Inchidere magazin";
        cout<<"\n==============================================================================";
        cout<<"\n\nOptiunea dorita: ";
        cin>>opt;

        switch(opt)
        {
            case 1:
                {
                    cout<<"\nIntroduceti datele cerute\n";
                    cout<<"Username: ";
                    cin>>username;
                    cout<<"Password: ";
                    cin>>password;
                    X = new UserAttempt(username,password,PetShop,opt);
                    tranzactii();
                    break;
                }
            case 2:
                {
                    cout<<"\nIntroduceti urmatoarele date:\n";
                    cout<<"Username: ";
                    cin>>username;
                    cout<<"Password: ";
                    cin>>password;
                    X = new UserAttempt(username,password,PetShop,opt);
                    break;
                }
            case 3:
                {
                      cout<<"\nIntroduceti parola de inchidere.";
                      cout<<"\nPassword: ";
                      cin>>stop_program;
                      break;
                }
            default:
                {
                    cout<<"\nEROARE! INERCATI DIN NOU, ALEGAND UNA DINTRE CELE TREI OPTIUNI.";
                    pause(5);
                    break;
                }
        }

    }while(stop_program!="parola");

    cout<<"\n\nMagazinul este inchis! Va asteptam si maine!:)\n";

    in.close();


    return 0;
}
