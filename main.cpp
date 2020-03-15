#include <iostream>
#include <string>
#include "GestionPort.h"
using namespace std;

void afficheMenu(){
    cout << "Menu" << "\n" << "\n";
    cout << "0: Quitter" << "\n";
    cout << "1: Saisie d'un client" << "\n";
    cout << "2: Afficher les informations d'un client" << "\n";
}

int main(){
    vector<Usager> Abonnes;
    vector<Voilier> Places(100);
    GestionPort GestionLaRochelle;
    Port LaRochelle("La Rochelle", 0, 101);
    
    while(true){
        afficheMenu();
        int choix;
        cin >> choix;
        if(choix == 0){
            return(0);
        }
        else if(choix == 1){
            Abonnes = GestionLaRochelle.enregistreClient(Abonnes, LaRochelle);
            //Places = GestionLaRochelle.enregistrePlace(Places, Abonnes);
        }
        else if(choix == 2){
            GestionLaRochelle.afficheInfos(Abonnes);
        }
    }

    return 0;
}