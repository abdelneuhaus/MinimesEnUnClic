#include <iostream>
#include <fstream>
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


Voilier GestionPort::choixBateau(){
    string nomVoilier;
    double longueur;
    string typePlace;
    cout << "\n";
    cout << "Saisie du voilier" << "\n";
    cout << "Quel est le nom du voilier ?" << "\n";
    cin >> nomVoilier;
    cout << "Quel est la longueur du voilier ?" << "\n";
    cin >> longueur;
    while(longueur < 1){
        cout << "Longueur invalide. Resaisir une longueur valide" << "\n";
        cin >> longueur;
    }
    cout << "Voulez-vous une place normale ou pas (corps mort) ?" << "\n";
    cin >> typePlace;
    
    // Check les places disponible à donner au bateau
    if (typePlace == "oui" || typePlace == "OUI" || typePlace == "Oui"){
        if (longueur < 9){
            VoilierNH voilier(nomVoilier, longueur);
            voilier.setTypeVoilier("NH");
            voilier.setPlace(PlacesNH[0]);
            PlacesNH.erase(PlacesNH.begin());
            return voilier;
        }
        else if (longueur >= 10 and longueur < 24){
            VoilierT1 voilier1(nomVoilier, longueur);
            voilier1.setTypeVoilier("T1");
            voilier1.setPlace(PlacesT1[0]);
            PlacesT1.erase(PlacesT1.begin());
            return voilier1;
        }
        else if (longueur >= 25){
            VoilierT2 voilier2(nomVoilier, longueur);
            voilier2.setTypeVoilier("T2");
            voilier2.setPlace(PlacesT2[0]);
            PlacesT2.erase(PlacesT2.begin());
            return voilier2;
        }
    }
    else{
        if (longueur < 10){
            VoilierNH voilier(nomVoilier, longueur);
            voilier.setTypeVoilier("NH");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
        else if (longueur > 10 && longueur < 25){
            VoilierT1 voilier(nomVoilier, longueur);
            voilier.setTypeVoilier("T1");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
        else if (longueur > 25){
            VoilierT2 voilier(nomVoilier, longueur);
            voilier.setTypeVoilier("T2");
            voilier.setPlace(CorpsMort[0]);
            CorpsMort.erase(CorpsMort.begin());
            return voilier;
        }
    }
}


vector<Usager> GestionPort::enregistreClient(vector<Usager> Abonnes){
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
    if(voilier.getPlace() > 90){
        formule = false;
    }
    else{
        cout << "L'usager veut-il s'abonner (A) ou est t'il de passage (P) ?" << "\n";
        cout << "Taper A ou P" << "\n";
        cin >> choixFormule;
        while(choixFormule != "A" && choixFormule != "a" && choixFormule != "P" && choixFormule != "p"){
            cout << "Recommencer" << "\n";
            cin >> choixFormule;
        }
        if ((choixFormule == "A" || choixFormule == "a") && voilier.getPlace() < 91){
            formule = true;
        }
        else if (choixFormule == "P" || choixFormule == "p"){
            formule = false;
        }
    }
    cout << "\n";
    Usager client(nom, prenom, voilier, formule);
    client = saisieFacture(client);

    Abonnes.push_back(client);

    return Abonnes;
}



void GestionPort::afficheInfos(vector<Usager> Abonnes){
    cout << "Indiquer le numéro de dossier auquel accéder" << "\n";
    int cle;
    cin >> cle;

    if(Abonnes[cle].getPresence() == true){
        cout << "\n";
        cout << "Numéro de dossier : " << cle << "\n";
        cout << "Nom : " << Abonnes[cle].getNom() << "\n";
        cout << "Prenom : " << Abonnes[cle].getPrenom() << "\n";
        cout << "Nom du bateau : " << Abonnes[cle].getVoilier().getNomVoilier() << "\n";
        cout << "Place occupée par le bateau : " << Abonnes[cle].getVoilier().getPlace() << "\n";
        cout << "Facture : " << Abonnes[cle].getFacture() << " euros" << "\n";
        cout << "\n";
    }
    else if (Abonnes[cle].getPresence() == false){
        cout << "\n";
        cout << "Numéro de dossier : " << cle << "\n";
        cout << "Nom : " << Abonnes[cle].getNom() << "\n";
        cout << "Prenom : " << Abonnes[cle].getPrenom() << "\n";
        cout << "Nom du bateau : " << Abonnes[cle].getVoilier().getNomVoilier() << endl;
        cout << "Facture payée : " << Abonnes[cle].getFacture() << " euros" << "\n";
        cout << "Ce client est parti" << "\n";
        cout << "\n";
    }
}


Usager GestionPort::saisieFacture(Usager Client){
    int duree;
    string duo;
    string uno;
    int service;

    if (Client.getVoilier().getPlace() == -1){
        cout << "Ce client a quitté le port" << "\n";
        cout << "Voici la somme qu'il a payé : " << Client.getFacture() << "\n";
    }
    else{
        if ((Client.getVoilier().getTypeVoilier() == "T1" || Client.getVoilier().getTypeVoilier() == "T2") && Client.getVoilier().getPlace() < 91 && Client.getFormule() == __FLT_HAS_DENORM__){
            cout << "Le client compte-il utiliser au moins d'un des deux services (eau et eletricité) ?" << "\n";
            cin >> duo;
            if (duo == "NON" || duo == "non" || duo == "Non"){
                service = 0;
            }
            else{
                cout << "Le client compte-il utiliser les deux services (eau et électricité) ?" << "\n";
                cin >> uno; 
                if (uno == "OUI" || uno == "oui" || uno == "Oui"){
                    service = 10;
                }
                else{   
                    service = 0;
                }
            }
        }
        if (Client.getFormule() == true){
            cout << Client.getNom() << " " << Client.getPrenom() << " est un abonné(e)" << "\n";
            cout << "Combien de mois durera l'abonnement ?" << "\n";
            cin >> duree;
            if(duree%12 != 0){
                if (Client.getVoilier().getTypeVoilier() == "NH"){
                    Client.setFacture(41.67 * duree);
                }
                else if(Client.getVoilier().getTypeVoilier() == "T1"){
                    Client.setFacture(41.67 * 1.3 * duree);
                }
                else if(Client.getVoilier().getTypeVoilier() == "T2"){
                    Client.setFacture(41.67 * 1.6 * duree);
                }
            }
            else{
                if (Client.getVoilier().getTypeVoilier() == "NH"){
                    Client.setFacture(500 * (duree/12));
                }
                else if(Client.getVoilier().getTypeVoilier() == "T1"){
                    Client.setFacture(500 * 1.3 * (duree/12));
                }
                else if(Client.getVoilier().getTypeVoilier() == "T2"){
                    Client.setFacture(500 * 1.6 * (duree/12));
                }
            }
        }
        else if (Client.getFormule() == false && Client.getVoilier().getPlace() < 91){
            cout << Client.getNom() << " " << Client.getPrenom() << " est un(e) client(e) de passage" << "\n";
            cout << "Combien de jours restera-il ?" << "\n";
            cin >> duree;
            while(duree < 1){
                cout << "Duree invalide. Resaisir une durée valide" << "\n";
                cin >> duree;
            }
            if (Client.getVoilier().getTypeVoilier() == "NH"){
                Client.setFacture(20 * duree);
            }
            else if(Client.getVoilier().getTypeVoilier() == "T1"){
                Client.setFacture(20 * 1.3 * duree + service);
            }
            else if(Client.getVoilier().getTypeVoilier() == "T2"){
                Client.setFacture(20 * 1.6 * duree + service);
            }
        }

        else if (Client.getFormule() == false && Client.getVoilier().getPlace() >= 91){
            cout << Client.getNom() << " " << Client.getPrenom() << " est un(e) client(e) de passage qui utilise un corps mort" << "\n";
            cout << "Combien de jours restera-il ?" << "\n";
            cin >> duree;
            while(duree < 1){
                cout << "Duree invalide. Resaisir une durée valide" << "\n";
                cin >> duree;
            }  
            if (Client.getVoilier().getTypeVoilier() == "NH"){
                Client.setFacture(20 * duree * 0.5);
            }
            else if(Client.getVoilier().getTypeVoilier() == "T1"){
                Client.setFacture(20 * 1.3 * duree * 0.5);
            }
            else if(Client.getVoilier().getTypeVoilier() == "T2"){
                Client.setFacture(20 * 1.6 * duree * 0.5);
            }
        }
    }
    cout << "Prix de la facture : " << Client.getFacture() << " euros" << "\n";
    return Client;
}


vector <Usager> GestionPort::retirerClient(vector<Usager> Abonnes){
    string choix;
    int numeroDossier;

    cout << "Entrer le numéro de dossier du client qui quitte le port" << "\n";
    cin >> numeroDossier;
    while(numeroDossier < 0){
        cout << "Numéro invalide. Resaisir un numéro valide (le premier étant 0)" << "\n";
        cin >> numeroDossier;
    }
    if(Abonnes[numeroDossier].getPresence() == false){
        cout << "Ce client a déjà quitté le port" << "\n";
    }
    else if (Abonnes[numeroDossier].getVoilier().getPlace() < 91 && Abonnes[numeroDossier].getVoilier().getTypeVoilier() == "NH"){
        PlacesNH.push_back(Abonnes[numeroDossier].getVoilier().getPlace());
        Abonnes[numeroDossier].departClient();
        cout << "Somme réglée : " << Abonnes[numeroDossier].getFacture() << " euros" << "\n";
        cout << "Retrait du bateau. La place est désormais disponible" << "\n";
        return Abonnes;
    }
    else if (Abonnes[numeroDossier].getVoilier().getPlace() < 91 && Abonnes[numeroDossier].getVoilier().getTypeVoilier() == "T1"){
        PlacesT1.push_back(Abonnes[numeroDossier].getVoilier().getPlace());
        Abonnes[numeroDossier].departClient();
        cout << "Somme réglée : " << Abonnes[numeroDossier].getFacture() << " euros" << "\n";
        cout << "Retrait du bateau. La place est désormais disponible" << "\n";
        return Abonnes;
    }
    else if (Abonnes[numeroDossier].getVoilier().getPlace() < 91 && Abonnes[numeroDossier].getVoilier().getTypeVoilier() == "T2"){
        PlacesT2.push_back(Abonnes[numeroDossier].getVoilier().getPlace());
        Abonnes[numeroDossier].departClient();
        cout << "Somme réglée : " << Abonnes[numeroDossier].getFacture() << " euros" << "\n";
        cout << "Retrait du bateau. La place est désormais disponible" << "\n";
        return Abonnes;
    }
    else{
        CorpsMort.push_back(Abonnes[numeroDossier].getVoilier().getPlace());
        Abonnes[numeroDossier].departClient();
        cout << "Somme réglée : " << Abonnes[numeroDossier].getFacture() << " euros" << "\n";
        cout << "Retrait du bateau. La place est désormais disponible" << "\n";
        return Abonnes;
    }
}



void GestionPort::afficherPlaces(){
    int choix;

    cout << "De quel type de bateau voulez-vous afficher les places disponibles ?" << "\n";
    cout << "1: Bateau non habitable" << "\n";
    cout << "2: Bateau de type 1" << "\n";
    cout << "3: Bateau de type 2" << "\n";
    cout << "4: Places sur corps mort" << "\n";
    cin >> choix;
    while(choix != 1 && choix != 2 && choix != 3 && choix != 4){
        cout << "Erreur. Recommencer" << "\n";
        cin >> choix;
    }
    if (choix == 1){
        cout << "Liste des places pour bateaux non habitables disponibles :" << "\n";
        for(int i = 0; i < PlacesNH.size(); i++){
            cout << PlacesNH[i] << "\n";
        }
    }
    else if (choix == 2){
        cout << "Liste des places pour bateaux de type 1 disponibles :" << "\n";
        for(int i = 0; i < PlacesT1.size(); i++){
            cout << PlacesT1[i] << "\n";
        }    
    }
    else if (choix == 3){
        cout << "Liste des places pour bateaux de type 2 disponibles :" << "\n";
        for(int i = 0; i < PlacesT2.size(); i++){
            cout << PlacesT2[i] << "\n";
        }    
    }
    else if (choix == 4){
        cout << "Liste des places pour bateaux de type 2 disponibles :" << "\n";
        for(int i = 0; i < CorpsMort.size(); i++){
            cout << CorpsMort[i] << "\n";
        }    
    }
}


void GestionPort::saveData(vector<Usager> Clients) const{
    ofstream ClientsFile;
    ClientsFile.open("test.txt");
    if(ClientsFile.is_open()){
        for (int i = 0; i < Clients.size(); i++){
            Clients[i].saveData(ClientsFile);
            ClientsFile << endl;
        }
        ClientsFile.close();
    }
}

vector<Usager> GestionPort::loadData() const{
    string nom, prenom, nomVoilier, typeVoilier, buffer;
    bool formule, presence, cabine, service;
    int place, longueur, facture;
    vector<Usager> Clients;

    ifstream ClientsFile("test.txt");
    if (ClientsFile.is_open()){
        while (getline(ClientsFile, nom)){
            getline(ClientsFile, prenom);
            ClientsFile >> presence;
            ClientsFile.ignore();
            ClientsFile >> facture;
            ClientsFile.ignore();
            ClientsFile >> formule;
            ClientsFile.ignore();
            ClientsFile >> cabine;
            ClientsFile.ignore();
            ClientsFile >> longueur;
            ClientsFile.ignore();           
            getline(ClientsFile, nomVoilier);
            getline(ClientsFile, typeVoilier);
            ClientsFile >> service;
            ClientsFile.ignore();
            ClientsFile >> place;
            ClientsFile.ignore();
            getline(ClientsFile, buffer);

            if(typeVoilier == "NH"){
                VoilierNH voilier(nomVoilier, longueur);
                voilier.setTypeVoilier(typeVoilier);
                voilier.setPlace(place);
                Usager client(nom, prenom, voilier, formule);
                client.setFacture(facture);
                Clients.push_back(client);
                if(place != -1){
                if(place > 90){
                    for(int i = 0; i < CorpsMort.size(); i++){
                        if(CorpsMort[i] == place){
                            CorpsMort.erase(CorpsMort.begin()+ i);
                        }
                    }
                }
                else{
                    if(longueur < 10){
                        for(int i = 0; i < PlacesNH.size(); i++){
                            if(PlacesNH[i] == place){
                                PlacesNH.erase(PlacesNH.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 10 && longueur < 25){
                        for(int i = 0; i < PlacesT1.size(); i++){
                            if(PlacesT1[i] == place){
                                PlacesT1.erase(PlacesT1.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 25){
                        for(int i = 0; i < PlacesT2.size(); i++){
                            if(PlacesT2[i] == place){
                                PlacesT2.erase(PlacesT2.begin()+ i);
                            }
                        }
                    }
                }
            }

        }

            else if(typeVoilier == "T1"){
                VoilierT1 voilier(nomVoilier, longueur);
                voilier.setTypeVoilier(typeVoilier);
                voilier.setPlace(place);
                Usager client(nom, prenom, voilier, formule);
                client.setFacture(facture);
                Clients.push_back(client);
                if(place != -1){
                if(place > 90){
                    for(int i = 0; i < CorpsMort.size(); i++){
                        if(CorpsMort[i] == place){
                            CorpsMort.erase(CorpsMort.begin()+ i);
                        }
                    }
                }
                else{
                    if(longueur < 10){
                        for(int i = 0; i < PlacesNH.size(); i++){
                            if(PlacesNH[i] == place){
                                PlacesNH.erase(PlacesNH.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 10 && longueur < 25){
                        for(int i = 0; i < PlacesT1.size(); i++){
                            if(PlacesT1[i] == place){
                                PlacesT1.erase(PlacesT1.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 25){
                        for(int i = 0; i < PlacesT2.size(); i++){
                            if(PlacesT2[i] == place){
                                PlacesT2.erase(PlacesT2.begin()+ i);
                            }
                        }
                    }
                }
            }
        }

            else{
                VoilierT2 voilier(nomVoilier, longueur);
                voilier.setTypeVoilier(typeVoilier);
                voilier.setPlace(place);
                Usager client(nom, prenom, voilier, formule);
                client.setFacture(facture);
                Clients.push_back(client);
                if(place != -1){
                if(place > 90){
                    for(int i = 0; i < CorpsMort.size(); i++){
                        if(CorpsMort[i] == place){
                            CorpsMort.erase(CorpsMort.begin()+ i);
                        }
                    }
                }
                else{
                    if(longueur < 10){
                        for(int i = 0; i < PlacesNH.size(); i++){
                            if(PlacesNH[i] == place){
                                PlacesNH.erase(PlacesNH.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 10 && longueur < 25){
                        for(int i = 0; i < PlacesT1.size(); i++){
                            if(PlacesT1[i] == place){
                                PlacesT1.erase(PlacesT1.begin()+ i);
                            }
                        }
                    }
                    else if(longueur >= 25){
                        for(int i = 0; i < PlacesT2.size(); i++){
                            if(PlacesT2[i] == place){
                                PlacesT2.erase(PlacesT2.begin()+ i);
                            }
                        }
                    }
                }
            }
        }
    }
        ClientsFile.close();
    }
    return Clients;
}       