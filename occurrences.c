//
// Created by Angel Miranda on 20/04/24.
//

#include "occurrences.h"

int firstOccurrence(const int *arr, int n, int x) {
    int low = 0, high = n - 1; // Inicializamos los índices de búsqueda.
    int result = -1; // Inicializamos el resultado.
    while (low <= high) { // Mientras no se crucen los índices.
        int mid = low + (high - low) / 2; // Calculamos el índice medio.
        if (arr[mid] < x) { // Si el número en el índice medio es menor que x.
            low = mid + 1; // Actualizamos el índice bajo.
        } else { // Si el número en el índice medio es mayor o igual que x.
            if (arr[mid] == x) result = mid; // Actualizamos el resultado.
            high = mid - 1; // Actualizamos el índice alto.
        }
    }
    return result;
}

int lastOccurrence(const int *arr, int n, int x) {
    int low = 0, high = n - 1; // Inicializamos los índices de búsqueda.
    int result = -1; // Inicializamos el resultado.
    while (low <= high) { // Mientras no se crucen los índices.
        int mid = low + (high - low) / 2; // Calculamos el índice medio.
        if (arr[mid] > x) { // Si el número en el índice medio es mayor que x.
            high = mid - 1; // Actualizamos el índice alto.
        } else {
            if (arr[mid] == x) result = mid; // Actualizamos el resultado.
            low = mid + 1; // Actualizamos el índice bajo.
        }
    }
    return result;
}