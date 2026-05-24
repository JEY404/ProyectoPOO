#ifndef EXPLORADOR_H
#define EXPLORADOR_H
#include <string>

class Zona;
class Explorador {
private:
    std::string nombre;
    int energia;
    int puntajeAmbiental;
    Zona* zonaActual;

public:
    Explorador(std::string nombre);
    void cambiarZona(Zona* zona);
    void consumirEnergia(int cantidad);
    void recuperarEnergia(int cantidad);
    void agregarPuntos(int puntos);
    void mostrarEstado();
    Zona* getZonaActual();
};

#endif
