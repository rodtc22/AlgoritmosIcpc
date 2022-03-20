#include <bits/stdc++.h>
using namespace std;

const int tam = 1e5;
int tree[(tam+1)*4];
int n;
int vec[tam];

//NO ES NECESARIO ESTA FUNCION
int init(int izq, int der, int pos){
    if(izq == der) return tree[pos]= vec[izq];
    else{
        int med = (izq+der)>>1;
        int a = init(izq,med,pos*2+1);
        int b = init(med+1, der, pos*2+2);
        return tree[pos]=min(a,b);
    }
}

int query(int izq, int der, int pos, int a, int b){
    if(a<=izq && der<=b) return tree[pos];
    else if(izq > b || der <a) return (1<<20);
    else{
        int med = (izq+der)>>1;
        int x = query(izq,med,pos*2+1,a,b);
        int y = query(med+1, der,pos*2+2,a,b);
        return min(x,y);
    }
}

int update(int izq, int der, int pos, int index, int nuevo){
    if(izq == der && der == index){
        vec[izq] = nuevo;
        return tree[pos] = nuevo;
    }else if(index > der || index < izq){
        return tree[pos];
    }else{
        int med = (izq+der)>>1;
        int a = update(izq,med,pos*2+1,index,nuevo);
        int b = update(med+1,der,pos*2+2, index,nuevo);
        return tree[pos] = min(a,b);
    }
}

int query(int a,int b){ return query(0,n-1,0,a-1,b-1);}
void update(int pos,int val){update(0,n-1,0,pos,val);}

void llenar(){
    cin >> n;
    for(int i = 0 ; i < n ; i++) 
        scanf("%d",&vec[i]),update(i,vec[i]);
}

int main(){
    llenar();
    int a,b;
    while(cin >> a>> b){
        cout <<query(a,b)<<endl;
    }
    return 0;
}