// ConsoleApplication2 hoy 2 trabajo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// COMP-120 C9 Programación
// Trabajo Grupal
// Propósito: Este programa tiene como objetivo simular la gestión de una biblioteca utilizando programación orientada a objetos.
// Nombre: Gabriel Colmenares, Christian A. Matías Alvarez, Jorge L. Pina Floresi
// Clase: 7
// Fecha: 1110/2024

#include <iostream>  // Biblioteca para entrada y salida de datos (cout, cin)
#include <string>    // Biblioteca para trabajar con cadenas de texto (string)
#include <cstdlib>   // Biblioteca para funciones generales, como exit()

using namespace std;

// Definir el tamaño maximo de estantes y bibliotecarios
const int MAX_ESTANTES = 10;               // Establece el numero maximo de estantes en la biblioteca.
const int MAX_BIBLIOTECARIOS = 5;           // Define el número máximo de bibliotecarios que se pueden registrar.
const int MAX_LIBROS_POR_ESTANTE = 10;     // Establece el número máximo de libros que puede almacenar cada estante.

// Clase Libro: Representa un libro en la biblioteca.
class Libro {
public:
    string titulo; // Titulo del libro
    string autor;  // Autor del libro

    // Constructor de la clase Libro
    // Inicializa el titulo y autor del libro cuando se crea un objeto.
    Libro(string t = "", string a = "") : titulo(t), autor(a) {}

    // Destructor de la clase Libro
    // Este destructor no realiza ninguna accion especifica, pero puede ser útil si se usa memoria dinamica.
    ~Libro() {}

    // Metodo para mostrar la informacion de un libro
    void mostrarInfo() const {
        cout << "Titulo: " << titulo << ", Autor: " << autor << endl;
    }
};

// Clase Estante: Representa un estante donde se almacenan los libros.
class Estante {
public:
    Libro* libros[MAX_LIBROS_POR_ESTANTE];  // Arreglo de punteros a objetos de la clase Libro
    int contadorLibros = 0;  // Número de libros actuales en el estante

    // Constructor de la clase Estante
    // Inicializa los punteros de los libros en nullptr para indicar que no hay libros almacenados.
    Estante() {
        for (int i = 0; i < MAX_LIBROS_POR_ESTANTE; i++) {
            libros[i] = nullptr;  // Inicializa todos los punteros a nullptr
        }
    }

    // Método para agregar un libro al estante
    void agregarLibro(const Libro& libro) {
        if (contadorLibros < MAX_LIBROS_POR_ESTANTE) {
            libros[contadorLibros] = new Libro(libro);  // Crea un nuevo objeto Libro en la memoria dinamica
            contadorLibros++;
            cout << "Libro '" << libro.titulo << "' agregado al estante." << endl;
        }
        else {
            cout << "Estante lleno. No se pueden agregar mas libros." << endl;
        }
    }

    // Método para eliminar un libro del estante
    void eliminarLibro(const string& titulo) {
        for (int i = 0; i < contadorLibros; i++) {
            if (libros[i] && libros[i]->titulo == titulo) {
                delete libros[i];  // Libera la memoria del libro eliminado
                libros[i] = nullptr;

                // Reorganiza los libros en el estante para evitar huecos
                for (int j = i; j < contadorLibros - 1; j++) {
                    libros[j] = libros[j + 1];
                }
                libros[contadorLibros - 1] = nullptr;
                contadorLibros--;

                cout << "Libro '" << titulo << "' eliminado del estante." << endl;
                return;
            }
        }
        cout << "Error: El libro '" << titulo << "' no se encuentra en este estante." << endl;
    }

    // Metodo para mostrar los libros de un estante
    void mostrarLibros() const {
        if (contadorLibros == 0) {
            cout << "No hay libros en este estante." << endl;
        }
        else {
            for (int i = 0; i < contadorLibros; i++) {
                if (libros[i]) {
                    libros[i]->mostrarInfo();  // Muestra la informacion de cada libro almacenado
                }
            }
        }
    }

    // Destructor de la clase Estante
    // Libera la memoria de los libros almacenados en el estante cuando el estante es destruido.
    ~Estante() {
        for (int i = 0; i < contadorLibros; i++) {
            delete libros[i];  // Libera la memoria de cada libro
        }
    }
};

// Clase Bibliotecario: Representa un bibliotecario en la biblioteca.
class Bibliotecario {
public:
    string nombre; // Nombre del bibliotecario

    // Constructor de la clase Bibliotecario
    Bibliotecario(string n = "") : nombre(n) {}

    // Metodo para mostrar la informacion de un bibliotecario
    void mostrarInfo() const {
        cout << "Bibliotecario: " << nombre << endl;
    }

    // Destructor de la clase Bibliotecario
    ~Bibliotecario() {
        // El destructor no realiza ninguna acción especifica
    }
};

// Clase Biblioteca: Representa la biblioteca y maneja los estantes y bibliotecarios.
class Biblioteca {
public:
    Estante estantes[MAX_ESTANTES];             // Arreglo de estantes en la biblioteca
    Bibliotecario bibliotecarios[MAX_BIBLIOTECARIOS];  // Arreglo de bibliotecarios registrados
    int contadorEstantes = 0;  // Numero actual de estantes en la biblioteca
    int contadorBibliotecarios = 0;  // Numero de bibliotecarios registrados

