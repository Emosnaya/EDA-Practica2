/*Elaborar un programa que almacene 10 enteros, mediante un apuntador que cambie de valor
realizar la suma y el promedio de los elementos dentro del arreglo.*/

/**
 * @file Prueba1.c
 * @author David Romero Molina (aydropunk@tutamail.com)
 * @version 0.1
 * @date 2022-02-20
 */

#include <stdio.h> //Biblioteca principal
#include <stdlib.h>  // Biblioteca para la utilizacion de malloc() y free()

// Prototipos de la funciÃ³n
int obtener_tamano(void);
int *reservar_memoria(int);
void llenar_arreglo(int *, int);
int sumar(const int *, int);
float promediar(int, int);
void liberar_memoria(int *);

//Funcion principal
int main(void) { //Especifico que la funcion main solo se puede ser llamado sin ningun parametro (void)

    //Igualamos las variables que se declararon en el prototipo de la funcion 
    int tamano = obtener_tamano();
    int *arreglo = reservar_memoria(tamano);

    float promedio = 0.0f;//Inicializamos en 0 la variable promedio tipo float
    int suma = 0;//Declaramos una variable tipo entera que se llame suma y inicia en 0

    if (arreglo) {
        llenar_arreglo(arreglo, tamano);
        suma = sumar(arreglo, tamano);
        promedio = promediar(suma, tamano);
        liberar_memoria(arreglo);
    }
    printf("\nSumatoria: %d\nPromedio:  %.2f\n", suma, promedio); /*Se imprime en pantalla la suma total y 
	el promedio con 2 decimales de los elementos ingresados*/
    return 0;//Retornamos a 0
}


//Funcion para obtener el tamano del arreglo

int obtener_tamano(void) { //No retorna nada 
    int tamano;//Declaramos una variable llamada tamano
    printf("Ingrese la cantidad de elementos:\ncantidad = ");/*Le pedimos al usuario que ingrese la 
	cantidad de elementos que conforman el arreglo*/
    scanf("%d", &tamano);//Escaneamos mediante la variable tamano
    if (tamano < 0) {//Muy importante que tamano sea mayor a 0, por el contrario no podriamos llenar los elementos del arreglo
        return 0;
    }
    return tamano;//Retornamos tamano
}

//Funcion para reservar memoria para el promedio

int *reservar_memoria(int tamano) {
    int *arreglo = malloc((size_t) tamano * sizeof *arreglo);/*El apuntador "arreglo" asigna un tamano de memoria a reservar, mediante la funcion
"malloc" por "size_t" que me garantiza que podre acceder a todos los elementos del arreglo.
Posteriormente multiplicamos "tamano" (ingresado por el usuario) por "sizeof" por "arreglo"
Es decir, devuelve 2 bytes por el "arreglo" (int) y estos bytes los multiplicamos 
por el tamano (ingresado por el usuario)*/

    if (!arreglo) {//Si arreglo
        printf("\n* Error al reservar memoria *\n");//Se imprime en pantalla un error, advirtiendonos que no reservamos memoria
        return NULL;//No devolvemos nada 
    }
    return arreglo;//Retornamos a arreglo
}

//Funcion para llenar el arreglo

void llenar_arreglo(int *arreglo, int tamano) {
    if (tamano > 0) {//Muy importante que tamano sea mayor a 0, por el contrario no podriamos llenar los elementos del arreglo
        printf("\nIngrese los elementos del arreglo:\n");//Le pedimos al usuario que ingrese los numeros que conforman al elemento
        for (int i = 0; i < tamano; ++i) {//Para i <- 0 Hasta tamano con paso 1 Hacer
            printf("arreglo[%d] = ", i + 1);/*Imprimimos en pantalla en arreglo [%d], con esto el numero que esta entre corchetes va a ir aumentado
                                            1 mas 1*/
            scanf("%d", &arreglo[i]);//Escaneamos mediante la variable tamano que tiene como parametro la variable i
        }
    }
}

//Funcion para sumar el arreglo

int sumar(const int *arreglo, int tamano) {
    int suma = 0;//Declaramos una variable tipo entero que se llama suma y esta es igual a 0
    for (int i = 0; i < tamano; ++i) {//Para i <- 0 Hasta tamano con paso 1 Hacer
        suma += arreglo[i];/*Con el operador "+=" asigamos una suma, es decir, el primer valor que ingresemos se va a tomar como variable suma, para 
posteriormente ingresar el segundo valor se va tomar como la variable arreglo con parametro en i, asi sucesivamente, es decir
va ir sumando los numeros conforme vayamos ingresando*/
    }
    return suma;//Retornamos a suma
}

//Funcion para sacar el promedio del arreglo

float promediar(int suma, int tamano) {
    if (tamano == 0) {//Comparamos si tamano es igual a 0
        return 0.0f;//Retornamos a 0.0 por el float
    }
    return (float) suma / (float) tamano;/*Retornamos a suma dividido entre tamano, es decir,
la cantidad de numeros ingresados por el usuario.*/
}

void liberar_memoria(int *arreglo) {
    free(arreglo); //Con la funcion "free" liberamos memoria del arreglo
}