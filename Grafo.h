#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <fstream>

using namespace std;

template <typename T>
struct Arista;
template <typename T>
struct Vertice;

template <typename T>
struct Vertice{
    T dato;
    //Apuntador al siguiente vertice.
    Vertice *siguienteVertice;
    //Inicio de la secuencia de aristas adyacentes.
    Arista<T> *hArista;

    Vertice (){
        siguienteVertice = nullptr;
        hArista = nullptr;
    }

    Vertice (const T& valor){
        dato = valor;
        siguienteVertice = nullptr;
        hArista = nullptr;
    }
};

template <typename T>
struct Arista{
    int costo;
    Vertice<T> *destino;
    Arista *siguienteArista;

    Arista (){
        costo = 0;
        destino = nullptr;
        siguienteArista = nullptr;
    }

    Arista (Vertice<T> *destino, int costo){
        this->costo = costo;
        this->destino = destino;
        siguienteArista = nullptr;
    }
};

template <typename T>
class Grafo {
    public:
        Grafo (){
            origen = nullptr;
        }

        bool insertarVertice (const T& elemento);
        bool crearArista (const T& origen, const T& destino, int costo);
        bool eliminarVertice (const T& elemento);
        bool eliminarArista (const T& origen, const T& destino);
        Vertice<T>* buscarVertice (const T& elemento);
        void imprimir ();
        void imprimirAristas ();
        void respaldar (ofstream &archivo);

    private:
        bool isEmpty ();
        Vertice<T>* crearNuevoVertice (const T& elemento);
        Arista<T>* crearNuevaArista (Vertice<T>* destino, int costo);
        void eliminarVerticeDeOtrasAristas (Vertice<T>* vertice);
        Vertice<T>* origen;
};

template <typename T>
bool Grafo<T>::isEmpty (){
    return origen == nullptr;
}

template <typename T>
Vertice<T>* Grafo<T>::crearNuevoVertice (const T& elemento){
    Vertice<T> *nuevo = new Vertice<T> (elemento);

    return nuevo;
}

template <typename T>
bool Grafo<T>::insertarVertice (const T& elemento){
    Vertice<T> *actual, *anterior;

    //Para cuando no tenemos ningun vertice en el grafo.
    if (isEmpty ()){
        origen = crearNuevoVertice (elemento);

        return true;
    }
    //Caso contrario, ya existen vertices en el grafo, por lo que hay que recorrerlo hasta encontrar el final.
    else{
        actual = origen;

        while (actual != nullptr){
            anterior = actual;
            actual = actual->siguienteVertice;
        }

        anterior->siguienteVertice = crearNuevoVertice (elemento);

        return true;
    }

    return false;
}

template <typename T>
Arista<T>* Grafo<T>::crearNuevaArista (Vertice<T>* destino, int costo){
    Arista<T>* nuevo = new Arista<T> (destino, costo);

    return nuevo;
}

template <typename T>
bool Grafo<T>::crearArista (const T& origen, const T& destino, int costo){
    Vertice<T> *auxOrigen, *auxDestino;

    //Recorremos el grafo para encontrar el vertice.
    auxOrigen = buscarVertice (origen);
    auxDestino = buscarVertice (destino);

    //Si alguno o ambos de los vertices no existen, lanzamos un error en tiempo de ejecucion.
    if (auxOrigen == nullptr || auxDestino == nullptr){
        return false;
    }
    else{
        Arista<T>* auxArista = auxOrigen->hArista;

        if (auxArista == nullptr){
            auxOrigen->hArista = crearNuevaArista (auxDestino, costo);

            return true;
        }
        else{
            //Empezamos a recorrer la lista de aristas, hasta encontrar un lugar disponible.
            while (auxArista->siguienteArista != nullptr){
                auxArista = auxArista->siguienteArista;
            }

            auxArista->siguienteArista = crearNuevaArista (auxDestino, costo);

            return true;
        }
        
        return false;
    }
}

