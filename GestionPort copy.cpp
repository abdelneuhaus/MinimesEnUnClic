#include <iostream>
#include "GestionPort.h"
using namespace std;


GestionPort::GestionPort(){}

Voilier GestionPort::choixBateau(){
    string nomVoilier;
    double longueur;
    cout << "\n";
    cout << "Saisie du voilier" << "\n";
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;

    if (longueur < 10){
        Voilier voilier(nomVoilier, longueur, false, false);
        voilier.setTypeVoilier("NH");
        return voilier;
    }
    else if (longueur > 10 and longueur < 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T1");
        return voilier;
    }
    else if (longueur > 25){
        Voilier voilier(nomVoilier, longueur, true, true);
        voilier.setTypeVoilier("T2");
        return voilier;
    }
}


vector<Usager> GestionPort::enregistreClient(vector<Usager> Abonnes, Port port){
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


vector<int> GestionPort::enregistrePlace(vector<int> Places, vector<Usager> Abonnes){
    // Attribution d'une place de bateau au client
    // Places 0 à 30 = NH; 31 à 71 = T1; 72 à 98 = T2; 99 et 100 = corps morts
    int numero = Abonnes.size() - 1;
    for(int i = 0; i < 31; i++){
        Abonnes[numero].getVoilier().setPlace(Places[3]);
        cout << Places[3] << "\n";
        Places.erase(Places.begin());
        break;
    }
    return Places;
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