#include <iostream>
using namespace std;

int array [1000000];
int n;

void llenar(){
    for(int i = 0 ; i < n ; i++){
        array[i] = rand()%n+1;
    }
}

void mostrar(){
    cout << "\nMOSTRANDO EL VECTOR: \n";
    for (int i = 0 ; i < n ; i++){
        cout << array[i] << "   ";
    }
    cout << endl;
}

void QuickSort(int izq , int der){
    int i = izq, j = der;
    int mitad = array[(izq+der)/2];

    while(i <= j){
        while(array[i] < mitad) i++;
        while(array[j] > mitad) j--;
        if(i <= j){
            swap(array[i],array[j]);
            i++; j--;
        }
    }
    if (izq < j)
        QuickSort(izq, j);
    if(i < der)
        QuickSort(i ,der);

}

int main()
{
    cout << "ingrese el nro de elementos: ";
    cin >> n;
    llenar();
    mostrar();
    cout<< "\nQUICK SORT"<<endl;
    QuickSort(0,n-1);
    mostrar();
    return 0;
}
