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
        int getFacture();
        void setFacture(int prix);  
        void departClient();
        bool getPresence();
        void saveData(std::ofstream& file) const;     

    private:
        std::string m_nom;
        std::string m_prenom;
        bool m_formule;
        Voilier m_voilier;  
        int m_facture;
        bool m_presence;
};

#endif