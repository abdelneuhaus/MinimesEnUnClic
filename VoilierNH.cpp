#include "VoilierNH.h"
#include <string>
#include <iostream>
using namespace std;

VoilierNH::VoilierNH(string nomVoilier, double longueur): 
    Voilier(nomVoilier, longueur){
        m_cabine = false;
        m_utiliseService = false;
        m_place = -1;
}

VoilierNH::~VoilierNH(){};

string VoilierNH::afficheType() const{
    return "NH";
}