#include <stdio.h>
#include "occurrences.h"
#include "power.h"
#include "ternary.h"

int main(void) {
    puts("Bienvenido al programa de ejercicios de divide y vencerás.");
    puts("Escoge una opción:");
    puts("1. Potencia");
    puts("2. Búsqueda ternaria");
    puts("3. Índices de aparición");
    printf(">> ");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Introduce la base:\n>> ");
            double base;
            scanf("%lf", &base);
            printf("Introduce el exponente:\n>> ");
            unsigned int exponent;
            scanf("%u", &exponent);
            printf("El resultado es: %lf\n", power(base, exponent));
            break;
        case 2: {
            printf("Introduce el tamaño del arreglo:\n>> ");
            int size;
            scanf("%d", &size);
            int arr[size];
            printf("Introduce los elementos del arreglo:\n");
            for (int i = 0; i < size; i++) {
                printf(">> ");
                scanf("%d", &arr[i]);
            }
            printf("Introduce el elemento a buscar:\n>> ");
            int x;
            scanf("%d", &x);
            int result = ternarySearch(arr, 0, size - 1, x);
            if (result == -1) {
                puts("El elemento no se encuentra en el arreglo.");
            } else {
                printf("El elemento se encuentra en la posición %d.\n", result);
            }
            break;
        }
        case 3: {
            printf("Introduce el tamaño del arreglo:\n>> ");
            int size;
            scanf("%d", &size);
            int arr[size];
            printf("Introduce los elementos del arreglo:\n");
            for (int i = 0; i < size; i++) {
                printf(">> ");
                scanf("%d", &arr[i]);
            }
            printf("Introduce el elemento a buscar:\n>> ");
            int x;
            scanf("%d", &x);
            int first = firstOccurrence(arr, size, x);
            int last = lastOccurrence(arr, size, x);
            if (first == -1) {
                puts("El elemento no se encuentra en el arreglo.");
            } else {
                printf("El elemento se encuentra en las posiciones %d a %d.\n", first, last);
            }
            break;
        }
        default:
            puts("Opción no válida.");
            break;
    }
    return 0;
}
