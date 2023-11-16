#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define M 15
/// PROTOTIPO DE FUNCIONES ///

int valinum (int ri, int rf, char msg[30], char msg2[30]);
void mayusculas (char cad[]);
void minusculas (char cad[]);
void contarcad (char cad[]);
void removerespacios(char cadena []);
char buscavocal (char cad[]);
char buscacons (char cad[]);
void enie(char cadena[]);
void llenar_vect_aleatorio(int vect[], int m, int ri, int rf);
void buscar (int vect[], int m);
int busq_sec(int vect[], int n, int num);
void ordenar(int vect[], int m);
bool no_repetir_m(int matriz[4][4],int n);
bool no_repetir(int vect[],int n);
void imprimir_mat(int matriz[4][4], int m, int n);
void llenar_matriz(int matriz[4][4], int m, int ri, int rf);
void llenar_vect_aleatorio(int vect[], int m, int ri, int rf);

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

void mayusculas (char cad[])
{
    int i, tam;
    tam=strlen(cad);
    
    for(i=0; i<tam; i++)
    {
        if (cad[i]>='a' && cad[i]<='z')
        {
            cad[i]=cad[i]-('a'-'A');
        }
    }
}

void minusculas (char cad[])
{
    int i, tam;
    tam=strlen(cad);

    for(i=0; i<tam; i++)
    {
        if (cad[i]>='A' && cad[i]<='Z')
        {
            cad[i]=cad[i]+('a'-'A');
        }
    }
}

void contarcad (char cad[])
{
    int i;
    i=0;
    while (cad[i] != '\0')
    {
        i=i+1;
        
    }
    printf("%s tiene %d caracteres\n", cad, i);
}


void removerespacios(char cadena [])
{
 int i,j;
 char cadenasin[30];
 i=0;
 j=0;
 while (cadena[i]!='\0') 
 {
  if(cadena[i]!=' ')
  {
   cadenasin[j]=cadena[i];
   j++;
  }
  i++;
 }
 system("pause");
}


char buscavocal (char cad[])
{
    char vocal;
    int tam, i;
    tam=strlen(cad);
    i=1;
    while (i<tam)
    {
        if(cad[i]=='A' || cad[i]=='E' || cad[i]=='I' || cad[i]=='O' || cad[i]=='U' || cad[i]=='/' || cad[i]=='-' || cad[i]=='.')
        {
            return cad[i];
        }
        i++;
    }
    return 'X';
}

char buscacons (char cad[])
{
    char vocal;
    int tam, i;
    tam=strlen(cad);
    i=1;
    while (i<tam)
    {
        if(cad[i]!='A' && cad[i]!='E' && cad[i]!='I' && cad[i]!='O' && cad[i]!='U' && cad[i]!=' ')
        {
            return cad[i];
        }
        i++;
    }
    return 'X';
}


void enie(char cadena[])
{
    int i, len;

    len = strlen(cadena);

    for(i=0; i<len; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91)
        {
            cadena[i] = 'X';
        }
    }
}

void llenar_vect_aleatorio(int vect[], int m, int ri, int rf)
{
    int rango, i, n;
    system("cls");
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(i = 0; i < m; i++)
    {
        do
        {
            n = (rand()%rango) + ri;
        } while (no_repetir(vect, n));
        vect[i] = n;  
    }
    printf("\nEl vector se lleno correctamente!!\n");
    system("pause");
    system("cls");
}


void llenar_matriz(int matriz[4][4], int m, int ri, int rf)
{
    system("cls");
    int rango, i, n, j;
    system("cls");
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < 4; i++)
        {
            do{
                n = (rand()%rango) + ri;
                } while (no_repetir_m(matriz, n));
        matriz[j][i] = n;  
        }
    }
    printf("\nLa matriz se lleno correctamente!!\n");
    system("pause");
    system("cls");
}

void imprimir_mat(int matriz[4][4], int m, int n)
{
    system("cls");
    printf("\nMATRIZ");
    int j, i;
    printf("\n");
    for (j = 0; j < m; j++)
    {
        printf("\n[");
        for(i = 0; i < n; i++)
        {
            printf("%d, ", matriz[j][i]);
        }
        printf("]");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void imprimir_vect(int vect[], int m)
{
    int i;
    system("cls");
    printf("\nVECTOR");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect[i]);
    }
    printf("]");
    printf("\n");
    system("pause");
    system("cls");
}
bool no_repetir(int vect[],int n)
{
    int i;
    for (i = 0; i < 15; i++)
    {
        if (n == vect[i])
        {
            return true;
        }            
    }
    return false;
}
bool no_repetir_m(int matriz[4][4],int n)
{
    int i, j;
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if (n == matriz[j][i])
            {
                return true;
            }    
        }        
    }
    return false;
}
void ordenar(int vect[], int m)
{
    int temp, i, j;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    system("cls");
    printf("\nEl vector ha sido ordenado!!\n");
    system("pause");
    system("cls");
}


int busq_sec(int vect[], int n, int num)
{
    int i;
    n = num;
    for (i = 0; i < n; i++)
    {
        if(num == vect[i])
        {
            return i;
        }
    }
    return -1;
}

// FUNCION PARA BUSCAR NUMERO //
void buscar (int vect[], int m)
{
    int num, x, i;
    system("cls");
    num = valinum(100, 200, "Que numero deseas buscar?: \n", "ERROR");
    x = busq_sec(vect, M, num);
    if (x != -1)
    {
        printf("\nSi existe el numero");
        printf("\n%d esta en el indice %d", num, x);
    }
    else
    {
        printf("\nNo existe el numero\n");
    }
    system("pause");
    system("cls");
}