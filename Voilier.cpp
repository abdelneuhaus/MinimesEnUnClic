#include "Voilier.h"
#include <iostream>
#include <string>
using namespace std;


Voilier::Voilier(): m_longueur(0), m_cabine(0), m_utiliseService(0){}

Voilier::~Voilier(){}

Voilier::Voilier(const Voilier &VoilierCopie, string nomVoilier):
    m_nomVoilier(nomVoilier), m_longueur(VoilierCopie.m_longueur), m_cabine(VoilierCopie.m_cabine), m_utiliseService(VoilierCopie.m_utiliseService){}

double Voilier::getLongueur(){return m_longueur;}


bool Voilier::getCabine(){return m_cabine;}


bool Voilier::getUtiliseService(){return m_utiliseService;}

string Voilier::getNomVoilier(){
    return m_nomVoilier;
}