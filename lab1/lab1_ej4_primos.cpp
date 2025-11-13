#include <iostream>
#include <cmath>
using namespace std;

// Clase para verificar si un número es primo
class NumeroPrimo {
private:
    int n; // Variable que almacena el número primo

public:
// Constructor que inicializa la variable n
    NumeroPrimo(int numero) : n(numero) {}

    // Función que verifica si el número es primo
    bool esPrimo(){
        bool primo = true; // Se supone que el número es primo
        for (int i = 2; i < n; i++){ 
            if(n % i == 0) { // Si n es divisible por i
                return false;} // Si no es primo retorna false
        }
        return true;
    }
};

// Clase que interactua con el usuario
class VerificadorDePrimos {
public:
    void iniciar() {
        char respuesta;
        do {
            int n;
            cout << "Ingrese un número para verificar si es primo: "; // Input que se le solicita al usuario
            cin >> n; // Output que ingresa el usuario

            NumeroPrimo numeroPrimo(n);
            if (numeroPrimo.esPrimo()) {
                cout << n << " es primo.\n"; // Output que devuelve el valor del numero primo
            } else {
                cout << n << " no es primo.\n"; // Output que devuelve el valor del numero no primo
            }

            cout << "¿Desea verificar otro número? (y/n): "; // Input que se le solicita al usuario
            cin >> respuesta; // Output que ingresa el usuario
        } while (respuesta == 'y'); // Repite si la respuesta es 'y'

        cout << "Programa finalizado.\n"; // Output que se le muestra al usuario al terminar
    }
};

int main() {
    VerificadorDePrimos verificador;
    verificador.iniciar(); // Realiza el proceso de verificación del numero
    return 0;
}