#include "VuelaFlight.h"
/**
 * @brief VuelaFlight
 */
VuelaFlight::VuelaFlight() :aeropuertos(),rutas(),airlines() {}
/**
 * @brief Constructor parametrizado
 * @param vector
 * @param ruta
 */
VuelaFlight::VuelaFlight(std::vector<Aeropuerto> aeropuerto, std::list<Ruta> ruta ,std::deque<Aerolinea> airline):aeropuertos(),rutas(),airlines(){}
/**
 * @brief Destructor
 */
VuelaFlight::~VuelaFlight() {
}
/**
 * @brief BuscarRutasOrigenDestino
 * @param idAerOrig
 * @param idAerDest
 * @return
 */
Ruta &VuelaFlight::buscarRutasOriDeS(string idAerOrig, string idAerDest) {
    std::list<Ruta>::iterator i;
    //Recorremos todos los aeropuertos
    for(i=rutas.begin(); i!=rutas.end(); i++){
        //Obtenemos los datos
        string origenBusq = i->getOrigin()->getIata();
        string destinoBusq = i->getDestination()->getIata();
        //En caso de que se encuentre
        if(origenBusq==idAerOrig && destinoBusq==idAerDest)
            //Devolvemos el dato
            return *i;
    }
    throw std::invalid_argument("La ruta no ha sido encontrado" "\n" "Intente cambiar su origen y destino" );
}
/**
 * @brief BuscarRutasOrigen
 * @param idAerOrig
 * @return
 */
std::list<Ruta *> VuelaFlight::buscarRutasOrigen(string idAerOrig) {
    std::list<Ruta*> lista;
    std::list<Ruta>::iterator i;
    //Recorremos todos los aeropuertos
    for(i = rutas.begin(); i!=rutas.end(); i++){
        //Obtenemos los datos
        string origenBusq = i->getOrigin()->getIata();
        //En caso de que se encuentre
        if(origenBusq==idAerOrig){
            //Devolvemos el dato
            lista.push_back(&i.operator*());
        }
    }
    return  lista;


}

/**
 * @brief Buscar Aeropuerto por Pais
 * @param pais
 * @return
 */
std::vector<Aeropuerto * > VuelaFlight::buscarAeropuertoPais(string pais) {
    //Donde lo vamos a meter
    std::vector<Aeropuerto*> encontrado;
    //Recorremos el tamaño fisico
    for (int i = 0; i < aeropuertos.size(); ++i) {
        if(aeropuertos[i].getIsoPais() == pais){
            //Insertamso el vector de aeropuertos
            encontrado.push_back(&aeropuertos[i]);
        }
    }
    return  encontrado;


}
/**
 * @brief Metodo para añadir nueva ruta
 * @param idAerOrig
 * @param idAerDest
 * @param aerolinea
 */
void VuelaFlight::addNuevaRuta(Aeropuerto* AerOrig, Aeropuerto* AerDest, Aerolinea* aerolineaEncontrada) {
            //Añadimos las rutas ya con la aerolinea  y los aeropertos
            rutas.push_back(Ruta(aerolineaEncontrada,AerDest,AerOrig));
            //d. Obtener la dirección del objeto ruta recién insertado en la lista (en la última posición).
            //e. Enlazar la aerolínea encontrada antes con la ruta anterior mediante
            //Aerolinea::linkAerolRuta.
            aerolineaEncontrada->linkAerolRuta(&(rutas.back()));

}

/**
 * @brief Constructor Copia
 * @param vl
 */

VuelaFlight::VuelaFlight(const VuelaFlight &vl) : aeropuertos(vl.aeropuertos), rutas(vl.rutas),airlines(vl.airlines){}
/**
 * @brief Añade aeropuerto
 * @param aeropuerto
 */

void VuelaFlight::añadeAeropuerto(const Aeropuerto aeropuerto) {
    aeropuertos.push_back(aeropuerto);

}
/**
 * @brief Metodo AddAerolinea
 * @param aerolinea
 */
void VuelaFlight::addAerolinea(std::string icao,Aerolinea aerolinea) {
    airlines.insert( pair<std::string, Aerolinea> (icao,aerolinea));

}
/**
 * @brief Metodo Buscar Aerolinea por Icao
 * @param icaoAerolinea
 * @return
 */
Aerolinea &VuelaFlight::buscaAerolinea(std::string icaoAerolinea) {
    std::map<string ,Aerolinea>::iterator itAerolinea = airlines.find(icaoAerolinea);
    if(!(&itAerolinea)){
        throw std::invalid_argument("No se ha encontrado la aerolinea");
    }
    return  *(&itAerolinea->second);
}
/**
 * @brief Metodo que busca las Aerolineas Activas
 * @return
 */
