#include <bits/stdc++.h>
using namespace std;

const int tam = 20;
int vec[tam],bit[tam+1];
int n;

void llenarVec(){
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> vec[i];
}

void mostrar(){
    printf("MOSTRANDO VECTORES:\n");
    for(int i = 0 ; i < n ; i++) printf("%d ",vec[i]); printf("\n");
    for(int i = 1  ; i <= n ; i++) printf("%d ",bit[i]); printf("\n");
}

void update(int pos , int val){
    vec[pos-1]=val;
    while(pos <= n){
        bit[pos]+=val;
        pos = pos + (pos&(-pos));
    }
}
//consulta de 1..pos
int query1(int pos){
    int ans = 0;
    while(pos!=0){
        ans+=bit[pos];
        pos = pos - (pos&(-pos));
    }
    return ans;
}

int query2(int l , int r){
    //la operacion es el inverso de la suma
    return (query1(r)-query1(l-1));
}

void init(){
    for(int i = 1 ; i <= n ; i++) update(i,vec[i-1]);
}

int main(){
    llenarVec();
    init();
    mostrar();
    int a,b,c;
    cin >>a>>b;
    update(a,b);
    mostrar();
    while(cin >> a >> b){
        cout  << query2(a,b)<<endl;
    }
    return 0;
}