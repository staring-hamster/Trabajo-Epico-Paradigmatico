// Incluimos las librerias necesarias para el programa, como iostream para la entrada y salida de datos, print para imprimir de manera formateada, string para manejar cadenas de texto, y vector para manejar listas de tareas.
// "print" es una funcion de C++23 que nos permite imprimir de manera formateada, similar a printf en C, pero con la ventaja de que podemos usar variables directamente en la cadena de texto, usando {} como marcadores de posicion.
// Mejor que cout en mi opinon xd
#include <iostream>
#include <print>
#include <string>
#include <vector>

// Incluimos la clase Tarea, que nos permite crear objetos de tipo Tarea, con nombre, descripcion y estado (terminada o pendiente).
#include "tarea.hpp"

// Usamos el espacio de nombres std, para no tener que escribir std:: antes de cada funcion o clase de la libreria estandar.
using namespace std;

// Esta funcion agrega una tarea a la lista de tareas, pidiendo al usuario el nombre y la descripcion de la tarea.
void agregarTarea(vector<Tarea> &listaTareas){
    string nombre;
    string descripcion;

    // Le pedimos al usuario que ingrese el nombre y la descripcion de la tarea, y los guardamos en las variables correspondientes.
    println("\nIngrese el nombre de la tarea: ");
    cin >> nombre;
    println("\nIngrese la descripcion de la tarea: ");
    cin >> descripcion;
    
    // Comprobamos que el nombre y la descripcion no esten vacios, si lo estan, no se agrega la tarea a la lista.
    if (nombre.empty() || descripcion.empty()){
        println("\nNo se puede tener un nombre o descripcion vacios.");
        return;
    }

    // Creamos una nueva tarea con el nombre y la descripcion ingresados por el usuario, y la agregamos a la lista de tareas.
    Tarea nuevaTarea(nombre, descripcion, false);
    listaTareas.push_back(nuevaTarea);
}

void imprimirTareas(vector<Tarea> &listaTareas){
    // Iteramos sobre la lista de tareas, y por cada tarea, imprimimos su nombre, descripcion y estado (terminada o pendiente).
    for (int i = 0; i < listaTareas.size(); i++){
        Tarea &tarea = listaTareas.at(i);
        
        string nombreTarea = tarea.getNombre();
        string descripcionTarea = tarea.getDescripcion();
        // Usemos un operador ternario para determinar el estado de la tarea, si es true, es "Terminada", si es false, es "Pendiente".
        string estadoTarea = tarea.getEstado() ? "Terminada" : "Pendiente";

        // Imprimimos la informacion de la tarea, usando el metodo println de la libreria print, que nos permite imprimir de manera formateada.
        println(
            "\n{}. Nombre: {} \nDescripcion: {} \nEstado: {}\n", 
            to_string(i + 1), 
            nombreTarea, 
            descripcionTarea,
            estadoTarea
        );
    }
}

// Esta funcion cambia el estado de una tarea, pidiendo al usuario que ingrese el numero de la tarea que desea cambiar, y el nuevo estado (terminada o pendiente).
void cambiarEstadoTarea(vector<Tarea> &listaTareas){
    println("\nQue tarea desea cambiar?");

    int eleccionTarea;
    cin >> eleccionTarea;

    // Comprobamos que la tarea elegida exista, si no existe, mostramos un mensaje de error y salimos de la funcion.
    if (eleccionTarea > listaTareas.size() || eleccionTarea < 0){
        println("\nSe ha escogido una tarea no existente.");
        return;
    }

    println("\n1. Terminada \n2. Pendiente");

    int eleccionEstado;
    cin >> eleccionEstado;

    // Comprobamos que el estado elegido sea valido, si no es valido, mostramos un mensaje de error y salimos de la funcion.
    if (eleccionEstado != 1 && eleccionEstado != 2){
        println("Estado invalido.");
        return;
    }

    // Usamos un operador ternario para determinar el nuevo estado de la tarea, si el usuario eligio 1, el estado sera true (terminada), si eligio 2, el estado sera false (pendiente).
    bool estadoTarea = (eleccionEstado == 1) ? true : false;

    // Obtenemos la tarea elegida por el usuario, y cambiamos su estado usando el metodo setEstado de la clase Tarea.
    // El simbolo & nos permite obtener una referencia a la tarea, en lugar de una copia, para que los cambios se reflejen en la lista de tareas.
    Tarea &tarea = listaTareas.at(eleccionTarea - 1);
    tarea.setEstado(estadoTarea);
}

int main(){
    // Creamos una lista de tareas, que sera un vector de objetos de tipo Tarea.
    // El vector nos permite agregar y eliminar tareas dinamicamente, sin tener que preocuparnos por el tamaño del array.
    // C++ es una magia ;)
    vector<Tarea> listaTareas;

    bool ejecutando = true;

    // Usamos un bucle do-while para mostrar el menu de opciones al usuario, y ejecutar la opcion elegida, hasta que el usuario decida salir del programa.
    do {
        println("\n---- GESTOR DE TAREAS 3000 ----\n1. Agregar una tarea\n2. Listar tareas\n3. Cambiar estado de tarea\n4. Salir");

        int opcion;
        cin >> opcion;

        // Usamos un switch para ejecutar la opcion elegida por el usuario, llamando a la funcion correspondiente, y pasando la lista de tareas como parametro.
        switch (opcion){
            case 1:
                agregarTarea(listaTareas);
                break;
            case 2:
                imprimirTareas(listaTareas);
                break;
            case 3:
                cambiarEstadoTarea(listaTareas);
                break;
            case 4:
                ejecutando = false;
                break;
            default:
                println("\nOpcion invalida, intente otra vez.");
                break;
        }
    }
    while (ejecutando);
    
    return 0;
}