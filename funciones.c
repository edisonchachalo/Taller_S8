#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i]);
        
        printf("Ingrese la cantidad de pantallas necesarias para %s: ", productos[i]);
        cantidades[i][0] = validarEntrada();
        
        printf("Ingrese la cantidad de memorias necesarias para %s: ", productos[i]);
        cantidades[i][1] = validarEntrada();
        
        printf("Ingrese la cantidad de procesadores necesarios para %s: ", productos[i]);
        cantidades[i][2] = validarEntrada();
        
        printf("Ingrese la cantidad de altavoces necesarios para %s: ", productos[i]);
        cantidades[i][3] = validarEntrada();

        printf("Ingrese el tiempo de fabricacion (en minutos) para %s: ", productos[i]);
        tiemposFabricacion[i] = validarEntrada();
    }
}

void editarNombre(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int cantidad) {
    char nombreBuscar[20];
    printf("Ingrese el nombre del producto que desea editar: ");
    scanf("%s", nombreBuscar);
    
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombreBuscar) == 0) {
            printf("Ingrese el nuevo nombre: ");
            scanf("%s", productos[i]);
            
            printf("Ingrese la nueva cantidad de pantallas necesarias: ");
            cantidades[i][0] = validarEntrada();
            
            printf("Ingrese la nueva cantidad de memorias necesarias: ");
            cantidades[i][1] = validarEntrada();
            
            printf("Ingrese la nueva cantidad de procesadores necesarios: ");
            cantidades[i][2] = validarEntrada();
            
            printf("Ingrese la nueva cantidad de altavoces necesarios: ");
            cantidades[i][3] = validarEntrada();

            printf("Ingrese el nuevo tiempo de fabricacion (en minutos): ");
            tiemposFabricacion[i] = validarEntrada();
            
            printf("Producto actualizado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int *cantidad) {
    char nombreBuscar[20];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < *cantidad; i++) {
        if (strcmp(productos[i], nombreBuscar) == 0) {
            for (int j = i; j < *cantidad - 1; j++) {
                strcpy(productos[j], productos[j + 1]);
                for (int k = 0; k < 4; k++) {
                    cantidades[j][k] = cantidades[j + 1][k];
                }
                tiemposFabricacion[j] = tiemposFabricacion[j + 1];
            }
            (*cantidad)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int evaluarPedido(int cantidad, int tiempoEntrega, int *productoSeleccionado, int tiempoFabricacion, int *pantallas, int *procesadores, int *memorias, int *altavoces) {
    int requierePantallas = cantidad * productoSeleccionado[0];
    int requiereMemorias = cantidad * productoSeleccionado[1];
    int requiereProcesadores = cantidad * productoSeleccionado[2];
    int requiereAltavoces = cantidad * productoSeleccionado[3];
    int tiempoRequerido = cantidad * tiempoFabricacion;

    if (requierePantallas > *pantallas || requiereProcesadores > *procesadores ||
        requiereMemorias > *memorias || requiereAltavoces > *altavoces || tiempoRequerido > tiempoEntrega) {
        
        printf("No se puede cumplir el pedido con los recursos actuales.\n");
        printf("Para cumplir con el pedido hacen falta:\n");
        if (requierePantallas > *pantallas) printf("%d pantallas.\n", requierePantallas - *pantallas);
        if (requiereProcesadores > *procesadores) printf("%d procesadores.\n", requiereProcesadores - *procesadores);
        if (requiereMemorias > *memorias) printf("%d memorias.\n", requiereMemorias - *memorias);
        if (requiereAltavoces > *altavoces) printf("%d altavoces.\n", requiereAltavoces - *altavoces);
        if (tiempoRequerido > tiempoEntrega) printf("Se necesitan %d minutos mas de tiempo de entrega.\n", tiempoRequerido - tiempoEntrega);
        
        printf("Desea modificar el pedido? (1 = Si, 0 = No): ");
        int modificar = validarEntrada();

        if (modificar == 1) {
            return -1;
        } else {
            return 0;
        }
    }

    printf("Pedido viable. Confirmando...\n");
    *pantallas -= requierePantallas;
    *procesadores -= requiereProcesadores;
    *memorias -= requiereMemorias;
    *altavoces -= requiereAltavoces;
    return 1;
}

void reabastecerInventario(int *pantallas, int *procesadores, int *memorias, int *altavoces) {
    int opcion;
    
    printf("\n--- Reabastecimiento de Inventario ---\n");
    printf("Inventario actual:\n");
    printf("1. Pantallas: %d\n", *pantallas);
    printf("2. Procesadores: %d\n", *procesadores);
    printf("3. Memorias: %d\n", *memorias);
    printf("4. Altavoces: %d\n", *altavoces);
    printf("5. Reabastecer todos los componentes\n");
    printf("Seleccione el componente a reabastecer (1-5): ");
    opcion = validarEntrada();

    switch (opcion) {
        case 1:
            printf("Ingrese la cantidad de pantallas a agregar: ");
            *pantallas += validarEntrada();
            printf("Inventario de pantallas actualizado.\n");
            break;
        case 2:
            printf("Ingrese la cantidad de procesadores a agregar: ");
            *procesadores += validarEntrada();
            printf("Inventario de procesadores actualizado.\n");
            break;
        case 3:
            printf("Ingrese la cantidad de memorias a agregar: ");
            *memorias += validarEntrada();
            printf("Inventario de memorias actualizado.\n");
            break;
        case 4:
            printf("Ingrese la cantidad de altavoces a agregar: ");
            *altavoces += validarEntrada();
            printf("Inventario de altavoces actualizado.\n");
            break;
        case 5:
            printf("Ingrese la cantidad de pantallas a agregar: ");
            *pantallas += validarEntrada();
            printf("Ingrese la cantidad de procesadores a agregar: ");
            *procesadores += validarEntrada();
            printf("Ingrese la cantidad de memorias a agregar: ");
            *memorias += validarEntrada();
            printf("Ingrese la cantidad de altavoces a agregar: ");
            *altavoces += validarEntrada();
            printf("Inventario completo actualizado.\n");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
    }
}

int validarEntrada() {
    int valor;
    while (scanf("%d", &valor) != 1 || valor < 0) {
        printf("Entrada invalida. Ingrese un numero positivo: ");
        while (getchar() != '\n');
    }
    return valor;
}