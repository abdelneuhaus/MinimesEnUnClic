#include <iostream>
#include "GestionPort.h"
using namespace std;

vector<int> GestionPort::PlacesNH;
vector<int> GestionPort::PlacesT1;
vector<int> GestionPort::PlacesT2;
vector<int> GestionPort::CorpsMort;


GestionPort::GestionPort(){
    
    for(int i = 0; i < 31; i++){
        PlacesNH.push_back(i);
    }

    for(int i = 31; i < 61; i++){
        PlacesT1.push_back(i);
    }
    for(int i = 61; i < 91; i++){
        PlacesT2.push_back(i);
    }

    for (int i = 91; i < 101; i++){
        CorpsMort.push_back(i);
    }
}


Voilier GestionPort::choixBateau(vector<Usager> Abonnes){
    string nomVoilier;
    double longueur;
    string typePlace;
    cout << "\n";
    cout << "Saisie du voilier" << "\n";
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;
    cout << "Voulez-vous une place normale ou pas ?" << "\n";
    cin >> typePlace;
    
    // Check les places disponible à donner au bateau
    if (typePlace == "oui" || typePlace == "OUI" || typePlace == "Oui"){
        if (longueur < 10){
            Voilier voilier(nomVoilier, longueur, false, false);
            voilier.setTypeVoilier("NH");
            voilier.setPlace(PlacesNH[0]);
            PlacesNH.erase(PlacesNH.begin());
            return voilier;
        }
        else if (longueur > 10 and longueur < 25){
            Voilier voilier(nomVoilier, longueur, true, true);
            voilier.setTypeVoilier("T1");
            voilier.setPlace(PlacesT1[0]);
            PlacesT1.erase(PlacesT1.begin());
            return voilier;
        }
        else if (longueur > 25){
            Voilier voilier(nomVoilier, longueur, true, true);
            voilier.setTypeVoilier("T2");
            voilier.setPlace(PlacesT2[0]);
            PlacesT2.erase(PlacesT2.begin());
            return voilier;
        }
    }
    else{
        if (longueur < 10){
            Voilier voilier(nomVoilier, longueur, false, false);
            voilier.setTypeVoilier("NH");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
        else if (longueur > 10 and longueur < 25){
            Voilier voilier(nomVoilier, longueur, true, true);
            voilier.setTypeVoilier("T1");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
        else if (longueur > 25){
            Voilier voilier(nomVoilier, longueur, true, true);
            voilier.setTypeVoilier("T2");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
    }
}


vector<Usager> GestionPort::enregistreClient(vector<Usager> Abonnes){
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



vector<Usager> GestionPort::saisieFacture(vector<Usager> Clients){
    int numeroDossier;
    int duree;

    cout << "\n";
    cout << "Entrer le numéro de dossier auquel vous voulez accéder" << "\n";
    cout << "Pour rappel, il y'a actuellement " << Clients.size() - 1 << "\n";
    cin >> numeroDossier;
    while(numeroDossier > Clients.size() - 1){
        cout << "Ce client n'existe pas" << "\n";
        cin >> numeroDossier;
    }
    if (Clients[numeroDossier].getVoilier().getPlace() == -1){
        cout << "Ce client a quitté le port" << "\n";
        cout << "Voici la somme qu'il a payé : " << Clients[numeroDossier].getFacture() << "\n";
    }
    else{ 
        if (Clients[numeroDossier].getFormule() == true){
            cout << Clients[numeroDossier].getNom() << " " << Clients[numeroDossier].getPrenom() << " est un abonné" << "\n";
            cout << "Combien de mois durera l'abonnement ?" << "\n";
            cin >> duree;
            if(duree%12 == 0){
                if (Clients[numeroDossier].getVoilier().getTypeVoilier() == "NH"){
                    Clients[numeroDossier].setFacture(41.67*duree);
                }
                else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T1"){
                    Clients[numeroDossier].setFacture(41.67*1.3*duree);
                }
                else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T2"){
                    Clients[numeroDossier].setFacture(41.67*1.6*duree);
                }
            }
            else{
                if (Clients[numeroDossier].getVoilier().getTypeVoilier() == "NH"){
                    Clients[numeroDossier].setFacture(500*duree);
                }
                else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T1"){
                    Clients[numeroDossier].setFacture(500*1.3*duree);
                }
                else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T2"){
                    Clients[numeroDossier].setFacture(500*1.6*duree);
                }
            }
        }
        else if (Clients[numeroDossier].getFormule() == false && Clients[numeroDossier].getVoilier().getPlace() < 91){
            cout << Clients[numeroDossier].getNom() << " " << Clients[numeroDossier].getPrenom() << " est un client de passage" << "\n";
            cout << "Combien de jours ?" << "\n";
            cin >> duree;
            if (Clients[numeroDossier].getVoilier().getTypeVoilier() == "NH"){
                Clients[numeroDossier].setFacture(20*duree);
            }
            else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T1"){
                Clients[numeroDossier].setFacture(20*1.3*duree);
            }
            else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T2"){
                Clients[numeroDossier].setFacture(20*1.6*duree);
            }
        }
        else if (Clients[numeroDossier].getFormule() == false && Clients[numeroDossier].getVoilier().getPlace() < 91){
            cout << Clients[numeroDossier].getNom() << " " << Clients[numeroDossier].getPrenom() << " est un client de passage qui utilise un corps mort" << "\n";
            cout << "Combien de jours ?" << "\n";
            cin >> duree;
            if (Clients[numeroDossier].getVoilier().getTypeVoilier() == "NH"){
                Clients[numeroDossier].setFacture(20*duree*0.5);
            }
            else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T1"){
                Clients[numeroDossier].setFacture(20*1.3*duree*0.5);
            }
            else if(Clients[numeroDossier].getVoilier().getTypeVoilier() == "T2"){
                Clients[numeroDossier].setFacture(20*1.6*duree*0.5);
            }
        }
    }
} 