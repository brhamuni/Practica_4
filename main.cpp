#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "UTM.h"
#include "Aeropuerto.h"
#include "Aerolinea.h"
#include "VuelaFlight.h"

/**
 * @brief Practica 3 EEDD
 * @date 19/10/2023
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, const char * argv[]) {
    VuelaFlight vuelaFlight;
    cout<<"Hay un total de: "
    <<vuelaFlight.aeropuertos.size()<<" aeropuertos, "
    <<vuelaFlight.airlines.size()<<" aerolineas, "
    <<vuelaFlight.rutas.size()<<" rutas,"<<std::endl;


    string aerolinea1="AEA5201";
    map<string,Aerolinea>::iterator aerolineaAEA=vuelaFlight.airlines.find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloAEA =(*aerolineaAEA).second.getVuelos("AEA5201");
    if(&vueloAEA[0]== nullptr){
        cout<<"El vuelo es realizado con la aerolinea: "<<aerolineaAEA->second.getNombre()<<", con pais: "<<
            aerolineaAEA->second.getPais()<<", aeropuerto de origen: "<<vueloAEA[0]->getAirpOrigin()->getIata()<<
            ", aeropuerto de destino: "<<vueloAEA[0]->getAirpDestin()->getIata();
    }else
        cout<<"El vuelo AEA5201 no existe"<<endl;

    aerolinea1="VLG2021";
    map<string,Aerolinea>::iterator aerolineaVLG=vuelaFlight.airlines.find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloVLG =(*aerolineaVLG).second.getVuelos("AEA5201");
    if(&vueloVLG[0]== nullptr){
        cout<<"El vuelo es realizado con la aerolinea: "<<aerolineaVLG->second.getNombre()<<", con pais: "<<
            aerolineaVLG->second.getPais()<<", aeropuerto de origen: "<<vueloVLG[0]->getAirpOrigin()->getIata()<<
            ", aeropuerto de destino: "<<vueloVLG[0]->getAirpDestin()->getIata();
    }else
        cout<<"El vuelo VLG2021 no existe"<<endl;





    return 0;
}