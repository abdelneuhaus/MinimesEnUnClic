#ifndef VOILIERT2_H
#define VOILIERT2_H
#include "Voilier.h"
#include <string>

class VoilierT2 : public Voilier{

    public:
        VoilierT2(std::string nomVoilier, double longueur);
        virtual ~VoilierT2();
        virtual std::string afficheType() const;
};

#endif