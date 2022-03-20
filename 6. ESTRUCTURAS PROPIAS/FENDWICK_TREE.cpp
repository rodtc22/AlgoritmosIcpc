#include <bits/stdc++.h>
using namespace std;

//TODO NUMERO POSITIVO PUEDE SER EXPRESADO EN NUMEROS DE POTENCIAS DE 2.
//Y CUANDO EL INDEX ES POTENCIA DE 2 SE TOMA LA SUMA DESDE EL INICIO
//PARA SER EL INTERVALO MAS GRANDE
const int tam = 100000001;
int vec[tam];
int tree[tam];
int n,x,a,b;

//LEE EL VECTOR
void leerVec(){
    cout <<"Leyendo el vector: ";
    for (int i = 0; i < n; i++)
        cin >> vec[i];
}

//MUESTRA EL VECTOR
void mostrarVec(int v[]){
    cout <<"Mostrando el vector: \n";
    for (int i = 0; i <= n; i++)
        cout <<v[i]<<" ";
    cout << endl;
}

//OBTIENE EL BIT MENOS SIGNIFICATIVO
int LSB(int num){
    int x = num;
    //tratamos de generar 111...1 de la misma longitud de num
    int longitudBinaria = log2(x)+1;
    int complemento_a_1 =  (1<<(longitudBinaria+1))-1;
    
    //el complemento a 1 es solo el numero con sus bits invertidos
    complemento_a_1 = x ^ complemento_a_1;

    int complemento_a_2 =  complemento_a_1 + 1;

    //ahora devolvemos el resultado de and bit a bit
    return x & complemento_a_2;
}

//BASICAMENTE CONSISTE EN DECIR, VAMOS A CAMBIAR LA SUMA DESDE AQUI
//Y LUEGO CAMBIAMOS A SUS PROPAGACIONES
void update(int i, int val){
    int pos=i+1;
    do{
        tree[pos] = tree[pos] - vec[i] + val;
        pos = pos + LSB(pos);
    }while(pos < n);    
    //vec[i]=val;
}

int get(int pos){
    int sum = 0;
    while(pos >= 1){
        sum+=tree[pos];
        int bit = log2(LSB(pos));
        pos = pos & ~(1 << bit);
    }
    return sum;
}

//CREO QUE LA COMPLEJIDAD DE CONSTRUIR ES N*LOG(N)
void construyeArbol(){
    //pongo el cero como un acumulador neutro de la suma
    memset(tree,0,n);
    //recorro todas las posiciones del array para ir generando las 
    //respectivas sumas
    for (int i = 0; i < n; i++)
    {
        int pos = i+1;
        //mientras pueda pasar entre nodos
        do{
            //suma vec[i] a la suma que ya tenia antes ese nodo
            tree[pos] = tree[pos] + vec[i];
            //avanza a la proxima propagacion
            pos = pos + LSB(pos);
        }while(pos<n);
    }
    
}
//7 5 4 1 -1 0 8 7
int main(){
    cout <<"Ingrese n: ";
    cin >>n;
    leerVec();
    mostrarVec(vec);
    construyeArbol();
    mostrarVec(tree);
    cout <<"1. update\n2. get\n3. display\n";
    while(cin >> x){
        if(x==1){
            cout <<"pos,val: "<<endl;
            cin >> a >> b;
            update(a,b);
        }else if(x==2){
            cout <<"tam: "<<endl;
            cin >> a;
            cout << get(a)<<endl;
        }else{
            mostrarVec(tree);
        }
        cout <<"1. update\n2.get\n3. display\n";
    }
    return 0;
}