template <typename T>
bool Grafo<T>::eliminarVertice (const T& elemento){
    Vertice<T> *actual, *anterior;

    if (isEmpty ()){
        throw runtime_error ("Intentando eliminar vertice en un grafo vacio.");
    }
    
    //Si el dato se encuentra en el origen.
    if (origen->dato == elemento){
        actual = origen;
        origen = origen->siguienteVertice;

        eliminarVerticeDeOtrasAristas (actual);
        delete (actual);

        return true;
    }
    else{
        actual = origen;
        anterior = nullptr;

        while (actual != nullptr){
            if (actual->dato == elemento){
                anterior->siguienteVertice = actual->siguienteVertice;

                eliminarVerticeDeOtrasAristas (actual);
                
                delete (actual);

                return true;
            }
            else{
                anterior = actual;
                actual = actual->siguienteVertice;
            }
        }

        return false;
    }
}

template <typename T>
void Grafo<T>::eliminarVerticeDeOtrasAristas (Vertice<T>* vertice){
    Vertice<T>* actual = origen;
    Arista<T>* actualArista, *anteriorArista = nullptr;

    while (actual != nullptr){
        if (actual->hArista != nullptr){
            actualArista = actual->hArista;

            if (actualArista->destino == vertice){
                actual->hArista = actualArista->siguienteArista;
                delete (actualArista);
            }
            else{
                while (actualArista != nullptr){
                    if (actualArista->destino == vertice){
                        anteriorArista->siguienteArista = actualArista->siguienteArista;

                        delete (actualArista);

                        break;
                    }
                    else{
                        anteriorArista = actualArista;
                        actualArista = actualArista->siguienteArista;
                    }
                }
            }
        }
        
        actual = actual->siguienteVertice;
    }
}

template <typename T>
bool Grafo<T>::eliminarArista (const T& origen, const T& destino){
    Vertice<T> *auxOrigen, *auxDestino;
    Arista<T> *actualArista, *anteriorArista;

    auxOrigen = buscarVertice (origen);
    auxDestino = buscarVertice (destino);

    if (auxOrigen == nullptr || auxDestino == nullptr){
        return false;
    }
    else{
        actualArista = auxOrigen->hArista;

        if (actualArista == nullptr){
            return false;
        }
        else if (actualArista->destino == auxDestino){
            auxOrigen->hArista = actualArista->siguienteArista;
            delete (actualArista);
            
            return true;
        }
        else{
            while (actualArista != nullptr){
                if (actualArista->destino == auxDestino){
                    anteriorArista->siguienteArista = actualArista->siguienteArista;
                    delete (actualArista);

                    return true;
                }
                else{
                    anteriorArista = actualArista;
                    actualArista = actualArista->siguienteArista;
                }
            }
            
            return false;
        }
    }
}

template <typename T>
Vertice<T>* Grafo<T>::buscarVertice (const T& elemento){
    Vertice<T>* aux = origen;

    while (aux != nullptr){
        if (aux->dato == elemento){
            return aux;
        }
        else{
            aux = aux->siguienteVertice;
        }
    }

    return nullptr;
}

template <typename T>
void Grafo<T>::imprimir (){
    Vertice<T>* actual = origen;

    while (actual != nullptr){
        cout << actual->dato << " ";

        actual = actual->siguienteVertice;
    }
}

template <typename T>
void Grafo<T>::imprimirAristas (){
    Vertice<T>* auxVertice;
    Arista<T>* auxArista;

    auxVertice = origen;

    while (auxVertice != nullptr){
        cout << auxVertice->dato << ": ";
        
        auxArista = auxVertice->hArista;
        while (auxArista != nullptr){
            cout << auxArista->destino->dato << " ";
            
            auxArista = auxArista->siguienteArista;
        }

        auxVertice = auxVertice->siguienteVertice;
        cout << endl;
    }
}

template <typename T>
void Grafo<T>::respaldar (ofstream &archivo){
    Vertice<T>* actual = origen;

    while (actual != nullptr){
        archivo << actual->dato;

        actual = actual->siguienteVertice;
    }
}

#endif