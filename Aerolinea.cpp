#include "Aerolinea.h"
#include "Ruta.h"

#include <deque>
/**
 * @brief Constructor por defecto
 */
Aerolinea::Aerolinea():id(0),icao(""),nombre(""),pais(""),activo(false),aerorutas(){}
/**
 * @brief Constructor copia
 * @param orig
 */
Aerolinea::Aerolinea(const Aerolinea &orig):id(orig.id),icao(orig.icao),nombre(orig.nombre),pais(orig.pais),activo(orig.activo),aerorutas(orig.aerorutas) {}
/**
 * @brief Constructor parametrizado
 * @param orig
 */
Aerolinea::Aerolinea(int id, std::string icao, std::string nombre, std::string pais, bool activo):id(id),icao(icao),nombre(nombre),pais(pais),activo(activo),aerorutas() {}

/**
 * @brief Metodo que obtiene los aeropuerto de origen
 * @return
 */
std::vector<Aeropuerto*> Aerolinea::getAeropuertosOrig() {
    //Creo un vector dinamico de aeropuertos que en el que voy a devolver los aeropuertos
    std::vector<Aeropuerto*> vAeroOrig;
    //Creo un arbol para almacenar los aeropuertos de origen
    std::map<string ,Aeropuerto*> arbolDeAeroOrig;
    //Obtengo   aerorutas
    std::vector<Ruta*> aerorutasMetodo = getAerorutas();
    for (int i = 0; i < aerorutasMetodo.size(); ++i) {
        Aeropuerto *aeropuerto = aerorutasMetodo[i]->getOrigin();
        //Si en el árbol el dato no esta repetido
            if(!arbolDeAeroOrig.insert(aeropuerto)){
                //Insertamos en el arbol
                arbolDeAeroOrig.insert(aeropuerto);
                vAeroOrig.push_back(aeropuerto);
            }
    }

    return  vAeroOrig;

}
/***
 * @brief Devuelve todas las rutas cuyo AeroPuerto de origen o destino tenga ese iata
 * @param iataAirport
 * @return
 */
std::vector<Ruta*> Aerolinea::getRutasAeropuerto(std::string iataAirport) {
    //Vector que vamos a llenar
    std::vector<Ruta*> vRutasAero;
    //Recorremos las rutas de la aerolinea
    for (int i = 0; i < aerorutas.size(); ++i) {
        string iataOrig = aerorutas[i]->getOrigin()->getIata();
        string iataDest = aerorutas[i]->getDestination()->getIata();
        //Si tiene ese iata  insertamos  la ruta
            if(iataOrig == iataAirport ||iataDest == iataAirport ){
                    vRutasAero.push_back(aerorutas[i]);
            }
    }
    //Devolvemos el vector de rutas
    return  vRutasAero;
}
/**
 * @brief Metodo que enlaza la Aerolinea con su ruta
 * @param r
 */
void Aerolinea::linkAerolRuta(Ruta *r) {
    this->aerorutas.push_back(r);
}
/**
 * @brief Destructor de Aerolinea
 */
Aerolinea::~Aerolinea() {
}
/**
 * @brief Metodo que compara si una aerolinea es menor que otra por icao
 * @param orig
 * @return
 */
bool Aerolinea::operator<(const Aerolinea &orig) const {
    return (this->icao<orig.icao);

}
/**
 * @brief  Metodo que compara si una aerolinea es mayor que otra por icao
 * @param orig
 * @return
 */
bool  Aerolinea::operator>(const Aerolinea &orig) const {
    return (this->icao>orig.icao);

}
/**
 * @brief Getter Id
 * @return
 */
unsigned int Aerolinea::getId() const {
    return id;
}
/**
 * @brief Setter Id
 * @param id
 */
void Aerolinea::setId(unsigned int id) {
    Aerolinea::id = id;
}
/**
 * @brief Getter Icao
 * @return
 */
const string &Aerolinea::getIcao() const {
    return icao;
}
/**
 * @brief Setter Icao
 * @param icao
 */

void Aerolinea::setIcao(const string &icao) {
    Aerolinea::icao = icao;
}
/**
 * @brief Getter Nombre
 * @return
 */
const string &Aerolinea::getNombre() const {
    return nombre;
}
/**
 * @brief Setter Nombre
 * @param nombre
 */

void Aerolinea::setNombre(const string &nombre) {
    Aerolinea::nombre = nombre;
}
/**
 * @brief Getter Pais
 * @return
 */
const string &Aerolinea::getPais() const {
    return pais;
}
/**
 * @brief Setter Pais
 * @param pais
 */
void Aerolinea::setPais(const string &pais) {
    Aerolinea::pais = pais;
}
/**
 * @brief Getter Activo
 * @return
 */
bool Aerolinea::isActivo() const {
    return activo;
}
/**
 * @brief Setter Activo
 * @param activo
 */
void Aerolinea::setActivo(bool activo) {
    Aerolinea::activo = activo;
}
/**
 * @brief Getter Con Acceso al private aerorutas
 * @return
 */
const std::vector<Ruta *> &Aerolinea::getAerorutas() const {
    return aerorutas;
}
/**
 * @brief Setter AeroRutas
 * @param aerorutas
 */

void Aerolinea::setAerorutas(const std::vector<Ruta *> &aerorutas) {
    Aerolinea::aerorutas = aerorutas;
}




