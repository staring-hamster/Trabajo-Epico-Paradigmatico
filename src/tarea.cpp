/*
    Definicion de los metodos de Tarea, proveniente de tarea.hpp
*/

#include "tarea.hpp"

// Constructor de la clase Tarea, que recibe el nombre, la descripcion y el estado de la tarea, y los asigna a los atributos de la clase.
Tarea::Tarea(string nombre, string descripcion, bool estado)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->estado = estado;
}

// Getters

string Tarea::getNombre()
{
    return nombre;
}

string Tarea::getDescripcion()
{
    return descripcion;
}

bool Tarea::getEstado()
{
    return estado;
}

// Setter

void Tarea::setEstado(bool estado)
{
    this->estado = estado;
}