std::vector<Aerolinea*> VuelaFlight::buscaAerolineasActiva() {
    std::map<string ,Aerolinea>::iterator buscaAerolinea;
    std::vector<Aerolinea*> devuelveAerolinea;
    for (buscaAerolinea=airlines.begin(); buscaAerolinea!=airlines.end(); buscaAerolinea++) {
        if(buscaAerolinea->second.isActivo()){
            devuelveAerolinea.push_back(&buscaAerolinea->second);
        }
    }
    return  devuelveAerolinea;

}
/**
 * @brief Metodo que busca la Aerolinea por el pais
 * @param idPais
 * @return
 */
std::vector<Aerolinea*> VuelaFlight::getAerolineasPais(std::string idPais) {
    std::map<string ,Aerolinea>::iterator buscaAerolinea;
    std::vector<Aerolinea*> devuelveAerolinea;
    for (buscaAerolinea=airlines.begin(); buscaAerolinea!=airlines.end(); ++buscaAerolinea) {
        if(buscaAerolinea->second.getPais() == idPais){
            devuelveAerolinea.push_back(&buscaAerolinea->second);
        }
    }

    return  devuelveAerolinea;
}
/**
 * @brief Metodo que carga las rutas que leemos
 * @param icaoRuta
 * @param origen2
 * @param destino2
 */
void VuelaFlight::cargarRutas(string icaoRuta,string origen2, string destino2){
#pragma  region   Buscar en tiempo logarítmico la aerolínea que hace la ruta en VuelaFlight::work
    std::map<string,Aerolinea>::iterator aerolineaEncontrada = airlines.find(icaoRuta);
#pragma  endregion
#pragma region Buscar en tiempo logarítmico en  PR2 + añadir nueva ruta
    std::vector<Aeropuerto>::iterator orig=aeropuertos.begin();
    Aeropuerto origen;
    origen.setIata(origen2);
    orig= std::lower_bound(aeropuertos.begin(), aeropuertos.end(),origen);
    std::vector<Aeropuerto>::iterator dest=aeropuertos.begin();
    Aeropuerto destino;
    destino.setIata(destino2);
    dest= std::lower_bound(aeropuertos.begin(), aeropuertos.end(),destino);

    if(&dest && &orig && &aerolineaEncontrada){
        //Añadimos nueva ruta a partir del origen el destino y el icao
        addNuevaRuta(&(*orig),&(*dest),&aerolineaEncontrada->second);
    }
}
/**
 * @brief Metodo que ordena los aeropuertos
 */

void VuelaFlight::ordenarAeropuertos(){
    std::sort(aeropuertos.begin(), aeropuertos.end());
}
/**
 * @brief Metodo que devuelve el tamaño del vector
 */
long VuelaFlight::tamaAeropuertos() {
    return aeropuertos.size();
}
/**
 * @brief Metodo que devuelve el tamaño de la lista de rutas
 */
long VuelaFlight::tamaRutas() {
    return rutas.size();
}
/**
 * @brief Metodo que devuelve el tamaño del arbol
 */
long VuelaFlight::tamaWork() {
    return airlines.size();
}

void VuelaFlight::cargarVuelos(std::string fichVuelos) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int contador = 0;

    std::string id;
    std::string iata;
    std::string tipo;
    std::string nombre;
    std::string latitud_str;
    std::string longitud_str;
    std::string continente;
    std::string iso_pais;

    float latitud, longitud;


    is.open("aeropuertos_v2.csv"); //carpeta de proyecto
    if (is.good()) {

        clock_t lectura = clock();

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (fila != "") {

                columnas.str(fila);

                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, iata, ';');
                getline(columnas, tipo, ';');
                getline(columnas, nombre, ';');
                getline(columnas, latitud_str, ';');
                getline(columnas, longitud_str, ';');
                getline(columnas, continente, ';');
                getline(columnas, iso_pais, ';');

                //  Transformamos la latitud y longitud a float
                latitud = std::stof(latitud_str);
                longitud = std::stof(longitud_str);


                UTM *utm = new UTM(latitud, longitud);

                //vuelaFlight.addNuevoAeropuerto(*aeropuerto);

                delete utm;
                fila = "";
                columnas.clear();
            }
        }

        is.close();

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}

bool
VuelaFlight::registrarVuelo(std::string fNumber, std::string iataAeroOrig, std::string iataAeroDest, std::string plane,
                            std::string datosMeteo, Fecha f) {
    std::vector<Aeropuerto>::iterator dest(std::lower_bound(this->aeropuertos.begin(), this->aeropuertos.end(),iataAeroDest));


}

