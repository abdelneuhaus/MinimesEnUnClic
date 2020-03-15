#include "Voilier.h"

class Usager{

    public:
        Usager();
        Usager(std::string nom, std::string prenom, Voilier voilier, bool formule);
        ~Usager();
        std::string getNom() const;
        std::string getPrenom() const;
        bool getFormule();
        Voilier getVoilier();
        int getNumeroClient();
        

    private:
        std::string m_nom;
        std::string m_prenom;
        bool m_formule;
        Voilier m_voilier;  
        int m_numeroClient;  
        int static dossier;
};