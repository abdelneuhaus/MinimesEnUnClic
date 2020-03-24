#include <iostream>
#include <string>
#include <fstream>
#include "GestionPort.h"
using namespace std;


void afficheMenu(){
    cout << "Menu" << "\n" << "\n";
    cout << "0: Quitter" << "\n";
    cout << "1: Saisie d'un client et de sa facture" << "\n";
    cout << "2: Afficher les informations d'un client" << "\n";
    cout << "3: Saisie du départ d'un client" << "\n";
    cout << "4: Afficher les places disponibles selon le type de bateau" << "\n";
    cout << "5: Sauvegarder les données" << "\n";
}

int main(){
    GestionPort GestionLaRochelle;
    vector<Usager> Clients;
    vector<Voilier*> Voiliers;

    Voiliers = GestionLaRochelle.loadDataVoilier();
    Clients = GestionLaRochelle.loadDataUsager(Voiliers);
    
    while(true){
        afficheMenu();
        int choix;
        cout << ">> ";
        cin >> choix;
        if(choix == 0){
            return(0);
        }
        else if(choix == 1){
            Voiliers = GestionLaRochelle.choixBateau(Voiliers);
            Clients = GestionLaRochelle.enregistreClient(Clients, Voiliers);
        }
        else if(choix == 2){
            GestionLaRochelle.afficheInfos(Clients, Voiliers);
        }
        else if(choix == 3){
            Voiliers = GestionLaRochelle.retirerBateau(Voiliers);
            Clients = GestionLaRochelle.retirerClient(Clients);
        }
        else if(choix == 4){
            GestionLaRochelle.afficherPlaces();
        }
        else if(choix == 5){
            GestionLaRochelle.saveDataClients(Clients);
            GestionLaRochelle.saveDataVoiliers(Voiliers);
        }
        else{
            cout << "Choix non disponible. Recommencer" << "\n";
        }
    }
    return 0;
}