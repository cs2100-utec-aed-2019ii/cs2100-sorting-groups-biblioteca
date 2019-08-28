#include <iostream>

void Quick_sort(int myArray[], int min, int max){
    int pivot = myArray[(min + max) / 2];

    int values_left_to_pivot = 0, values_right_to_pivot = max;
    while (values_left_to_pivot < values_right_to_pivot) {
        while (myArray[values_left_to_pivot] < pivot )
            values_left_to_pivot++;
        while( myArray[values_right_to_pivot] > pivot)
            values_right_to_pivot--;
        if (left <= right) {
            int var_temp;
            var_temp = myArray[values_left_to_pivot];
            myArray[values_left_to_pivot]=myArray[values_right_to_pivot];
            myArray[values_right_to_pivot]=var_temp;
            values_left_to_pivot++;
            values_right_to_pivot--;
        }}
    if (min < values_right_to_pivot)
        Quick_sort(myArray, min, values_right_to_pivot);
    if (max > values_left_to_pivot)
        Quick_sort(myArray, values_left_to_pivot, max);
}

int main (int, char * []){
    std::cout << "Hello World" << std::endl;
    return 1;
}