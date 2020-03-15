#include <iostream>
#include <string>
#include <map>
#include "Usager.h"
#include "VoilierNonHabitable.h"
#include "VoilierType1.h"
#include "VoilierType2.h"
using namespace std;

int GestionPort::numeroClient = 0;


Voilier GestionPort::choixBateau(){
    string nomVoilier;
    double longueur;
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;

    if (longueur < 10){
        VoilierNonHabitable voilier(nomVoilier, longueur);
        return voilier;
    }
    else if (longueur < 10 or longueur > 25){
        VoilierType1 voilier(nomVoilier, longueur);
        return voilier;
    }
    else if (longueur < 25){
        VoilierType2 voilier(nomVoilier, longueur);
        return voilier;
    }
}


map<int, Usager> GestionPort::ajouteClient(map<int, Usager> Abonnes, Port port){
    Voilier voilier = choixBateau();
    string nom;
    string prenom;
    string choixFormule;
    bool formule;

    cout << "Création du client" << "\n";
    cout << "\n";
    cout << "Saisie du nom de famille" << "\n";
    cin >> nom;
    cout << "Saisie du prénom" << "\n";
    cin >> prenom;
    cout << "L'usager veut-il s'abonner (A) ou est t'il de passage (P) ?" << "\n";
    cout << "Taper A ou P" << "\n";
    cin >> choixFormule;
    if (choixFormule == "A" || choixFormule == "a"){
        formule = true;
    }
    else if (choixFormule == "P" || choixFormule == "p"){
        formule = false;
    }

    Usager usager(nom, prenom, voilier, formule);

    Abonnes[numeroClient] = usager;
    numeroClient++;
    port.ajouteAbonne();
    port.getNombrePlaces();
    return Abonnes;
}