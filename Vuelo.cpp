#include "Vuelo.h"

Vuelo::Vuelo():flightNumb(""),plane(""),datoMeteo(""),fecha(){

}

Vuelo::Vuelo(std::string flightNumb, std::string plane, std::string datoMeteo, Fecha fecha):
        flightNumb(flightNumb),plane(plane),datoMeteo(datoMeteo),fecha(fecha){
}

Vuelo::Vuelo(const Vuelo &orig):
        flightNumb(orig.flightNumb),plane(orig.plane),datoMeteo(orig.datoMeteo),fecha(orig.fecha){
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

const Fecha &Vuelo::getFecha() const {
    return fecha;
}

void Vuelo::setFecha(const Fecha &fecha) {
    Vuelo::fecha = fecha;
}

Vuelo::~Vuelo() {

}
