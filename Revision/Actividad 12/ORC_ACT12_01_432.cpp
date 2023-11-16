#include "omar.h"
#define P 1500

typedef struct _alum
{
    int status;
    int matri;
    char nombre[30];
    char appat[30];
    char apmat[30];
    int edad;
    int sexo;
}talum;

//  FUNCIONES DEFINIDAS

talum gene_auto();
talum eliminar(talum vect[], int n);
void menu();
void apellidos(char cadena[]);
void nom_feme(char cadena[]);
void nom_masc(char cadena[]);
void imprimir(talum vect[], int n);
void ordenar(talum vect[], int n);
void encontrar(talum vect[],int n);
void encontrado(talum vect[], int i, int aux2);
int busqueda_sec(talum vect[], int n, int matri);
int busqueda_bin(talum vect[], int i, int matricula);
int lee_archivo(talum vect[], int i);
int crea_archivo(talum vect[], int i);

//FUNCION DEL MENU PRINCIPAL
void menu()
{
    talum vect[P], reg;
    int i=0, op=1, j, aux=0,aux2 = 0;
    
    do
    {   
        printf("1.-Cargar archivo\n");
        printf("2.-LLenar registro automatico (10 registros)\n");
        printf("3.-Eliminar registro\n");
        printf("4.-Buscar\n");
        printf("5.-Ordenar\n");
        printf("6.-Imprimir\n");
        printf("7.-Crear archivo\n");
        printf("0.-Salir\n");
        op = valinum(0, 7, "\nQue quieres hacer? ", "ERROR");
            switch(op)
            {
                case 1:
                        system("cls");
                        if(aux == 1)
                        {
                            printf("El archivo solo puede cargarse una vez\n");
                        }
                        else
                        {
                            i = lee_archivo(vect, i);
                            aux = 1;
                        }
                        system("pause");
                        system("cls");
                case 2:
                    if (i < P)
                    {
                        for (j = 0; j < 10; j++)
                        {
                            vect[i++] = gene_auto();
                        }
                    }
                    else
                    {
                        printf("\nYa no queda espacio en el vector\n");
                    } 
                    break;
                case 3:
                    eliminar(vect, i);
                    break;

                case 4:
                    encontrar(vect, i);
                    break;
                case 5:
                    ordenar(vect, i);
                    break;
                case 6:
                    imprimir(vect, i);
                    break;
                case 7:
                    i = crea_archivo(vect, i);
                    break;
                case 0:
                    break;
                default:
                    printf("Error, intente de nuevo");
                    break;
            }
    }while(op != 0 && i < P);
}

//INT MAIN PRINCIPAL

int main()
{
    menu();
}

//FUNCION QUE GENERAS 10 REGISTROS AUTOMATICOS
talum gene_auto()
{
    talum aut;
    system("cls");
    int sexo, random;
    random = rand()%2;
    aut.status = 1;
    aut.matri = (rand()%399999) + 300000;
    aut.sexo = rand()%2+1;
    if (aut.sexo == 1)
    {
        nom_masc(aut.nombre);
    }
    else
    {
        aut.sexo == 2;
        nom_feme(aut.nombre);
    }
    apellidos(aut.appat);
    apellidos(aut.apmat);
    aut.edad = (rand()%60) + 10;
    return aut;
}

//FUNCION DE APELLIDOS
void apellidos(char cadena[])
{
    char apell[20][20] = {"HERNANDEZ","GARCIA","MARTINEZ","LOPEZ","GONZALES","PEREZ","RODRIGUEZ","SANCHEZ","RAMIREZ","CRUZ","GOMEZ","FLORES","MORALES","VAZQUEZ","JIMENEZ","REYES","DIAZ","TORRES","VICENTE","CAMACHO"};
    strcpy(cadena,apell[rand()%20]);
}

//FUNCION DE NOMBRE MASCULINOS
void nom_masc(char cadena[])
{
    char nom[20][12] = {"JUAN","LUIS","PEDRO","HECTOR","DANIEL","MANUEL","CARLOS","ROBERTO","MIGUEL","FRANCISCO","DIEGO","RAFAEL","ANGEL","JAVIER","ANTONIO","ALFREDO","RUBEN","DIEGO","PABLO","JONATHAN"};
    strcpy(cadena,nom[rand()%20]);
}

//FUNCION DE NOMBRES FEMENINOS
void nom_feme(char cadena[])
{
    char nomfem[20][20] = {"GENESIS","LARA","MARIA","MARGARITA","JUANA","CARMEN","VERONICA","ROSA","FLOR","TERESA","ALICIA","ALEJANDRA","XIMENA","CAMILA","VALERIA","ELIZABETH","RENATA","DANNA","VICTORIA","ESMERALDA"};
    strcpy(cadena,nomfem[rand()%20]);
}

