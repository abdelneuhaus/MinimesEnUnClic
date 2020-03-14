#include "VoilierType2.h"
#include <string>
#include <iostream>
using namespace std;


VoilierType2::VoilierType2(string nomVoilier, double longueur): 
    m_nomVoilier(nomVoilier), m_longueur(longueur), m_cabine(true), m_utiliseService(true){
        while (m_longueur < 25){
            cout << "Ressaisir une taille supérieure à 25 mètres" << "\n";
            cin >> m_longueur;
        }
    }