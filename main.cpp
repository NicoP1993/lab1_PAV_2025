#include <iostream>
#include "Genero.h"
#include "DtConsulta.h"
#include "Gato.h"
#include "Mascota.h"
#include "Perro.h"
#include "RazaPerro.h"
#include "TipoPelo.h"
#include "DtFecha.h"
#include "DtMascota.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "Consulta.h"
#include "Socio.h"

using namespace std;

#define MAX_SOCIOS 100

Socio* socios[MAX_SOCIOS]; //Puntero de tipo Socio que contiene socios, tiene un maximo
int cantidadSocios = 0; //Posicion del tope, es 0 al iniciar

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota) {
    if (cantidadSocios < MAX_SOCIOS) {
        Socio* nuevoSocio = new Socio(ci, nombre, fechaIngreso);
        nuevoSocio->agregarMascota(dtMascota);
        socios[cantidadSocios++] = nuevoSocio;
        cout << "Socio registrado correctamente.\n";
    } else {
        cout << "No se pueden registrar más socios.\n";
    }
}

void agregarMascota(string ci, DtMascota* dtMascota) {
    for (int i = 0; i < cantidadSocios; i++) {
        if (socios[i]->getCi() == ci) {
            socios[i]->agregarMascota(dtMascota);
            cout << "Mascota agregada correctamente.\n";
            return;
        }
    }
    cout << "Error: No se encontró un socio con esa cédula.\n";
}

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    for (int i = 0; i < cantidadSocios; i++) {
        if (socios[i]->getCi() == ci) {
            socios[i]->agregarConsulta(new Consulta(motivo, fechaConsulta));
            cout << "Consulta registrada correctamente.\n";
            return;
        }
    }
    cout << "Error: No se encontró un socio con esa cédula.\n";
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) {
    for (int i = 0; i < cantidadSocios; i++) {
        if (socios[i]->getCi() == ciSocio) {
            return socios[i]->getConsultasAntesDeFecha(fecha, cantConsultas);
        }
    }
    cout << "Error: No se encontró un socio con esa cédula.\n";
    cantConsultas = 0;
    return nullptr;
}

void eliminarSocio(string ci) {
    for (int i = 0; i < cantidadSocios; i++) {
        if (socios[i]->getCi() == ci) {
            delete socios[i];
            socios[i] = socios[cantidadSocios - 1];
            cantidadSocios--;
            cout << "Socio eliminado correctamente.\n";
            return;
        }
    }
    cout << "Error: No se encontró un socio con esa cédula.\n";
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    for (int i = 0; i < cantidadSocios; i++) {
        if (socios[i]->getCi() == ci) {
            return socios[i]->getMascotas(cantMascotas);
        }
    }
    cout << "Error: No se encontró un socio con esa cédula.\n";
    cantMascotas = 0;
    return nullptr;
}

int main() {
    int opcion;
    do {
        
        cout << "Bienvenido! \nElija la opción:\n";
        cout << "1) Registrar socio\n";
        cout << "2) Agregar mascota\n";
        cout << "3) Ingresar consulta\n";
        cout << "4) Ver consultas antes de fecha\n";
        cout << "5) Obtener mascotas de un socio\n";
        cout << "6) Eliminar socio\n";
        cout << "0) Salir\n";
        cout << "Opción: " ;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string ci, nombre;
                int dia, mes, anio, tipoMascota;
                cout << "Ingrese CI: "; cin >> ci;
                cout << "Ingrese nombre: "; cin >> nombre;
                cout << "Ingrese fecha de ingreso (dd mm aaaa): "; cin >> dia >> mes >> anio;
                DtFecha fechaIngreso(dia, mes, anio);
                
                cout << "Ingrese tipo de mascota (1. Perro, 2. Gato): ";
                cin >> tipoMascota;
                string nombreMascota;
                int genero;
                float peso;
                cout << "Ingrese nombre de la mascota: "; cin >> nombreMascota;
                cout << "Ingrese género (0. Macho, 1. Hembra): "; cin >> genero;
                cout << "Ingrese peso: "; cin >> peso;
                
                DtMascota* nuevaMascota;
                if (tipoMascota == 1) {
                    string raza;
                    bool vacuna;
                    cout << "Ingrese raza: "; cin >> raza;
                    cout << "Tiene vacuna de cachorro? (1. Sí, 0. No): "; cin >> vacuna;
                    nuevaMascota = new DtPerro(nombreMascota, (Genero)genero, peso, raza, vacuna);
                } else {
                    int tipoPelo;
                    cout << "Ingrese tipo de pelo (0. Corto, 1. Mediano, 2. Largo): "; cin >> tipoPelo;
                    nuevaMascota = new DtGato(nombreMascota, (Genero)genero, peso, (TipoPelo)tipoPelo);
                }
                
                registrarSocio(ci, nombre, fechaIngreso, nuevaMascota);
                break;
            }
            case 2: {
                string ci;
                int tipoMascota;
                cout << "Ingrese CI del socio: "; cin >> ci;
                cout << "Ingrese tipo de mascota (1. Perro, 2. Gato): ";
                cin >> tipoMascota;
                string nombreMascota;
                int genero;
                float peso;
                cout << "Ingrese nombre de la mascota: "; cin >> nombreMascota;
                cout << "Ingrese género (0. Macho, 1. Hembra): "; cin >> genero;
                cout << "Ingrese peso: "; cin >> peso;
                
                DtMascota* nuevaMascota;
                if (tipoMascota == 1) {
                    string raza;
                    bool vacuna;
                    cout << "Ingrese raza: "; cin >> raza;
                    cout << "Tiene vacuna de cachorro? (1. Sí, 0. No): "; cin >> vacuna;
                    nuevaMascota = new DtPerro(nombreMascota, (Genero)genero, peso, raza, vacuna);
                } else {
                    int tipoPelo;
                    cout << "Ingrese tipo de pelo (0. Corto, 1. Mediano, 2. Largo): "; cin >> tipoPelo;
                    nuevaMascota = new DtGato(nombreMascota, (Genero)genero, peso, (TipoPelo)tipoPelo);
                }
                
                agregarMascota(ci, nuevaMascota);
                break;
            }
            case 3: {
                string ci, motivo;
                int dia, mes, anio;
                cout << "Ingrese CI del socio: "; cin >> ci;
                cout << "Ingrese motivo de la consulta: "; cin >> motivo;
                cout << "Ingrese fecha de la consulta (dd mm aaaa): "; cin >> dia >> mes >> anio;
                ingresarConsulta(motivo, ci, DtFecha(dia, mes, anio));
                break;
            }
            case 4: {
                string ci;
                int dia, mes, anio, cantConsultas;
                cout << "Ingrese CI del socio: "; cin >> ci;
                cout << "Ingrese fecha límite (dd mm aaaa): "; cin >> dia >> mes >> anio;
                DtConsulta** consultas = verConsultasAntesDeFecha(new DtFecha(dia, mes, anio), ci, cantConsultas);
                for (int i = 0; i < cantConsultas; i++) {
                    consultas[i]->imprimir();
                }
                break;
            }
            case 5: {
                string ci;
                cout << "Ingrese CI del socio a eliminar: "; cin >> ci;
                eliminarSocio(ci);
                break;
            }
            case 6: {
                string ci;
                int cantMascotas;
                cout << "Ingrese CI del socio: "; cin >> ci;
                DtMascota** mascotas = obtenerMascotas(ci, cantMascotas);
                for (int i = 0; i < cantMascotas; i++) {
                    mascotas[i]->imprimir();
                }
                break;
            }
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
    return 0;
}
