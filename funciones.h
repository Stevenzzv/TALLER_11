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
int leerInt();
float leerFloat();

// Verifica si una cadena está en blanco o contiene solo espacios
int blanco(const char str[]);

// Lee una cadena de caracteres con validación
void leerChar(char str[], int size);

#endif // FUNCIONES_H