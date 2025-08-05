// Lenguajes de Programación 1
// Actividad 1. Cálculo de edad en C++
// Autor: Alan Nieto
// Fecha: 04 de agosto de 2025

#include <iostream> // Se carga la librería.

int main() {
    int edad; // Se inicializa la variable edad.
    std::cout << "Ingrese su edad: "; // Se solicita ingresar la edad.
    std::cin >> edad; // Aqui se almacena el valor ingresado.

    if(edad >= 18) { // Si el número es mayor o igual a 18 
                    // se muestra el siguiente mensaje.
        std::cout << "El usuario es mayor de edad." << std::endl;
    } else {    // si no lo es, se muestra este otro mensaje.
        std::cout << "El usuario es menor de edad." << std::endl;
    }
    return 0;   // Se finaliza el programa.
}