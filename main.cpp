#include <iostream>
#include <string>
#include <map>
#include "Usager.h"
#include "GestionPort.cpp"
using namespace std;


int main(){

    map<int, Usager> Abonnes;
    Port LaRochelle("La Rochelle", 0, 10);

    Abonnes = ajoutClient(Abonnes, LaRochelle);
    cout << LaRochelle.getNombrePlaces() << "\n";
    Abonnes = ajoutClient(Abonnes, LaRochelle);
    cout << LaRochelle.getNombrePlaces() << "\n";
    Abonnes.erase(0);

    return 0;
}