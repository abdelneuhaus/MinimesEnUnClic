#include "VoilierNonHabitable.h"
#include <string>
#include <iostream>
using namespace std;


VoilierNonHabitable::VoilierNonHabitable(string nomVoilier, double longueur): 
    m_nomVoilier(nomVoilier), m_longueur(longueur), m_cabine(false), m_utiliseService(false){
        while (m_longueur > 10){
            cout << "Taille trop élevée. Ressaisir une taille inférieure à 10 mètres" << "\n";
            cin >> m_longueur;
        }
    }
