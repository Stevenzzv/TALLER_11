#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Libro
{
    int id;
    char titulo[100];
    char autor[50];
    int anioPublicacion;
    int disponible; // 1 si está disponible, 0 si está prestado
};

void menu();

// Leer un numero entero con validacion
int leerInt();

// Leer un numero decimal (float) con validacion
float leerFloat();

// Verifica si una cadena está en blanco o contiene solo espacios
int blanco(const char str[]);

// Lee una cadena de caracteres con validación
void leerChar(char str[], int size);

int libroRepetido(const struct Libro libros[], int cont, const char *nombreLibro);

void limpiarBuffer();

int buscarLibro(const struct Libro libro[], int cont, const char *buscar);

// Elimina un libro por su ID y reorganiza los IDs de los libros restantes
void eliminarLibro(struct Libro libros[], int *numLibros, int idEliminar);

#endif // FUNCIONES_H