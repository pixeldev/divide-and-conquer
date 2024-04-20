//
// Created by Angel Miranda on 20/04/24.
//

#include "occurrences.h"

int firstOccurrence(const int *arr, int low, int high, int x) {
    if (high >= low) { // Si el índice más alto es mayor o igual al índice más bajo
        int mid = low + (high - low) / 2; // Se obtiene el índice medio
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x) // Si el índice medio es 0 o el número es mayor al número anterior y el número en el índice medio es igual al número buscado
            return mid; // Se regresa el índice medio
        else if (x > arr[mid]) // Si el número es mayor al número en el índice medio
            return firstOccurrence(arr, mid + 1, high, x); // Se busca en la mitad derecha
        else // Si no
            return firstOccurrence(arr, low, mid - 1, x); // Se busca en la mitad izquierda
    }
    return -1; // Si no se encuentra el número
}

int lastOccurrence(const int *arr, int low, int high, int n, int x) {
    if (high >= low) { // Si el índice más alto es mayor o igual al índice más bajo
        int mid = low + (high - low) / 2; // Se obtiene el índice medio
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x) // Si el índice medio es igual al tamaño del arreglo menos 1 o el número es menor al número siguiente y el número en el índice medio es igual al número buscado
            return mid; // Se regresa el índice medio
        else if (x < arr[mid]) // Si el número es menor al número en el índice medio
            return lastOccurrence(arr, low, mid - 1, n, x); // Se busca en la mitad izquierda
        else // Si no
            return lastOccurrence(arr, mid + 1, high, n, x); // Se busca en la mitad derecha
    }
    return -1; // Si no se encuentra el número
}