#ifndef PRACTICA_3_AEROLINEA_H
#define PRACTICA_3_AEROLINEA_H
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include "Aeropuerto.h"
using  namespace  std;
class Ruta;
class Vuelo;
class Aerolinea {
private:
    unsigned int id;
    string icao;
    string nombre;
    string pais;
    bool activo;
    std::deque<Ruta*> aerorutas;
    std::multimap<string,Vuelo*> flights;
public:
    //Constructor por defecto
    Aerolinea();
    //Constructor copia
    Aerolinea(const Aerolinea &orig);
    //Constructor paramerizado
    Aerolinea(int id, string icao, string nombre ,string pais, bool activo);
    //Destrcutor
    ~Aerolinea();
    //Metodo que devuelve los aeropuertos de origen
    std::vector<Aeropuerto*>getAeropuertosOrig();
    //Metodo que devuelve todas las rutas cuya aeropuerto de origen tenga ese mismo iata
    std::vector<Ruta*> getRutasAeropuerto(string iataAirport);
    //Enlaza Aerolina con Aeroroutes
    void linkAerolRuta(Ruta *r);
    //Operator<
    bool operator<(const Aerolinea &orig) const;
    //Operador>
    bool  operator>(const Aerolinea &orig) const;
    //Getter Id
    unsigned int getId() const;
    //Setter Id
    void setId(unsigned int id);
    //Getter Icao
    const string &getIcao() const;
    //Setter Icao
    void setIcao(const string &icao);
    //Getter Nombre
    const string &getNombre() const;
    //Setter Nombre
    void setNombre(const string &nombre);
    //Getter Pais
    const string &getPais() const;
    //Setter Pais
    void setPais(const string &pais);
    //Getter Activo
    bool isActivo() const;
    //Setter Activo
    void setActivo(bool activo);
    //Getter de variable privada aeroruta
    const std::deque<Ruta *> &getAerorutas() const;
    //Setter Aerorutas
    void setAerorutas(const std::deque<Ruta *> &aerorutas);
};




#endif //PRACTICA_3_AEROLINEA_H
