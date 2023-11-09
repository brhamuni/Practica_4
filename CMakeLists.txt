cmake_minimum_required(VERSION 3.26)
project(PR4)

set(CMAKE_CXX_STANDARD 17)

add_executable(PR4 main.cpp
        Aerolinea.cpp
        Aerolinea.h
        Aeropuerto.cpp
        Aeropuerto.h
        fecha.cpp
        fecha.h
        Ruta.h
        Ruta.cpp
        UTM.cpp
        UTM.h
        VuelaFlight.h
        VuelaFlight.cpp
        Aerolinea.cpp
        VuelaFlight.cpp)
