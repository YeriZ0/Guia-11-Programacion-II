#include <iostream>
#include <stdlib.h>

#define LIST 5

#include "TrabajadorTiempoCompleto.h"
#include "TrabajadorPorHora.h"

using namespace std;

//Fredy Alexander Campos Figueroa - Programacion II

char menu(){
    char op;

    cout << " ****** Menu de Empleados ****** \n" << endl;
    cout << "\t1. Agregar trabajador " << endl;
    cout << "\t2. Mostrar planila " << endl;
    cout << "\t3. Ver detalles del trabajador " << endl;
    cout << "\t4. Cerrar programa \n" << endl;
    cout << "Ingrese una opcion -> "; cin >> op;

    return op;
}

Trabajador *agregarTrabajador(){
    int tipo, cod, numHoTra;
    string nom, ape;
    float sueldo;

    Trabajador *tb;

    cout << "\nDigite el codigo para el trabajador: "; cin >> cod;
    cout << "Digite el nombre del trabajador: "; cin >> nom;
    cout << "Digite el apellido del trabajador: "; cin >> ape;
    cout << "\nDigite el tipo de trabajador: " << endl;
    cout << "\t 1. Por tiempo completo" << endl;
    cout << "\t 2. Por horas \n -> ";
    cin >> tipo;

    if (tipo == 1){
        cout << "\nDigite el sueldo mensual: "; cin >> sueldo;
        tb = new TrabajadorTiempoCompleto(cod, nom, ape, sueldo);
    }else{
        cout << "\nDigite el sueldo por hora: "; cin >> sueldo;
        cout << "Digite el numero de horas de trabajo (Mensuales): "; cin >> numHoTra;
        tb = new TrabajadorPorHora(cod, nom, ape, sueldo, numHoTra);
    }

    return tb;
}

void mostrarPlanilla(Trabajador *lst[], int cont){
    if(cont == 0){
        cout << "La planilla esta vacia" << endl;
    }else{
        cout << "\nCod\tNombre\tApellido\tTipo\tSueldo\tTotal Pagar\n";
        for (int i=0; i<cont; i++)
        {
            cout << lst[i]->getCodigo() << "\t";
            cout << lst[i]->getNombre() << "\t";
            cout << lst[i]->getApellido() << "\t";
            (lst[i]->getTipoTrabajador()==1) ? cout << "TC\t" : cout << "TH\t";
            cout << lst[i]->getSueldoMensual() << "\t";
            cout << lst[i]->getTotalPagar() << "\n";
        }
    }
}

Trabajador *buscarTrabajador(Trabajador *lst[], int cont, int cod){
    bool encontrado = false;
    int c = 0;
    Trabajador *tb = NULL;

    while(c < cont && !encontrado){
        if(lst[c] -> getCodigo() == cod){
            encontrado = true;
            tb = lst[c];
        }else{
            c++;
        }
    }

    return tb;
}

void verDetalles(Trabajador *tb){
    if(tb -> getTipoTrabajador() == 1){
        cout << "\nTrabajador Tiempo Completo" << endl;
        TrabajadorTiempoCompleto *tc = (TrabajadorTiempoCompleto*) tb;
        cout << "Codigo: " << tb -> getCodigo() << endl;
        cout << "Nombre: " << tb -> getNombre() << endl;
        cout << "Apellido: " << tb -> getApellido() << endl;
        cout << "Sueldo Mensual: " << tb -> getSueldoMensual() << endl;
        cout << "Descuento ISSS: " << tc -> getDescuentoIsss() << endl;
        cout << "Descuento AFP: " << tc -> getDescuentoAfp() << endl;
        cout << "Descuento ISR: " << tc -> getDescuentoIsr() << endl;
        cout << "Total a pagar: " << tc -> getTotalPagar() << endl;
    }else{
        cout << "\nTrabajador Por Hora" << endl;
        TrabajadorPorHora *th = (TrabajadorPorHora*) tb;
        cout << "Codigo: " << tb -> getCodigo() << endl;
        cout << "Nombre: " << tb -> getNombre() << endl;
        cout << "Apellido: " << tb -> getApellido() << endl;
        cout << "Sueldo Mensual: " << tb -> getSueldoMensual() << endl;
        cout << "Descuento ISR: " << th -> getDescuentoIsr() << endl;
        cout << "Total a pagar: " << th -> getTotalPagar() << endl;
    }
}

int main(){

    Trabajador *planilla[LIST];
    int contador = 0, id;
    char seleccion;

    Trabajador *tb = NULL;

    do{
        system("cls");
        seleccion = menu();
        switch(seleccion){
            case '1':
                if(contador < LIST){
                    planilla[contador] = agregarTrabajador();
                    contador++;
                    cout << "Trabajador agregado con exito. " << endl;
                }else{
                    cout << "La planilla esta llena." << endl;
                }
            break;
            case '2':
                mostrarPlanilla(planilla, contador);
                break;
            case '3':
                cout << "Digite el ID del trabajador: "; cin >> id;
                tb = buscarTrabajador(planilla, contador, id);

                if(tb){
                    verDetalles(tb);
                }else{
                    cout << "El trabajador no se encontro. " << endl;
                }
            break;
            case '4':
                cout << "Cerrando del programa... " << endl;
            break;
            default:
                cout << "Error, no es una opcion existente." << endl;
            break;
        }
        system("pause");

    }while(seleccion != '4');

    return 0;
}
