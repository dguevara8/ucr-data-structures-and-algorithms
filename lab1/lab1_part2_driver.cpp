#include <iostream>  
#include <string>    
#include <iomanip>   
#include "lab1_part2_calculadora.h"

int main() {
    int d;
    int m;
    int diasdespues;
    
    // Se asegura de que la fecha sea válida
    while (cin >> m >> d >> diasdespues) {
        if (m < 1 || m > 12 || d < 1 || diasdespues < 0 || (m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) || d > 31) {
            cout << "Error: Entrada inválida." << endl;
            continue; // Si la entrada es inválida pide una nueva
        }

        Date2025 fecha(d, m); // Objeto Date2025 con la fecha ingresada
        if (m == -1 && d == -1) {
            cout << "Error: Fecha fuera de 2025." << endl;
            continue; // Si la fecha es inválida pide una nueva
        } 
        
        // Muestra el resultado de los días después de la fecha ingresada
        cout << diasdespues << " días después del ";
        fecha.print();  // Imprime la fecha original
        
        fecha.plusday(diasdespues);  // Aumenta los días
        
        cout << " es ";
        fecha.print();  // Imprime la fecha después de sumar los días
        cout << endl;
    }

    return 0;
}