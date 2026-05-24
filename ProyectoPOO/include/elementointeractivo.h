#ifndef ELEMENTOINTERACTIVO_H
#define ELEMENTOINTERACTIVO_H

#include <string>

class Explorador;
class ElementoInteractivo {
protected:
    std::string nombre;
    bool activo;
public:
    ElementoInteractivo(std::string nombre);
    virtual ~ElementoInteractivo();
    virtual void interactuar(Explorador* explorador) = 0;
    std::string getNombre();
};

#endif
