#ifndef RESERVA_H
#define RESERVA_H
#include <unordered_map>
#include <string>
#include "zona.h"

class Reserva {
private:
    std::unordered_map<std::string, Zona*> zonas;

public:
    Reserva();
    ~Reserva();
    void agregarZona(std::string codigo, Zona* zona);
    Zona* buscarZona(std::string codigo);
    void mostrarZonas();
    void mostrarElementosZona(Zona* zona);
    void contarElementos(Zona* zona);
    void mostrarEstadoZona(Zona* zona);
};

#endif
