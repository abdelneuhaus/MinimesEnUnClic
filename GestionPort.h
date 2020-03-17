#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#include "Usager.h"
#include "Port.h"
#include <vector>

class GestionPort{

    public:
        GestionPort();
        std::vector<Usager> enregistreClient(std::vector<Usager> Clients);
        Voilier choixBateau(std::vector<Usager> Clients);
        void afficheInfos(std::vector<Usager> Clients);
        Usager saisieFacture(Usager Client);
        std::vector<Usager> retirerClient(std::vector <Usager> Clients);
        void afficherPlaces();
        

    private:
        static std::vector<int> PlacesNH;
        static std::vector<int> PlacesT1;
        static std::vector<int> PlacesT2;
        static std::vector<int> CorpsMort;
        static int placeDefaut;
};

#endif