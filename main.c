#include <stdio.h>     // Biblioteca estandar de entrada y salida
#include <string.h>    // Biblioteca para manejo de cadenas
#include "funciones.h" // Biblioteca de funciones personalizadas

int main()
{
    // Biblioteca patitosFelices
    // SOftware para gestionar la la informacion de biblioteca y facilitar consultas y prestamos de libros a los usuarios.

    // Variables
    int opc = 0; // Opcion del menu
    char prueba[50];
    struct Libro libro[10];
    // Desarrollo del programa
    menu();

inicio: // Etiqueta para volver al menu en caso de opcion no valida

    do
    {
        opc = leerInt();
        if (opc < 1 || opc > 6)
        {
            printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
        }
    } while (opc < 1 || opc > 6);

    // Menu / Opciones

    do
    {
        switch (opc) // Casos del menu
        {
        case 1:

            break;

        default:
            if (opc < 1 || opc > 6)
            {
                printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
                goto inicio; // Volver al menu
            }
            break;
        }
        return 0;
        /* code */
    } while (opc != 6);
}