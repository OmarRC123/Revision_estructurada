//25/09/2023                                     
//Programa que despliega funciones de una cadena de caracteres de distintas formas           
//ORC_ACT7_01_432                                                   

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// PROTOTIPO DE FUNCIONES //
void menu();
void salida1(char cadena[], char msge[]);
void salida2(char cadena[], char msge[]);
void salida3(char cadena[], char msge[]);
void salida4(char cadena[], char msge[]);
void salida5(char cadena[], char msge[]);
void salida6(char cadena[], char msge[]);
void salida7(char cadena[], char msge[]);
void salida8(char cadena[], char msge[]);
void salida9(char cadena[], char msge[]);
int tam_cadena(char cadena[]);

int main()
{
    menu();
}

// FUNCION DE MENU //
void menu()
{
    char cadena[30];
    printf("Ingresa una cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);
    salida1(cadena, "SALIDA 1");
    salida2(cadena, "SALIDA 2");
    salida3(cadena, "SALIDA 3");
    salida4(cadena, "SALIDA 4");
    salida5(cadena, "SALIDA 5");
    salida6(cadena, "SALIDA 6");
    salida7(cadena, "SALIDA 7");
    salida8(cadena, "SALIDA 8");
    salida9(cadena, "SALIDA 9");
}
 // FUNCION QUE CUENTA CARACTERES DE CADENA //
int tam_cadena(char cadena[])
{
    int i;
    for(i = 0; cadena[i] != '\0'; i++);
    return i;
}

// FUNCION DE SALIDA 1 //
void salida1(char cadena[], char msge[])
{
    int i;
    printf("\n %s \n", msge);
    for (i = 0; cadena[i]!=0; i++)
    {
        printf("%c", cadena[i]);
    }
    printf("\n");
}

//FUNCION DE SALIDA 2 //
void salida2(char cadena[], char msge[])
{
    int i, t;
    printf("\n %s \n", msge);
    t = tam_cadena(cadena);
    for (i = t-1; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
    printf("\n");
}

//FUNCION DE SALIDA 3 //
void salida3(char cadena[], char msge[])
{
    int i, t;
    printf("\n %s \n", msge);
    t = tam_cadena(cadena);
    for (i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c\n", cadena[i]);
    }
    printf("\n");
}

// FUNCION DE SALIDA 4 //
void salida4(char cadena[], char msge[])
{
    int i, t;
    printf("\n %s \n", msge);
    t = tam_cadena(cadena);
    for (i = t-1; i >= 0; i--)
    {
        printf("%c\n", cadena[i]);
    }
    printf("\n");
}


// FUNCION DE SALIDA 5 //
void salida5(char cadena[], char msge[])
{
    int i, j, t;
    t = tam_cadena(cadena);
    printf("\n %s \n", msge);
    for(i = t; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

// FUNCION DE SALIDA 6 //
void salida6(char cadena[], char msge[])
{
    int i, j, t;
    t = tam_cadena(cadena);
    printf("\n %s \n", msge);
    for(i = 0; i <= t; i++)
    {
        for(j = t; j >= i; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

// FUNCION DE SALIDA 7 //
void salida7(char cadena[], char msge[])
{
    int i, j, t;
    t = tam_cadena(cadena);
    printf("\n %s \n", msge);
    for(i = 0; i <= t; i++)
    {
        for(j = i; j <= t; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

// FUNCION DE SALIDA 8 //
void salida8(char cadena[], char msge[])
{
    int i, j, t;
    t = tam_cadena(cadena);
    printf("\n %s \n", msge);
    for(i = 0; i <= t; i++)
    {
        for(j = t; j >= i; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

//FUNCION DE SALIDA 9 //
void salida9(char cadena[], char msge[])
{
    int i, j, t;
    t = tam_cadena(cadena);
    printf("\n %s \n", msge);
    for(i = 0; i <= t; i++)
    {
        if(cadena[i] == 'a' || cadena[i] == 'A' || cadena[i] == 'e' || cadena[i] == 'E' || cadena[i] == 'i' || cadena[i] == 'I' || cadena[i] == 'o' || cadena[i] == 'O' || cadena[i] == 'u' || cadena[i] == 'U')
        {
            printf("%c",cadena[i]);
        }
    }
    printf("\n");
    for(i = 0; i <= t; i++)
    {
        if(cadena[i] != 'a' && cadena[i] != 'A')
        {
            if(cadena[i] != 'e' && cadena[i] != 'E')
            {
                if(cadena[i] != 'i'&& cadena[i] != 'I')
                {
                    if(cadena[i] != 'o' && cadena[i] != 'O')
                    {
                        if(cadena[i] != 'u' && cadena[i] != 'U')
                        {
                            printf("%c",cadena[i]);
                        }
                    }
                }
            }
        }
    
    }
}