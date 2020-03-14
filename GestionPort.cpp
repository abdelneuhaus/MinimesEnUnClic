#include <iostream>
#include <string>
#include <map>
#include "Usager.h"
using namespace std;

static int numeroClient = 0;

map<int, Usager> ajoutClient(map<int, Usager> Abonnes, Port port){
    string nom;
    string prenom;
    bool formule;
    string nomVoilier;
    double longueur;
    bool cabine, utiliseService;

    cout << "Saisir le nom du voilier de l'abonné" << "\n";
    cin >> nomVoilier;
    cout << "Saisir la longueur" << "\n";
    cin >> longueur;
    cout << "Saisir la présence (0) ou absence de cabine (1)" << "\n";
    cin >> cabine;
    cout << "Idem" << "\n";
    cin >> utiliseService;

    cout << "Maintenant, saisir le nom de l'abonné" << "\n";
    cin >> nom;
    cout << "Saisir la prénom" << "\n";
    cin >> prenom;
    cout << "Abonné (0) ou de passage (1)" << "\n";
    cin >> formule;

    Voilier voilier(nomVoilier, longueur, cabine, utiliseService);
    Usager client(nom, prenom, voilier, formule);

    Abonnes[numeroClient] = client;
    numeroClient++;
    port.ajouteAbonne();
    port.getNombrePlaces();

    return Abonnes;
}



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