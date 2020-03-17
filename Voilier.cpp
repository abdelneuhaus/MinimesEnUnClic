#include "Voilier.h"
#include <string>
using namespace std;


Voilier::Voilier(): m_nomVoilier("Voilier"), m_longueur(0), m_cabine(0), m_utiliseService(0){
    m_place = - 1;
}

Voilier::Voilier(string nomVoilier, double longueur, bool cabine, bool utiliseService): 
    m_nomVoilier(nomVoilier), m_longueur(longueur), m_cabine(cabine), m_utiliseService(utiliseService){
        m_place = - 1;
    }

Voilier::~Voilier(){}

Voilier::Voilier(const Voilier &VoilierCopie, string nomVoilier):
    m_nomVoilier(nomVoilier), m_longueur(VoilierCopie.m_longueur), m_cabine(VoilierCopie.m_cabine), m_utiliseService(VoilierCopie.m_utiliseService){}



double Voilier::getLongueur() const{
    return m_longueur;
}

bool Voilier::getCabine() const{
    return m_cabine;
}

bool Voilier::getUtiliseService() const{
    return m_utiliseService;
}

string Voilier::getNomVoilier() const{
    return m_nomVoilier;
}

string Voilier::getTypeVoilier() const{
    return m_typeVoilier;
}

void Voilier::setTypeVoilier(string type){
    m_typeVoilier = type;
}



int Voilier::getPlace(){
    return m_place;
}

void Voilier::setPlace(int nbr){
    m_place = nbr;
}