#include <iostream>
#include <cstdlib>
using namespace std;
int m [20];

void llenar(){
    for(int i = 0 ; i < 20 ; i++ ){
        int num = rand()%20+1;
        m[i]=num;
    }
}

void mostrar(){
    cout << "MOSTRANDO EL VECTOR: \n";
    for (int i = 0 ; i < 20 ; i++ ){
        cout <<m[i]<<"  ";
    }
    cout <<endl<<endl;
}
/*
lo que hace este metodo es ir al ultimo elemento del vector en
cada repeticion entonces pregunta si en el segundo for ya llegó al inicio
(entonces el metodo para) y verifica que ese ultimo elemento de cada
repeticion sea menor que el de la izquierda así vá buscando su posicion
de derecha a izquierda.

SU COMPLEJIDAD ES DE O(n^2)
*/
void insertion(){
    int n = 20,i=0,j=0;
    for(i = 1 ; i <= n ; i++ ){
        int temp = m[i];
        for(j = i ; j > 0 && temp < m[j-1] ; j-- ){
            m[j] = m[j-1];
        }
        m[j]=temp;
    }
}

int main()
{
    llenar();
    mostrar();
    insertion();
    mostrar();
    return 0;
}
