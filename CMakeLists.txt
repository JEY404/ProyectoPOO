cmake_minimum_required(VERSION 3.20)
project(EcoMisionProyecto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Rutas completas desde la carpeta raíz externa
include_directories(
        ProyectoPOO/include
        ProyectoPOO/include/ElementosInteractivos
        ProyectoPOO/include/Zonas
        ProyectoPOO/src
        ProyectoPOO/src/ElementosInteractivos
        ProyectoPOO/src/Zonas
)

add_executable(EcoMisionProyecto
        ProyectoPOO/main.cpp

        ProyectoPOO/src/ecomision.cpp
        ProyectoPOO/src/elementointeractivo.cpp
        ProyectoPOO/src/explorador.cpp
        ProyectoPOO/src/reserva.cpp
        ProyectoPOO/src/zona.cpp

        ProyectoPOO/src/ElementosInteractivos/animalherido.cpp
        ProyectoPOO/src/ElementosInteractivos/estacionenergia.cpp
        ProyectoPOO/src/ElementosInteractivos/plantamedicinal.cpp
        ProyectoPOO/src/ElementosInteractivos/portaltp.cpp
        ProyectoPOO/src/ElementosInteractivos/residuocontaminante.cpp

        ProyectoPOO/src/Zonas/bosquehumedo.cpp
        ProyectoPOO/src/Zonas/centrorecoanimal.cpp
        ProyectoPOO/src/Zonas/labambiental.cpp
        ProyectoPOO/src/Zonas/riocontaminado.cpp
        ProyectoPOO/src/Zonas/senderomontanoso.cpp
        ProyectoPOO/src/Zonas/vivero.cpp
)