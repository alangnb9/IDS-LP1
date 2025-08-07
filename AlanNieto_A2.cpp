// Lenguajes de Programación 1
// Actividad 2. Operaciones Básicas en C++
// Autor: Alan Nieto
// Fecha: 07 de agosto de 2025

#include <iostream> // Se carga la librería.

int main() {
    float num1, num2; // Se inicializan las variables.
    std::cout << "Ingrese el valor del primer número: "; // Se solicita al usuario ingresar un número.
    std::cin >> num1; // Se almacena el primer valor ingresado por el usuario.
    std::cout << "Ingrese el valor del segundo número: "; // Se solicita al usuario ingresar otro número.
    std::cin >> num2; // Se almacena el segundo valor ingresado por el usuario.

    float suma = num1 + num2; // Se define la variable suma.
    float resta = num1 - num2; // Se define la variable resta.
    float producto = num1*num2; // Se define la variable producto.
    float division = num1/num2; // Se define la variable división.

    std::cout << "La suma es: " << suma << std::endl; // Se muestra el resultado de la suma.
    std::cout << "La resta es: " << resta << std::endl; // Se muestra el resultado de la resta.
    std::cout << "La multiplicación es: " << producto << std::endl; // Se muestra el resultado de la multiplicación.
    std::cout << "La división es: " << division << std::endl; // Se muestra el resultado de la división.

    return 0; // Se finaliza el programa.
}