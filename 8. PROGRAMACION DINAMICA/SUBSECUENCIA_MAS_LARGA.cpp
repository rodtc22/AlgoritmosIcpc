#include <bits/stdc++.h>
using namespace std;
//9 0 8 2 5 3 4 6 1 7
int N ; //será el nro de valores que tendra mi secuencia
int valor[1000];  //aqui vendran los valores para la subsecuencia mas larga
int cache[1000];    //aqui vendran los valores guardados de los calculos anteriores

void leer(){
    for (int i = 0; i < N; i++)
        cin >> valor[i];
}

void mostrar(int a){
    cout << "MOSTRANDO VALORES DEL VECTOR ";
    if(a==1){
        cout << "VALOR: "<<endl;
        for(int i = 0 ; i < N ; i++)
            cout << valor[i]<<"  ";
    }else{
        cout << "CACHE: "<<endl;
        for (int i = 0; i < N; i++)
            cout << cache[i] << "  ";
    }
    cout <<endl;
}

int operacion(int a, int b){
    return (a > b) ? a : b;
}

int obtener_secuencia(int i){
    //verificamos que el valor haya sido calculado
    if(cache[i]!=-1){
        return cache[i];
    }
    int cont=1;
    for(int j = 0 ; j < i ; j++){
        //verifica que el valor del tope de la subsecuencia sea menor que los
        //valores anteriores hasta esa posicion
        if(valor[i] > valor[j]){
            //obtener_secuencia(j) me dice "obten la secuencia mas larga hasta la
            //posicion "j" y compara si es mayor a lo que tenemos hasta ahora"
            cont = operacion(cont,obtener_secuencia(j)+1);
        }
    }
    return cache[i]= cont;
}

//esta funcion irá iterando sobre todos los valores de la secuencia original
//buscando la subsecuencia mas larga hasta cada valor i
void subsecuencia(){
    memset(cache,-1,sizeof(cache));//(vector,valor,tam_vector)
    for(int i = 0 ; i < N ; i++){
        obtener_secuencia(i);
    }
}

int main()
{
    cout << "ingrese el nro de elementos de la secuencia original: ";
    cin >> N;
    leer();
    mostrar(1);
    subsecuencia();
    mostrar(2);
    return 0;
}
