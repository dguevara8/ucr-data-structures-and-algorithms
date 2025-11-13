#include "lab1_part2_calculadora.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

// Definición de los arrays estáticos
string Date2025::dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
string Date2025::meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", 
                              "Octubre", "Noviembre", "Diciembre"};

// Constructor que establece la fecha predeterminada
Date2025::Date2025(): d(1), m(1) {}

// Constructor que recibe un número de día (1-365), si es inválido se imprime un mensaje de error
Date2025::Date2025(int dd) {
    if (dd < 1 || dd > 365) {
        cout << "Error: Día inexistente.\n";
        d = -1;
    } else {
        d = dd;
    }
}

// Constructor que recibe un día y un mes para validar la fecha 
Date2025::Date2025(int dd, int mm) {
    if (mm < 1 || mm > 12 || dd < 1 || (mm == 2 && dd > 28) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) || dd > 31) {
        cout << "Error: Fecha inválida.\n";
        d = -1;
        m = -1;
    } else {
        d = dd;
        m = mm;
    }
}

// Método para establecer una fecha
void Date2025::setdate(int dd, int mm) {
    if (mm < 1 || mm > 12 || dd < 1 || (mm == 2 && dd > 28) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) || dd > 31) {
        cout << "Error: Fecha inválida.\n";
        d = -1;
        m = -1;
    } else {
        d = dd;
        m = mm;
    }
}

// Método para imprimir la fecha en formato de día, mes y año con nombre del día de la semana
void Date2025::print() const {
    if (m == -1 && d == -1) {
        cout << "Una fecha fuera de 2025.\n";
        return;
    }

    int dd = d;  // Usa el valor actualizado de d
    int mm = m;  // Usa el valor actualizado de m
    int yy = 2025; // Año fijo para el 2025
    int mon;
    
    if(mm > 2)
        mon = mm;  // Para los meses de marzo a diciembre, el código del mes es igual al mes
    else {
        mon = (12 + mm);  // Para enero y febrero, se ajusta el código del mes a 13 y 14
        yy--;  // Disminuye el año para enero y febrero
    }

    int y = yy % 100;   // Últimos dos dígitos del año
    int c = yy / 100;  // Primeros dos dígitos del año
    // Fórmula de Zeller para calcular el día de la semana
    int w = (dd + ((13 * (mon + 1)) / 5) + y + (y / 4) + (c / 4) + (5 * c));
    w = w % 7;

    // Imprime el día de la semana y la fecha en formato: "Día d de mes de 2025"
    cout << dias[(w + 5) % 7] << " " << d << " de " << meses[m - 1] << " de 2025";
}

// Método para sumar días a la fecha actual y ajusta el día y el mes si es necesario
void Date2025::plusday(int days) {
    if (m == -1 && d == -1) {
        cout << "Una fecha fuera de 2025.\n";
        return;
    }

    // Suma los días al día actual
    d += days;

    // Ajusta la fecha cuando el día excede el número de días del mes
    while (d > 28) {
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
            d -= 30;
            m++;
        } else if (m == 2 && d > 28) {
            d -= 28;
            m++;
        } else if (d > 31) {
            d -= 31;
            m++;
        } else {
            break;
        }
        if (m > 12) {
            d = -1;
            m = -1;
            return;
        }
    }
}

