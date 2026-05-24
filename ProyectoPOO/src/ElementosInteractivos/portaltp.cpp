#include "../../include/ElementosInteractivos/portaltp.h"
#include "../../include/explorador.h"
#include "../../include/zona.h"
#include <iostream>

Portaltp::Portaltp(std::string nombre,Zona* destino)
:ElementoInteractivo(nombre){
    this->destino=destino;
}

void Portaltp::interactuar(Explorador* explorador){
    explorador->cambiarZona(destino);
    std::cout<<"Zona cambiada"<<'\n';
}
