// Lenguajes de Programación 1
// Actividad 3. Cálculo de RFC
// Autor: Alan Nieto
// Fecha: 10 de agosto de 2025

#include <iostream> // Se cargan las librerías.
#include <vector>
#include <string>
#include <cctype>

// Las palabras inconvenientes se obtuvieron de la siguiente lista:
// https://solucionfactible.com/sfic/resources/files/palabrasInconvenientes-rfc.pdf

const std::vector<std::string> palabras_inconvenientes = {
    "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COJA", "COJE", "COJI",
    "COJO", "CULO", "FETO", "GUEY", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KOGE", "KOJO", "KAKA",
    "KULO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MION", "MOCO", "MULA", "PEDA", "PEDO", "PENE",
    "PUTA", "PUTO", "QULO", "RATA", "RUIN"
};

// Obtener la primera vocal interna de un apellido
char PrimeraVocal(const std::string& apellido) {
    for (size_t i = 1; i < apellido.size(); ++i) {
        if (isalpha(static_cast<unsigned char>(apellido[i]))) {
            char letra = toupper(static_cast<unsigned char>(apellido[i]));
            if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
                return letra;
            }
        }
    }
    return 'X';
}

// Corregir palabras inconvenientes en el RFC
std::string corregirRFC(std::string rfc) {
    if (rfc.length() >= 4) {
        std::string letras = rfc.substr(0, 4);
        for (const std::string& palabra : palabras_inconvenientes) {
            if (letras == palabra) {
                rfc[3] = 'X';
                break;
            }
        }
    }
    return rfc;
}

// Generar el RFC
std::string crearRFC(const std::string& apellidoPaterno, 
                    const std::string& apellidoMaterno, 
                    const std::string& nombre, 
                    const std::string& fecha) {
    std::string rfc;
    
    // Primera letra y vocal del apellido paterno
    if (!apellidoPaterno.empty()) {
        rfc += toupper(static_cast<unsigned char>(apellidoPaterno[0]));
        rfc += PrimeraVocal(apellidoPaterno);
    } else {
        rfc += "XX";
    }
    
    // Primera letra del apellido materno
    if (!apellidoMaterno.empty()) {
        rfc += toupper(static_cast<unsigned char>(apellidoMaterno[0]));
    } else {
        rfc += 'X';
    }
    
    // Primera letra del nombre
    if (!nombre.empty()) {
        rfc += toupper(static_cast<unsigned char>(nombre[0]));
    } else {
        rfc += 'X';
    }
    
    // Fecha
    if (fecha.length() >= 10) {        
        rfc += fecha.substr(8, 2); // Año        
        rfc += fecha.substr(3, 2); // Mes        
        rfc += fecha.substr(0, 2); // Día
    } else {
        rfc += "000000";
    }
    
    // Verifica las palabras inconvenientes
    rfc = corregirRFC(rfc);
    
    // Devuelve los primeros 10 caracteres
    return rfc.substr(0, 10);
}

int main() {
    std::string apellidoPaterno, apellidoMaterno, nombre, fecha;
    
    std::cout << "CÁLCULO DE RFC\n";
    std::cout << "Ingrese su apellido paterno: "; // Se solicitan los datos del usuario.
    std::getline(std::cin, apellidoPaterno);
    
    std::cout << "Ingrese su apellido materno: ";
    std::getline(std::cin, apellidoMaterno);
    
    std::cout << "Ingrese su nombre: ";
    std::getline(std::cin, nombre);
    
    std::cout << "Ingrese su fecha de nacimiento en el siguiente formato (DD/MM/AAAA): ";
    std::getline(std::cin, fecha);
    
    std::string rfc = crearRFC(apellidoPaterno, apellidoMaterno, nombre, fecha); // Se genera el RFC.
    
    std::cout << "El RFC es: " << rfc << std::endl; // Se presenta el RFC generado.
    
    return 0; // Se finaliza el programa.
}