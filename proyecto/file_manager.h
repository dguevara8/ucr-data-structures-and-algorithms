#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "graphs.h"
#include <fstream>
#include <sstream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


// Guarda la información del grafo en un archivo "flights.txt"
bool guardarGrafo(const Graph &grafo, const string filename = "flights.txt") {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir: " << filename << endl;
        return false;
    }

    // 1) Guardar todas las ciudades, una por línea, con el formato:
    //    CITY nombre x y
    auto ciudades = grafo.obtenerCiudades();
    for (auto &par : ciudades) {
        const auto &ciudad = par.second;
        outFile << "CITY " 
                << ciudad.nombre << " " 
                << ciudad.x << " " 
                << ciudad.y << "\n";
    }

    // 2) Guardar todas las conexiones, una por línea, con el formato:
    //    CONNECTION origen destino peso
    for (auto &par : ciudades) {
        const auto &origen = par.second;
        for (auto &vuelo : origen.conexiones) {
            outFile << "CONNECTION " 
                    << origen.nombre << " " 
                    << vuelo.destino << " " 
                    << vuelo.peso << "\n";
        }
    }

    outFile.close();
    return true;
}


    // Carga la información desde "flights.txt" y reconstruye el grafo.
bool cargarGrafo(Graph &grafo, const string filename = "flights.txt") {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "No se pudo abrir el archivo para leer: " << filename << endl;
        return false;
    }

    // Se limpia el grafo actual.
    grafo.vaciarGrafo();

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) 
            continue;

        // Separa la línea en tokens
        istringstream iss(line);
        string type;
        iss >> type;  // Puede ser "CITY" o "CONNECTION"

        if (type == "CITY") {
            // Formato esperado: CITY nombre x y
            string nombre;
            int x, y;
            if (!(iss >> nombre >> x >> y)) {
                cerr << "Error al leer ciudad en la línea: " << line << endl;
                continue;
            }
            grafo.agregarCiudad(nombre, x, y);

        } else if (type == "CONNECTION") {
            // Formato esperado: CONNECTION origen destino peso
            string origen, destino;
            double peso;
            if (!(iss >> origen >> destino >> peso)) {
                cerr << "Error al leer conexión en la línea: " << line << endl;
                continue;
            }
            grafo.agregarConexion(origen, destino, peso);

        } else {
            // Si no empieza con "CITY" o "CONNECTION", se ignora o se maneja un error
            cerr << "Línea desconocida: " << line << endl;
        }
    }

    inFile.close();
    return true;
}
    
#endif