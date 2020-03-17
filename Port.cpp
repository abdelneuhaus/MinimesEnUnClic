#include "Port.h"
#include <iostream>
#include <string>
using namespace std;

int Port::numeroClient = 0;

Port::Port(string nomPort, int nombreAbonnes, int places): m_nomPort(nomPort), m_nombreAbonnes(nombreAbonnes), m_places(places){}

int Port::getNombreAbonnes(){
    return m_nombreAbonnes;
}

int Port::getNombrePlaces(){
    return m_places;
}

void Port::ajouteAbonne(){
    m_nombreAbonnes++;
    m_places--;
}

void Port::retireAbonne(){
    m_nombreAbonnes--;
    m_places++;
}