#ifndef TRABAJADORPORHORA_H_INCLUDED
#define TRABAJADORPORHORA_H_INCLUDED

#include "Trabajador.h"

class TrabajadorPorHora : public Trabajador{
    private:
        float sueldoPorHora;
        int numHorasTrabajadas;
        void calcular(){
            this -> sueldoMensual = this -> sueldoPorHora * this -> numHorasTrabajadas;
            this -> descuentoIsr = this -> sueldoMensual * 0.1;
            this -> totalPagar = this -> sueldoMensual - this -> descuentoIsr;
        }
    public:
        TrabajadorPorHora(int c, string n, string a, float sHora, int nHoTrab) : Trabajador(c, n, a){
            this -> sueldoPorHora = sHora;
            this -> numHorasTrabajadas = nHoTrab;
            this -> calcular();
        }
        float getSueldoMensual(){
            return this -> sueldoPorHora;
        }
        int getNumHorasTrabajadas(){
            return this -> numHorasTrabajadas;
        }
        int getTipoTrabajador(){
            return 2; //el numero '2' representa a los trabajadores pagados por hora
        }
};

#endif // TRABAJADORPORHORA_H_INCLUDED
