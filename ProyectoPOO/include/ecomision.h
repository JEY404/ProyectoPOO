#ifndef ECOMISION_H
#define ECOMISION_H
#include <vector>
#include "reserva.h"
#include "explorador.h"

class EcoMision{
private:
    Reserva reserva;
    std::vector<Explorador*> exploradores;
public:
    EcoMision();
    ~EcoMision();
    void crearExplorador(std::string nombre);
    void eliminarExplorador();
    void buscarExplorador();
    void iniciarSistema();
    void crearReserva();
    void asignarZonaInicial();
    void mostrarInformacion();
    void pruebaSistema();
    int seleccionarExplorador();
    int cantidadExploradores();
    Explorador* getExplorador(int idx);

};

#endif
