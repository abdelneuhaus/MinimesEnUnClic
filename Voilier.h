#include <string>

class Voilier{

    public:
        Voilier();
        ~Voilier();
        Voilier(const Voilier &VoilierCopie, std::string nomVoilier);
        std::string getNomVoilier();
        double getLongueur();
        bool getCabine();
        bool getUtiliseService();


    private:
        std::string m_nomVoilier;
        double m_longueur;
        bool m_cabine;
        bool m_utiliseService;
};