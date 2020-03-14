#include "Usager.h"
#include <string>
using namespace std;

Usager::Usager(): m_nom("Vide"), m_prenom("Vide"), m_voilier(Voilier()), m_formule(1){}

Usager::Usager(string nom, string prenom, Voilier voilier, bool formule): 
    m_nom(nom), m_prenom(prenom), m_voilier(voilier), m_formule(formule){}

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

void Usager::quittePort(Port port){
    port.retireAbonne();
}

Voilier Usager::getVoilier(){
    return m_voilier;
}