#include "VoilierType1.h"
#include <string>
#include <iostream>
using namespace std;


VoilierType1::VoilierType1(string nomVoilier, double longueur): 
    m_nomVoilier(nomVoilier), m_longueur(longueur), m_cabine(true), m_utiliseService(true){
        while (m_longueur < 10 or m_longueur > 25){
            cout << "Ressaisir une taille comprise entre 10 et 25 mètres" << "\n";
            cin >> m_longueur;
        }
    }