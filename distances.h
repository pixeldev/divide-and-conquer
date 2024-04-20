//
// Created by Angel Miranda on 19/04/24.
//

#ifndef DIVIDE_Y_VENCERAS_DISTANCES_H
#define DIVIDE_Y_VENCERAS_DISTANCES_H

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

/**
 * Estructura que representa un punto en el plano.
 *
 * x la coordenada x del punto.
 */
typedef struct Point {
    int x, y;
} Point;

/**
 * Estructura que representa la distancia entre dos puntos.
 *
 * p1 el primer punto.
 * p2 el segundo punto.
 * distance la distancia entre los dos puntos.
 */
typedef struct Distance {
    Point p1, p2;
    float distance;
} Distance;

/**
 * Compara dos puntos por su coordenada x.
 *
 * @param a el primer punto.
 * @param b el segundo punto.
 * @return la diferencia entre las coordenadas x de los puntos.
 */
int compareX(const void *a, const void *b);

/**
 * Compara dos puntos por su coordenada y.
 *
 * @param a el primer punto.
 * @param b el segundo punto.
 * @return la diferencia entre las coordenadas y de los puntos.
 */
int compareY(const void *a, const void *b);

/**
 * Calcula la distancia entre dos puntos.
 *
 * @param p1 el primer punto.
 * @param p2 el segundo punto.
 * @return la distancia entre los dos puntos.
 */
float dist(Point p1, Point p2);

/**
 * Dado un conjunto de puntos, encuentra la distancia
 * más pequeña entre dos puntos en el conjunto.
 *
 * @param P el conjunto de puntos.
 * @param n el número de puntos en P.
 * @return la distancia más pequeña entre dos puntos en P.
 */
Distance *bruteForce(Point P[], int n);

/**
 * Dados dos números, devuelve el menor de los dos.
 *
 * @param x el primer número
 * @param y el segundo número
 * @return el menor de los dos números
 */
Distance *min(Distance *x, Distance *y);

/**
 * Dado un conjunto de puntos ordenados por su coordenada y,
 * encuentra la distancia más pequeña entre dos puntos en el conjunto.
 *
 * @param strip el conjunto de puntos ordenados por su coordenada y.
 * @param size  el número de puntos en strip.
 * @param d     la distancia más pequeña entre dos puntos en el conjunto.
 * @return la distancia más pequeña entre dos puntos en strip.
 */
Distance *stripClosest(Point strip[], int size, float d);

/**
 * Dado un conjunto de puntos ordenados en el plano,
 * encuentra el par de puntos que tengan la distancia más pequeña.
 *
 * @param P el conjunto de puntos.
 * @param n el número de puntos en P.
 * @return la distancia más pequeña entre dos puntos en P.
 */
Distance *closestSorted(Point P[], int n);

/**
 * Dado un conjunto de puntos en el plano, encuentra el par de
 * puntos que tengan la distancia más pequeña.
 * Este método acepta un conjunto de puntos en cualquier orden y
 * se encarga de ordenarlos y llamar a closestSorted() para resolver el problema.
 *
 * @param P el conjunto de puntos.
 * @param n el número de puntos en P.
 * @return la distancia más pequeña entre dos puntos en P.
 */
Distance *closestUnsorted(Point P[], int n);

#endif //DIVIDE_Y_VENCERAS_DISTANCES_H
