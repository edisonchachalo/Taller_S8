#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion, cantidad, tiempoEntrega, productoSeleccionado;
    int pantallas, procesadores, memorias, altavoces;
    char productos[5][20];  // Máximo 5 productos
    int cantidades[5][4];   // Almacenar los componentes por producto
    int tiemposFabricacion[5];
    int cantidadProductos = 0;

    // Solicitar inventario inicial
    printf("\n--- Configuracion de Inventario Inicial ---\n");
    printf("Ingrese la cantidad inicial de pantallas: ");
    pantallas = validarEntrada();
    printf("Ingrese la cantidad inicial de procesadores: ");
    procesadores = validarEntrada();
    printf("Ingrese la cantidad inicial de memorias: ");
    memorias = validarEntrada();
    printf("Ingrese la cantidad inicial de altavoces: ");
    altavoces = validarEntrada();

    do {
        printf("\n--- Sistema de Produccion ---\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar productos\n");
        printf("3. Eliminar productos\n");
        printf("4. Ingresar pedido\n");
        printf("5. Reabastecer inventario\n");
        printf("6. Ver inventario actual\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        opcion = validarEntrada();

        switch (opcion) {
            case 1:
                printf("Ingrese la cantidad de productos: ");
                cantidadProductos = validarEntrada();
                ingresarProductos(productos, cantidades, tiemposFabricacion, cantidadProductos);
                break;

            case 2:
                if (cantidadProductos == 0) {
                    printf("No hay productos registrados. Ingrese productos primero.\n");
                    break;
                }
                editarNombre(productos, cantidades, tiemposFabricacion, cantidadProductos);
                break;

            case 3:
                if (cantidadProductos == 0) {
                    printf("No hay productos registrados. Ingrese productos primero.\n");
                    break;
                }
                eliminarProducto(productos, cantidades, tiemposFabricacion, &cantidadProductos);
                break;

            case 4:
                if (cantidadProductos == 0) {
                    printf("No hay productos registrados. Ingrese productos primero.\n");
                    break;
                }
                if (pantallas == 0 || procesadores == 0 || memorias == 0 || altavoces == 0) {
                    printf("El inventario de componentes esta vacio. Debe reabastecer antes de realizar pedidos.\n");
                    break;
                }

                
                printf("Seleccione el producto para el pedido:\n");
                for (int i = 0; i < cantidadProductos; i++) {
                    printf("%d. %s\n", i + 1, productos[i]);
                }
                printf(">> ");
                productoSeleccionado = validarEntrada();
                if (productoSeleccionado < 1 || productoSeleccionado > cantidadProductos) {
                    printf("Opcion invalida.\n");
                    break;
                }

                printf("Ingrese la cantidad a fabricar: ");
                cantidad = validarEntrada();
                printf("Ingrese el tiempo de entrega (minutos): ");
                tiempoEntrega = validarEntrada();

                int resultado = evaluarPedido(cantidad, tiempoEntrega, cantidades[productoSeleccionado - 1], tiemposFabricacion[productoSeleccionado - 1], &pantallas, &procesadores, &memorias, &altavoces);
                while (resultado == -1) {
                    printf("Ingrese una nueva cantidad a fabricar: ");
                    cantidad = validarEntrada();
                    printf("Ingrese un nuevo tiempo de entrega (minutos): ");
                    tiempoEntrega = validarEntrada();
                    resultado = evaluarPedido(cantidad, tiempoEntrega, cantidades[productoSeleccionado - 1], tiemposFabricacion[productoSeleccionado - 1], &pantallas, &procesadores, &memorias, &altavoces);
                }
                break;

            case 5:
                reabastecerInventario(&pantallas, &procesadores, &memorias, &altavoces);
                break;

            case 6:
                printf("\n--- Inventario Actual ---\n");
                printf("Pantallas: %d\n", pantallas);
                printf("Procesadores: %d\n", procesadores);
                printf("Memorias: %d\n", memorias);
                printf("Altavoces: %d\n", altavoces);
                break;

            case 7:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida, intente nuevamente.\n");
                break;
        }

    } while (opcion != 7);

    return 0;
}