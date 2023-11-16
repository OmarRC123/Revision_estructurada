//25/09/2023                                     
//Programa que despliega funciones de una cadena de caracteres de distintas formas           
//ORC_ACT7_02_432  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mayus(char cadena[]);
void minus(char cadena[]);
void cap(char cadena[]);
void tamcad(char cadena[]);
void alreves(char cadena[]);
void noespa(char cadena[]);
void alfa(char cadena[]);
void ops(char cadena[]);
void palin(char cadena[]);

int main()
{
    char cadena[30];
    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    printf("Cadena en mayus: ");
    mayus(cadena);

    printf("\nCadena en minus: ");
    minus(cadena);

    printf("\nCadena con capital: ");
    cap(cadena);

    printf("\nLargo de la cadena: ");
    tamcad(cadena);

    printf("\nCadena al reves: ");
    alreves(cadena);

    printf("\nCadena sin espacios: ");
    noespa(cadena);

    printf("\nCaracteres alfabeticos y espacios: ");
    alfa(cadena);

    printf("\nEs palindromo? ");
    palin(cadena);

    return 0;
}

void mayus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }
        printf("%c", caracter);
    }
}

void minus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];
        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }
        printf("%c", caracter);
    }
}

void cap(char cadena[])
{
    int i;
    char caracter;

    caracter = cadena[0];
    if (caracter >= 'a' && caracter <= 'z')
    {
        caracter -= 32;
    }
    printf("%c", caracter);

    for (i = 1; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }
        printf("%c", caracter);
    }
}

void tamcad(char cadena[])
{
    int largo;

    for (largo = 0; cadena[largo] != '\0'; largo++)
    {
    }

    printf("\nLa cadena tiene %d caracteres", largo);
}

void alreves(char cadena[])
{
    int i, j, largo;
    char reves[30];

    for (largo = 0; cadena[largo] != '\0'; largo++)
    {
    }

    for (i = largo - 1, j = 0; i >= 0; i--, j++)
    {
        reves[j] = cadena[i];
        printf("%c", reves[j]);
    }
}

void noespa(char cadena[])
{
    int i, j;
    char sinEsp[30];

    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            sinEsp[j] = cadena[i];
            printf("%c", sinEsp[j]);
            j++;
        }
    }
}

void alfa(char cadena[])
{
    int i, j;
    char nuevaCadena[30];

    j = 0;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if ((cadena[i] == ' ') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            if (cadena[i] != ' ' || (i > 0 && cadena[i + 1] != '\0' && cadena[i - 1] != ' '))
            {
                nuevaCadena[j] = cadena[i];
                printf("%c", nuevaCadena[j]);
                j++;
            }
        }
    }
}

void ops(char cadena[])
{
    printf("\nLa cadena en mayúsculas: \n");
    mayus(cadena);
    printf("\nLa cadena en minúsculas: \n");
    minus(cadena);
    printf("\nLa cadena con capital: \n");
    cap(cadena);
    printf("\n La cadena sin espacios: \n");
    noespa(cadena);
    printf("\n La cadena al revés: \n");
    alreves(cadena);
}

void palin(char cadena[])
{
    int i, inicio, final, largo;
    char caracter;
    char cadena2[30];
    inicio = 0;
    largo = 0;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        if (caracter != ' ')
        {
            cadena2[largo] = caracter;
            largo++;
        }
    }
    final = largo - 1;

    while (inicio < final)
    {
        if (cadena2[inicio] != cadena2[final])
        {
            printf("No es un palíndromo");
            return;
        }

        inicio++;
        final--;
    }

    printf("Si es un palíndromo");
}