#include <iostream>

int SelectionSort(int *array){
    int min = array[0];
    for (int i = 0; i < sizeof(array) - 1; i++){
        for (int j = i + 1; j < sizeof(array); j++){
            if (array[i]>array[j]){
                int aux;
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }            
        }        
    }
    return array;
}


int main (int, char * []){
    std::cout << "Hello World" << std::endl;
    return 1;
}