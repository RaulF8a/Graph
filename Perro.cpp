#include "Perro.h"

Perro::Perro (){

}

Perro::Perro (const string& nombre, int edad, const string& raza){
    this->nombre = nombre;
    this->edad = edad;
    this->raza = raza;
}

string Perro::getNombre () const{
    return nombre;
}

void Perro::setNombre (const string& valor){
    nombre = valor;
}

int Perro::getEdad () const{
    return edad;
}

void Perro::setEdad (int valor){
    edad = valor;
}

string Perro::getRaza () const{
    return raza;
}

void Perro::setRaza (const string& valor){
    raza = valor;
}