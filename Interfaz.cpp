#include "Interfaz.h"

Interfaz::Interfaz (){

}

bool Interfaz::insertarVertice (const Perro& valor){
    return grafo.insertarVertice (valor);
}

bool Interfaz::insertarArista (const Perro& origen, const Perro& destino, int peso){
    return grafo.crearArista (origen, destino, peso);
}

bool Interfaz::eliminarVertice (const Perro& valor){
    return grafo.eliminarVertice (valor);
}

bool Interfaz::eliminarArista (const Perro& origen, const Perro& destino){
    return eliminarArista (origen, destino);
}

void Interfaz::buscarVertice (const Perro& valor){
    Vertice<Perro>* aux = grafo.buscarVertice (valor);

    if (aux != nullptr){
        cout << "Se encontro en la direccion: " << aux << endl;
    }
    else{
        cout << "No se encontro." << endl;
    }
}

void Interfaz::mostrarVertices (){
    grafo.imprimir ();
}

void Interfaz::mostrarVerticesConAristas (){
    grafo.imprimirAristas ();
}

void Interfaz::respaldarArchivo (){
    ofstream archivo ("file01.txt", ios::out);

    if (archivo.is_open ()){
        grafo.respaldar (archivo);
    }
    else{
        throw runtime_error ("El archivo no pudo ser abierto.");
    }

    archivo.close ();
}

void Interfaz::cargarArchivo (){
    ifstream archivo ("file01.txt", ios::in);
    string auxString;
    Perro auxPerro;

    if (archivo.is_open()){
        while (true){
            getline (archivo, auxString, '|');

            if (auxString.size () > 0){
                auxPerro.setNombre (auxString);

                getline (archivo, auxString, '|');
                auxPerro.setEdad (stoi (auxString));

                getline (archivo, auxString, '*');
                auxPerro.setRaza (auxString);

                insertarVertice (auxPerro);
            }
            else{
                break;
            }
        }
    }
    else{
        throw runtime_error ("El archivo no pudo ser abierto.");
    }

    archivo.close ();
}