//FUNCION QUE IMPRIME TODOS LOS REGISTROS
void imprimir(talum vect[], int n)
{
    int i, borrar = 0;
    system("cls");
    if (borrar == 0 )
    {
        for(i = 0; i < n; i++)
        {
            printf("\n\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d",i+1, vect[i].matri, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
        }
    printf("\n");
    system("pause");
    system("cls");
    }
    else
    {
        printf("SIN DATOS REGISTRADOS");
    }
}



// FUNCION DE BUSQUEDA SECUENCIAL //
int busqueda_sec(talum vect[], int n, int matri)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(matri == vect[i].matri)
        {
            return i;
        }
    }
    return -1;
}
// FUNCION QUE BUSCA UN REGISTRO CON METODO DE BUSQUEDA BINARIA //
int busqueda_bin(talum vect[], int i, int matricula)
{
    int izq, der, med;
    izq = 0;
    der = i - 1;
    while(izq <= der) 
    {
        med = izq + (der - izq) / 2;
        if(vect[med].matri == matricula)
        {
            return med;
        }
        
        if(vect[med].matri < matricula)
        {
            izq = med + 1;
        } 
        else
        {
            der = med - 1;
        }
    }
    return -1;
}
void encontrar(talum vect[], int n)
{
    int matri, z;
    matri = valinum(300000,399999,"\nIngresa la matricula que deseas buscar: ", "ERROR");
    
    
    if (n<750)
    {
        z = busqueda_sec(vect, n, matri);
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
                printf("\n");
                printf("MATRICULA: %d\n",vect[z].matri);
                printf("PRIMER NOMBRE: %s\n",vect[z].nombre);
                printf("APELLIDO PATERNO: %s\n",vect[z].appat);
                printf("APELLIDO MATERNO: %s\n",vect[z].apmat);
                printf("SEXO: %d\n",vect[z].sexo);
                printf("EDAD: %d\n",vect[z].edad);
                printf("\n");
        }
        else
        {
            printf("\nLo siento, no hay registro de la matricula digitada\n");
        }
    }
    else
    {
         z = busqueda_bin(vect, n, matri);
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
                printf("\n");
                printf("MATRICULA: %d\n",vect[z].matri);
                printf("PRIMER NOMBRE: %s\n",vect[z].nombre);
                printf("APELLIDO PATERNO: %s\n",vect[z].appat);
                printf("APELLIDO MATERNO: %s\n",vect[z].apmat);
                printf("SEXO: %d\n",vect[z].sexo);
                printf("EDAD: %d\n",vect[z].edad);
                printf("\n");
        }
        else
        {
            printf("\nLo siento, no hay registro de la matricula digitada\n");
        }    
    }
    system("pause");
}

// FUNCION QUE ORDENA LOS REGISTROS //
void ordenar(talum vect[], int n)
{
    int i, j, aux;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                aux = vect[i].matri;
                vect[i].matri = vect[j].matri;
                vect[j].matri = aux;
            }
        }
    }
}

//FUNCION QUE ELIMINA REGISTROS
talum eliminar(talum vect[], int n)
{
    int z = 0;
    int matri = valinum(300000, 399999, "\nIngresa la matricula para borrar los datos correspondientes: ", "ERROR");
    talum vec[P];

    for (int i = 0; i < n; i++)
    {
        if (matri != vect[i].matri)
        {
            vec[z] = vect[i];
            z++;
        }
    }

    if (z == n)
    {
        printf("\nLo siento, no hay datos registrados con esa matricula\n");
    }
    else
    {
        printf("\nEliminando registro completo\n");
        n = z;
        for (int i = 0; i < z; i++)
        {
            vect[i] = vec[i];
        }
    }
    if (z > 0)
    {
        return vec[z - 1];
    }
    else
    {
        talum vacio;
        vacio.status = 0;
        return vacio;
    }
}

//FUNCION QUE LEE EL ARCHIVO PARA CARGARLO EN EL VECTOR
int lee_archivo(talum vect[], int i)
{
    int x;
    FILE *fa;
    talum reg;
    fa = fopen("datos.txt","r");
    if (fa != NULL)
    {
        do
        {
            fscanf(fa, "%d %d %s %s %s %d %d", &x, &reg.matri, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo);
            vect[i] = reg;
            i++;
        } while(!feof(fa));
        printf("\nEl archivo se cargo correctamente\n");
    }
    else
    {
        printf("El archivo no existe\n");
    }
    fclose(fa); 
    return i;
}

//FUNCION QUE CREA EL ARCHIVO DE TEXTO
int crea_archivo(talum vect[], int n)
{
    int i;
    char nombre[30];
    FILE *fa;
    talum reg;
    system("cls");
    printf("Dame el nombre del archivo: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre, ".txt");
    fa = fopen(nombre,"w");
    if (fa != NULL)
    {
        fprintf(fa,"\tNo.   Matricula       Nombre(s)       Apellido Paterno   Apellido Materno         Edad        \tSexo:(1 - HOMBRE; 2 - MUJER)");
        
        for(i = 0; i < n; i++)
        {
            fprintf(fa, "\n\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d",i+1, vect[i].matri, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
        }
        
        printf("\nEl archivo se creo correctamente\n");
    }
    system("pause");
    system("cls");
    fclose(fa); 
    return i;
}