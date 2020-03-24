#include "Voilier.h"
#include <string>
#include <iostream>
using namespace std;


Voilier::Voilier(){}

Voilier::Voilier(string nomVoilier, double longueur) : m_nomVoilier(nomVoilier), m_longueur(longueur){}

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

int Voilier::getPlace() const{
    return m_place;
}

void Voilier::setPlace(int nbr){
    m_place = nbr;
}

string Voilier::afficheType() const{
    return "None";
}

void Voilier::saveData(ofstream& file) const {
    file << m_nomVoilier << endl;
    file << m_typeVoilier << endl;
    file << m_cabine << endl;
    file << m_longueur << endl;
    file << m_utiliseService << endl;
    file << m_place << endl;
}