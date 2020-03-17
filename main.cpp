#include <iostream>
#include <string>
#include "GestionPort.h"
using namespace std;


void afficheMenu(){
    cout << "Menu" << "\n" << "\n";
    cout << "0: Quitter" << "\n";
    cout << "1: Saisie d'un client et de sa facture" << "\n";
    cout << "2: Afficher les informations d'un client" << "\n";
}

int main(){
    vector<Usager> Clients;
    vector<int> Places(100, 3);
    GestionPort GestionLaRochelle;
    
    while(true){
        afficheMenu();
        int choix;
        cin >> choix;
        if(choix == 0){
            return(0);
        }
        else if(choix == 1){
            Clients = GestionLaRochelle.enregistreClient(Clients);
            Clients = GestionLaRochelle.saisieFacture(Clients);
        }
        else if(choix == 2){
            GestionLaRochelle.afficheInfos(Clients);
        }
    }
    return 0;
}