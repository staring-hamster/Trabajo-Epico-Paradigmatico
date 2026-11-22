# Archivo de compilacion automatica de CMake.

# La version minima requerida de CMake para poder compilar
cmake_minimum_required(VERSION 3.10.0)

# El nombre del proyecto
project(Administrador-Tareas)

# Establecemos un estandar de C++ (en este caso C++ 23 esta perfecto, viva C++ moderno :D )
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aqui se pone el nombre del ejecutable que va a ser compilado,
# Ademas de declarar los archivos a .cpp al Linker.
add_executable(tareador 
        src/main.cpp
        src/tarea.cpp
)

# Declaramos la carpeta de los archivos de encabezado, tambien para el Linker :)
target_include_directories(tareador PRIVATE include)