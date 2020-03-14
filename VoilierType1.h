#include "Voilier.h"

class VoilierType1 : public Voilier{

    public:
        VoilierType1(std::string nomVoilier, double longueur);

    private:
        std::string m_nomVoilier;
        double m_longueur;
        bool m_cabine;
        bool m_utiliseService;
};
