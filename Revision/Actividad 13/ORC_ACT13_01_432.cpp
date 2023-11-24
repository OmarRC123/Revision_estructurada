#include "omar.h"
#define P 5000


typedef struct _datos
{
    int status;
    int id;
    char nombre[30];
    char appat[30];
    char apmat[30];
    int edad;
    int sexo;
    char puesto[30];
}tdatos;

//  FUNCIONES DEFINIDAS
void editar(tdatos vect[], int n);
tdatos gene_auto();
tdatos eliminar(tdatos vect[], int n);
void menu();
void apellidos(char cadena[]);
void nom_feme(char cadena[]);
void nom_masc(char cadena[]);
void imprimir(tdatos vect[], int n);
void ordenar(tdatos vect[], int n);
void encontrar(tdatos vect[],int n);
void encontrado(tdatos vect[], int i, int aux2);
int busqueda_sec(tdatos vect[], int n, int id);
int busqueda_bin(tdatos vect[], int i, int id);
void lee_archivo(tdatos vect[], int i);
void crea_archivo(tdatos vect[], int i);
void puestos(char cadena[]);
void gen_bin(tdatos vect[], int i);
int lee_bin(tdatos vect[], int i);

//FUNCION DEL MENU PRINCIPAL
void menu()
{
    tdatos vect[P], reg, eliminado[P];
    int i=0, op=1, j, aux=0,aux2 = 0, k=0, z, id;
    
    do
    {   
        printf("1.-Agregar (100 registros automaticos)\n");
        printf("2.-Editar registro\n");
        printf("3.-Eliminar registro\n");
        printf("4.-Buscar\n");
        printf("5.-Ordenar\n");
        printf("6.-Imprimir\n");
        printf("7.-Crear archivo de texto\n");
        printf("8.-Mostrar archivo de texto\n");
        printf("9.-Crear archivo binario\n");
        printf("10.-Cargar archivo binario\n");
        printf("11.-Mostrar borrados\n");
        printf("0.-Salir\n");
        op = valinum(0, 11, "\nQue quieres hacer? ", "ERROR");
            switch(op)
            {
                case 1:
                    if (i < P)
                    {
                        for (j = 0; j < 100; j++)
                        {
                            vect[i++] = gene_auto();
                        }
                    }
                    else
                    {
                        printf("\nYa no queda espacio en el vector\n");
                    } 
                    break;
                case 2:
                    editar(vect, i); 
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
                    crea_archivo(vect, i);
                    break;
                case 8:
                    lee_archivo(vect, i);
                    break;    
                case 9:
                    gen_bin(vect, i);
                    break;
                case 10:
                    i = lee_bin(vect, i);
                    system("pause");
                    system("cls");
                    break;
                case 11:
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

//FUNCION QUE GENERAS 100 REGISTROS AUTOMATICOS
tdatos gene_auto()
{
    tdatos aut;
    system("cls");
    int sexo, random;
    random = rand()%2;
    aut.status = 1;
    aut.id = (rand()%399999) + 300000;
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
    puestos(aut.puesto);
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
void puestos(char cadena[])
{
    char puesto[50][50] = {"Instalador", "Chalan", "Representante","Tecnico","Asociado de almacen", "Ensamblaje","Produccion","Soldador","Gerente","Tecnico de seguridad","Inspector"};
    strcpy(cadena,puesto[rand()%5]);
}
//FUNCION QUE IMPRIME TODOS LOS REGISTROS
void imprimir(tdatos vect[], int n)
{
    int i, borrar = 0;
    system("cls");
    if (borrar == 0 )
    {
        printf("\tNo.   id       Nombre(s)       Apellido Paterno   Apellido Materno            Edad   \tSexo:(1 - HOMBRE; 2 - MUJER)             Puesto");
        for(i = 0; i < n; i++)
        {
           
            printf("\n\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d                    %-110s",i+1, vect[i].id, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo, vect[i].puesto);
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
int busqueda_sec(tdatos vect[], int n, int id)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(id == vect[i].id)
        {
            return i;
        }
    }
    return -1;
}
// FUNCION QUE BUSCA UN REGISTRO CON METODO DE BUSQUEDA BINARIA //
int busqueda_bin(tdatos vect[], int i, int id)
{
    int izq, der, med;
    izq = 0;
    der = i - 1;
    while(izq <= der) 
    {
        med = izq + (der - izq) / 2;
        if(vect[med].id == id)
        {
            return med;
        }
        
        if(vect[med].id < id)
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
void encontrar(tdatos vect[], int n)
{
    int id, z;
    id = valinum(300000,399999,"\nIngresa la id que deseas buscar: ", "ERROR");
    
    
    if (n<750)
    {
        z = busqueda_sec(vect, n, id);
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
                printf("\n");
                printf("id: %d\n",vect[z].id);
                printf("PRIMER NOMBRE: %s\n",vect[z].nombre);
                printf("APELLIDO PATERNO: %s\n",vect[z].appat);
                printf("APELLIDO MATERNO: %s\n",vect[z].apmat);
                printf("SEXO: %d\n",vect[z].sexo);
                printf("EDAD: %d\n",vect[z].edad);
                printf("\n");
        }
        else
        {
            printf("\nLo siento, no hay registro del id digitado\n");
        }
    }
    else
    {
         z = busqueda_bin(vect, n, id);
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
                printf("\n");
                printf("id: %d\n",vect[z].id);
                printf("PRIMER NOMBRE: %s\n",vect[z].nombre);
                printf("APELLIDO PATERNO: %s\n",vect[z].appat);
                printf("APELLIDO MATERNO: %s\n",vect[z].apmat);
                printf("SEXO: %d\n",vect[z].sexo);
                printf("EDAD: %d\n",vect[z].edad);
                printf("\n");
        }
        else
        {
            printf("\nLo siento, no hay registro del id digitado\n");
        }    
    }
    system("pause");
}

// FUNCION QUE ORDENA LOS REGISTROS //
void ordenar(tdatos vect[], int n)
{
    int i, j, aux;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if (vect[j].id < vect[i].id)
            {
                aux = vect[i].id;
                vect[i].id = vect[j].id;
                vect[j].id = aux;
            }
        }
    }
}

//FUNCION QUE ELIMINA REGISTROS
tdatos eliminar(tdatos vect[], int n)
{
    int z = 0;
    int matri = valinum(300000, 399999, "\nIngresa la matricula para borrar los datos correspondientes: ", "ERROR");
    tdatos vec[P];

    for (int i = 0; i < n; i++)
    {
        if (matri != vect[i].id)
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
        tdatos vacio;
        vacio.status = 0;
        return vacio;
    }
}


//FUNCION QUE LEE EL ARCHIVO PARA CARGARLO EN EL VECTOR
void lee_archivo(tdatos vect[], int i)
{
    int x, j;
    FILE *fa;
    tdatos reg;
    char nombre[30];
    system("cls");
    printf("Dame el nombre del archivo: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre, ".txt");
    fa = fopen(nombre,"r");
    if (fa != NULL)
    {
        do
        {
            fscanf(fa, "%d %d %s %s %s %d %d %s", &x, &reg.id, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo, &reg.puesto);
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
    system("cls");
    for(j = 0; j < i; j++)
    {
        fscanf(fa, "\n\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d          %-110s",j+1, vect[i].id, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo, vect[i].puesto);
    }
    system("pause");
}

//FUNCION QUE CREA EL ARCHIVO DE TEXTO
void crea_archivo(tdatos vect[], int n)
{
    int i;
    char nombre[30];
    FILE *fa;
    tdatos reg;
    system("cls");
    printf("Dame el nombre del archivo: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre, ".txt");
    fa = fopen(nombre,"w");
    if (fa != NULL)
    {
        
        for(i = 0; i < n; i++)
        {
            fprintf(fa, "\t%2d     %6d         %-15s   %-20s %-20s  %2d             %d          %-110s",i+1, vect[i].id, vect[i].nombre,vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo, vect[i].puesto);
        }
        
        printf("\nEl archivo se creo correctamente\n");
    }
    system("pause");
    system("cls");
    fclose(fa); 
}
void editar(tdatos vect[], int n)
{
    int id, z, op;
    id = valinum(300000,399999,"\nIngresa el id que deseas editar: ", "ERROR");
    tdatos reg;
    if (n<750)
    {
        z = busqueda_sec(vect, n, id);
        vect[z]= reg;
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
            if (op == 1)
            {
                id = valinum(300000, 399999, "Ingrese el nuevo id", "Error");
                reg.id = id;
                printf ("\nEl registro se cambio con exito ");
                system ("pause");
                system ("cls");
            }
            if (op == 2)
            {
                printf ("Ingrese el nuevo nombre: ");
                fgets(reg.nombre, 30, stdin);
                
            }
            if (op == 3)
            {
                printf ("Ingrese el nuevo apellido: ");
                fgets(reg.appat, 30, stdin);
                
            }
            if (op == 4)
            {
                printf ("Ingrese el nuevo apellido: ");
                fgets(reg.apmat, 30, stdin);
               
            }
            if (op == 5)
            {
                reg.edad = valinum(10, 60, "Ingrese la nueva edad", "Error");
               
            }
            if (op == 6)
            {
                reg.sexo = valinum(300000, 399999, "1-Hombre 2-Mujer", "Error");
                
            }
            if (op == 7)
            {
                printf ("Ingrese el nuevo puesto: ");
                fgets(reg.puesto, 30, stdin);
                
            }
        }
        else
        {
            printf("\nLo siento, no hay registro del id digitado\n");
        }
    }
    else
    {
         z = busqueda_bin(vect, n, id);
        if (z != -1)
        {
            printf("\n Registro encontrado con exito");
            if (op == 1)
            {
                id = valinum(300000, 399999, "Ingrese el nuevo id", "Error");
                reg.id = id;
                printf ("\nEl registro se cambio con exito ");
                system ("pause");
                system ("cls");
            }
            if (op == 2)
            {
                printf ("Ingrese el nuevo nombre: ");
                fgets(reg.nombre, 30, stdin);
                
            }
            if (op == 3)
            {
                printf ("Ingrese el nuevo apellido: ");
                fgets(reg.appat, 30, stdin);
                
            }
            if (op == 4)
            {
                printf ("Ingrese el nuevo apellido: ");
                fgets(reg.apmat, 30, stdin);
               
            }
            if (op == 5)
            {
                reg.edad = valinum(10, 60, "Ingrese la nueva edad", "Error");
               
            }
            if (op == 6)
            {
                reg.sexo = valinum(300000, 399999, "1-Hombre 2-Mujer", "Error");
                
            }
            if (op == 7)
            {
                printf ("Ingrese el nuevo puesto: ");
                fgets(reg.puesto, 30, stdin);
                
            }
        }
        else
        {
            printf("\nLo siento, no hay registro del id digitado\n");
        }    
    }
    system("pause");
}
void gen_bin(tdatos vect[], int i)
{
    int n;
    char nombre[30];
    FILE *fa;
    tdatos reg;
    system("cls");
    printf("Dame el nombre del archivo: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre, ".dll");
    fa = fopen(nombre,"ab");
    for(n=0 ; n<i ; n++)
    {
        reg = vect[n];
        fwrite(&reg, sizeof(tdatos), 1, fa);
    }
    printf("\nEl archivo se creo correctamente\n");
    fclose(fa);    
}
int lee_bin(tdatos vect[], int i)
{
    int x;
    char nombre[30];
    FILE *fa;
    tdatos reg;
    system("cls");
    printf("Dame el nombre del archivo para abrirlo: ");
    fflush(stdin);
    gets(nombre);
    strcat(nombre, ".dll");
    fa = fopen(nombre,"rb");
    if (fa)
    {
        while (fread(&reg, sizeof(tdatos), 1, fa))
        {
            vect[i++] = reg;
        }
        printf("\nEl archivo se cargo correctamente\n");
    }
    else
    {
        printf("Error, el archivo no existe");
    }
    fclose(fa);
    return i;
}