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
int libroRepetido(const struct Libro libro[], int numLibros, const char *nombreLibro)
{
    for (int i = 0; i < numLibros; i++)
    {
        if (strcmp(libro[i].titulo, nombreLibro) == 0)
        {
            return 1; // Libro repetido
        }
    }
    return 0; // Libro no repetido
}

// Limpiar el buffer de entrada

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}