    // Metodo para agregar un nuevo estante
    void agregarEstante() {
        if (contadorEstantes < MAX_ESTANTES) {
            estantes[contadorEstantes++] = Estante();  // Crea un nuevo estante
            cout << "Nuevo estante agregado a la biblioteca." << endl;
        }
        else {
            cout << "No se pueden agregar mas estantes. Biblioteca llena." << endl;
        }
    }

    // Metodo para agregar un libro a un estante especifico
    void agregarLibroAEstante(int estanteIndex, const Libro& libro) {
        if (estanteIndex < 1 || estanteIndex > contadorEstantes) {
            cout << "Error: Estante no valido." << endl;
        }
        else {
            estantes[estanteIndex - 1].agregarLibro(libro);  // Llama al metodo para agregar el libro en el estante correspondiente
        }
    }

    // Método para registrar un bibliotecario
    void registrarBibliotecario(const string& nombre) {
        if (contadorBibliotecarios < MAX_BIBLIOTECARIOS) {
            bibliotecarios[contadorBibliotecarios++] = Bibliotecario(nombre);  // Registra un nuevo bibliotecario
            cout << "Bibliotecario '" << nombre << "' registrado." << endl;
        }
        else {
            cout << "No se pueden registrar mas bibliotecarios. Ya hay el maximo permitido." << endl;
        }
    }

    // Método para eliminar un bibliotecario
    void eliminarBibliotecario(const string& nombre) {
        bool encontrado = false;
        for (int i = 0; i < contadorBibliotecarios; i++) {
            if (bibliotecarios[i].nombre == nombre) {
                for (int j = i; j < contadorBibliotecarios - 1; j++) {
                    bibliotecarios[j] = bibliotecarios[j + 1];
                }
                contadorBibliotecarios--;
                cout << "Bibliotecario '" << nombre << "' eliminado." << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Error: Bibliotecario '" << nombre << "' no encontrado." << endl;
        }
    }

    // Método para mostrar la lista de bibliotecarios
    void mostrarBibliotecarios() const {
        if (contadorBibliotecarios == 0) {
            cout << "No hay bibliotecarios registrados." << endl;
        }
        else {
            for (int i = 0; i < contadorBibliotecarios; i++) {
                bibliotecarios[i].mostrarInfo();
            }
        }
    }

    // Método para mostrar los libros en los estantes
    void mostrarEstantes() const {
        if (contadorEstantes == 0) {
            cout << "No hay estantes en la biblioteca." << endl;
        }
        else {
            for (int i = 0; i < contadorEstantes; i++) {
                cout << "Estante " << i + 1 << ":" << endl;
                estantes[i].mostrarLibros();  // Muestra los libros almacenados en el estante
            }
        }
    }

    // Destructor de la clase Biblioteca
    ~Biblioteca() {
        // El destructor no realiza ninguna acción adicional
    }
};

// Función para leer enteros con validación
int leerEntero(const string& mensaje) {
    int numero;
    cout << mensaje;
    while (true) {
        cin >> numero;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no valida. " << mensaje;
        }
        else {
            break;
        }
    }
    return numero;
}

// Funcion para volver al menu
void volvermenu() {
    string pregunta;
    cout << "\nDeseas volver al menu?" << endl;
    cout << "Escoja su respuesta: ";
    cin >> pregunta;

    if (pregunta == "si" || pregunta == "Si" || pregunta == "SI") {
        cin.ignore(); // Ignora el salto de línea
        system("cls");
    }
    else {
        cout << "Gracias por usar nuestros servicios" << endl;
        exit(0); // Cierra el programa
    }
}

// Función principal
int main() {
    char menu;
    Biblioteca biblioteca;

    do {
        cout << "\n--- Menu Biblioteca ---\n";
        cout << "1. Agregar Estante\n";
        cout << "2. Agregar Libro a Estante\n";
        cout << "3. Registrar Bibliotecario\n";
        cout << "4. Eliminar Bibliotecario\n";
        cout << "5. Mostrar Bibliotecarios\n";
        cout << "6. Mostrar Estantes\n";
        cout << "7. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> menu;

        switch (menu) {
        case '1':
            biblioteca.agregarEstante();
            break;
        case '2': {
            int estanteIndex = leerEntero("Ingrese el numero de estante (1 - " + to_string(MAX_ESTANTES) + "): ");
            string titulo, autor;
            cout << "Ingrese el titulo del libro: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);
            Libro libro(titulo, autor);
            biblioteca.agregarLibroAEstante(estanteIndex, libro);
            break;
        }
        case '3': {
            string nombre;
            cout << "Ingrese el nombre del bibliotecario: ";
            cin.ignore();
            getline(cin, nombre);
            biblioteca.registrarBibliotecario(nombre);
            break;
        }
        case '4': {
            string nombre;
            cout << "Ingrese el nombre del bibliotecario a eliminar: ";
            cin.ignore();
            getline(cin, nombre);
            biblioteca.eliminarBibliotecario(nombre);
            break;
        }
        case '5':
            biblioteca.mostrarBibliotecarios();
            volvermenu();
            break;
        case '6':
            biblioteca.mostrarEstantes();
            volvermenu();
            break;
        case '7':
            cout << "Gracias por usar el sistema de la biblioteca." << endl;
            return 0;
            break;
        default:
            cout << "Opcion no valida. Por favor intente de nuevo." << endl;
            break;
        }
        
    } while (menu != '7');

   
}
