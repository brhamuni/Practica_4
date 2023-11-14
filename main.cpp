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

    Aerolinea ibe=vuelaFlight.buscaAerolinea("IBE");
    Aerolinea aea=vuelaFlight.buscaAerolinea("AEA");



    cout<<"Hay un total de: "
    <<vuelaFlight.aeropuertos.size()<<" aeropuertos, "
    <<vuelaFlight.airlines.size()<<" aerolineas, "
    <<vuelaFlight.rutas.size()<<" rutas,"<<std::endl;


    string aerolinea1="AEA5201";
    map<string,Aerolinea>::iterator aerolineaAEA=vuelaFlight.airlines.find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloAEA =(*aerolineaAEA).second.getVuelos("AEA5201");
    if(vueloAEA.size() != 0){
        cout<<"El vuelo es realizado con la aerolinea: "<<aerolineaAEA->second.getNombre();
        cout<<", con pais: "<<aerolineaAEA->second.getPais();
        cout<<", origen: "<<vueloAEA[1]->getAirpOrigin()->getIata();
        cout<<", destino: "<<vueloAEA[1]->getAirpDestin()->getIata()<<endl;
        cout<<endl<<"VUELOS CON AEA: "<<endl;
        for (int i = 0; i < vueloAEA.size(); ++i) {
            if(vueloAEA[i]->getDatoMeteo().substr(0,6)=="Lluvia" || vueloAEA[i]->getDatoMeteo().substr(0,9)=="Chubascos" ){
                cout<<"Vuelo: "<<i+1<<", Dia: "<<vueloAEA[i]->getFecha()<<", Condiciones: "<<vueloAEA[i]->getDatoMeteo()<<endl;
            }
        }
        cout<<"Hay un total de: "<<vueloAEA.size()<<" vuelos"<<endl;
    }else
        cout<<"El vuelo AEA5201 no existe"<<endl;

    aerolinea1="VLG2021";
    map<string,Aerolinea>::iterator aerolineaVLG=vuelaFlight.airlines.find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloVLG =(*aerolineaVLG).second.getVuelos("VLG2021");
    if(vueloVLG.size()!=0){
        cout<<"El vuelo es realizado con la aerolinea: "<<aerolineaVLG->second.getNombre();
        cout<<", con pais: "<<aerolineaVLG->second.getPais();
        cout<<", origen: "<<vueloVLG[1]->getAirpOrigin()->getIata();
        cout<<", destino: "<<vueloVLG[1]->getAirpDestin()->getIata();
        cout<<endl<<"VUELOS CON VLG: "<<endl;
        for (int i = 0; i < vueloVLG.size(); ++i) {
            if(vueloVLG[i]->getDatoMeteo().substr(0,6)=="Lluvia" || vueloVLG[i]->getDatoMeteo().substr(0,9)=="Chubascos" ){
                cout<<"Vuelo: "<<i+1<<", Dia: "<<vueloVLG[i]->getFecha()<<", Condiciones: "<<vueloVLG[i]->getDatoMeteo()<<endl;
            }
        }
        cout<<"Hay un total de: "<<vueloAEA.size()<<" vuelos"<<endl;

    }else
        cout<<"El vuelo VLG2021 no existe"<<endl;

    Fecha fechaVLG(13,4,2018);
    vueloVLG=(*aerolineaAEA).second.getVuelos(Fecha(12,4,2018),Fecha(14,4,2018));
    cout<<"Los aviones usados por la aerolinea Vueling el 13/4/2018 son: "<<endl;
    for (int i = 0; i <vueloVLG.size(); ++i) {
        cout<<"Modelo :"<<i+1<< vueloVLG[i]->getPlane()<<endl;
    }




    return 0;
}