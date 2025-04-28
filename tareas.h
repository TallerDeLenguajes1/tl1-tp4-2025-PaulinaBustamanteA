// Estructura de tarea
typedef struct Tarea {
    int TareaID;        // Numérico autoincremental comenzando en 1000
    char *Descripcion;  // Descripción de la tarea
    int Duracion;       // Duración en minutos, entre 10 y 100
} Tarea;

// Nodo para lista enlazada
typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

// Funciones de manipulación de listas enlazadas
Nodo *CrearListaVacia();
Nodo *CrearNodo(Tarea tarea);
void InsertarNodoEnLista(Nodo **Lista, Nodo *nodo);
void MostrarLista(Nodo *Lista, const char *nombre_lista);
void MoverTarea(Nodo **ListaPendientes, Nodo **ListaRealizadas);
void ConsultarTareaPorID(Nodo *ListaPendientes, Nodo *ListaRealizadas, int id);
void ConsultarTareaPorPalabra(Nodo *ListaPendientes, Nodo *ListaRealizadas, const char *palabra);
