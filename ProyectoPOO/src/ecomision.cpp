#include "../include/ecomision.h"
#include "../include/Zonas/bosquehumedo.h"
#include "../include/Zonas/riocontaminado.h"
#include "../include/Zonas/senderomontanoso.h"
#include "../include/Zonas/centrorecoanimal.h"
#include "../include/Zonas/labambiental.h"
#include "../include/Zonas/vivero.h"
#include "../include/ElementosInteractivos/animalherido.h"
#include "../include/ElementosInteractivos/plantamedicinal.h"
#include "../include/ElementosInteractivos/residuocontaminante.h"
#include "../include/ElementosInteractivos/estacionenergia.h"
#include "../include/ElementosInteractivos/portaltp.h"
#include <iostream>

EcoMision::EcoMision(){
}

EcoMision::~EcoMision(){
    for(Explorador* explorador:exploradores){
        delete explorador;
    }
}

void EcoMision::crearExplorador(std::string nombre){
    Explorador* nuevo=new Explorador(nombre);
    exploradores.push_back(nuevo);
}

void EcoMision::eliminarExplorador(){
    if(exploradores.size()>0){
        delete exploradores.back();
        exploradores.pop_back();
    }
}

void EcoMision::buscarExplorador(){
    for(Explorador* explorador:exploradores){
        explorador->mostrarEstado();
    }
}

void EcoMision::crearReserva(){
    Zona* bosque=new BosqueHumedo("bosque","Bosque Humedo");
    Zona* rio=new RioContaminado("rio","Rio Contaminado");
    Zona* sendero=new SenderoMontanoso("sendero","Sendero Montañoso");
    Zona* centro=new CentroRecoAnimal("centro","Centro Recuperacion Animal");
    Zona* lab=new LabAmbiental("lab","Laboratorio Ambiental");
    Zona* vivero=new Vivero("vivero","Vivero Natural");

    bosque->agregarElemento(new AnimalHerido("Venado"));
    bosque->agregarElemento(new PlantaMedicinal("Aloe",20));
    rio->agregarElemento(new ResiduoContaminante("Desecho Quimico",15));
    rio->agregarElemento(new EstacionEnergia("Panel Solar",25));
    sendero->agregarElemento(new AnimalHerido("Lobo"));
    centro->agregarElemento(new PlantaMedicinal("Lavanda",15));
    lab->agregarElemento(new ResiduoContaminante("Mercurio",20));
    vivero->agregarElemento(new EstacionEnergia("Bateria Verde",30));
    bosque->agregarElemento(new Portaltp("Portal Rio",rio));
    rio->agregarElemento(new Portaltp("Portal Sendero",sendero));

    reserva.agregarZona("bosque",bosque);
    reserva.agregarZona("rio",rio);
    reserva.agregarZona("sendero",sendero);
    reserva.agregarZona("centro",centro);
    reserva.agregarZona("lab",lab);
    reserva.agregarZona("vivero",vivero);
}

void EcoMision::iniciarSistema(){
    crearReserva();
    crearExplorador("Carlos");
    crearExplorador("Laura");
    Zona* zonaInicial=reserva.buscarZona("bosque");
    exploradores[0]->cambiarZona(zonaInicial);
    exploradores[1]->cambiarZona(zonaInicial);
    std::cout<<"Sistema iniciado"<<'\n';
}

void EcoMision::asignarZonaInicial(){
    Zona* zonaInicial=reserva.buscarZona("bosque");
    for(Explorador* explorador:exploradores){
        explorador->cambiarZona(zonaInicial);
    }
}

void EcoMision::mostrarInformacion(){
    std::cout<<"======== ZONAS ========"<<'\n';
    reserva.mostrarZonas();
}

void EcoMision::pruebaSistema(){
    mostrarInformacion();
    Explorador* explorador=exploradores[0];
    Zona* zona=explorador->getZonaActual();
    std::cout<<"         Elementos"<<'\n';
    zona->mostrarElementos();
    std::cout<<"         Interacciones"<<'\n';
    zona->interactuarConElemento(0,explorador);
    zona->interactuarConElemento(1,explorador);
    explorador->mostrarEstado();
    std::cout<<"         Cambio de Zona"<<'\n';
    zona->interactuarConElemento(2,explorador);
    explorador->mostrarEstado();

}


Explorador* EcoMision::getExplorador(int idx) {
    return exploradores[idx];
}

int EcoMision::cantidadExploradores() {
    return exploradores.size();
}

int EcoMision::seleccionarExplorador() {
    std::cout << "\n   Seleccione su Exploradorr:   \n";

    int totalExploradores = exploradores.size();
    if (totalExploradores == 0) {
        std::cout << "No hay exploradores aún registrados :(\n";
        return -1;
    }

    for (int i = 0; i < totalExploradores; i++) {
        std::cout << (i + 1) << ". " << exploradores[i]->getNombre() << "\n";
    }

    int seleccionUsuario = -1;
        while (seleccionUsuario < 1 || seleccionUsuario > totalExploradores) {
        std::cout << "Ingrese el numero del explorador (1 a " << totalExploradores << "): ";
        std::cin >> seleccionUsuario;

        if (std::cin.fail() || seleccionUsuario < 1 || seleccionUsuario > totalExploradores) {
            std::cin.clear();
            std::string descarte;
            std::cin >> descarte;
            std::cout << "Selección invalida\n";
            seleccionUsuario = -1;
        }
    }
    return seleccionUsuario - 1;
}
