#ifndef PR4_VUELO_H
#define PR4_VUELO_H
#include <string>
#include <iostream>
#include "fecha.h"
#include "Aerolinea.h"

class Vuelo {
private:
    std::string flightNumb;
    std::string plane;
    std::string datoMeteo;
    Fecha fecha;
    Aerolinea* linkaero;
    Aeropuerto* airpOrigin;
    Aeropuerto* airpDestin;

public:
    Vuelo();
    Vuelo(std::string flightNumb,std::string plane,std::string datoMeteo,Fecha fecha);
    Vuelo(const Vuelo &orig);

    virtual ~Vuelo();

    const std::string &getFlightNumb() const;

    void setFlightNumb(const std::string &flightNumb);

    const std::string &getPlane() const;

    void setPlane(const std::string &plane);

    const std::string &getDatoMeteo() const;

    void setDatoMeteo(const std::string &datoMeteo);

    const Fecha &getFecha() const;

    void setFecha(const Fecha &fecha);


};


#endif //PR4_VUELO_H
