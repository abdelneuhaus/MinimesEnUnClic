#include "VoilierT1.h"
#include <string>
#include <iostream>
using namespace std;

VoilierT1::VoilierT1(string nomVoilier, double longueur): 
    Voilier(nomVoilier, longueur){
        m_cabine = true; 
        m_utiliseService = true;
        m_place = -1;
        m_typeVoilier = "T1";
    }

VoilierT1::~VoilierT1(){}

string VoilierT1::afficheType() const{
    return "Voilier de type 1";
}