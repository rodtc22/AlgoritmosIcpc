#include <bits/stdc++.h>
using namespace std;

const int nros = 1e7;
//notemos que tam2 = log2(tam) lo precalculamos con  una calculadora
//respecto a los limites del problema tam2 = log2(tam)+1;  
const int potencias = 25;
int table [potencias][nros];

int n,n2;

void llenar(){
    memset(table,0,sizeof(table));
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> table[0][i];
}
void mostrar(){
    n2 = log2(n)+1;
    for(int i = 0 ; i < n2 ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << table[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<endl;
}
void init(){
    n2 = log2(n)+1;
    for(int i = 1 ; i <= n2 ; i++)
        for(int j = 0 ;j < n ; j++)
            table[i][j] = min(table[i-1][j],table[i-1][j+(1<<i-1)]);
}
int query_explicado(int i , int j){
    //EN ESTE CASO TRATAREMOS EL CASO DE RANGE MINIMUM QUERY

    //primero calculamos la potencia de 2 mas
    //cercana que no se pase para ver que longitud debe tener
    int lenght2 = 32-(log2(j-i))-1;
    lenght2 = 1<<lenght2;
    cout <<"length2: "<< lenght2<<" "<<i<<" "<<j<<endl;
    int index1 = i,index2=j-lenght2+1;
    //para obtener la fila a la que debo preguntar
    lenght2 = 32 -1 - log2(lenght2);
    //lo que tiene que responder es la composicion de los
    //dos rangos que estamos componiendo.
    return min(table[lenght2][index1],table[lenght2][index2]);    
}
int query(int i , int j){
    int lenght2 = 32-(__builtin_clz(j-i))-1;
    lenght2 = 1<<lenght2;
    int index1 = i,index2=j-lenght2+1;
    lenght2 = 32 -1 - (__builtin_clz(lenght2));
    return min(table[lenght2][index1],table[lenght2][index2]);    
}

int main(){
    llenar();
    init();
    mostrar();
    int i ,j;
    while(cin >> i >> j)
        cout<<"res: " << query(i,j)<<endl;
    return 0;
}
/*
16
3 3 2 1 5 6 5 4 9 3 3 6 5 7 2 3
2 8
7 15
5 5
5 15
5 7
*/