#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tareas.h"

// Crear una lista vacía
Nodo *CrearListaVacia() {
    return NULL;
}

// Crear un nodo para insertar en la lista
Nodo *CrearNodo(Tarea tarea) {
    Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
    nuevo_nodo->T = tarea;
    nuevo_nodo->Siguiente = NULL;
    return nuevo_nodo;
}

// Insertar un nodo al principio de la lista
void InsertarNodoEnLista(Nodo **Lista, Nodo *nodo) {
    nodo->Siguiente = *Lista;
    *Lista = nodo;
}

// Mostrar tareas en una lista
void MostrarLista(Nodo *Lista, const char *nombre_lista) {
    printf("***** %s *****\n", nombre_lista);
    while (Lista != NULL) {
        printf("ID: %d | Descripción: %s | Duración: %d minutos\n",
               Lista->T.TareaID, Lista->T.Descripcion, Lista->T.Duracion);
        Lista = Lista->Siguiente;
    }
}

// Mover una tarea de la lista de pendientes a la lista de realizadas
void MoverTarea(Nodo **ListaPendientes, Nodo **ListaRealizadas) {
    int id;
    printf("Ingrese el ID de la tarea a mover a realizadas: ");
    scanf("%d", &id);

    Nodo *anterior = NULL, *actual = *ListaPendientes;

    while (actual != NULL && actual->T.TareaID != id) {
        anterior = actual;
        actual = actual->Siguiente;
    }

    if (actual != NULL) {
        if (anterior == NULL) {
            *ListaPendientes = actual->Siguiente;
        } else {
            anterior->Siguiente = actual->Siguiente;
        }
        actual->Siguiente = *ListaRealizadas;
        *ListaRealizadas = actual;
        printf("Tarea movida a realizadas.\n");
    } else {
        printf("Tarea no encontrada.\n");
    }
}

// Consultar tarea por ID
void ConsultarTareaPorID(Nodo *ListaPendientes, Nodo *ListaRealizadas, int id) {
    Nodo *actual = ListaPendientes;
    while (actual != NULL) {
        if (actual->T.TareaID == id) {
            printf("Tarea pendiente: %s (Duración: %d minutos)\n", actual->T.Descripcion, actual->T.Duracion);
            return;
        }
        actual = actual->Siguiente;
    }

    actual = ListaRealizadas;
    while (actual != NULL) {
        if (actual->T.TareaID == id) {
            printf("Tarea realizada: %s (Duración: %d minutos)\n", actual->T.Descripcion, actual->T.Duracion);
            return;
        }
        actual = actual->Siguiente;
    }

    printf("Tarea no encontrada.\n");
}

// Consultar tarea por palabra clave
void ConsultarTareaPorPalabra(Nodo *ListaPendientes, Nodo *ListaRealizadas, const char *palabra) {
    Nodo *actual = ListaPendientes;
    while (actual != NULL) {
        if (strstr(actual->T.Descripcion, palabra) != NULL) {
            printf("Tarea pendiente: %s (Duración: %d minutos)\n", actual->T.Descripcion, actual->T.Duracion);
        }
        actual = actual->Siguiente;
    }

    actual = ListaRealizadas;
    while (actual != NULL) {
        if (strstr(actual->T.Descripcion, palabra) != NULL) {
            printf("Tarea realizada: %s (Duración: %d minutos)\n", actual->T.Descripcion, actual->T.Duracion);
        }
        actual = actual->Siguiente;
    }
}

// Función para cargar tareas pendientes
void CargarTareas(Nodo **ListaPendientes) {
    int continuar = 1;
    int id = 1000;
    char descripcion[100];
    int duracion;

    while (continuar) {
        printf("Ingrese descripción de la tarea: ");
        getchar();  // Limpiar buffer
        fgets(descripcion, 100, stdin);
        descripcion[strcspn(descripcion, "\n")] = 0;  // Eliminar salto de línea

        printf("Ingrese duración de la tarea (entre 10 y 100): ");
        scanf("%d", &duracion);

        Tarea nuevaTarea = {id++, descripcion, duracion};
        Nodo *nuevoNodo = CrearNodo(nuevaTarea);
        InsertarNodoEnLista(ListaPendientes, nuevoNodo);

        printf("¿Desea ingresar otra tarea? (1 = Sí, 0 = No): ");
        scanf("%d", &continuar);
    }
}
