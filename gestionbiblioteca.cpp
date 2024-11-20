// COMP-120 C9 Programación
// Trabajo Grupal
// Propósito: Este programa tiene como objetivo simular la gestión de una biblioteca utilizando programación orientada a objetos.
// Nombre: Gabriel Colmenares, Christian A. Matías Alvarez, Jorge L. Pina Flores
// Clase: 7
// Fecha: 11/10/2024

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Definir el tamaño máximo de estantes y bibliotecarios
const int MAX_ESTANTES = 10;
const int MAX_BIBLIOTECARIOS = 5;
const int MAX_LIBROS_POR_ESTANTE = 10; // Máximo de libros por estante

// Clase Libro
class Libro {
public:
    string titulo;
    string autor;

    Libro(string t = "", string a = "") : titulo(t), autor(a) {}

    ~Libro() {
        // El destructor no imprime ningún mensaje
    }

    void mostrarInfo() const {
        cout << "Titulo: " << titulo << ", Autor: " << autor << endl;
    }
};

// Clase Estante
class Estante {
public:
    Libro* libros[MAX_LIBROS_POR_ESTANTE]; // Arreglo de punteros a libros
    int contadorLibros = 0;

    Estante() {
        for (int i = 0; i < MAX_LIBROS_POR_ESTANTE; i++) {
            libros[i] = nullptr;
        }
    }

    void agregarLibro(const Libro& libro) {
        if (contadorLibros < MAX_LIBROS_POR_ESTANTE) {
            libros[contadorLibros] = new Libro(libro);
            contadorLibros++;
            cout << "Libro '" << libro.titulo << "' agregado al estante." << endl;
        } else {
            cout << "Estante lleno. No se pueden agregar más libros." << endl;
        }
    }

    void eliminarLibro(const string& titulo) {
        for (int i = 0; i < contadorLibros; i++) {
            if (libros[i] && libros[i]->titulo == titulo) {
                delete libros[i];
                libros[i] = nullptr;

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

    void mostrarLibros() const {
        if (contadorLibros == 0) {
            cout << "No hay libros en este estante." << endl;
        } else {
            for (int i = 0; i < contadorLibros; i++) {
                if (libros[i]) {
                    libros[i]->mostrarInfo();
                }
            }
        }
    }

    ~Estante() {
        for (int i = 0; i < contadorLibros; i++) {
            delete libros[i];
        }
        // El destructor no imprime ningún mensaje
    }
};

// Clase Bibliotecario
class Bibliotecario {
public:
    string nombre;

    Bibliotecario(string n = "") : nombre(n) {}

    void mostrarInfo() const {
        cout << "Bibliotecario: " << nombre << endl;
    }

    ~Bibliotecario() {
        // El destructor no imprime ningún mensaje
    }
};

// Clase Biblioteca
class Biblioteca {
public:
    Estante estantes[MAX_ESTANTES];
    Bibliotecario bibliotecarios[MAX_BIBLIOTECARIOS];
    int contadorEstantes = 0;
    int contadorBibliotecarios = 0;

    void agregarEstante() {
        if (contadorEstantes < MAX_ESTANTES) {
            estantes[contadorEstantes++] = Estante();
            cout << "Nuevo estante agregado a la biblioteca." << endl;
        } else {
            cout << "No se pueden agregar más estantes. Biblioteca llena." << endl;
        }
    }

    void agregarLibroAEstante(int estanteIndex, const Libro& libro) {
        if (estanteIndex < 1 || estanteIndex > contadorEstantes) {
            cout << "Error: Estante no valido." << endl;
        } else {
            estantes[estanteIndex - 1].agregarLibro(libro);
        }
    }

    void registrarBibliotecario(const string& nombre) {
        if (contadorBibliotecarios < MAX_BIBLIOTECARIOS) {
            bibliotecarios[contadorBibliotecarios++] = Bibliotecario(nombre);
            cout << "Bibliotecario '" << nombre << "' registrado." << endl;
        } else {
            cout << "No se pueden registrar mas bibliotecarios. Ya hay el maximo permitido." << endl;
        }
    }

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

    void mostrarBibliotecarios() const {
        if (contadorBibliotecarios == 0) {
            cout << "No hay bibliotecarios registrados." << endl;
        } else {
            for (int i = 0; i < contadorBibliotecarios; i++) {
                bibliotecarios[i].mostrarInfo();
            }
        }
    }

    void mostrarEstantes() const {
        if (contadorEstantes == 0) {
            cout << "No hay estantes en la biblioteca." << endl;
        } else {
            for (int i = 0; i < contadorEstantes; i++) {
                cout << "Estante " << i + 1 << ":" << endl;
                estantes[i].mostrarLibros();
            }
        }
    }

    ~Biblioteca() {
        // El destructor no imprime ningún mensaje
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
        } else {
            break;
        }
    }
    return numero;
}

void volvermenu()
{
    string pregunta;
      cout<<"\n Deseas volver al menu?"<<endl;
            cout<< "Escoja su respuesta: ";
            cin>>pregunta;
            
            if(pregunta == "si" || pregunta == "Si" || pregunta == "SI" )
            {
            	cin.ignore(); // Ignora el salto de linea 
				system("cls");
			}
			else
			{ 
				cout<<"Gracias por usar nuestros servicios"<<endl;
                exit(0); // Me perite cerrar el programa desde una función
			}
}


// Función principal
int main () 
{
    // Implementación de variables o función:
    char menu;
    void volvermenu();
    Biblioteca biblioteca;
    
// Declaración del menú con un do-while (ciclo de repetición)
   do
   {

        
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
            case '1': {
                system("cls");
                biblioteca.agregarEstante();
                break;
            }
            case '2': {
                system("cls");
                int numEstante = leerEntero("Ingrese el numero de estante: ");
                string titulo, autor;
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el autor del libro: ";
                getline(cin, autor);
                biblioteca.agregarLibroAEstante(numEstante, Libro(titulo, autor));
                break;
            }
            case '3': {
                system("cls");
                string nombre;
                cout << "Ingrese el nombre del bibliotecario: ";
                cin.ignore();
                getline(cin, nombre);
                biblioteca.registrarBibliotecario(nombre);
                break;
            }
            case '4': {
                system("cls");
                string nombre;
                cout << "Ingrese el nombre del bibliotecario a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                biblioteca.eliminarBibliotecario(nombre);
                break;
            }
            case '5': {
                system("cls");
                biblioteca.mostrarBibliotecarios();
                volvermenu();
                break;
            }
            case '6': {
                system("cls");
                biblioteca.mostrarEstantes();
                volvermenu();
                break;
            }
            case '7': {
                cout << "Saliendo del programa...";
                return 0;
                break;
            }
            default:
                cout << "Opcion no valida, intente de nuevo." << endl;
        }
    } while (menu !=7);


}