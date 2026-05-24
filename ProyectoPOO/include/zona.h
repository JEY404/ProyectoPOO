#ifndef ZONA_H
#define ZONA_H
#include <vector>
#include <string>
#include "elementointeractivo.h"

class Explorador;
class Zona {
protected:
    std::string codigo;
    std::string nombre;
    std::vector<ElementoInteractivo*> elementos;

public:
    Zona(std::string codigo, std::string nombre);
    virtual ~Zona();
    void agregarElemento(ElementoInteractivo* elemento);
    void mostrarElementos();
    void interactuarConElemento(int indice, Explorador* explorador);
    void interactuarConElemento(std::string nombre, Explorador* explorador);
    std::string getNombre();

};

#endif
