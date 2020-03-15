#include "Usager.h"
#include <string>
using namespace std;

int Usager::dossier = 0;

Usager::Usager(): m_nom("Vide"), m_prenom("Vide"), m_voilier(Voilier()), m_formule(1), m_numeroClient(0){}

Usager::Usager(string nom, string prenom, Voilier voilier, bool formule): 
    m_nom(nom), m_prenom(prenom), m_voilier(voilier), m_formule(formule), m_numeroClient(dossier){
        dossier++;
    }

Usager::~Usager(){}



string Usager::getNom() const{
    return m_nom;
}

string Usager::getPrenom() const{
    return m_prenom;
}

bool Usager::getFormule(){
    return m_formule;
}

Voilier Usager::getVoilier(){
    return m_voilier;
}

int Usager::getNumeroClient(){
    return m_numeroClient;
}