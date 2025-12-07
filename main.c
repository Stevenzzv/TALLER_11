#include <stdio.h>     // Biblioteca estandar de entrada y salida
#include <string.h>    // Biblioteca para manejo de cadenas
#include "funciones.h" // Biblioteca de funciones personalizadas

int main()
{

    // Variables
    int opc = 0;
    char buscar[50];
    struct Libro libro[10];

    int cont = 0;
    int aux = 0;
    int respuesta = 0;
    int opcion = 0;
    int idCambiar = 0;
    int idEliminar = 0;

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
        leerLibro:
            if (cont >= 10)
            {
                printf("Capacidad maxima de libros alcanzada.\n");
                break;
            }
            printf("Ingrese el nombre del libro a agregar: ");
            leerChar(libro[cont].titulo, 100);

            do
            {
                if (libroRepetido(libro, cont, libro[cont].titulo))
                {
                    printf("-------------------------------------------\n");
                    printf("El libro ya existe.\n");
                    printf("Ingresar otro libro. 1)si 2)no: ");
                    respuesta = leerInt();
                    limpiarBuffer();
                    if (respuesta == 1)
                    {
                        printf("-------------------------------------------\n");
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
            if (cont == 0)
            {
                printf("No hay libros registrados en el sistema.\n");
                break;
            }

            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
            printf("------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < cont; i++)
            {
                printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[i].id, libro[i].titulo, libro[i].autor, libro[i].anioPublicacion, libro[i].disponible ? "Si" : "No");

                printf("------------------------------------------------------------------------------------------\n");
            }

            break;
        case 3:
            if (cont == 0)
            {
                printf("No hay libros registrados en el sistema.\n");
                break;
            }
        buscar:
            printf("Ingrese el nombre del libro a buscar: ");
            leerChar(buscar, 50);

            aux = buscarLibro(libro, cont, buscar);

            if (aux != -1) // Si el libro fue encontrado
            {
                printf("-------------------------------------------\n");
                printf("1. Cambiar estado ('Disponible' , 'Prestado'):\n");
                printf("2. Eliminar libro\n");
                printf("3. Volver al menu principal\n");
                printf("-------------------------------------------\n");

            Menu1case3:
                opcion = leerInt();
                limpiarBuffer();

                switch (opcion)
                {
                case 1:
                    libro[aux].disponible = !libro[aux].disponible;
                    printf("Estado del libro actualizado exitosamente.\n");
                    printf("Libro: %s ahora esta %s.\n", libro[aux].titulo, libro[aux].disponible ? "Disponible" : "Prestado");
                    break;
                case 2:
                    eliminarLibro(libro, &cont, libro[aux].id);
                    break;
                case 3:
                    break;

                default:
                    if (opcion < 1 || opcion > 3)
                    {
                        printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
                        goto Menu1case3; // Volver al menu
                    }
                    break;
                }
                break; // Pendiente
            }
            else // Si el libro no fue encontrado
            {
                printf("-------------------------------------------\n");
                printf("1. Registrar libro no encontrado\n");
                printf("2. Buscar otro libro\n");
                printf("3. Volver al menu principal\n");
                printf("-------------------------------------------\n");

            Menu2case3:
                opcion = leerInt();
                limpiarBuffer();

                switch (opcion)
                {
                case 1:
                    goto leerLibro;

                    break;
                case 2:
                    goto buscar;
                    break;
                case 3:
                    break;

                default:
                    if (opcion < 1 || opcion > 3)
                    {
                        printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
                        goto Menu2case3; // Volver al menu
                    }
                    break;
                }
            }

            break;
        case 4:
            if (cont == 0)
            {
                printf("No hay libros registrados en el sistema.\n");
                break;
            }
            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
            printf("------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < cont; i++)
            {
                printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[i].id, libro[i].titulo, libro[i].autor, libro[i].anioPublicacion, libro[i].disponible ? "Si" : "No");

                printf("------------------------------------------------------------------------------------------\n");
            }

            printf("Seleccione el ID del libro a cambiar estado ('Disponible' , 'Prestado'): ");
        ID:
            idCambiar = leerInt();
            limpiarBuffer();

            if (idCambiar < 1 || idCambiar > cont)
            {
                printf("ID no valido.\n");
                printf("Seleccione un ID valido: ");
                goto ID;
                break;
            }

            libro[idCambiar - 1].disponible = !libro[idCambiar - 1].disponible;
            printf("Estado del libro actualizado exitosamente.\n");
            printf("Libro: %s ahora esta %s.\n", libro[idCambiar - 1].titulo, libro[idCambiar - 1].disponible ? "Disponible" : "Prestado");

            break;
        case 5:
            if (cont == 0)
            {
                printf("No hay libros registrados en el sistema.\n");
                break;
            }
            printf("------------------------------------------------------------------------------------------\n");
            printf("| %-4s | %-30s | %-20s | %-10s | %-10s |\n", "ID", "Nombre", "Autor", "Anio", "Disponible");
            printf("------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < cont; i++)
            {
                printf("| %-4d | %-30.30s | %-20s | %-10d | %-10s |\n", libro[i].id, libro[i].titulo, libro[i].autor, libro[i].anioPublicacion, libro[i].disponible ? "Si" : "No");

                printf("------------------------------------------------------------------------------------------\n");
            }

            printf("Seleccione el ID del libro a eliminar: ");
            idEliminar = leerInt();
            limpiarBuffer();
            eliminarLibro(libro, &cont, idEliminar);
            break;
        case 6:
            printf("saliendo...\n");
            break;
        default:
            if (opc < 1 || opc > 6)
            {
                printf("Opcion no valida. Por favor, seleccione una opcion del menu: ");
                goto inicio; // Volver al menu
            }
            break;
        }

    } while (opc != 6);

    return 0;
}