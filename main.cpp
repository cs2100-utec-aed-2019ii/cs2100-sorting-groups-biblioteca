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
    
    T Merge(int p, int q,int r)
    {

        int n1,n2,i,j,k;

        n1=q-p+1;
        n2=r-q;
        int L[n1],R[n2];

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

    int MergeSort(int p,int r)
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
    lista->MergeSort(0,20);
    lista->printArray(20);
    return 1;
}