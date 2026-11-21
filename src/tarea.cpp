/*
    Definicion de los metodos de Tarea, proveniente de tarea.hpp
*/

#include "tarea.hpp"

// Constructor
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
