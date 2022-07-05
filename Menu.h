#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include "Interfaz.h"

using namespace std;

enum opciones {
    OPC_SALIR,
    OPC_INSERTARV,
    OPC_INSERTARA,
    OPC_ELIMINARV,
    OPC_ELIMINARA,
    OPC_BUSCAR,
    OPC_MOSTRARV,
    OPC_MOSTRARVA,
    OPC_RESPALDAR,
    OPC_RECUPERAR
};

void menu (Interfaz &perros){
    int opcionMenu;
    Perro auxPerro, auxPerro2;
    string nombre;
    bool bandera = false;
    int peso;

    do{
        system ("cls");
        cout << "\t\t Veterinaria\n" << endl;

        cout << OPC_INSERTARV << ". Insertar Perro." << endl;
        cout << OPC_INSERTARA << ". Crear Arista entre Perros." << endl;
        cout << OPC_ELIMINARV << ". Eliminar Perro." << endl;
        cout << OPC_ELIMINARA << ". Descartar Arista entre Perros." << endl;
        cout << OPC_BUSCAR << ". Buscar Perro." << endl;
        cout << OPC_MOSTRARV << ". Mostrar Perros." << endl;
        cout << OPC_MOSTRARVA << ". Mostrar Perros y sus Aristas." << endl;
        cout << OPC_RESPALDAR << ". Respaldar Perros en Archivo." << endl;
        cout << OPC_RECUPERAR << ". Recuperar Perros de Archivo." << endl;
        cout << OPC_SALIR << ". Salir" << endl;

        cout << "\nOpcion: ";
        fflush (stdin);
        cin >> opcionMenu;

        switch (opcionMenu){
            case OPC_INSERTARV:
                system ("cls");
                cout << "\t\t Insertar Perro\n" << endl;

                cin >> auxPerro;

                perros.insertarVertice (auxPerro);

                cout << "\nPerro insertado con exito." << endl;

                system ("pause");
                break;
            case OPC_INSERTARA:
                system ("cls");
                cout << "\t\t Insertar Arista entre Perros\n" << endl;

                cout << "Digita el nombre del primer perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro.setNombre (nombre);

                cout << "\nDigita el nombre del segundo perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro2.setNombre (nombre);

                cout << "\nDigita el peso de la arista: ";
                cin >> peso;

                bandera = perros.insertarArista (auxPerro, auxPerro2, peso);

                if (bandera){
                    cout << "\nArista creada con exito." << endl;
                }
                else{
                    cout << "\nNo se pudo crear la arista." << endl;
                }

                system ("pause");
                break;
            case OPC_ELIMINARV:
                system ("cls");
                cout << "\t\t Eliminar Perro\n" << endl;

                cout << "Digita el nombre del perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro.setNombre (nombre);

                bandera = perros.eliminarVertice (auxPerro);

                if (bandera){
                    cout << "\nPerro eliminado con exito." << endl;
                }
                else{
                    cout << "\nNo se pudo eliminar el perro." << endl;
                }

                system ("pause");
                break;
            case OPC_ELIMINARA:
                system ("cls");
                cout << "\t\t Eliminar Arista entre Perros\n" << endl;

                cout << "Digita el nombre del primer perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro.setNombre (nombre);

                cout << "\nDigita el nombre del segundo perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro2.setNombre (nombre);

                bandera = perros.eliminarArista (auxPerro, auxPerro2);

                if (bandera){
                    cout << "\nArista eliminada con exito." << endl;
                }
                else{
                    cout << "\nNo se pudo eliminar la arista." << endl;
                }

                system ("pause");
                break;
            case OPC_BUSCAR:
                system ("cls");
                cout << "\t\t Buscar Perro\n" << endl;

                cout << "Digita el nombre del perro: ";
                fflush (stdin);
                getline (cin, nombre, '\n');
                auxPerro.setNombre (nombre);

                cout << "\n";
                perros.buscarVertice (auxPerro);

                system ("pause");
                break;
            case OPC_MOSTRARV:
                system ("cls");
                cout << "\t\t Mostrar Perros\n" << endl;

                perros.mostrarVertices ();

                cout << "\n" << endl;
                system ("pause");
                break;
            case OPC_MOSTRARVA:
                system ("cls");
                cout << "\t\t Mostrar Perros y sus Aristas\n" << endl;

                perros.mostrarVerticesConAristas ();

                cout << "\n";
                system ("pause");
                break;
            case OPC_RESPALDAR:
                system ("cls");
                cout << "\t\t Respaldar Perros en Archivo\n" << endl;

                perros.respaldarArchivo ();

                cout << "Perros cargados al archivo con exito.\n" << endl;

                system ("pause");
                break;
            case OPC_RECUPERAR:
                system ("cls");
                cout << "\t\t Recuperar Perros de Archivo\n" << endl;

                perros.cargarArchivo ();

                cout << "Perros recuperados del archivo con exito.\n" << endl;

                system ("pause");
                break;
            case OPC_SALIR:
                system ("cls");
                break;
            default:
                cout << "Opcion no valida." << endl;
                system ("pause");
        }
        
    }while (opcionMenu != OPC_SALIR);
}

#endif