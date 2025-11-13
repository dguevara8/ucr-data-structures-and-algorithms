#ifndef GRAPHS_H
#define GRAPHS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

// Estructura que representa un vuelo (conexión)
struct Flight {
    string destino;  // Ciudad destino
    double peso;     // Peso
};

// Clase del grafo dirigido
class Graph {
public:
    // Estructura que representa una ciudad
    struct City {
        string nombre;
        int x, y; // Coordenadas del nodo
        vector<Flight> conexiones;  // Vuelos asociados
    };

    // Métodos para gestionar ciudades y conexiones

    // Método para agregar una ciudad al grafo
    bool agregarCiudad(const string& nombre, int x = 0, int y = 0) {
        if (ciudades.find(nombre) != ciudades.end()) {
            cerr << "La ciudad " << nombre << " ya existe. Intenta con otro nombre\n";
            return false;
        }
        City ciudad{nombre, x, y, {}};
        ciudades[nombre] = ciudad;
        return true;
    }

    // Método para eliminar una ciudad y todas las conexiones asociadas
    bool eliminarCiudad(const string& nombre) {
        if (ciudades.erase(nombre) == 0) {
            cerr << "La ciudad " << nombre << " no existe. Intenta con otro nombre\n";
            return false;
        }
        // Eliminar conexiones asociadas a esta ciudad
        for (auto& par : ciudades) {
            auto& vuelos = par.second.conexiones;
            vuelos.erase(remove_if(vuelos.begin(), vuelos.end(),
                          [&nombre](const Flight& vuelo){ return vuelo.destino == nombre; }),
                          vuelos.end());
        }
        return true;
    }

    // Método para agregar una conexión entre dos ciudades
    bool agregarConexion(const string& origen, const string& destino, double peso) {
        auto it = ciudades.find(origen);
        it->second.conexiones.push_back({destino, peso});
        return true;
    }

    // Método para modificar el peso de una conexión existente
    bool modificarConexion(const string& origen, const string& destino, double nuevoPeso) {
        auto it = ciudades.find(origen);
        for (auto& vuelo : it->second.conexiones) {
            if (vuelo.destino == destino) {
                vuelo.peso = nuevoPeso;
                return true;
            }
        }
        cerr << "La conexión de " << origen << " a " << destino << " no existe.\n";
        return false;
    }

    // Método para eliminar una conexión entre dos ciudades
    bool eliminarConexion(const string& origen, const string& destino) {
        auto it = ciudades.find(origen);
        auto& vuelos = it->second.conexiones;
        auto originalSize = vuelos.size();
        vuelos.erase(remove_if(vuelos.begin(), vuelos.end(),
                      [&destino](const Flight& vuelo){ return vuelo.destino == destino; }),
                      vuelos.end());
        if (vuelos.size() == originalSize) {
            cerr << "La conexión de " << origen << " a " << destino << " no existe.\n";
            return false;
        }
        return true;
    }

    void vaciarGrafo() {
        ciudades.clear();
    }
    
    // Acceso a las ciudades del grafo
    const unordered_map<string, City>& obtenerCiudades() const {
        return ciudades;
    }
    unordered_map<string, City>& obtenerCiudades() {
        return ciudades;
    }

private:
    unordered_map<string, City> ciudades;
};

#endif
