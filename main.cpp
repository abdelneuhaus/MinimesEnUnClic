#include <iostream>
#include <string>
#include <map>
#include "GestionPort.h"
using namespace std;

int main(){

    map<int, Usager> Abonnes;
    vector<Voilier> Places;
    Places.reserve(101);
    GestionPort GestionLaRochelle;
    Port LaRochelle("La Rochelle", 0, 101);

    Abonnes = GestionLaRochelle.ajouteClient(Abonnes, LaRochelle);
    Abonnes = GestionLaRochelle.ajouteClient(Abonnes, LaRochelle);
    Abonnes = GestionLaRochelle.ajouteClient(Abonnes, LaRochelle);

    GestionLaRochelle.afficheInfos(Abonnes, 1);

    return 0;
}