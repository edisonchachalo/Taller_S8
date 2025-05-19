void ingresarProductos(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int cantidad);
void editarNombre(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int cantidad);
void eliminarProducto(char productos[][20], int cantidades[][4], int *tiemposFabricacion, int *cantidad);
int evaluarPedido(int cantidad, int tiempoEntrega, int *productoSeleccionado, int tiempoFabricacion, int *pantallas, int *procesadores, int *memorias, int *altavoces);
void reabastecerInventario(int *pantallas, int *procesadores, int *memorias, int *altavoces);
int validarEntrada();