#include "Usager.h"
#include "VoilierNonHabitable.h"
#include "VoilierType1.h"
#include "VoilierType2.h"
#include <map>

class GestionPort{

    public:
        std::map<int, Usager> ajouteClient(std::map<int, Usager> Abonnes, Port port);
        Voilier choixBateau();

    private:
        static int numeroClient;
};