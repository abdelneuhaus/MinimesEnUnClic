#ifndef GESTIONPORT_H
#define GESTIONPORT_H

#include "Usager.h"
#include "Port.h"
#include <map>
#include <vector>

class GestionPort{

    public:
        GestionPort();
        std::vector<Usager> enregistreClient(std::vector<Usager> Abonnes, Port port);
        std::vector<Voilier> enregistrePlace(std::vector<Voilier> places, std::vector<Usager> Abonnes);
        Voilier choixBateau();
        void afficheInfos(std::vector<Usager> Abonnes);
};

#endif