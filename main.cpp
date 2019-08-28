#include <iostream>
#include <time.h>

template <typename T>
class Sorting {
private:
    T* lista;
public:
    Sorting(/* args */);
    ~Sorting();
};

void llenar_int(List<int>* lista,int max,int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int data = rand()%(max+1);
        lista->add_end(data);
    }
}

int main (int, char * []){
    List<int>* lista = new List<int>();
    return 1;
}