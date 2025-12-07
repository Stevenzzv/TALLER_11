#include <stdio.h> // Biblioteca estandar de entrada y salida
#include <string.h>
#include "funciones.h" // Asegurarse de incluir la definición de la estructura Libro

// Implementacion de funciones personalizadas
void menu()
{
    printf("----- Menu Biblioteca Patitos Felices -----\n");

    printf("1. (AGREGAR) libro\n");
    printf("2. (LISTADO) de libros\n");
    printf("3. (BUSCAR) libro\n");
    printf("4. (ACTUALIZAR ESTADO) libro\n");
    printf("5. (ELIMINAR) libro\n");
    printf("6. (SALIR)\n");

    printf("-------------------------------------------\n");
    printf("Seleccione una opcion: ");
}

// Leer un numero entero con validacion
int leerInt()
{
    int valor;

    while (scanf("%d", &valor) != 1)
    {
        printf("Entrada invalida. Por favor, ingrese un numero entero: ");
        while (getchar() != '\n')
            ; // Limpiar el buffer de entrada
    }

    return valor;
}

// Leer un numero decimal (float) con validacion
float leerFloat()
{
    float valor;

    while (scanf("%f", &valor) != 1)
    {
        printf("Entrada invalida. Por favor, ingrese un numero decimal: ");
        while (getchar() != '\n')
            ; // Limpiar el buffer de entrada
    }

    return valor;
}

// Verifica si una cadena está en blanco o contiene solo espacios
int blanco(const char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            return 0; // No está en blanco
        }
    }
    return 1; // Está en blanco
}

// Lee una cadena de caracteres con validación
void leerChar(char str[], int size)
{
    do
    {
        fgets(str, size, stdin);
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0'; // Eliminar el salto de línea
        }
        if (blanco(str))
        {
            printf("La cadena ingresada esta en blanco. Intente nuevamente.\n");
        }
    } while (blanco(str));
}

// Verifica si un libro ya está registrado
int libroRepetido(const struct Libro libro[], int cont, const char *nombreLibro)
{
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(libro[i].titulo, nombreLibro) == 0)
        {
            return 1; // Libro repetido
        }
    }
    return 0; // Libro no repetido
}

// Buscar libro
int buscarLibro(const struct Libro libro[], int cont, const char *buscar)
{
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(libro[i].titulo, buscar) == 0)
        {
            printf("El libro esta registrado en el sistema.\nInformacion:\n");
            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[i].id, libro[i].titulo, libro[i].autor, libro[i].anioPublicacion, libro[i].disponible ? "Si" : "No");

            printf("------------------------------------------------------------------------------------------\n");
            return i; // Libro encontrado
        }
    }
    printf("El libro no esta registrado en el sistema.\n");
    return -1; // Libro no encontrado
}

// Limpiar el buffer de entrada

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Elimina un libro por su ID y reorganiza los IDs de los libros restantes
void eliminarLibro(struct Libro libros[], int *numLibros, int idEliminar)
{
    int encontrado = 0;

    for (int i = 0; i < *numLibros; i++)
    {
        if (libros[i].id == idEliminar)
        {
            encontrado = 1;
        }
        if (encontrado && i < *numLibros - 1)
        {
            libros[i] = libros[i + 1]; // Desplazar el libro siguiente hacia la izquierda
            libros[i].id = i + 1;      // Actualizar el ID del libro
        }
    }

    if (encontrado)
    {
        (*numLibros)--; // Reducir el contador de libros
        printf("Libro con ID %d eliminado exitosamente.\n", idEliminar);
    }
    else
    {
        printf("Libro con ID %d no encontrado.\n", idEliminar);
    }
}