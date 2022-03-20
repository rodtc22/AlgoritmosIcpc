#include <iostream>
#include <queue>

using namespace std;

int nros [1000000];
bool veri[1000000];
queue <int> cola;

void llenando_vector(int n){
    //LLENANDO LOS VALORES AL VECTOR
    for(int i = 2 ; i <= n ; i++ ){
        nros[i] = i;
    }
}

void criba(int n){
    //CRIBA
    for(int i = 2 ; i <= n ; i++){
        if(!veri[i]){
            for(int j = i*i ; j <= n ; j+=i ){
                if(j % i == 0){
                    veri[j]=true;
                }

            }
        }
    }
}

void guardando_primos(int n){
    for(int i = 2 ; i <= n ; i++ ){
        if(!veri[i]){
            cola.push(nros[i]);
        }
    }
}

void mostrar_primos(int n){
    //IMPRIMIENDO LOS PRIMOS QUE CONTIENE LA COLA
    cout << "nro de primos en el rango de 1 - "<<n<<": "<<cola.size()<<endl;

    int valor,tam=cola.size();
    for(int i = 1 ; i <= tam ; i++ ){
        valor = cola.front();
        cola.pop();
        cout << valor <<"  ";
    }
}

int main()
{
    //parece que tiene un error con el 1001
    int n ;
    cout << "ingrese el rango para la criba: ";
    cin >> n;
    llenando_vector(n);
    criba(n);
    guardando_primos(n);
    mostrar_primos(n);
    return 0;
}


