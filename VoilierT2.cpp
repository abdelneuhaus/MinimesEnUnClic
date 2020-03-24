#include "VoilierT2.h"
#include <string>
#include <iostream>
using namespace std;

VoilierT2::VoilierT2(string nomVoilier, double longueur): 
    Voilier(nomVoilier, longueur){
        m_cabine = true;
        m_utiliseService = true;
        m_place = -1;
        m_typeVoilier = "T2";
    }

VoilierT2::~VoilierT2(){};