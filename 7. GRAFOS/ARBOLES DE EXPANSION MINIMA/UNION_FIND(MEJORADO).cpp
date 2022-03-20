#include <bits/stdc++.h>
using namespace std;

const int tam =1e6; 
int uf[tam];

//PONEMOS EN -1 PARA DENOTAR EL LIDER DEL COMPONENTE CONEXO
//ADEMAS ES -1 POR QUE AL INICIO SOLO SE TIENE UN ELEMENTO EN CADA COMPONENTE
void init(int n) {
    fill(uf,uf+n,-1);
}

//CALCULAMOS EL LIDER NO SOLO PARA X, SI NO PARA TODOS LOS ELEMENTOS DEL COMPONENTE CONEXO
int find(int x){
    if(uf[x]<0) return x;
    return find(uf[x]);
}

//UNIMOS DOS COMPONENTES CONEXOS DONDE AL SUMAR UF[X] Y UF[Y] SERÁ <0 ADEMAS COMO SON LOS
//LIDERES DE LOS COMPONENTES, ESA SUMA REPRESENTA CUANTOS ELEMENTOS EL COMPONENTE EN EL
//QUE SE ENCUENTRA
void join(int x, int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    if(uf[x] > uf[y]) swap(x,y);
    uf[x] = uf[x] + uf[y];
    uf[y]=x;
}

int main(){
    int n;
    cin >> n ;
    init(n);
    join(1,5);
    join(3,2);
    join(4,2);
    join(6,3);
    for (int i = 1; i < n+1; i++)
        printf("%d %d\n",i,uf[i]);
    return 0;
}