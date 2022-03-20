#include <iostream>
#include <cstdlib>

using namespace std;

int n = 25;
int v [25];

void mostrar(){
    cout << "MOSTRANOD LOS ELEMENTOS DEL VECTOR: \n";
    for(int i = 0 ; i < n ; i++ ){
        cout << v[i] <<"  ";
    }
    cout << endl;
}

void llenar(){
    for(int i = 0 ; i < n ; i++ ){
        v[i] = 0;
    }
    for(int i= 0 ; i < n ; i++ ){
        int r = rand()%n+1;
        v[i] = r;
    }
    cout << endl;
}

void ordenar_insercion(){
    int i ,j;
    for(i = 1 ; i < n ; i++ ){
        int min = v[i];
        for(j = i ; j > 0 && min < v[j-1] ; j--){
            v[j]= v[j-1];
        }
        v[j]= min;
    }
}

//PARA PODER USAR ESTE METODO, EL VECTOR DEBE ESTAR ORDENADO
//CONSISTE EN PARTIR EN DOS Y PREGUNTAR SI ESTÁ A LA DERECHA
//O IZQUIERDA, ASÍ OPTAR POR ESE LADO, DESPREACIANDO EL OTRO
//YA QUE COMO ESTÁ ORDENADO NO VALE LA PENA IR.
int busqueda_Binaria(int e){
    cout << "\nBUSCANDO "<<e<<endl;
    int  pos = -1 ;
    int lado = 0;
    int tam = n-1;
    int mitad = 0;

    while(lado <= tam){
        mitad = (lado + tam) / 2;
        cout << "\nMITAD= pos: "<<mitad<<" valor: "<<v[mitad]<<endl;
        if(v[mitad] > e){//pregunto si el elemento está a la izq
            tam = mitad -1;
            cout <<"izq ";
        }else{
            if(v[mitad] == e){
                    cout <<"med ";
                pos = mitad;
                break;
            }else{//significa que está a la derecha
                lado = mitad +1;
            cout <<"der ";
            }
        }
    }
    return pos;
}

int main()
{
    llenar();
    mostrar();
    ordenar_insercion();
    mostrar();
    int p = busqueda_Binaria(7);
    cout << "la posicion es: "<<p;
    return 0;
}
