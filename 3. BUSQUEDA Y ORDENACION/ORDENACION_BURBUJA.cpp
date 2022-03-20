#include <iostream>
#include <cstdlib>

using namespace std;

int n = 10000;
int v [10000];

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

void ordenar_burbuja(){
    for(int i = 2 ; i <= n ; i++ ){
        for(int j = 0 ; j <= n-i ; j++){
            int temp;
            if(v[j]>v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    cout << endl;
}

int main()
{
    llenar();
    mostrar();
    ordenar_burbuja();
    mostrar();
    return 0;
}
