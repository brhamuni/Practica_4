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

    return 0;
}