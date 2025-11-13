#include "graphs.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cassert>

using namespace std;

inline vector<string> dijkstra(const Graph& graph, const string& start, const string& finish) {

    // Verificar que los nodos de inicio y destino existan en el grafo
    assert(graph.obtenerCiudades().count(start) && "El nodo de inicio no existe en el grafo");
    assert(graph.obtenerCiudades().count(finish) && "El nodo de destino no existe en el grafo");

    // Mapa para almacenar la distancia mínima desde el nodo de inicio a cada nodo
    unordered_map<string, double> dist;

    // Mapa para almacenar el nodo previo en el camino más corto
    unordered_map<string, string> prev;
    
    // Cola de prioridad para seleccionar el nodo con la distancia mínima
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

    // Inicializar las distancias a infinito y los nodos previos a una cadena vacía
    for (const auto& pair : graph.obtenerCiudades()) {
        dist[pair.first] = numeric_limits<double>::infinity();
        prev[pair.first] = "";
    }

    dist[start] = 0.0;
    pq.push({0.0, start});

    while (!pq.empty()) {
        // Obtener el nodo con la distancia mínima
        auto [currentDist, current] = pq.top();
        pq.pop();

        if (current == finish) break; // Si hemos llegado al nodo de destino, terminamos

        // Explorar las conexiones del nodo actual
        for (const auto& flight : graph.obtenerCiudades().at(current).conexiones) {
            // Calcular la nueva distancia
            double newDist = currentDist + flight.peso;

            // Si la nueva distancia es menor que la distancia almacenada
            if (newDist < dist[flight.destino]) {
                // Actualizar la distancia y el nodo previo
                dist[flight.destino] = newDist;
                prev[flight.destino] = current;

                // Insertar el nodo destino en la cola de prioridad
                pq.push({newDist, flight.destino});
            }
        }
    }

    // Construir el camino más corto desde el nodo de destino al nodo de inicio
    vector<string> path;
    for (string at = finish; !at.empty(); at = prev[at]) {
        path.push_back(at);
    }
    // Invertir el camino para obtener el orden correcto
    reverse(path.begin(), path.end());

    // Si el camino contiene solo un nodo y no es el nodo de inicio, no se encontró un camino
    if (path.size() == 1 && path[0] != start) {
        return {}; // No path found
    }

    // Sanity check: Verificar que el primer nodo del camino es el nodo de inicio
    assert(path.empty() || path.front() == start);

    return path;
}
