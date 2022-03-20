#include <bits/stdc++.h>
using namespace std;

void perm(string x , int pos , int n){
    if(pos==n){
        //imprimir posicion a posicion
        cout <<x <<endl;
    }else{
        for(int i = pos ; i < n ;i++){
            swap(x[i],x[pos]);
            perm(x,pos+1,n);
            swap(x[i],x[pos]);
        }
    }
}

int main(){
    string x = "ABCD";
    perm(x,0,x.size());
    return 0;
}   