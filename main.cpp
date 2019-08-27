#include <iostream>

int SelectionSort(int *array){
    int min = array[0];
    int SortedArray[sizeof(array)];
    for (int i=0; i < sizeof(array);i++){
        if (array[i]<min)
        {
            min = array[i];
        }
        for (int j = 0; j < sizeof(array); i++)
        {
            SortedArray[j] = min;
        }
        
        
    }
    return array;
}


int main (int, char * []){
    std::cout << "Hello World" << std::endl;
    return 1;
}