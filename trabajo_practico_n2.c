#include <stdio.h>

void quicksort(int array[], int inicio, int fin);

void main(){
     
    int cant = 0;
    int array[51];
    
    printf("Ingrese la cantidad de elmentos de su vector(max 50): ");
    scanf("%i", &cant);
    
    printf("Ingrese los valores de su vector: ");
    for (int i = 0; i < cant; i++)
    {
        scanf("%i", &array[i]);
    }
    quicksort(array, 0, cant - 1);
    
    printf("\nSu vector ordenado:");
    for (int i = 0; i < cant; i++)
    {
        printf("%i ", array[i]);
    }
}
void quicksort(int array[], int inicio, int fin){

    int pivote, j, i, aux;
    if (inicio >= fin){
    return;
    }
    else{
    j = fin;
    i = inicio + 1;
    pivote = array[inicio];

    while (i <= j)
    {
        while (array[i] <= pivote && i <= fin)
        {
            i++;
        }
        while (array[j] > pivote && j >= inicio)
        {
            j--;
        }
        if(i < j){
           aux = array[i];
           array[i] = array[j];
           array[j] = aux;
           i++;
           j--;
        }
    }

    array[inicio] = array[j];
    array[j] = pivote;
    quicksort(array, inicio, j - 1);
    quicksort(array, j + 1, fin);
    }
}