#ifndef VOILIER_H
#define VOILIER_H

#include <string>

class Voilier{

    public:
        Voilier();
        Voilier(std::string nomVoilier, double longueur);
        virtual ~Voilier();
        Voilier(const Voilier &VoilierCopie, std::string nomVoilier);

        std::string getNomVoilier() const;
        double getLongueur() const;
        bool getCabine() const;
        bool getUtiliseService() const;
        std::string getTypeVoilier() const;
        void setTypeVoilier(std::string type);
        int getPlace() const;
        void setPlace(int nbr);
        virtual std::string afficheType() const;


    protected:
        std::string m_nomVoilier;
        double m_longueur;
        bool m_cabine;
        bool m_utiliseService;
        std::string m_typeVoilier;
        int m_place;
};

#endif