#include <iostream>
#include <time.h>

template <typename T>
class Sorting {
private:
    T* lista;
public:
    Sorting(/* args */);
    ~Sorting();

    T* get_lista(){ return lista; }

    void printArray(int size)
    {
        for (int i=0; i < size; i++)
            cout <<  lista[i+1] << ' ';
        cout << endl;
    }
};

void llenar_int(List<int>* lista,int max,int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int data = rand()%(max+1);
        lista->add_end(data);
    }
}

int main (int, char * []){
    Sorting<int>* lista = new Sorting<int>();
    llenar_int(lista->get_lista(),50,20);
    lista->printArray(20);
    return 1;
}