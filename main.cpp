#include <iostream>
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

    void InsertSort()
    {
        int i, key, j;
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

void llenar_int(int* list, int max, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        list[i] = 1 + rand()%(max);
    }
}

int main() {

    cout << "Heap Sort: \n";
    Sorting<int>* heap_sort = new Sorting<int>(10);
    llenar_int(heap_sort->get_lista(),10,10);
    heap_sort->printArray();
    heap_sort->heapSort();
    heap_sort->printArray();


    cout << "Merge Sort: \n";
    Sorting<int>* merge_sort = new Sorting<int>(16);
    llenar_int(merge_sort->get_lista(),50,16);
    merge_sort->printArray();
    merge_sort->MergeSort(0,16);
    merge_sort->printArray();

    return 0;
}