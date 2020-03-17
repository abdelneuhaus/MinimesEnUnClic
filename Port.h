#ifndef PORT_H
#define PORT_H
#include <string>

class Port{

    public:
        Port(std::string nomPort, int places, int nombresAbonnes);
        int getNombrePlaces();
        int getNombreAbonnes();
        void ajouteAbonne();
        void retireAbonne();


    private:
        std::string m_nomPort;
        int m_places;
        int m_nombreAbonnes;
        static int numeroClient;
};

#endif