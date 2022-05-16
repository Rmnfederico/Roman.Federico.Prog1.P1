#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*

1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto
 y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.

 2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
 y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena


 3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
 Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.

*/

//Prototipos

//1.
float aplicarDescuento(float precio);

//2.
int contarCaracteres(char cadena[], char caracter);

//3.

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;

}Notebook;

int ordenarPorMarcaoPrecio(Notebook vec[], int tam);

//Hardcodeo de datos
void hardcodearNotebooks(Notebook vec[], int tam, int cant);
void mostrarNotebookFila(Notebook note);
int listarNotebooks(Notebook vec[], int tam);



//////////////////////////////////////////////////////////////
int main()
{
    float descuento = aplicarDescuento(100);
    printf("%f\n", descuento);

    int caracteres;
    caracteres = contarCaracteres("abuela",'a');
    printf("%d", caracteres);

    Notebook arrayNotes[10];

    hardcodearNotebooks(arrayNotes, 10, 10);
    listarNotebooks(arrayNotes, 10);


    return 0;
}






//Desarrollo

//1.Primera funcion -
float aplicarDescuento(float precio)
{

    return precio*0.95;
}

//2.Segunda funcion -
int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;
    int lenCadena;
    lenCadena = strlen(cadena);

    if(cadena != NULL && lenCadena >0)
    {
        for(int i=0; i<lenCadena; i++)
        {
            if(cadena[i] == caracter)
            {
                contador ++;

            }

        }
    }


    return contador;
}

//Tercera funcion -

int ordenarPorMarcaoPrecio(Notebook vec[], int tam)
{
    int retorno = 0;
    Notebook auxNotebook;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( (strcmp(vec[i].marca, vec[j].marca) > 0) || (strcmp(vec[i].marca, vec[j].marca) == 0 && vec[i].precio > vec[j].precio))
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                }


            }
        }
        retorno = 1;
    }

    return retorno;
}





void hardcodearNotebooks(Notebook vec[], int tam, int cant)
{

    Notebook auxNotebooks[10] =
    {
        {0, "Proce 1", "Marca 1", 34},
        {0, "Proce 2", "Marca 2", 24},
        {0, "Proce 3", "Marca 3", 21},
        {0, "Proce 4", "Marca 4", 45},
        {0, "Proce 5", "Marca 5", 29},
        {0, "Proce 6", "Marca 6", 32},
        {0, "Proce 7", "Marca 7", 18},
        {0, "Proce 8", "Marca 8", 45},
        {0, "Proce 9", "Marca 9", 26},
        {0, "Proce 10", "Marca 10", 25}
    };

    for(int i = 0; i<tam; i++)
    {
        vec[i] = auxNotebooks[i];

    }
}



void mostrarNotebookFila(Notebook note)
{


    printf("    %4d    %10s      %s    %2f  \n",
           note.id,
           note.procesador,
           note.marca,
           note.precio);
}




int listarNotebooks(Notebook vec[], int tam)
{
    int retorno = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Notebooks ***\n");
        printf("   id       Proce.       Marca       Precio\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {

            {
                mostrarNotebookFila(vec[i]); /////////
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay notebooks en el sistema\n");
        }

        retorno = 1;
    }
    return retorno;
}
