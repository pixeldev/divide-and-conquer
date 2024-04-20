//
// Created by Angel Miranda on 19/04/24.
//

#include "distances.h"

int compareX(const void *a, const void *b) { // usamos void* por compatibilidad con qsort
    Point *p1 = (Point *) a, *p2 = (Point *) b; // casteamos los punteros a Point
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) { // usamos void* por compatibilidad con qsort
    Point *p1 = (Point *) a, *p2 = (Point *) b; // casteamos los punteros a Point
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); // fórmula de distancia euclidiana
}

Distance *bruteForce(Point P[], int n) {
    Distance *min = malloc(sizeof(Distance)); // inicializamos la mínima
    min->distance = FLT_MAX; // le asignamos el valor máximo de un float
    for (int i = 0; i < n; ++i) // recorremos el arreglo de puntos
        for (int j = i + 1; j < n; ++j) // recorremos el arreglo de puntos
            if (dist(P[i], P[j]) < min->distance) {// si la distancia entre los puntos es menor que la mínima
                min->distance = dist(P[i],P[j]);
                min->p1 = P[i];
                min->p2 = P[j]; // actualizamos la mínima
            }
    return min;
}

Distance *min(Distance *x, Distance *y) {
    return (x < y) ? x : y; // si x es menor que y, regresamos x, si no, regresamos y
}

Distance *stripClosest(Point strip[], int size, float d) {
    Distance *min = malloc(sizeof(Distance)); // inicializamos la mínima
    min->distance = d; // le asignamos d
    qsort(strip, size, sizeof(Point), compareY); // ordenamos el arreglo de puntos por y
    for (int i = 0; i < size; ++i) // recorremos el arreglo de puntos
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j) // recorremos el arreglo de puntos y verificamos que la diferencia entre las y sea menor que la mínima
            if (dist(strip[i], strip[j]) < min->distance) { // si la distancia entre los puntos es menor que la mínima
                min->distance = dist(strip[i], strip[j]); // actualizamos la mínima
                min->p1 = strip[i];
                min->p2 = strip[j];
            }
    return min;
}

Distance *closestSorted(Point P[], int n) {
    if (n <= 3) // si el tamaño del arreglo es menor o igual a 3
        return bruteForce(P, n); // usamos fuerza bruta
    int mid = n / 2; // calculamos el punto medio
    Point midPoint = P[mid]; // obtenemos el punto medio
    Distance *dl = closestSorted(P, mid); // obtenemos la mínima de la izquierda
    Distance *dr = closestSorted(P + mid, n - mid); // obtenemos la mínima de la derecha
    Distance *d = min(dl, dr); // obtenemos la mínima
    Point strip[n]; // creamos un arreglo de puntos
    int j = 0; // inicializamos un contador
    for (int i = 0; i < n; i++) // recorremos el arreglo de puntos
        if (abs(P[i].x - midPoint.x) < d->distance) // si la diferencia entre las x es menor que la mínima
            strip[j] = P[i], j++; // agregamos el punto al arreglo de puntos
    return min(d, stripClosest(strip, j, d->distance)); // regresamos la mínima entre la mínima y la mínima del strip
}

Distance *closestUnsorted(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX); // ordenamos el arreglo de puntos por x
    return closestSorted(P, n); // regresamos la mínima
}