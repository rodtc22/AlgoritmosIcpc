#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int tam= 1e8;

int uf[tam];

void init(int n){fill(uf,uf+n+1,-1);}

int find(int x){
    if(uf[x]<0)return x;
    return uf[x]= find(uf[x]);
}

void join(int x , int y){
    x = find(x),y=find(y);
    if(x==y) return ;
    if(uf[x]>uf[y]) swap(x,y); // como uf[x] es negativo entonces es decir -1 > -2
    uf[x]+=uf[y];
    uf[y]=x;
}

int kruskal(int n , vector<iii>& aristas){
    sort(aristas.begin(),aristas.end());
    int arcos_usados=0,ans=0;
    for(iii a : aristas){
        int cost = a.first;
        int x = a.second.first;
        int y = a.second.second;

        x = find(x),y=find(y);
        
        if(x==y) continue;
        
        join(x,y);
        ans+=cost;
        arcos_usados++;

        if(arcos_usados == n-1) return ans;
    }
    return -1;
}

int main(){
    init(9);
    //si vamos a leer un grafo entonces debemos almacenarlos en la lista de arcos
    //por que una lista de adyacencia no serviria en este caso
    return 0;
}