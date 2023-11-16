#include "Ruta.h"

Ruta::~Ruta() {
}

Ruta::Ruta():company(nullptr),origin(nullptr),destination(nullptr),flightRou() {
}
Ruta::Ruta(const Ruta &orig) :company(orig.company),origin(orig.origin),destination(orig.destination),flightRou(orig.flightRou) {}
Ruta::Ruta( Aerolinea *company,Aeropuerto *dest,Aeropuerto* orig, list<Vuelo*>  flvuelo) :company(company),origin(orig),destination(dest),flightRou(flvuelo) {}

Aeropuerto *Ruta::getDestination() const {
    return destination;
}

Aeropuerto *Ruta::getOrigin()  {
    return origin;
}

Aerolinea *Ruta::getCompany()  {
    return company;
}

void Ruta::setDestination(Aeropuerto *destination) {
    Ruta::destination = destination;
}

void Ruta::setOrigin(Aeropuerto *origin) {
    Ruta::origin = origin;
}

void Ruta::setCompany(Aerolinea *company) {
    Ruta::company = company;
}

list<Vuelo *> Ruta::getFlightRou() const {
    return flightRou;
}

void Ruta::setFlightRou(list<Vuelo*>flightRou) {
    Ruta::flightRou = flightRou;
}

bool Ruta::addVuelo(Vuelo *v) {
    if(v->getLinkaero()->getIcao()==this->company->getIcao()&&
       v->getAirpDestin()->getIata()==this->destination->getIata()&&
       v->getAirpOrigin()->getIata()==this->origin->getIata()){
        flightRou.push_back(v);
        return true;
    }
    return false;
}

long Ruta::getNumVuelos() {
    return  flightRou.size();
}

//cambiar a lista
list<Vuelo *> Ruta::getVuelos() {
    return flightRou;
}
