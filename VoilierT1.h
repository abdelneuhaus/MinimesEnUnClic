#ifndef VOILIERT1_H
#define VOILIERT1_H
#include "Voilier.h"
#include <string>

class VoilierT1 : public Voilier{

    public:
        VoilierT1(std::string nomVoilier, double longueur);
        virtual ~VoilierT1();
};

#endif