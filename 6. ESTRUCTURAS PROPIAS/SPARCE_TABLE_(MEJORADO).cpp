#include <bits/stdc++.h>
using namespace std;

const int neutro = 1<<29;
const int fil = 1e5;
const int col = 30;

int n,alto,largo;
int table[fil][col];

void init(){
    memset(table,neutro,sizeof(table));
    cin >> n; 
    for(int i = 0 ; i < n ; i++)
        cin >> table[0][i];
    //calculando el alto de la sparce table
    alto = 31 - __builtin_clz(n);
    for(int i = 1 ; i <= alto ; i++){
        //calculando el largo a recorrer para cada fila
        largo  = n - ((1<<i)-1);
        for(int j = 0 ; j < largo ; j++)
            table[i][j] = min(table[i-1][j],table[i-1][j+(1<<i-1)]);
    }
}

void mostrar(){
    for(int i = 0 ; i <=alto ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cout <<table[i][j]<<" ";
        }
        cout <<endl;
    }
}
//recorre las consultas en potencias de dos
int query(int a, int b){
    a--;b--;
    int dis =b-a+1;
    int tam = 31 - __builtin_clz(dis);
    int answer = neutro;
    for(int i = 0 ; i <= tam ; i++){
        if(dis&(1<<i)){
            answer=min(answer,table[i][a]);
            a = a + (1<<i);
        }
    }
    return answer;
}

int main(){
    init();
    mostrar();
    int x,y;
    while(cin >> x >> y){
        cout <<"x: "<<x<<" y: "<<y<<" -> " << query(x,y)<<endl;
    }
    return 0;
}