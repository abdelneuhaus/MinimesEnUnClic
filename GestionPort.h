#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#include "Usager.h"
#include <vector>

class GestionPort{

    public:
        GestionPort();
        std::vector<Usager> enregistreClient(std::vector<Usager> Clients, std::vector<Voilier*> Voiliers);
        std::vector<Voilier*> choixBateau(std::vector<Voilier*> listeVoiliers);
        void afficheInfos(std::vector<Usager> Clients, std::vector<Voilier*> Voiliers);
        Usager saisieFacture(Usager Client);
        std::vector<Voilier*> retirerBateau(std::vector <Voilier*> Voiliers);
        std::vector<Usager> retirerClient(std::vector<Usager> Clients);
        void afficherPlaces();
        void saveDataClients(std::vector<Usager> Clients) const;
        void saveDataVoiliers(std::vector<Voilier*> Voiliers) const;
        std::vector<Voilier*> loadDataVoilier() const;
        std::vector<Usager> loadDataUsager(std::vector<Voilier*>) const;        
        

    private:
        static std::vector<int> PlacesNH;
        static std::vector<int> PlacesT1;
        static std::vector<int> PlacesT2;
        static std::vector<int> CorpsMort;
};

#endif