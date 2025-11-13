#include <iostream>
#include <iomanip>
using namespace std;

// Clase para convertir temperaturas de Celsius a Fahrenheit
class CelsiusToFahrenheit {
  private:
    float celsius; // Variable para almacenar la temperatura en Celsius

  public:
 // Función que lee la temperatura en Celsius
    void TemperaturaC() {
      cout << "Celsius:"; // Input que se le solicita al usuario 
      cin >> celsius; // Output que ingresa el usuario
    }

    // Función para convertir la temperatura
    double toFahrenheit() {
      return ((celsius * 9) / 5) + 32; // Fórmula de conversión de Celsius a Fahrenheit
    }

    // Función que devuelve el valor de celsius
    float resultadoC() {
      return celsius;
    }
};

// Clase para convertir temperaturas de Fahrenheit a Celsius
class FahrenheitToCelsius {
  private:
    float fahrenheit;
  // Función que lee la temperatura en Fahrenheit
  public:
    void TemperaturaF() {
      cout << "Fahrenheit:"; // Input que se le solicita al usuario 
      cin >> fahrenheit; // Output que ingresa el usuario
    }

    // Función para convertir la temperatura
    double toCelsius() {
      return (fahrenheit - 32) * (5.0 / 9.0); // Fórmula de conversión de Fahrenheit a Celsius
    }

    // Función que devuelve el valor de fahrenheit
    float resultadoF() {
      return fahrenheit;
    }
};

int main() {

    CelsiusToFahrenheit C;
    C.TemperaturaC(); // Almacena la temperatura en celsius
    double temperaturaF = C.toFahrenheit(); // Convierte la temperatura
    // Muestra la temperatura original en Celsius y la convertida en Fahrenheit
    cout << fixed << setprecision(1) << C.resultadoC() << "°C = " << temperaturaF << "°F\n";

    FahrenheitToCelsius F;
    F.TemperaturaF(); // Almacena la temperatura en fahrenheit
    double temperaturaC = F.toCelsius(); // Convierte la temperatura
    // Muestra la temperatura original en Fahrenheit y la convertida en Celsius
    cout << fixed << setprecision(1) << F.resultadoF() << "°F = " << temperaturaC << "°C\n";

  return 0;
}