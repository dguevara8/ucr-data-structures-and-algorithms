#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;
        vector<pair<int, pair<string, string>>> edges; // Lista de aristas (peso, (v1, v2))
        unordered_map<string, int> nodeIndex; // Mapeo de nombres de nodos a índices
        vector<int> parent; // Almacena el nodo padre de cada nodo 
        vector<int> rank;   // Almacena el rango de cada nodo 
        int V, E; // Número de vértices y aristas
    
    public:
        // Constructor que inicializa el número de vértices y aristas
        Graph(int V, int E) : V(V), E(E) {}

        void printGraph() {
            int index = 0;
            parent.clear(); // Limpia la estructura de padres
            rank.clear();   // Limpia la estructura de rangos
            nodeIndex.clear(); // Limpia el mapeo de nodos

            // Asigna un índice único a cada nodo
            for (const auto& kv : adjList) {
                if (nodeIndex.find(kv.first) == nodeIndex.end()) {
                    nodeIndex[kv.first] = index++;
                }
            }

            V = nodeIndex.size(); // Se asegura de tener el número correcto de nodos
            parent.resize(V, -1);
            rank.resize(V, 0);
        }

        bool addEdge(string vertex1, string vertex2, int weight) {
            edges.push_back({weight, {vertex1, vertex2}});
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
            return true;
        }

        // Función para encontrar el representante de un conjunto
        int find(int i){
            if (parent[i] == -1)
                return i;

            return parent[i] = find(parent[i]);
        }

        // Función para unir dos conjuntos en DSU
        void unite(int v1, int v2)
        {
            int s1 = find(v1);
            int s2 = find(v2);

            if (s1 != s2) {  // Si no pertenecen al mismo conjunto
                if (rank[s1] < rank[s2]) {
                    parent[s1] = s2; // Une el árbol más pequeño al más grande
                } else if (rank[s1] > rank[s2]) {
                    parent[s2] = s1;
                } else {
                    parent[s2] = s1;
                    rank[s1] ++; // Aumenta el rango si eran del mismo tamaño
                }
            }
        }

        void kruskalMST(){
            sort(edges.begin(), edges.end()); // Ordena aristas por peso
            printGraph(); // Inicializa DSU con mapeo de nodos

            int mst_weight = 0; // Almacena el peso total del MST
            int count = 0; // Contador de aristas añadidas al MST

            for (const auto& edge : edges) {
                int weight = edge.first;
                string vertex1 = edge.second.first;
                string vertex2 = edge.second.second;

                int v1 = nodeIndex[vertex1];
                int v2 = nodeIndex[vertex2];

                if (find(v1) != find(v2)) {
                    unite(v1, v2);
                    mst_weight += weight;
                    cout << vertex1 << " -- " << vertex2 << " == " << weight << endl;
                    count++;
                    if (count == V - 1) break;
                }
            }
            cout << "Costo mínimo del MST: " << mst_weight << endl;
        }

};

#endif
