#include "Usager.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


Usager::Usager(): m_nom("Vide"), m_prenom("Vide"), m_voilier(0), m_formule(1){
    m_facture = 0;
    m_presence = false;
}

Usager::Usager(string nom, string prenom, Voilier *voilier, bool formule): 
    m_nom(nom), m_prenom(prenom), m_voilier(voilier), m_formule(formule){
        m_facture = 0;
        m_presence = true;
    }

Usager::~Usager(){}

string Usager::getNom() const{
    return m_nom;
}

string Usager::getPrenom() const{
    return m_prenom;
}

bool Usager::getFormule() const{
    return m_formule;
}

Voilier Usager::getVoilier() const{
    return *m_voilier;
}

int Usager::getFacture(){
    return m_facture;
}

void Usager::setFacture(int prix){
    m_facture = prix;
}

void Usager::setPresence(bool presence){
    m_presence = presence;
}

void Usager::departClient(){
    m_presence = false;
}

bool Usager::getPresence(){
    return m_presence;
}

void Usager::saveData(ofstream& file) const {
    file << m_nom << endl;
    file << m_prenom << endl;
    file << m_presence << endl;
    file << m_facture << endl;
    file << m_formule << endl;
}