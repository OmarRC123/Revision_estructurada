//Robles Carrasco Omar     372304                                                    
//30/10/2023                                     
//Programa que llena vectores y matrices, desplegandolas                                     
//ORC_ACT8_01_432                                                   

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define M 10

// PROTOTIPO DE FUNCIONES //
void menu();
int valinum (int ri, int rf, char msg[30], char msg2[35]);
bool no_repetir(int vect2[], int n);
void llenar_manual(int vect1[], int m);
void llenar_aleatorio(int vect2[], int m, int ri, int rf);
void llenar_vect1y2(int vect1[], int vect2[], int vect3[], int m);
void imprimir_vect(int vect1[], int vect2[], int vect3[], int m);
void llenar_matriz(int vect1[], int vect2[], int matriz[4][4]);
void imprimir_matriz(int matriz[4][4]);
int main()
{
    menu();
}

// FUNCION DE MENU PRINCIPAL //
void menu()
{
    int deci, vect1[M], vect2[M], vect3[M*2], m, matriz[4][4], aux=0;
    do{
        printf("\n1) Llenar vector 1 manualmente");
        printf("\n2) Llenar vector 2 aleatoriamente");
        printf("\n3) Llenar vector 3 con vector 1 y 2");
        printf("\n4) Imprimir todos los vectores anteriores");
        printf("\n5) Llenar matriz 4x4 con vector 1 y 2");
        printf("\n6) Imprimir matriz");
        printf("\n0) SALIR");
        printf("\nQue quieres hacer?, Ingresa el numero correspondiente a lo que deseas hacer: ");
        scanf("%d", &deci);
        switch(deci)
        {
            case 1:
                printf("\nHas escogido la opcion 1");
                llenar_manual(vect1, M);
                break;

            case 2:
                printf("\nHas escogido la opcion 2");
                llenar_aleatorio(vect2, M, 1, 10);
                break;

            case 3:
                printf("\nHas escogido la opcion 3");
                llenar_vect1y2(vect1, vect2, vect3, M);
                break;

            case 4:
                printf("\nHas escogido la opcion 4");
                imprimir_vect(vect1, vect2, vect3, M);
                break;
                
            case 5:
                printf("\nHas escogido la opcion 5");
                llenar_matriz(vect1, vect2, matriz);
                aux = 1;
                break;
            
            case 6:
                printf("\nHas escogido la opcion 6");
                if (aux ==1)
                {
                    imprimir_matriz(matriz);
                }
                else
                {
                    printf("La matriz no ha sido llenada");     
                }
                break;

            default:
                break;
        }

    }while(deci != 0);
}

// FUNCION QUE EVITA NUMEROS REPETIDOS DE VECTOR 2 //
bool no_repetir(int vect2[],int n)
{
    int i;
    for (i = 0; i <10; i++)
    {
        if (n == vect2[i])
        {
            return true;
        }            
    }
    return false;
}

// FUNCION QUE VALIDA NUMEROS //
int valinum (int ri, int rf, char msg[30], char msg2[35])
{
    char xnum[30];
    int n;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        fgets(xnum, 30, stdin);
        n=atoi(xnum);
        if(n<ri || n>rf)
        {
            printf("%s", msg2);
        }
    } while (n<ri || n>rf);
    return n;
}

// FUNCION DE LLENAR VECTOR 1 MANUALMENTE //
void llenar_manual(int vect1[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect1[i] = valinum(30, 70, "\nDame un numero entre el 30 y 70\n", "\nERROR\n");

    }
}

// FUNCION QUE LLENA VECTOR 2 ALEATORIAMENTE //
void llenar_aleatorio(int vect2[], int m, int ri, int rf)
{
    int rango, i, n;
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(i = 0; i < m; i++)
    {
        do
        {
            n = (rand()%rango) + ri;
        } while (no_repetir(vect2, n));
        vect2[i] = n;  
    }
}

// FUNCION QUE LLENA EL VECTOR 3 CON EL VECTOR 1 Y EL VECTOR 2 //
void llenar_vect1y2(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect3[i] = vect1[i];
    }

    for(i = 0; i < m; i++)
    {
        vect3[i+10] = vect2[i];
    }
}

// FUNCION QUE IMPRIME LOS 3 VECTORES //
void imprimir_vect(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    printf("\nVECTOR 1");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect1[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 2");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect2[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 3");
    printf("\n[");
    for (i = 0; i < m*2; i++)
    {
        printf("%d, ", vect3[i]);
    }
    printf("]");
    printf("\n");
}

// FUNCION QUE LLENA UNA MATRIZ // 
void llenar_matriz(int vect1[], int vect2[], int matriz[4][4])
{
    int j, i, k;
    k = 0;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 4; i++)
        {
            matriz[j][i] = vect1[k];
            k = k + 1;
        }
    }

    matriz[2][0] = vect1[8];
    matriz[2][1] = vect1[9];
    matriz[2][2] = vect2[0];
    matriz[2][3] = vect2[1];

    for (i = 0; i < 4; i++)
    {
        matriz[3][i] = vect2[i+2];
    }

}

// FUNCION QUE IMPRIME LA MATRIZ //
void imprimir_matriz(int matriz[4][4])
{
    int j, i;
    printf("\n");
    for (j = 0; j < 4; j++)
    {
        printf("\n[");
        for(i = 0; i < 4; i++)
        {
            printf("%d, ", matriz[j][i]);
        }
        printf("]");
    }
    printf("\n");

}