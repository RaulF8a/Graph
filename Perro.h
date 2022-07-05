#ifndef PERRO_H
#define PERRO_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Perro {
    public:
        Perro ();
        Perro (const string& nombre, int edad, const string& raza);

        string getNombre () const;
        void setNombre (const string& valor);
        int getEdad () const;
        void setEdad (int valor);
        string getRaza () const;
        void setRaza (const string& valor);

        friend ostream& operator << (ostream& os, const Perro &p){
            os << p.nombre << "|" << p.edad << "|" << p.raza << "*";

            return os;
        }

        friend istream& operator >> (istream& is, Perro &p){
            cout << "Digita el nombre del perro: ";
            fflush (stdin);
            getline (cin, p.nombre);

            cout << "Digita su edad: ";
            cin >> p.edad;

            cout << "Digita su raza: ";
            fflush (stdin);
            getline (cin, p.raza);

            return is;
        }

        bool operator == (const Perro &p){
            return p.nombre == nombre;
        }

        bool operator == (const Perro &p) const{
            return p.nombre == nombre;
        }

        bool operator < (const Perro &p){
            return nombre < p.nombre;
        }

        bool operator < (const Perro &p) const{
            return nombre < p.nombre;
        }

        bool operator > (const Perro &p){
            return nombre > p.nombre;
        }

        bool operator > (const Perro &p) const{
            return nombre > p.nombre;
        }
    
    private:
        string nombre;
        int edad;
        string raza;
};

#endif