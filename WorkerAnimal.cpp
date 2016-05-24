#include "WorkerAnimal.h"
vector<string> WorkerAnimal::Nume;
WorkerAnimal* WorkerAnimal::Instance;
WorkerAnimal::WorkerAnimal()
{
    IncarcareNume();
}
WorkerAnimal::~WorkerAnimal()
{
    //dtor
}
int WorkerAnimal::GenerarePret()
{
    srand (time(NULL));
    return rand() % 500 + 100;
}
WorkerAnimal* WorkerAnimal::GetInstance()
{
    if (!Instance)
    {
        Instance = new WorkerAnimal;
    }
    return Instance;
}
void WorkerAnimal::IncarcareNume()
{
    string NumeCurrent;
    ifstream citire("NumeAnimale.in",ios::in);
    while (citire>>NumeCurrent)
    {
        WorkerAnimal::Nume.push_back(NumeCurrent);
    }
}
string WorkerAnimal::GenerareNume()
{
    srand (time(NULL));
    int lungime = WorkerAnimal::Nume.size();
    if (lungime!=0)
    {
    int indice = rand() % lungime;
    cout<<"Animal "<<WorkerAnimal::Nume[indice]<<'\n';
    return WorkerAnimal::Nume[indice];
    }
    else return "Chihuahuas will rule the world";

}
animal* WorkerAnimal::GenerareAnimal()
{
    int IdAnimal = rand() % 12; /// generam efectiv un animal
    string NumeCurrent = GenerareNume();
    int pret = GenerarePret();
    switch (IdAnimal)
     {
        case 0 : {return new Caine(NumeCurrent,pret);break;}

        case 1 : {return new Pisica(NumeCurrent,pret);break;}

        case 2 : {return new Iepure(NumeCurrent,pret);break;}

        case 3 : {return new Sarpe(NumeCurrent,pret);break;}

        case 4 : {return new Iguana(NumeCurrent,pret);break;}

        case 5 : {return new Papagal(NumeCurrent,pret);break;}

        case 6 : {return new Papagal(NumeCurrent,pret);break;}

        case 7 : {return new Porumbel(NumeCurrent,pret);break;}

        case 8 : {return new Corb(NumeCurrent,pret);break;}

        case 9 : {return new Peste(NumeCurrent,pret);break;}

        case 10 : {return new Foca(NumeCurrent,pret);break;}

        case 11 : {return new Caracatita(NumeCurrent,pret);break;}

        //compleateaza restul animalelor
    }
}
