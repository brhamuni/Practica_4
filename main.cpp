#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "UTM.h"
#include "Aeropuerto.h"
#include "Aerolinea.h"
#include "VuelaFlight.h"


/**
 * @brief Practica 4 EEDD
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
    <<vuelaFlight.getAeropuertos().size()<<" aeropuertos, "
    <<vuelaFlight.getAirlines().size()<<" aerolineas, "
    <<vuelaFlight.getRutas().size()<<" rutas, "
    <<vuelaFlight.getTamavuelos()<<" vuelos."<<endl;

#pragma region Ejercicio 2 (AEA5201 VLG2021)

    string aerolinea1="AEA5201";
    map<string,Aerolinea>::iterator aerolineaAEA=vuelaFlight.getAirlines().find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloAEA =(*aerolineaAEA).second.getVuelos("AEA5201");

    //Si el vector tiene algun elemento significa que tiene vuelos
    if(vueloAEA.size() != 0){
        cout<<endl<<"El vuelo AEA5201 es realizado con la aerolinea: "<<aerolineaAEA->second.getNombre()
        <<", con pais: "<<aerolineaAEA->second.getPais()
        <<", origen: "<<vueloAEA[1]->getAirpOrigin()->getIata()
        <<", destino: "<<vueloAEA[1]->getAirpDestin()->getIata()<<endl;
        cout<<"--------------VUELOS CON AEA: --------------"<<endl;
        for (int i = 0; i < vueloAEA.size(); ++i) {
            if(vueloAEA[i]->getDatoMeteo().substr(0,6)=="Lluvia" || vueloAEA[i]->getDatoMeteo().substr(0,9)=="Chubascos" ){
                cout<<"Vuelo: "<<i+1<<", Dia: "<<vueloAEA[i]->getFecha()<<", Condiciones: "<<vueloAEA[i]->getDatoMeteo()<<endl;
            }
        }
        cout<<"Hay un total de: "<<vueloAEA.size()<<" vuelos"<<endl<<endl;
    }else
        cout<<"El vuelo AEA5201 no existe"<<endl;

    aerolinea1="VLG2021";
    map<string,Aerolinea>::iterator aerolineaVLG=vuelaFlight.getAirlines().find(aerolinea1.substr(0,3));
    vector<Vuelo*> vueloVLG =(*aerolineaVLG).second.getVuelos("VLG2021");

    //Si el vector tiene algun elemento significa que tiene vuelos
    if(vueloVLG.size()!=0){
        cout<<"El vuelo VLG2021 es realizado con la aerolinea: "<<aerolineaVLG->second.getNombre()
        <<", con pais: "<<aerolineaVLG->second.getPais()
        <<", origen: "<<vueloVLG[1]->getAirpOrigin()->getIata()
        <<", destino: "<<vueloVLG[1]->getAirpDestin()->getIata()<<endl;
        cout<<"--------------VUELOS CON VLG: --------------"<<endl;
        for (int i = 0; i < vueloVLG.size(); ++i) {
            if(vueloVLG[i]->getDatoMeteo().substr(0,6)=="Lluvia" || vueloVLG[i]->getDatoMeteo().substr(0,9)=="Chubascos" ){
                cout<<"Vuelo: "<<i+1<<", Dia: "<<vueloVLG[i]->getFecha()<<", Condiciones: "<<vueloVLG[i]->getDatoMeteo()<<endl;
            }
        }
        cout<<"Hay un total de: "<<vueloAEA.size()<<" vuelos"<<endl;

    }else
        cout<<"El vuelo VLG2021 no existe"<<endl;

#pragma endregion

#pragma region Ejercicio 3 (VLG, el 13/4/2018)
    Fecha fechaVLG(13,4,18);
    vector<Vuelo*>vueloVLG2=vuelaFlight.vuelosOperadorPor("VLG",fechaVLG);
    //Uso un mapa para quitar los repetidos
    std::map<string ,Vuelo*>vueloVLG2SinRepetidos;
    for (int i = 0; i <vueloVLG2.size(); ++i) {
        pair<string,Vuelo*> pair1(vueloVLG2[i]->getPlane(),vueloVLG2[i]);
        vueloVLG2SinRepetidos.insert(pair1);
    }
    std::map<string ,Vuelo*>::iterator iterador;
    cout<<endl<<"--------------Los aviones usados por la aerolinea Vueling el 13/4/2018 son: --------------"<<endl;
    for (iterador=vueloVLG2SinRepetidos.begin(); iterador!=vueloVLG2SinRepetidos.end(); iterador++) {
        cout<<"Modelo: "<< iterador->second->getPlane()<<endl;
    }
    cout<<"Total de aviones usados por vueling: "<<vueloVLG2SinRepetidos.size()<<endl;

#pragma endregion

#pragma region Ejercicio 4 Vuelos de Spain a London

    set<string> vuelosLHR=vuelaFlight.buscaVuelosDestAerop("ES","LHR");
    set<string> vuelosSTN=vuelaFlight.buscaVuelosDestAerop("ES","STN");
    set<string> vuelosLTN=vuelaFlight.buscaVuelosDestAerop("ES","LTN");
    set<string> vuelosLGW=vuelaFlight.buscaVuelosDestAerop("ES","LGW");

    set<string> vuelosLondon;
    //Concatenamos los vuelos para dejarlos todos en vuelosLondon
    vuelosLondon.insert(vuelosLHR.begin(), vuelosLHR.end());
    vuelosLondon.insert(vuelosSTN.begin(), vuelosSTN.end());
    vuelosLondon.insert(vuelosLTN.begin(), vuelosLTN.end());
    vuelosLondon.insert(vuelosLGW.begin(), vuelosLGW.end());

    cout<<endl<<"--------------Todos los vuelos a Londres que salen desde Spain: --------------"<<endl;
    set<string>::iterator vuelosLondonIT;
    for(vuelosLondonIT=vuelosLondon.begin();vuelosLondonIT!=vuelosLondon.end();vuelosLondonIT++){
        cout<<"Vuelo: "<<*vuelosLondonIT<<endl;
    }
    cout<<"El total de vuelos de Spain a London son: "<< vuelosLondon.size() <<" vuelos."<<endl;

#pragma endregion

#pragma region Ejercicio Parejas

    set<Aeropuerto*> aeropuertosEVE=vuelaFlight.buscaAeropuertosAerolinea("EVE");
    set<Aeropuerto*>::iterator aeropuertosEVEIT;

    cout<<endl<<"--------------Todos los aeropuertos de la aerolinea EVE: --------------"<<endl;
    for(aeropuertosEVEIT=aeropuertosEVE.begin();aeropuertosEVEIT!=aeropuertosEVE.end();aeropuertosEVEIT++){
        cout<<"Vuelo: "<<(*aeropuertosEVEIT)->getNombre()<<endl;
    }
    cout<<"El total los aeropuertos que son intervenidos por la aerolinea EVE son: "<< aeropuertosEVE.size() <<" vuelos."<<endl;

#pragma endregion

    return 0;
}