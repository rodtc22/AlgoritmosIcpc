#include <bits/stdc++.h>
using namespace std;

int father[100];
int n;

void init() { 
    cin >>n; 
    for(int i = 1 ; i <= n ;i++) 
        father[i]=i;
}
int find(int x) {
    return father[x];
}
void criterio(int x, int y) {
    //el padre, será el de mayor peso
    (father[x]>father[y])? father[x]=father[y] : father[y]=father[x];
}

void join(int x,int y){
    if(find(x)!=find(y)){
        int f = father[x];
        for(int i = 1 ; i <= n ; i++)
            if(father[i]==f)
                father[i]=father[y];//criterio(i,y);
    }
    //mosttrar
    for(int i = 1 ; i <= n ; i++) cout<<father[i]<<" ";
    cout <<endl;
}

int main(){
    init();
    join(3,2);
    join(4,1);
    join(3,1);
    join(3,5);
    join(3,6);
    return 0 ;
}