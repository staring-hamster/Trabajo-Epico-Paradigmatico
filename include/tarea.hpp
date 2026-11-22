/* 
    Directiva del preprocesador para hacer que este header se 
    incluya solo UNA vez en el programa, evitando bugs
*/
#pragma once

// Headers estandar
#include <string>

using namespace std;

/*
    Declaracion de la clase tarea, que va a contener:
    - Nombre
    - Descripcion
    - Estado de completacion
*/
class Tarea {
    private:
        // Aqui van las variables privadas, queremos que sean de solo lectura.
        string nombre;
        string descripcion;
        bool estado;

    public:
        // Declaracion del constructor

        Tarea(string nombre, string descripcion, bool estado);

        // Declaracion de getters, para mantener la encapsulacion
        
        string getNombre();
        string getDescripcion();

        bool getEstado();
        void setEstado(bool estado);

};
