#ifndef SORTING_H
#define SORTING_H

#include <iostream>

using namespace std;

    void heapify (int arr [ ] , int n , int i ){
        int largest = i ;
        int left = 2 * i + 1 ;
        int right = 2 * i + 2 ;
        // Si el hijo izquierdo es más grande que el nodo actual
        if ( left < n && arr [ left ] > arr [ largest] ) largest = left ;
        // Si el hijo derecho es más grande que el nodo actual 
        if ( right < n && arr [right ] > arr [largest] ) largest = right ;
        // Si el nodo más grande no es el nodo actual, hace el intercambio
        if ( largest != i ) {
            swap ( arr [ i ], arr [largest] ) ; // Intercambia el nodo con el más grande
            heapify ( arr , n , largest) ; // Llama recursivamente en el nodo afectado
        }


    }

    void heapSort(int arr[ ] , int n ){
        // Reorganiza el array
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    
        //Extrae los elementos uno por uno del heap
        for (int i = n - 1; i >= 0; i--) {
            // Mueve el nodo raíz al final
            swap(arr[0], arr[i]);
    
            // Llama a heapify en la parte reducida del heap
            heapify(arr, i, 0);
        }
    }
    
    // Imprime un array de n tamano
    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }


#endif