#include <stdio.h> //Librerias Estándar
#include<windows.h>
 
//Prototipo de función
void eliminar(int *);

int main(){
    int array[10]; // Declaramos el arreglo unidimensional de 10 elementos
    int *ptr = array; //Declaramos un apuntador, que apunta al arreglo
    int s = 0, s1 = 0; // Declaramos enteros

    printf("Ingresa el arreglo unidimensional de 10 elementos:\n"); //Solicitamos los elementos del arreglo
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", (ptr+i));//leemos los elementos gracias al apuntador
    }
    system("cls"); //Limpiamos pantalla

        printf("Deseas eliminar elementos del arreglo?\n1.- Si\n2.- No\n");// Preguntamos al usuario si quiere eliminar elementos
        scanf("%d", &s); //Leemos su respuesta
        if(s == 1){
            eliminar(ptr); //Llamamos a la función con el apuntador como argumento
        }
        else {
            printf("No se han borrado elementos...\n"); // Imprimimos un mensaje 
        }

        printf("Deseas ver arreglo?\n1.- Si\n2.- No\n"); // Imprimimos al usuario si desea ver ver el arreglo en pantalla
        scanf("%d", &s1);
        if(s1 == 1){        //Si eligio que si, se imprimira en pantalla 
            system("cls");
            for(int i = 0 ; i < 10; i++){
                printf("%d\n", ptr[i]);
            }
        } else {        //En caso de que no, se cerrara el programa
            printf("Adios...");
        }
        free(ptr); //Limpiamos memoria
        return 0;
}

//Declaramos la función
void eliminar(int *ptr){
    int eliminarx;      //La funcion se repetira acorde al tamaño del arreglo
            for(int i = 9 ; i >= 0 ; i--){
                printf("Deseas eliminar el elemento %d\n1.- Si\n2.- No\n", ptr[i]); //Le preguntara al usuario si desea borrar el ultimo elemento
                scanf("%d", &eliminarx);
                if(eliminarx == 1){     //En caso de que si, el apuntador se volvera nulo
                    ptr[i] = NULL;
                } else {        //En caso contrario ya no podra seguir borrando los elementos y se cierra la funcion
                    break;
                }
            }
}