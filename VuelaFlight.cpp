#include "VuelaFlight.h"
/**
 * @brief VuelaFlight
 */
VuelaFlight::VuelaFlight() :aeropuertos(),rutas(),airlines() {
    cargarAeropuertos("aeropuertos_v2.csv");
    cargarAerolineas("aerolineas_v1.csv");
    cargarRutas("rutas_v1.csv");
    cargarVuelos("infovuelos_v1.csv");
}

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
void VuelaFlight::registrarRutas(string icaoRuta, string origen2, string destino2){
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
    int vuelos=0;
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int contador = 0;

    std::string flightNumber;
    std::string dep_airport_code;
    std::string arr_airport_code;
    std::string plane;
    std::string dep_weather_desc;
    std::string dep_date;


    is.open(fichVuelos); //carpeta de proyecto
    if (is.good()) {
        clock_t lecturaVuelos = clock();

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (fila != "") {

                columnas.str(fila);

                //formato de fila: flightNumber;dep_airport_code;arr_airport_code;plane;dep_weather_desc;dep_date

                getline(columnas, flightNumber, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, dep_airport_code, ';');
                getline(columnas, arr_airport_code, ';');
                getline(columnas, plane, ';');
                getline(columnas, dep_weather_desc, ';');
                getline(columnas, dep_date, ';');

                string anio=dep_date.substr(6,2);
                string mes=dep_date.substr(3,2);
                string dia=dep_date.substr(0,2);
                int anioint= stoi(anio);
                int mesint= stoi(mes);
                int diaint= stoi(dia);
                Fecha fecha(diaint,mesint,anioint);
                if(registrarVuelo(flightNumber,dep_airport_code,arr_airport_code,plane,dep_weather_desc,fecha)==true)
                    vuelos++;

                fila = "";
                columnas.clear();
            }
        }

        is.close();
        std::cout << "Tiempo lectura de los vuelos: " << ((clock() - lecturaVuelos) / (float) CLOCKS_PER_SEC)
                  << " segs." << std::endl;
        cout<<"Hay un total de: "<<vuelos<<" vuelos"<<endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}

bool VuelaFlight::registrarVuelo(std::string &fNumber, std::string &iataAeroOrig, std::string &iataAeroDest,
                                 std::string &plane, std::string &datosMeteo, Fecha f) {

    std::map<string,Aerolinea>::iterator aerolineaEncontrada = airlines.find(fNumber.substr(0,3));

    std::vector<Aeropuerto>::iterator orig;
    Aeropuerto origen;
    origen.setIata(iataAeroOrig);
    orig= std::lower_bound(aeropuertos.begin(), aeropuertos.end(),origen);
    std::vector<Aeropuerto>::iterator dest;
    Aeropuerto destino;
    destino.setIata(iataAeroDest);
    dest= std::lower_bound(aeropuertos.begin(), aeropuertos.end(),destino);

    if (aerolineaEncontrada!=airlines.end() && dest!=aeropuertos.end() && orig!=aeropuertos.end()){
        //cout<<"Se ha metido "<<endl;
        Vuelo* vuelo= new Vuelo(fNumber, plane, datosMeteo, f, &(*orig), &(*dest), &(aerolineaEncontrada->second));
        aerolineaEncontrada->second.addVuelo(*vuelo);

        return true;
    }else {
        return false;
    }
}

vector<Vuelo*> VuelaFlight::buscaVuelos(std::string fnumber) {
    map<string,Aerolinea>::iterator iterador=airlines.begin();
    vector<Vuelo*> vuelos;
    for (iterador; iterador!=airlines.end() ; iterador++) {
        vector<Vuelo*>aux =iterador->second.getVuelos(fnumber);
        vuelos.insert(vuelos.end(),aux.begin(),aux.end());
    }

    return vuelos;
}

