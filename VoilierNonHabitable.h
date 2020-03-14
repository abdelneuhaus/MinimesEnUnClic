#include "Voilier.h"

class VoilierNonHabitable : public Voilier{

    public:
        VoilierNonHabitable(std::string nomVoilier, double longueur);

    private:
        std::string m_nomVoilier;
        double m_longueur;
        bool m_cabine;
        bool m_utiliseService;
};
