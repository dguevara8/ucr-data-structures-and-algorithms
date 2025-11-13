#include <iostream>
#include <vector>
using namespace std;

// Función principal (main)
int main() {
    // Declaración de variables
    int num_meses; 
    int gasto;
    vector<int> gasto_men;
    int sum = 0;

    // Mostrar las propiedades del objeto
    cout << "Ingrese el numero de meses: "; // Input que se le solicita al usuario 
    cin >> num_meses; // Output que ingresa el usuario
    cout << "Ingrese los gastos mensuales separados por espacio: "; // Input que se le solicita al usuario 
    
    for(int i = 0; i < num_meses; i++) {
        cin >> gasto; // Output que ingresa el usuario
        gasto_men.push_back(gasto); // Almacena el gasto en el vector
        sum+= gasto; // Suma el gasto al total
    }

    // Verifica que el número de meses sea múltiplo de 12
    if (num_meses % 12 == 0) {
        // Calcula el promedio mensual
        double promedio_men = double(sum) / num_meses;
        // Muestra el resultado del promedio mensual
        cout << "\nPromedio mensual: "<< promedio_men;

        // Calcula el gasto anual promedio
        int gasto_anual= sum  / (num_meses/12);
        // Muestra el resultado del gasto anual
        cout << "\nGasto anual promedio: " << gasto_anual << endl;
    } else {
        // Muestra un mensaje de error si el número de meses no es múltiplo de 12
        cout <<  "\nError: El número de meses debe ser múltiplo de 12 para calcular el gasto anual promedio.";
    }

    return 0;

};
