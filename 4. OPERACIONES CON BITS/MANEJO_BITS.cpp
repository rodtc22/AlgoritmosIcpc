#include <bits/stdc++.h>
using namespace std;

int main(){
	//ceros a la izquierda de un long 
    cout << __builtin_clzll(10) << endl;

    //ceros a la izquierda de un int
    cout << __builtin_clz(15) << endl;

     // ceros a la derecha de un int
    cout << __builtin_ctz(2048) << endl;
    
    //cuenta la cantidad de 1's que tiene el nro
    cout << __builtin_popcount(15) << endl;
    return 0;
}