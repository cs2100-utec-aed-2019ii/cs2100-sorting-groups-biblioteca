#include <iostream>

int InsertSort(int *array, int size){
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[i-1])
        {
            int aux = array[i];
            for (int j = i-1; j >= 0; j--){
                if(aux < array[j]){
                    for (int k = 0; k < i-j; k++)
                    {
                        array[i-k] = array[j-k]
                    }
                    
                }
            }
        }      
    }
}

int main (int, char * []){
    std::cout << "Hello World" << std::endl;
    return 1;
}