
# Sistema de Gestión de Biblioteca

Este proyecto es un sistema de gestión de biblioteca desarrollado en C++ que permite simular las operaciones básicas de una biblioteca, como la gestión de libros, estantes y bibliotecarios, utilizando los principios de la programación orientada a objetos (OOP).

## Objetivo del Proyecto

El objetivo principal es modelar una biblioteca realista donde:
- Los libros son organizados en estantes.
- Los estantes tienen una capacidad máxima para simular limitaciones físicas.
- Los bibliotecarios son responsables de la gestión de la biblioteca.

## Funcionalidades Principales

1. **Gestión de Libros**
   - Agregar libros a estantes específicos.
   - Eliminar libros de los estantes por su título.
   - Mostrar información de los libros en los estantes.

2. **Gestión de Estantes**
   - Agregar nuevos estantes a la biblioteca (limitados a 10 estantes).
   - Mostrar todos los estantes y sus libros.

3. **Gestión de Bibliotecarios**
   - Registrar bibliotecarios (hasta 5).
   - Eliminar bibliotecarios por nombre.
   - Mostrar la lista de bibliotecarios registrados.

4. **Interfaz de Usuario**
   - Menú interactivo para acceder a todas las funciones mencionadas.
   - Validación de entradas y mensajes de error claros para el usuario.

## Estructura del Sistema

El proyecto utiliza las siguientes clases:

### Clase `Libro`
- **Atributos**:
  - `titulo`: Título del libro.
  - `autor`: Autor del libro.
- **Métodos**:
  - `mostrarInfo`: Muestra el título y autor del libro.
- **Constructor**: Inicializa los atributos.
- **Destructor**: Indica cuándo un objeto de libro es destruido.

### Clase `Estante`
- **Atributos**:
  - Arreglo de libros con capacidad máxima de 10 libros.
- **Métodos**:
  - `agregarLibro`: Agrega un libro al estante si hay espacio.
  - `eliminarLibro`: Elimina un libro por su título y ajusta los libros restantes.
  - `mostrarLibros`: Muestra todos los libros del estante.
 - **Destructor**: Muestra un mensaje al destruir un objeto estante.

### Clase `Bibliotecario`
- **Atributos**:
  - `nombre`: Nombre del bibliotecario.
- **Métodos**:
  - `mostrarInfo`: Muestra la información del bibliotecario.
- **Constructor y Destructor**: Para inicializar y destruir el objeto.

### Clase `Biblioteca`
- **Atributos**:
  - Arreglo de estantes y bibliotecarios con sus contadores.
- **Métodos**:
  - `agregarEstante`: Agrega un estante si no se alcanza el límite.
  - `agregarLibroAEstante`: Agrega un libro a un estante específico.
  - `registrarBibliotecario`: Registra un nuevo bibliotecario.
  - `eliminarBibliotecario`: Elimina un bibliotecario por su nombre.
  - `mostrarEstantes`: Lista los estantes y sus libros.
  - `mostrarBibliotecarios`: Lista los bibliotecarios registrados.
- **Destructor**: Limpia los recursos al destruir el objeto.

## Documentación

- [Archivo de texto (Word) con más detalles sobre la documentación](https://docs.google.com/document/d/1v7otKp0ij44Q1Bf-e4NliAAeafjqd_iK/edit?usp=sharing&ouid=103856854554494021555&rtpof=true&sd=true)

## Proceso de Testing

Se realizaron pruebas exhaustivas en cada funcionalidad para garantizar la estabilidad del sistema, incluyendo casos límite como:
- Intentar agregar más libros o estantes de los permitidos.
- Eliminar elementos inexistentes.
- Validación de entradas no válidas en el menú interactivo.

## Ejecución

El sistema es controlado a través de un menú interactivo. Para iniciar el programa, simplemente ejecute el archivo principal.

## Autores

- Christian A. Matias
- Jorge L. Piña
- Gabriel Colmenares

## Curso

COMP120-C7-2024

Profesor: Hector D. Concepción Rivera

## Fecha de Entrega

23/11/2024
