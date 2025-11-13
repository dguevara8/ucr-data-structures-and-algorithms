#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph;
    int edges;
    string v1, v2;
    int weight;

    cout << "Ingrese la cantidad de aristas: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Ingrese los nodos y el peso de la arista (Ejemplo: A B 5): ";
        cin >> v1 >> v2 >> weight;
        graph.addEdge(v1, v2, weight);
    }
     /* Esta parte no debe ser modificada*/
    string startVertex;
    cout << "Ingrese el vértice de inicio para Dijkstra: ";
    cin >> startVertex;

    graph.dijkstra(startVertex);

     /* Esta parte no debe ser modificada*/

    return 0;
}
