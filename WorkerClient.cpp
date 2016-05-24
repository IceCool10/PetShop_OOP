#include "WorkerClient.h"
vector<string> WorkerClient::Nume;
WorkerClient* WorkerClient::Instance;

WorkerClient::WorkerClient()
{
   this->IncarcareNume();
}

WorkerClient::~WorkerClient()
{
    //dtor
}
WorkerClient* WorkerClient::GetInstance()
{
    if (!Instance)
    {
        Instance = new WorkerClient;
    }
    return Instance;
}
int WorkerClient::GenerareAnimal()
{
    srand (time(NULL));
    int id_animal = rand() % 12; /// generam efectiv un animal
    return id_animal;
}
void WorkerClient::IncarcareNume()
{
    string NumeCurrent;
    ifstream citire("NumeClient.in");
    while (citire>>NumeCurrent)
    {
        WorkerClient::Nume.push_back(NumeCurrent);
    }
}
string WorkerClient::GenerareNume()
{
    srand (time(NULL));
    int lungime = WorkerClient::Nume.size();
    if (lungime!=0)
    {
    int indice = rand() % lungime;
    cout<<"Client "<<WorkerClient::Nume[indice]<<'\n';
    return WorkerClient::Nume[indice];
    }
    else return "Minions will rule the world";

}
Client* WorkerClient::GenerareClient()
{

    //WorkerClient::Instance = this;
   Client* c = new Client();
    c->nume = Instance->GenerareNume();
    c->setCumpara(Instance->GenerareAnimal());
    return c;
}
