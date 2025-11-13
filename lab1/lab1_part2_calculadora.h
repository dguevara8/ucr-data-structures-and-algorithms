#include <iostream>
using namespace std;

#ifndef LAB1_PART2_CALCULADORA_H
#define LAB1_PART2_CALCULADORA_H

// Declaración de la clase Date2025
class Date2025{
    private:
        int m;  // Variable para almacenar el mes
        int d;  // Variable para almacenar el día
        
         // Arrays estáticos para los días de la semana y los meses del año
        static string dias[7];
        static string meses[12];

    public:
    // Constructores de la clase
        Date2025();
        Date2025(int dd);
        Date2025(int dd, int mm);

    // Métodos de la clase
        void setdate(int dd, int mm);
        void print() const;
        void plusday(int days);

};

#endif