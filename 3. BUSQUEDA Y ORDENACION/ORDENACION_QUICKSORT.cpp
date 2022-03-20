#include <iostream>
#include <cstdlib>
using namespace std;

int n = 100000;
int v [1000000];

void llenar(){
    for(int i = 0 ; i < n ; i++){
        v[i] = rand()%n+1;
    }
}

void mostrar(){
    cout << "\nMOSTRANDO EL VECTOR: \n";
    for (int i = 0 ; i < n ; i++){
        cout << v[i] << "   ";
    }
    cout << endl;
}

int pivote (int first , int last ){
    int p = first;
    int pivotElement = v[first];

    for( int  i = first +1 ; i <= last ; i++ ){
        if(v[i] <= pivotElement){
            p++;
            swap(v[i], v[p]);

        }
    }
    swap(v[p] , v[first]);
    return p;
}

//OBTENGO EL ELEMENTO CON VALOR MEDIO DEL ARRAY, LUEGO LO LLAMO
//PIVOTE Y CON ESA REFERENCIA, MANDO SUS MAYORES A UN LADO Y SUS
//MENORES A OTRO LADO.
void quick_sort(int first, int last){
    int pivotElement;
    if(first < last){
        pivotElement = pivote(first,last);
        quick_sort(first,pivotElement-1);
        quick_sort(pivotElement+1,last);
    }
}


int main()
{
    llenar();
    mostrar();
    //MANDO DE QUE POSICION A QUE POSICION DESEO ORDENAR 0-24
    cout << "QUICK SORT: \n";
    quick_sort(0,n-1);
    mostrar();

    return 0;
}
