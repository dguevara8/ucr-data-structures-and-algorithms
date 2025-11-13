#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    int nodes, edges;
    string v1, v2;
    int weight;

    cout << "Ingrese la cantidad de nodos y aristas: ";
    cin >> nodes >> edges;
    Graph graph(nodes, edges);

    for (int i = 0; i < edges; i++) {
        cout << "Ingrese los nodos y el peso de la arista (Ejemplo: A B 2): ";
        cin >> v1 >> v2 >> weight;
        graph.addEdge(v1, v2, weight);
    }
    /* Esta parte no debe ser modificada*/
    cout << "Árbol de Expansión Mínima (MST) usando Kruskal:" << endl;
    graph.kruskalMST();
    /* Esta parte no debe ser modificada*/

    return 0;
}
