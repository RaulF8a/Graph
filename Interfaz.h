#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <stdlib.h>
#include "Grafo.h"
#include "Perro.h"

using namespace std;

class Interfaz{
    public:
        Interfaz ();

        bool insertarVertice (const Perro& valor);
        bool insertarArista (const Perro& origen, const Perro& destino, int peso);
        bool eliminarVertice (const Perro& valor);
        bool eliminarArista (const Perro& origen, const Perro& destino);
        void buscarVertice (const Perro& valor);
        void mostrarVertices ();
        void mostrarVerticesConAristas ();
        void respaldarArchivo ();
        void cargarArchivo ();

    private:
        Grafo<Perro> grafo;
};

#endif