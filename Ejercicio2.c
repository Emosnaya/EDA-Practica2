//Elaborar un programa que reciba un arreglo con 
//N datos y genere como salida el mismo arreglo 
//pero sin elementos repetidos.(Usar apuntadores)

#include <stdio.h>//Se incluye la biblioteca principal

void print_(int *, int);//Función para imprimir el arreglo final


int main(){//Función principal
    int n,j=0,z=0,cont,num; //Se define n, para la magnitud del arreglo, j, z, cont, num como contadores y auxiliares para el proceso de eliminación
    int a[50]; //Definimos a, como arreglo
    int *ptr, *aux, *final;//Se define ptr, aux, final como apuntadores   
    ptr= a, aux=a, final=a;//Asignamos el arreglo “a” a cada apuntador
    printf("\nIngrese la magnitud de su arreglo:\t");//Se pide la magnitud del arreglo
    scanf("%d",&n);
    if (n > 0) {
        printf("\nIngrese sus %d elementos\n", n); //Se ingresa los elementos del arreglo y se guardan en ptr
        for (int i = 0; i < n; i++){
        scanf("%d",& *(ptr+i));
        }
        for (int i = 0; i < n; i++){
            cont=0;// Es un contador
            num=*(ptr+i);//Se asignan los valores de ptr en la variable num
            *(aux+j)=num;//Se asignan los valores de num en el apuntador aux+j
            j++;//j aumenta uno
            for (int k = 0; k < n; k++){
                if ((*(aux+k)==num)){//Si el valor en el apuntador aux es igual al valor en num
                cont++;// el contador aumenta
                } 
            }
            if (cont==1){//Si el contador es igual a uno 
             *(final+z)=num;//Se le asigna el valor de num al apuntador final
             z++;//Z aumenta uno
            }
        }
    print_(final, z);//Imprime el arreglo final         
    }
    else//Si el arreglo no cuenta con elementos se imprime 
    printf("\nEl arreglo no tiene elementos\t");
    return 0;
}

void print_(int *final, int z){//Se solicita el apuntador final y la variable z
    printf("\nEl arreglo sin repeticiones es:\n");//Para poder mostrar esté arreglo
    for (int i = 0; i < z; i++){
        printf("\t[%d]\n",*(final+i));
    }
}