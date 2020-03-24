#ifndef VOILIERNH_H
#define VOILIERNH_H
#include "Voilier.h"
#include <string>

class VoilierNH : public Voilier{

    public:
        VoilierNH(std::string nomVoilier, double longueur);
        virtual ~VoilierNH();
        virtual std::string afficheType() const;
};

#endif