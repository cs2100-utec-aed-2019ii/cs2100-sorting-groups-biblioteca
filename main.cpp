#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

template <typename T>
class Sorting {
private:
    T* lista = nullptr;
    int tamano;
public:
    Sorting(int tamano_){
        tamano = tamano_;
        lista = new T(tamano);
    }

    T* get_lista(){ return lista; }

    void set_lista(T* array){lista=array;}

    void InsertSort()
    {
        int i, j;
        T key;
        for (i = 1; i < tamano; i++)
        {
            key = lista[i];
            j = i - 1;

            while (j >= 0 && lista[j] > key)
            {
                lista[j + 1] = lista[j];
                j = j - 1;
            }
            lista[j + 1] = key;
        }
    }

    void SelectionSort(){
        int min = lista[0];
        for (int i = 0; i < tamano - 1; i++){
            for (int j = i + 1; j < tamano; j++){
                if (lista[i]>lista[j]){
                    int aux;
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }

    void Merge(int p, int q,int r)
    {

        int n1,n2,i,j,k;

        n1=q-p+1;
        n2=r-q;
        T L[n1],R[n2];

        for(i=0;i<n1;i++)
        {
            L[i]=lista[p+i];
        }

        for(j=0;j<n2;j++)
        {
            R[j]=lista[q+j+1];
        }
        i=0,j=0;

        for(k=p;i<n1&&j<n2;k++)
        {
            if(L[i]<R[j])
            {
                lista[k]=L[i++];
            }
            else
            {
                lista[k]=R[j++];
            }
        }

        while(i<n1)
        {
            lista[k++]=L[i++];
        }

        while(j<n2)
        {
            lista[k++]=R[j++];
        }
    }


    void MergeSort(int p,int r)
    {
        int q;
        if(p<r)
        {
            q=(p+r)/2;
            MergeSort(p,q);
            MergeSort(q+1,r);
            Merge(p,q,r);
        }
    }

    void heapify(int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && lista[l] > lista[largest])
            largest = l;

        if (r < n && lista[r] > lista[largest])
            largest = r;

        if (largest != i)
        {
            swap(lista[i], lista[largest]);

            heapify(n, largest);
        }
    }

    void heapSort()
    {
        for (int i = tamano / 2 - 1; i >= 0; i--)
            heapify(tamano, i);

        for (int i=tamano-1; i>=0; i--)
        {
            swap(lista[0], lista[i]);

            heapify(i, 0);
        }
    }

    void BubbleSort(){
        int var_last = tamano-1;
        for (int i=0; i<var_last;i++){
            for(int j=tamano-1; j>i;j--){
                if(lista[j-1]>lista[j]) {
                    int var_temp;
                    var_temp= lista[j-1];
                    lista[j-1]=lista[j];
                    lista[j]= var_temp;
                }}
        }
    }

    void Quick_sort(int min_position, int max_position){
        int pivot = lista[(min_position + max_position) / 2];
        int values_left_to_pivot = min_position, values_right_to_pivot = max_position;
        while (values_left_to_pivot < values_right_to_pivot) {
            while (lista[values_left_to_pivot] < pivot )
                values_left_to_pivot++;
            while( lista[values_right_to_pivot] > pivot)
                values_right_to_pivot--;
            if (left <= right) {
                int var_temp;
                var_temp = lista[values_left_to_pivot];
                lista[values_left_to_pivot]=lista[values_right_to_pivot];
                lista[values_right_to_pivot]=var_temp;
                values_left_to_pivot++;
                values_right_to_pivot--;
            }}
        if (min_position < values_right_to_pivot)
            Quick_sort(min_position, values_right_to_pivot);
        if (max_position > values_left_to_pivot)
            Quick_sort(values_left_to_pivot, max_position);
    }

    void printArray()
    {
        for (int i=0; i < tamano; i++)
            cout <<  lista[i] << ' ';
        cout << endl;
    }

    ~Sorting(){
        delete lista;
    }

};
int main(int, char*[]) {

    char array0[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout<<"Quick Sort: \n";
    Sorting<char>* quick_sort = new Sorting<char>(16);
    quick_sort->set_lista(array0);
    quick_sort->printArray();
    quick_sort->Quick_sort(0,16);
    quick_sort->printArray();

    char array1[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout << "Buble Sort: \n";
    Sorting<char>* buble_sort = new Sorting<char>(16);
    buble_sort->set_lista(array1);
    buble_sort->printArray();
    buble_sort->BubbleSort();
    buble_sort->printArray();

    char array2[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout << "Insert Sort: \n";
    Sorting<char>* inser_sort = new Sorting<char>(16);
    inser_sort->set_lista(array2);
    inser_sort->printArray();
    inser_sort->InsertSort();
    inser_sort->printArray();

    char array3[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout << "Selection Sort: \n";
    Sorting<char>* selection_sort = new Sorting<char>(16);
    selection_sort->set_lista(array3);
    selection_sort->printArray();
    selection_sort->SelectionSort();
    selection_sort->printArray();

    char array4[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout << "Heap Sort: \n";
    Sorting<char>* heap_sort = new Sorting<char>(16);
    heap_sort->set_lista(array4);
    heap_sort->printArray();
    heap_sort->heapSort();
    heap_sort->printArray();

    char array5[16] = {'V','I','C','T','O','R','M','A','R','L','O','N','L','U','I','S'};

    cout << "Merge Sort: \n";
    Sorting<char>* merge_sort = new Sorting<char>(16);
    merge_sort->set_lista(array5);
    merge_sort->printArray();
    merge_sort->MergeSort(0,16);
    merge_sort->printArray();

    return 1;
}