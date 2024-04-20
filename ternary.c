//
// Created by Angel Miranda on 19/04/24.
//
#include "ternary.h"

int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) { // Si el arreglo tiene al menos un elemento
        int mid1 = l + (r - l) / 3; // Dividir el arreglo en 3 partes
        int mid2 = r - (r - l) / 3; // Dividir el arreglo en 3 partes
        if (arr[mid1] == x) { // Si el elemento está en la primera parte
            return mid1; // Retornar el índice del elemento
        }
        if (arr[mid2] == x) { // Si el elemento está en la segunda parte
            return mid2; // Retornar el índice del elemento
        }
        if (x < arr[mid1]) { // Si el elemento está en la primera parte
            return ternarySearch(arr, l, mid1 - 1, x); // Buscar en la primera parte
        }
        else if (x > arr[mid2]) { // Si el elemento está en la tercera parte
            return ternarySearch(arr, mid2 + 1, r, x); // Buscar en la tercera parte
        }
        else { // Si el elemento está en la segunda parte
            return ternarySearch(arr, mid1 + 1, mid2 - 1, x); // Buscar en la segunda parte
        }
    }
    return -1;
}