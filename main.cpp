#include <iostream>
#include <string>
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
    cout << "6: Charger les données enregistrées" << "\n";
}

int main(){
    string file("./test.txt");
    vector<Usager> Clients;
    GestionPort GestionLaRochelle;
    
    while(true){
        afficheMenu();
        int choix;
        cout << ">> ";
        cin >> choix;
        if(choix == 0){
            return(0);
        }
        else if(choix == 1){
            Clients = GestionLaRochelle.enregistreClient(Clients);
        }
        else if(choix == 2){
            GestionLaRochelle.afficheInfos(Clients);
        }
        else if(choix == 3){
            Clients = GestionLaRochelle.retirerClient(Clients);
        }
        else if(choix == 4){
            GestionLaRochelle.afficherPlaces();
        }
        else if(choix == 5){
            GestionLaRochelle.saveData(Clients);
        }
        else if(choix == 6){
            Clients = GestionLaRochelle.loadData();
        }
    }
    return 0;
}