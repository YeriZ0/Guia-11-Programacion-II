#ifndef TRABAJADORTIEMPOCOMPLETO_H_INCLUDED
#define TRABAJADORTIEMPOCOMPLETO_H_INCLUDED

#include "Trabajador.h"

class TrabajadorTiempoCompleto : public Trabajador{
    private:
        float descuentoIsss;
        float descuentoAfp;
        void calcular(){
            //uso de operador ternario, " condicion " ? "si se cumple" : "si no se cumple"
            this -> descuentoIsss = (this -> sueldoMensual <= 1000) ? this -> sueldoMensual * 0.03 : 30;
            this -> descuentoAfp = (this -> sueldoMensual <= 7500) ? this -> sueldoMensual * 0.0725 : 543.75;

            float antesISR = this -> sueldoMensual - (this -> descuentoIsss + this -> descuentoAfp);

            if(antesISR <= 472){
                this -> descuentoIsr = 0;
            }else if(antesISR<= 895.24){
                this -> descuentoIsr = ((this -> sueldoMensual - 472) * 0.10) + 17.67;
            }else if(antesISR <= 2038.10){
                this -> descuentoIsr = ((this -> sueldoMensual - 895.24) * 0.20) + 60;
            }else if(antesISR >= 2038.11){
                this -> descuentoIsr = ((this -> sueldoMensual - 2038.10) * 0.30) + 288.57;
            }

            this -> totalPagar = this -> sueldoMensual - this -> descuentoIsss - this -> descuentoAfp - this -> descuentoIsr;
        }
    public:
        TrabajadorTiempoCompleto(int c, string n, string a, float sM) : Trabajador(c, n, a){
            this -> sueldoMensual = sM;
            this -> calcular();
        }
        float getDescuentoIsss(){
            return this -> descuentoIsss;
        }
        float getDescuentoAfp(){
            return this -> descuentoAfp;
        }
        int getTipoTrabajador(){
            return 1;
        }
};


#endif // TRABAJADORTIEMPOCOMPLETO_H_INCLUDED