vector<Vuelo *> VuelaFlight::vuelosOperadorPor(std::string icaoAerolinea, Fecha fecha) {
    map<string,Aerolinea>::iterator iterador;
    iterador=airlines.find(icaoAerolinea);
    iterador->second.getVuelos(fecha,fecha);
}

set<string> VuelaFlight::buscaVuelosDestAerop(std::string paisOrig, std::string iataAeroDest) {
    std::map<string,Aerolinea>::iterator iterador;
    set<string> identificadores;
    for(iterador=airlines.begin();iterador!=airlines.end();iterador++){
        if (iterador->second.getPais()==paisOrig){
            std::multimap<string,Vuelo*> vuelos=iterador->second.getFlights();
            std::multimap<string,Vuelo*>::iterator iteradorvuelos;
            for (iteradorvuelos=vuelos.begin();iteradorvuelos!=vuelos.end();iteradorvuelos++) {
                if (iteradorvuelos->second->getAirpDestin()->getIata()==iataAeroDest)
                    identificadores.insert(iteradorvuelos->second->getFlightNumb());
            }
        }
    }

    return identificadores;
}

void VuelaFlight::cargarAeropuertos(std::string fichAeropuertos) {
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


    is.open(fichAeropuertos); //carpeta de proyecto
    if (is.good()) {

        clock_t lecturaAeropuertos = clock();

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


                UTM utm(latitud, longitud);
                Aeropuerto aeropuerto(id,iata,tipo,nombre,continente,iso_pais,utm);
                this->aeropuertos.push_back(aeropuerto);


                fila = "";
                columnas.clear();
            }
        }

        is.close();

        std::cout << "Tiempo lectura de los aeropuertos: " << ((clock() - lecturaAeropuertos) / (float) CLOCKS_PER_SEC)
                  << " segs." << std::endl;
        std::sort(aeropuertos.begin(), aeropuertos.end());

    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}

void VuelaFlight::cargarRutas(std::string fichRutas) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int contador = 0;

    std::string aerolinea;
    std::string aero_origen;
    std::string aero_destino;
    std::sort(aeropuertos.begin(), aeropuertos.end());

    is.open(fichRutas); //carpeta de proyecto
    if (is.good()) {

        clock_t lecturaRutas = clock();

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (fila != "") {

                columnas.str(fila);

                //formato de fila: airline;airport_orig;airport_dest

                getline(columnas, aerolinea, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, aero_origen, ';');
                getline(columnas, aero_destino, ';');

                fila = "";
                columnas.clear();

                registrarRutas(aerolinea,aero_origen,aero_destino);
            }
        }

        is.close();

        std::cout << "Tiempo lectura de las rutas: " << ((clock() - lecturaRutas) / (float) CLOCKS_PER_SEC)
                  << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}

void VuelaFlight::cargarAerolineas(std::string fichAerolineas) {
    clock_t lecturaAerolineas = clock();
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int contador = 0;

    std::string ID;
    std::string ICAO;
    std::string Name;
    std::string Country;
    std::string Active;

    is.open(fichAerolineas); //carpeta de proyecto
    if (is.good()) {

        clock_t lecturaRutas = clock();

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (fila != "") {

                columnas.str(fila);

                //formato de fila: ID;ICAO;Name;Country;Active

                getline(columnas, ID, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, ICAO, ';');
                getline(columnas, Name, ';');
                getline(columnas, Country, ';');
                getline(columnas, Active, ';');

                unsigned int IDint = std::stoi(ID);
                bool Activebool;
                if (Active == "Y")
                    Activebool = true;
                else
                    Activebool = false;

                fila = "";
                columnas.clear();
                pair<string,Aerolinea> par(ICAO,Aerolinea(IDint, ICAO, Name, Country, Activebool));
                airlines.insert(par);
            }

        }

        is.close();

        std::cout << "Tiempo lectura de las aerolineas: " << ((clock() - lecturaAerolineas) / (float) CLOCKS_PER_SEC)
                  << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}