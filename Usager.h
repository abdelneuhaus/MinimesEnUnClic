#include <string>
#include "Voilier.h"
#include "Port.h"

class Usager{

    public:
        Usager();
        Usager(std::string nom, std::string prenom, Voilier voilier, bool formule);
        ~Usager();
        std::string getNom() const;
        std::string getPrenom() const;
        bool getFormule();
        Voilier getVoilier();
        void quittePort(Port port);
        

    private:
        std::string m_nom;
        std::string m_prenom;
        bool m_formule;
        Voilier m_voilier;    
};