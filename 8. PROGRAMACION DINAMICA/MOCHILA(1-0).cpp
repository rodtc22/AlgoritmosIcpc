#include <bits/stdc++.h>
using namespace std;

int nro,capacidad;
int valor[10001];
int peso[10001];
int cache [10001][10001];

/*
4
3
1 4
3 6
2 3
1 2

*/

int maximo(int a, int b){
    return (a>b) ? a : b;
}

int mochila(int elem, int cap){
    if(cap < 0) return -999999;
    if(elem == 0) return 0;
    if(cache[elem][cap] != -1) return cache[elem][cap];
    int llevar = valor[elem]+mochila(elem-1,cap-peso[elem]);
    int no_llevar = mochila(elem-1,cap);
    return cache[elem][cap] = maximo(llevar,no_llevar);
}

void leerDatos(){
    memset(cache,-1,sizeof(cache));
    cout  << "Ingrese el nro de elementos: ";
    cin >> nro;
    cout  << "Ingrese el capacidad que tiene la mochila: ";
    cin >> capacidad;
    for(int i = 1 ; i <= nro ; i++){
        cout << "Ingrese el peso del objeto y su valor: ";
        cin >> peso[i] >> valor[i];
    }
}

void mostrar(){


    for(int i = 1 ;  i <= nro ; i++ ){
        cout << peso[i]<<"  ";
    }
    cout<<endl;
    for(int i = 1 ;  i <= nro ; i++ ){
        cout << valor[i]<<"  ";
    }
    cout << endl<<endl;
    for(int i = 1 ;  i <= nro ; i++ ){
        for(int j = 1 ;  j <= capacidad ; j++ ){
            cout << cache[i][j]<<"\t";
        }
        cout <<endl;
    }
}
int main()
{
    leerDatos();
    int maximo_valor = mochila(nro,capacidad);
    cout << "EL MAXIMO VALOR QUE SE PUEDE OBTENER DE LA MOCHILA ES DE : "<<maximo_valor<<endl;
    mostrar();
    return 0;
}
