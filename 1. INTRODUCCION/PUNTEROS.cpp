#include <iostream>
using namespace std;

int noModifica(int a){
    a=a>>1;
    return a;
}

int modifica(int* a){
    *a = *a>>1;
    return *a;
}

int main(){
    cout << "Ingresa el valor: ";
    int a;
    cin >> a;
    cout <<"-Valor inicial: "<< a<<endl;
    cout <<"-Funcion no modifica: "<<noModifica(a)<<endl;
    cout <<"-Valor despues de funcion no modifica: "<<a<<endl;
    cout <<"-Funcion modifica: "<< modifica(&a)<<endl;
    cout <<"-Valor despues de funcion modifica: "<< a<< endl;
    return 0;
}