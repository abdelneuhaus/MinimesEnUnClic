#include "Usager.h"
#include "Port.h"
#include <map>
#include <vector>

class GestionPort{

    public:
        GestionPort();
        std::map<int, Usager> ajouteClient(std::map<int, Usager> Abonnes, Port port);
        Voilier choixBateau();
        void afficheInfos(std::map<int, Usager> Abonnes, int cle);
};