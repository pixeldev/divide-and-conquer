//
// Created by Angel Miranda on 19/04/24.
//

#ifndef DIVIDE_Y_VENCERAS_TERNARY_H
#define DIVIDE_Y_VENCERAS_TERNARY_H

/**
 * Dado un arreglo ordenado de números de tamaño n y un número x,
 * busca el elemento x en el arreglo. Para la búsqueda divide el
 * arreglo en 3 partes y como en búsqueda binaria, identifica en
 * cual de las 3 partes del arreglo seguirás haciendo la búsqueda,
 * descartando así 2/3 del espacio de búsqueda.
 *
 * @param array el arreglo de números ordenados
 * @param start el índice del primer elemento del arreglo
 * @param end   el índice del último elemento del arreglo
 * @param x     el número a buscar
 * @return el índice del número buscado, -1 si no se encuentra
 */
int ternarySearch(int array[], int start, int end, int x);

#endif //DIVIDE_Y_VENCERAS_TERNARY_H
