#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 10
#define MAX_CLIENTES 5

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} Cliente;

Producto crearProducto(int productoID) {
    Producto producto;
    producto.ProductoID = productoID;
    producto.Cantidad = rand() % 10 + 1;  // Cantidad aleatoria entre 1 y 10
    producto.TipoProducto = TiposProductos[rand() % 5];
    producto.PrecioUnitario = (rand() % 91 + 10);  // Precio entre 10 y 100
    return producto;
}

Cliente crearCliente(int clienteID) {
    Cliente cliente;
    cliente.ClienteID = clienteID;
    cliente.NombreCliente = (char*)malloc(100 * sizeof(char));

    printf("Ingrese el nombre del cliente: ");
    fgets(cliente.NombreCliente, 100, stdin);
    cliente.NombreCliente[strcspn(cliente.NombreCliente, "\n")] = '\0';  // Eliminar salto de línea

    cliente.CantidadProductosAPedir = rand() % 5 + 1;  // Cantidad de productos aleatoria entre 1 y 5
    cliente.Productos = (Producto*)malloc(cliente.CantidadProductosAPedir * sizeof(Producto));

    for (int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        cliente.Productos[i] = crearProducto(i + 1);
    }

    return cliente;
}

float calcularCosto(Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarCliente(Cliente cliente) {
    printf("Cliente ID: %d, Nombre: %s\n", cliente.ClienteID, cliente.NombreCliente);
    float totalCliente = 0;
    for (int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        float costo = calcularCosto(cliente.Productos[i]);
        printf("Producto ID: %d, Tipo: %s, Cantidad: %d, Precio Unitario: %.2f, Costo Total: %.2f\n",
               cliente.Productos[i].ProductoID,
               cliente.Productos[i].TipoProducto,
               cliente.Productos[i].Cantidad,
               cliente.Productos[i].PrecioUnitario,
               costo);
        totalCliente += costo;
    }
    printf("Total a pagar por el cliente: %.2f\n", totalCliente);
}

int main() {
    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    getchar();  // Limpiar el salto de línea

    Cliente *clientes = (Cliente*)malloc(cantidadClientes * sizeof(Cliente));

    for (int i = 0; i < cantidadClientes; i++) {
        clientes[i] = crearCliente(i + 1);
        mostrarCliente(clientes[i]);
    }

    free(clientes);
    return 0;
}
