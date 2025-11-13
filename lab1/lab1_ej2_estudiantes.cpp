#include <iostream>
#include <fstream> // Para manejar archivos
#include <algorithm> // Para manejar sort
#include <string>
#include <vector>
#include <sstream> // Para manejar la separación por comas
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    string nombre;
    string matricula;
    string direccion;
};

// Función para dividir una línea de texto en partes usando el delimitador ','
Estudiante parseLinea(const string& linea) {
    Estudiante estudiante;
    stringstream ss(linea);
    getline(ss, estudiante.nombre, ',');
    getline(ss, estudiante.matricula, ',');
    getline(ss, estudiante.direccion, ',');
    return estudiante;
}

// Función de comparación para ordenar estudiantes por nombre
bool compararPorNombre(const Estudiante& a, const Estudiante& b) {
    return a.nombre < b.nombre;
}

int main()
{
    // Declaración de variables
    string str;
    vector<string> original_order; // Para mantener el orden original
    vector<Estudiante> estudiantes; // Vector para almacenar los datos como estructura
    ofstream myfile;
    myfile.open ("estudiantes.txt"); // Abre el archivo

    cout << "Ingrese los datos de los estudiantes en el formato: Nombre, Matricula, Direccion" << endl; // Input que se le solicita al usuario 

    // Lee todas las líneas que ingrese el usuario
    while (getline(cin, str)) { 
        if (str.empty()) { // Si la línea está vacía, termina
            break;
        }

        // Convierte la línea en un objeto Estudiante
        Estudiante estudiante = parseLinea(str);
        estudiantes.push_back(estudiante);
        original_order.push_back(str); // Guarda tambien las lineas pero en el orden original
    }

    // Escribe la información en el archivo
    for (const auto& estudiante : estudiantes) {
        myfile << estudiante.nombre << "," << estudiante.matricula << "," << estudiante.direccion << "\n";
    }

    cout << "Informacion guardada en el archivo: estudiantes.txt " << endl; // Input de informacion al usuario 
    cout << "Informacion recuperada del archivo: estudiantes.txt " << endl; // Input de informacion al usuario 

    // Ordena alfabéticamente los datos de los estudiantes por nombre
    sort(estudiantes.begin(), estudiantes.end(), compararPorNombre);

    // Imprime la lista ordenada alfabéticamente
    cout << "\nEstudiantes ordenados por nombre: " << endl;
    for (const auto& estudiante : estudiantes) {
        cout << estudiante.nombre << "," << estudiante.matricula << "," << estudiante.direccion << "\n";
    }

    cout << "El archivo estudiantes.txt: " << endl; // Input de informacion al usuario 
    for (auto str : original_order){ // Recorre el vector de orden original
        cout << str << "\n"; // Imprime cada linea
    }

    myfile.close(); // Cierra el archivo

    return 0;
}