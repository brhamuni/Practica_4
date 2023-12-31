#include <vector>
#include <list>
#include <deque>
#include "Aeropuerto.h"
#include "Ruta.h"
#include <iostream>
#include <set>
#include <fstream>
#include <sstream>

#ifndef PRACTICA_2_VUELAFLIGHT_H
#define PRACTICA_2_VUELAFLIGHT_H
/**
 * @file VuelaFlight.h
 * @date 03/11/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @brief Vuela Flight
 */

class VuelaFlight {
private:
    std::vector<Aeropuerto> aeropuertos;
    std::list<Ruta> rutas;
    std::map<string,Aerolinea> airlines;
    int tamavuelos=0;

    //Metodos privados para cargar cada uno de los csv
    void cargarVuelos(string fichVuelos);
    void cargarRutas(string fichRutas);
    void cargarAeropuertos(string fichAeropuertos);
    void cargarAerolineas(string fichAerolineas);

public:
    //Constructor por defecto
    VuelaFlight();
    //Constructor copia
    VuelaFlight(const VuelaFlight &vl);
    //Constructor parametrizado
    VuelaFlight(std::vector<Aeropuerto> aeropuerto, std::list<Ruta> ruta ,std::deque<Aerolinea> airline);
    //Destructor VuelaFlight
    ~VuelaFlight();
    //Metodos que tenemos que utilizar en esta practica
    //BuscarRutaDeOrigenDestino
    Ruta& buscarRutasOriDeS(string idAerOrig,string idAerDest);
    //BuscarRutasDeOrigen
    std::list<Ruta*> buscarRutasOrigen (string idAerOrig);
    //Buscar AeropuertoPais
    std::vector<Aeropuerto*> buscarAeropuertoPais(string pais);
    //AñadirNuevoAeropuerto
    void añadeAeropuerto(const Aeropuerto aeropuerto);
    //AñadirNuevaRuta
    void addNuevaRuta(Aeropuerto* AerOrig, Aeropuerto* AerDest, Aerolinea* aerolineaEncontrada);
    //Añade Aerolinea
    void addAerolinea(std::string icao, Aerolinea aerolinea);
    //Buscar Aerolinea por icao
    Aerolinea &buscaAerolinea(string icaoAerolinea);
    //Buscar Aerolinea activa
    std::vector<Aerolinea*> buscaAerolineasActiva();
    //Metodo que obtiene la aerolineas por el Pais
    std::vector<Aerolinea*> getAerolineasPais(string idPais);
    //Metodo que Carga las Rutas
    void registrarRutas(string icaoRuta, string origen2, string destino2);
    //Metodo que ordenar Aeropuertos
    void ordenarAeropuertos();
    int getTamavuelos();
    int getNumAeropuertos();
    int getNumAerolineas();
    int getNumRutas();

    bool registrarVuelo(string& fNumber, string& iataAeroOrig, string& iataAeroDest, string& plane, string& datosMeteo, Fecha f);
    vector<Vuelo*> buscaVuelos(string fnumber);
    vector<Vuelo*> vuelosOperadorPor(string icaoAerolinea, Fecha fecha);
    set<string> buscaVuelosDestAerop(string paisOrig, string iataAeroDest);
    set<Aeropuerto*>buscaAeropuertosAerolinea(string icaoAerolinea);

    list<Ruta*> buscarRutasPaisOrig(string paisOrig);
};


#endif //PRACTICA_2_VUELAFLIGHT_H
