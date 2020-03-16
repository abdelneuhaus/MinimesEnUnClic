#include <iostream>
#include "GestionPort.h"
using namespace std;


GestionPort::GestionPort(){}

vector<int> GestionPort::getPlacesVides(vector<Usager> Abonnes, int debut, int fin){
    vector<int> tmp(40);
    for (int i = debut; i < fin; i++){
        for (int y = 0; i < Abonnes.size(); i++){
            if (Abonnes[y].getVoilier().getPlace() != i){
                tmp.push_back(i);
            }
        }
    }
}

Voilier GestionPort::choixBateau(vector<Usager> Abonnes){
    string nomVoilier;
    double longueur;
    cout << "\n";
    cout << "Saisie du voilier" << "\n";
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;

    // Check les places disponible à donner au bateau
    vector<int> listeNH(40);
    listeNH = getPlacesVides(Abonnes, 0, 31); 
    vector<int> listeT1(40);
    listeT1 = getPlacesVides(Abonnes, 31, 71); 
    vector<int> listeT2(40);
    listeT2 = getPlacesVides(Abonnes, 71, 99); 

    if (longueur < 10){
        Voilier voilier(nomVoilier, longueur, false, false);
        voilier.setTypeVoilier("NH");
        voilier.setPlace(listeNH[0]);
        return voilier;
    }
    else if (longueur > 10 and longueur < 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T1");
        voilier.setPlace(listeT1[0]);
        return voilier;
    }
    else if (longueur > 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T2");
        voilier.setPlace(listeT2[0]);
        return voilier;
    }
}


vector<Usager> GestionPort::enregistreClient(vector<Usager> Abonnes, Port port){
    Voilier voilier = choixBateau(Abonnes);
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
    while(choixFormule != "A" && choixFormule != "a" && choixFormule != "P" && choixFormule != "p"){
            cout << "Recommencer" << "\n";
            cin >> choixFormule;
    }
    if (choixFormule == "A" || choixFormule == "a"){
        formule = true;
    }
    else if (choixFormule == "P" || choixFormule == "p"){
        formule = false;
    }
    cout << "\n";
    Usager client(nom, prenom, voilier, formule);
    Abonnes.push_back(client);

    return Abonnes;
}


void GestionPort::afficheInfos(vector<Usager> Abonnes){
    cout << "Indiquer le numéro de dossier auquel accéder" << "\n";
    int cle;
    cin >> cle;
    cout << "\n";
    cout << "Numéro de dossier : " << cle << "\n";
    cout << "Nom : " << Abonnes[cle].getNom() << "\n";
    cout << "Prenom : " << Abonnes[cle].getPrenom() << "\n";
    cout << "Nom du bateau : " << Abonnes[cle].getVoilier().getNomVoilier() << "\n";
    cout << "Type de bateau : " << Abonnes[cle].getVoilier().getTypeVoilier() << "\n";
    cout << "Place occupée par le bateau : " << Abonnes[cle].getVoilier().getPlace() << "\n";
    cout << "\n";
}