#include <iostream>
#include "GestionPort.h"
using namespace std;


GestionPort::GestionPort(){}


Voilier GestionPort::choixBateau(){
    string nomVoilier;
    double longueur;
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;

    if (longueur < 10){
        Voilier voilier(nomVoilier, longueur, false, false);
        voilier.setTypeVoilier("NH");
        return voilier;
    }
    else if (longueur < 10 or longueur > 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T1");
        return voilier;
    }
    else if (longueur < 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T2");
        return voilier;
    }
}


map<int, Usager> GestionPort::ajouteClient(map<int, Usager> Abonnes, Port port){
    Voilier voilier = choixBateau();
    string nom;
    string prenom;
    string choixFormule;
    bool formule;

    // Création du client dans la database
    cout << "\n";
    cout << "Création du client" << "\n";
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
    cout << "\n";

    Usager client(nom, prenom, voilier, formule);
    Abonnes[client.getNumeroClient()] = client;


    // Attribution d'une place de bateau au client
    // Places 1 à 30 = NH; 31 à 71 = T1; 72 à 98 = T2; 


    return Abonnes;
}


void GestionPort::afficheInfos(map<int, Usager> Abonnes, int cle){
    cout << "Nom : " << Abonnes[cle].getNom() << "\n";
    cout << "Prenom : " << Abonnes[cle].getPrenom() << "\n";
    cout << "Bateau : " << Abonnes[cle].getVoilier().getNomVoilier() << "\n";
    cout << "Numéro de dossier : " << Abonnes[cle].getNumeroClient() << "\n";
    cout << "\n";
}