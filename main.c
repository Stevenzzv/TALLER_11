#include <stdio.h>     // Biblioteca estandar de entrada y salida
#include <string.h>    // Biblioteca para manejo de cadenas
#include "funciones.h" // Biblioteca de funciones personalizadas

int main()
{

    // Variables
    int opc = 0;
    char prueba[50];
    struct Libro libro[10];

    int cont = 0;

    do // Bucle principal del programa
    {
        menu();

    inicio: // Etiqueta para volver al menu en caso de opcion no valida

        do // Bucle para validar la opcion del menu
        {
            opc = leerInt();
            if (opc < 1 || opc > 6)
            {
                printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
            }
        } while (opc < 1 || opc > 6);

        limpiarBuffer();
        switch (opc)
        {
        case 1:
            printf("Ingrese el nombre del libro a agregar: ");
        leerLibro:
            leerChar(libro[cont].titulo, 100);

            do
            {
                if (libroRepetido(libro, cont, libro[cont].titulo))
                {
                    printf("-------------------------------------------\n");
                    printf("El libro ya existe.\n");
                    printf("Ingresar otro libro. 1)si 2)no: ");
                    int respuesta = leerInt();
                    limpiarBuffer();
                    if (respuesta == 1)
                    {
                        printf("-------------------------------------------\n");
                        printf("Ingrese otro nombre:");
                        goto leerLibro;
                    }
                    else
                    {
                        printf("-------------------------------------------\n");
                        break;
                    }
                }
                else
                {
                    printf("Ingrese el autor del libro: ");
                    leerChar(libro[cont].autor, 50);
                    printf("Ingrese el anio de publicacion: ");
                    libro[cont].anioPublicacion = leerInt();

                    libro[cont].id = cont + 1;  // Asignar ID secuencial
                    libro[cont].disponible = 1; // Disponible por defecto

                    printf("Libro agregado exitosamente.\n");
                    printf("------------------------------------------------------------------------------------------\n");
                    printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
                    printf("------------------------------------------------------------------------------------------\n");
                    printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[cont].id, libro[cont].titulo, libro[cont].autor, libro[cont].anioPublicacion, libro[cont].disponible ? "Si" : "No");

                    printf("------------------------------------------------------------------------------------------\n");
                    cont++;
                    break;
                }
            } while (1);

            break;
        case 2:

            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
            printf("------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < cont; i++)
            {
                printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[i].id, libro[i].titulo, libro[i].autor, libro[i].anioPublicacion, libro[i].disponible ? "Si" : "No");

                printf("------------------------------------------------------------------------------------------\n");
            }

            printf("Holaa\n");

            break;
        case 3:
            printf("Opcion 3 seleccionada.\n");
            break;
        case 4:
            printf("Opcion 4 seleccionada.\n");
            break;
        default:
            if (opc < 1 || opc > 6)
            {
                printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
                goto inicio; // Volver al menu
            }
            break;
            /* code */
        }

    } while (opc != 6);

    return 0;
}