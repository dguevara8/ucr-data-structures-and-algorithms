#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits.h>

using namespace std;


class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;
        vector<pair<int, pair<string, string>>> G; // Lista de aristas (peso, (v1, v2))
    
    public:
        void printGraph() {
            unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
            while (kvPair != adjList.end()) {
                cout  << kvPair->first << ": [ "; // Imprime el vertice actual
                unordered_set<string>::iterator edge = kvPair->second.begin();
                while (edge != kvPair->second.end()) {
                    cout  << edge->data() << " "; // Imprime la conexión
                    edge++;
                }
                cout << "]" << endl;
                kvPair++;
            }
        }

        bool addVertex(string vertex) {
            // Si el vertice no existe, lo agrega
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;  // Si el vertice ya existe, no lo agrega
        }

        bool addEdge(string vertex1, string vertex2, int weight) {
            G.push_back({weight, {vertex1, vertex2}}); // Guarda la arista en la lista de aristas
            adjList[vertex1].insert(vertex2); // Agrega vertex2 como vecino de vertex1
            adjList[vertex2].insert(vertex1); // Agrega vertex1 como vecino de vertex2
            return true;
        }

        int minDistance(int dist[], bool visited[], int V) {
            int min = INT_MAX, min_index;
            // Itera sobre todos los vertices para encontrar el de distancia minima
            for (int v = 0; v < V; v++) {
                if (visited[v] == false && dist[v] <= min) {
                    min = dist[v], min_index = v;
                }
            }
            return min_index;
        }

        void dijkstra(string startVertex){
            unordered_map<string, int> vertexIndex;
            int index = 0;

             // Asocia cada vertice con un indice unico
            for (auto& pair : adjList) {
                vertexIndex[pair.first] = index++;
            }

            int V = vertexIndex.size();  // Número de vértices
            int dist[V];  // Arreglo de distancias más cortas desde el vértice de inicio
            bool visited[V];  // Conjunto de vertices 

            // Inicializa las distancias y el conjunto de vértices 
            for (int i = 0; i < V; i++) {
                dist[i] = INT_MAX;  
                visited[i] = false; 
            }

            dist[vertexIndex[startVertex]] = 0;  // La distancia al vértice de inicio es 0

            // Ejecuta el algoritmo de Dijkstra
            for (int count = 0; count < V - 1; count++) {
                int u = minDistance(dist, visited, V); // Selecciona el vertice con la distancia minima
                visited[u] = true;  // Marca este vértice como revisado

                // Recorre todas las aristas y actualiza las distancias
                for (auto& edge : G) {
                    string uStr = edge.second.first;
                    string vStr = edge.second.second;
                    int uIdx = vertexIndex[uStr];
                    int vIdx = vertexIndex[vStr];
                    int weight = edge.first;

                    // Si el vertice no está revisado y la distancia encontrada es menor que la actual
                    if (!visited[vIdx] && dist[uIdx] != INT_MAX && dist[uIdx] + weight < dist[vIdx]) {
                        dist[vIdx] = dist[uIdx] + weight; // Actualiza la distancia
                    }
                }
            }
            printSolution(dist, vertexIndex); 
        }

        void printSolution(int dist[], unordered_map<string, int>& vertexIndex) {
            // Muestra la distancia desde el vertice de inicio a cada vértice en el grafo
            for (auto& pair : vertexIndex) {
                cout << "Vértice " << pair.first << ": " << dist[pair.second] << endl;
            }
        }
};

#endif