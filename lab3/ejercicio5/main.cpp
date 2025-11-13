#include <iostream>
#include "Sorting.h"

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos del array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    /* Esta parte no debe ser modificada*/

    heapSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    /* Esta parte no debe ser modificada*/

    return 0;
}
