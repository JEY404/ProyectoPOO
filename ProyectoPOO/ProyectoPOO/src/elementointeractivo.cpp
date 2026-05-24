#include "../include/elementointeractivo.h"

ElementoInteractivo::ElementoInteractivo(std::string nombre) {
    this->nombre = nombre;
    activo = true;
}

ElementoInteractivo::~ElementoInteractivo() {
}

std::string ElementoInteractivo::getNombre() {
    return nombre;
}
