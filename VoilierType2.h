#include "Voilier.h"

class VoilierType2 : public Voilier{

    public:
        VoilierType2(std::string nomVoilier, double longueur);

    private:
        std::string m_nomVoilier;
        double m_longueur;
        bool m_cabine;
        bool m_utiliseService;
};
