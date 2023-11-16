#include "omar.h"
#define P 500

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

talum gene_auto();
talum eliminar(talum vect[], int n);
talum gene_manu (void);
void menu();
int letreros();
void apellidos(char cadena[]);
void nom_feme(char cadena[]);
void nom_masc(char cadena[]);
void imprimir(talum vect[], int n);
void ordenar(talum vect[], int n);
void encontrar(talum vect[],int n);
int busqueda(talum vect[], int n, int matri);

talum gene_manu (void)
{
    talum reg;
    reg.status = 1;
    reg.matri = valinum(300000, 399999, "Dame la matricula: ", "ERROR");
    printf ("Nombre: ");
    fgets(reg.nombre, 30, stdin);
    printf ("Apellido paterno: ");
    fgets(reg.appat, 30, stdin);
    printf ("Apellido materno: ");
    fgets(reg.apmat, 30, stdin);
    reg.edad = valinum(10, 80, "Edad: ", "ERROR");
    reg.sexo = valinum(1, 2, "1-Hombre 2-Mujer: ", "ERROR");
}
void menu()
{
    talum vect[P], reg;
    int i=0, op, j;
    do
    {
    printf("1.-LLenar registro manual\n");
    printf("2.-LLenar registro automatico (10 registros)\n");
    printf("3.-Eliminar registro\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    op = valinum(0, 6, "\nQue quieres hacer? ", "ERROR");
        switch(op)
        {
            case 1:
                if (i < P-1)
                {
                    vect[i++] = gene_manu();
                }
                break;

            case 2:
                for (j = 0; j < 10; j++)
                {
                    vect[i++] = gene_auto();
                }
                break;
            
            case 3:
                eliminar(vect, i);
                break;

            case 4:
                ordenar(vect, i);
                break;

            case 5:
                encontrar(vect, i);
                break;

            case 6:
                imprimir(vect, i);
                break;

            default:
                break;
        }
    }while(op != 0 && i < P);
}


int letreros()
{
    int op;
    printf("1.-LLenar registro manual\n");
    printf("2.-LLenar registro automatico (10 registros)\n");
    printf("3.-Eliminar registro\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    op = valinum(0, 6, "\nQue quieres hacer? ", "ERROR");
    return op;
}
int main()
{
    menu();
}
talum gene_auto()
{
    talum aut;
    int sexo, random;
    random = rand()%2;
    aut.status = 1;
    aut.matri = (rand()%399999) + 300000;
    aut.sexo = rand()%2;
    if (aut.sexo == 1)
    {
        nom_masc(aut.nombre);
    }
    else
    {
        nom_feme(aut.nombre);
    }
    apellidos(aut.appat);
    apellidos(aut.apmat);
    aut.edad = (rand()%60) + 10;
    return aut;
}

void apellidos(char cadena[])
{
    char apell[20][20] = {"HERNANDEZ","GARCIA","MARTINEZ","LOPEZ","GONZALES","PEREZ","RODRIGUEZ","SANCHEZ","RAMIREZ","CRUZ","GOMEZ","FLORES","MORALES","VAZQUEZ","JIMENEZ","REYES","DIAZ","TORRES","VICENTE","CAMACHO"};
    strcpy(cadena,apell[rand()%20]);
}


void nom_masc(char cadena[])
{
    char nom[20][12] = {"JUAN","LUIS","PEDRO","HECTOR","DANIEL","MANUEL","CARLOS","ROBERTO","MIGUEL","FRANCISCO","DIEGO","RAFAEL","ANGEL","JAVIER","ANTONIO","ALFREDO","RUBEN","DIEGO","PABLO","JONATHAN"};
    strcpy(cadena,nom[rand()%20]);
}


void nom_feme(char cadena[])
{
    char nomfem[20][20] = {"GENESIS","LARA","MARIA","MARGARITA","JUANA","CARMEN","VERONICA","ROSA","FLOR","TERESA","ALICIA","ALEJANDRA","XIMENA","CAMILA","VALERIA","ELIZABETH","RENATA","DANNA","VICTORIA","ESMERALDA"};
    strcpy(cadena,nomfem[rand()%20]);
}

void imprimir(talum vect[], int n)
{
    int i, borrar = 0;
    printf("\tNo.   Matricula       Nombre(s)         Apellido Paterno     Apellido Materno     Edad       Sexo:(1 - HOMBRE; 2 - MUJER)");
    if (borrar == 0 )
    {
    for(i = 0; i < n; i++)
    {
        printf("\n\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d",i+1, vect[i].matri, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
    }
    printf("\n");
    }
    else
    {
        printf("SIN DATOS REGISTRADOS");
    }
}



// FUNCION QUE BUSCA UN REGISTRO //
int busqueda(talum vect[], int n, int matri)
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

// FUNCION QUE PROPORCIONA DATOS DEL ALUMNO //
void encontrar(talum vect[], int n)
{
    int matri, z;
    matri = valinum(300000,399999,"\nIngresa la matricula que deseas buscar: ", "ERROR");
    z = busqueda(vect, n, matri);

    if (z != -1)
    {
        printf("\nRESULTADO ENCONTRADO. La matricula es de: %s %s %s", vect[z].nombre, vect[z].appat, vect[z].apmat);
    }
    else
    {
        printf("\nLo siento, no hay registro de la matricula digitada");
    }
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
        printf("\nEliminando registro completo");
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

