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
        //std::vector<int> enregistrePlace(std::vector<int> places, std::vector<Usager> Abonnes);
        Voilier choixBateau(std::vector<Usager> Abonnes);
        void afficheInfos(std::vector<Usager> Abonnes);
        std::vector<int> getPlacesVides(std::vector<Usager> Abonnes, int debut, int fin);

};

#endif