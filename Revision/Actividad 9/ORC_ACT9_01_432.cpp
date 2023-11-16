//Robles Carrasco Omar     372304                                                        
//10/10/2023                                          
//Pograma que despliega un menu que trabaja con vectores y matrices, y que usa una libreria personal 
//ORC_ACT9_01_432                                                       

#include "omar.h"
#define M 15
#define N 4

int main()
{
    int op, vect[M], m, matriz[4][4], aux=2;
    char cadena[30];
    do{
        printf("\n          MENU            ");
        printf("\n1) Llenar un vector aleatoriamente con 15 numeros del 100 al 200 sin repetir");
        printf("\n2) LLenar matriz 4x4 con numeros aleatorios del 1 al 16 sin repetir");
        printf("\n3) Imprimir el vector de 15 numeros");
        printf("\n4) Imprimir la matriz de 4x4");
        printf("\n5) Ordenar el vector de 15 numeros");
        printf("\n6) Buscar un valor especifico en el vector de 15 numeros");
        printf("\n0) SALIR");
        printf("\nQue accion deseas realizar? Ingresa el numero que corresponde: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                llenar_vect_aleatorio(vect, M, 100, 200);
                aux = 0;
                break;

            case 2:
                llenar_matriz(matriz, M+1, 0, 16);
                break;
            
            case 3:
                imprimir_vect(vect, M);
                break;
            
            case 4:
                imprimir_mat(matriz, M-11, N);
                break;

            case 5:
                if (aux==0)
                {
                    ordenar(vect, M);
                    aux = 1;
                }
                
                else if(aux == 2) 
                {
                    system("cls");
                    printf("El vector necesita ser llenado\n");
                    system("pause");
                    system("cls");
                }

                else 
                {
                    system("cls");
                    printf("El vector ya fue ordenado\n");
                    system("pause");
                    system("cls");
                }

                break;

            case 6:
                buscar(vect, M);
                break;

            case 0:
                printf("\nDECIDISTE SALIR, ADIOS");
                break;
            
            default:
                printf("\nELIGE UNA OPCION CORRECTA");

        }

    }while(op != 0);
}