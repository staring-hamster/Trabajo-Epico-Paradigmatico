#include <iostream>
#include <print>
#include <string>
#include <vector>

#include "tarea.hpp"

using namespace std;

void agregarTarea(vector<Tarea> &listaTareas){
    string nombre;
    string descripcion;

    println("Ingrese el nombre de la tarea: ");
    cin >> nombre;
    println("Ingrese la descripcion de la tarea: ");
    cin >> descripcion;
    
    if (nombre.empty() || descripcion.empty()){
        print("No se puede tener un nombre o descripcion vacios.\n");
        return;
    }

    Tarea nuevaTarea(nombre, descripcion, false);
    listaTareas.push_back(nuevaTarea);
}

void imprimirTareas(vector<Tarea> &listaTareas){
    for (int i = 0; i < listaTareas.size(); i++){
        Tarea &tarea = listaTareas.at(i);
        
        string nombreTarea = tarea.getNombre();
        string descripcionTarea = tarea.getDescripcion();
        string estadoTarea = tarea.getEstado() ? "Terminada" : "Pendiente";

        println(
            "{}. Nombre: {} \nDescripcion: {} \nEstado: {}\n", 
            to_string(i + 1), 
            nombreTarea, 
            descripcionTarea,
            estadoTarea
        );
    }
}

void cambiarEstadoTarea(vector<Tarea> &listaTareas){
    println("Que tarea desea cambiar?");

    int eleccionTarea;
    cin >> eleccionTarea;

    if (eleccionTarea > listaTareas.size() || eleccionTarea < 0){
        println("Se ha escogido una tarea no existente.");
        return;
    }

    println("1. Terminada \n2. Pendiente");

    int eleccionEstado;
    cin >> eleccionEstado;

    if (eleccionEstado != 1 && eleccionEstado != 2){
        println("Estado invalido.");
        return;
    }

    bool estadoTarea = (eleccionEstado == 1) ? true : false;

    Tarea &tarea = listaTareas.at(eleccionTarea - 1);
    tarea.setEstado(estadoTarea);
}

int main(){
    vector<Tarea> listaTareas;

    bool ejecutando = true;

    do {
        println("\n---- GESTOR DE TAREAS 3000 ----\n1. Agregar una tarea\n2. Listar tareas\n3. Cambiar estado de tarea\n4. Salir\n");

        int opcion;
        cin >> opcion;

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
                println("Opcion invalida, intente otra vez.\n");
                break;
        }
    }
    while (ejecutando);
    
    return 0;
}