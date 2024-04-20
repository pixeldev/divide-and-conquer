//
// Created by Angel Miranda on 20/04/24.
//

#ifndef DIVIDE_Y_VENCERAS_OCCURRENCES_H
#define DIVIDE_Y_VENCERAS_OCCURRENCES_H

/**
 * Encuentra la primera ocurrencia de un número en un arreglo ordenado
 * utilizando el paradigma de divide y vencerás.
 *
 * @param arr   el arreglo ordenado.
 * @param n     el tamaño del arreglo.
 * @param x     el número a buscar.
 * @return la primera ocurrencia del número en el arreglo, -1 si no se encuentra.
 */
int firstOccurrence(const int *arr, int n, int x);

/**
 * Encuentra la última ocurrencia de un número en un arreglo ordenado
 * utilizando el paradigma de divide y vencerás.
 *
 * @param arr   el arreglo ordenado.
 * @param n     el tamaño del arreglo.
 * @param x     el número a buscar.
 * @return la última ocurrencia del número en el arreglo, -1 si no se encuentra.
 */
int lastOccurrence(const int *arr, int n, int x);

#endif //DIVIDE_Y_VENCERAS_OCCURRENCES_H
