#include "Vuelo.h"

Vuelo::Vuelo():flightNumb(""),plane(""),datoMeteo(""),fecha(),linkaero(),airpOrigin(),airpDestin(){

}

Vuelo::Vuelo(std::string flightNumb,std::string plane,std::string datoMeteo,Fecha fecha,
             Aerolinea *aerolinea, Aeropuerto*orig, Aeropuerto*dest):
        flightNumb(flightNumb),plane(plane),datoMeteo(datoMeteo),fecha(fecha),linkaero(aerolinea),airpOrigin(orig),airpDestin(dest){
}

Vuelo::Vuelo(const Vuelo &orig):
        flightNumb(orig.flightNumb),plane(orig.plane),datoMeteo(orig.datoMeteo),fecha(orig.fecha),
        linkaero(orig.linkaero), airpDestin(orig.airpDestin),airpOrigin(orig.airpOrigin){
}

const std::string &Vuelo::getFlightNumb() const {
    return flightNumb;
}

void Vuelo::setFlightNumb(const std::string &flightNumb) {
    Vuelo::flightNumb = flightNumb;
}

const std::string &Vuelo::getPlane() const {
    return plane;
}

void Vuelo::setPlane(const std::string &plane) {
    Vuelo::plane = plane;
}

const std::string &Vuelo::getDatoMeteo() const {
    return datoMeteo;
}

void Vuelo::setDatoMeteo(const std::string &datoMeteo) {
    Vuelo::datoMeteo = datoMeteo;
}

 Fecha &Vuelo::getFecha()  {
    return fecha;
}

void Vuelo::setFecha(const Fecha &fecha) {
    Vuelo::fecha = fecha;
}

Vuelo::~Vuelo() {

}

Aerolinea *Vuelo::getLinkaero() const {
    return linkaero;
}

void Vuelo::setLinkaero(Aerolinea *linkaero) {
    Vuelo::linkaero = linkaero;
}

Aeropuerto *Vuelo::getAirpOrigin() const {
    return airpOrigin;
}

void Vuelo::setAirpOrigin(Aeropuerto *airpOrigin) {
    Vuelo::airpOrigin = airpOrigin;
}

Aeropuerto *Vuelo::getAirpDestin() const {
    return airpDestin;
}

void Vuelo::setAirpDestin(Aeropuerto *airpDestin) {
    Vuelo::airpDestin = airpDestin;
}
