#ifndef USAGER_H
#define USAGER_H

#include "Voilier.h"

class Usager{

    public:
        Usager();
        Usager(std::string nom, std::string prenom, Voilier voilier, bool formule);
        ~Usager();
        std::string getNom() const;
        std::string getPrenom() const;
        bool getFormule() const;
        Voilier getVoilier() const;
        int getNumeroClient() const;
        

    private:
        std::string m_nom;
        std::string m_prenom;
        bool m_formule;
        Voilier m_voilier;  
        int m_numeroClient;  
};

#endif