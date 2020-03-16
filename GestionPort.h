#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#include "Usager.h"
#include "Port.h"
#include <vector>

class GestionPort{

    public:
        GestionPort();
        std::vector<Usager> enregistreClient(std::vector<Usager> Abonnes, Port port);
        //std::vector<int> enregistrePlace(std::vector<int> places, std::vector<Usager> Abonnes);
        Voilier choixBateau(std::vector<Usager> Abonnes);
        void afficheInfos(std::vector<Usager> Abonnes);

    private:
        static std::vector<int> PlacesNHT1;
        static std::vector<int> PlacesT2;
        static std::vector<int> CorpsMort;
};

#endif