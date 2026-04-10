#ifndef HISTORIALNAVEGACION_H
#define HISTORIALNAVEGACION_H

#include <string>

#include "Pila.h"
#include "Visita.h"

class HistorialNavegacion {
private:
    Pila<Visita> pilaAtras;
    Pila<Visita> pilaAdelante;
    bool tieneSitioActual;
    Visita sitioActual;

    std::string obtenerFechaHoraActual() const;

public:
    HistorialNavegacion();

    void abrirSitio(const std::string& sitioVisitado, int idUsuario);
    void irAtras();
    void irAdelante();
    void cerrarSitioActual();
    void mostrarSitioActual() const;
    void responderPreguntasTeoricas() const;
};

#endif
