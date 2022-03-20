#include <iostream>
#include <cstdio>

using namespace std;

bool esPrimo(int n){
    if(n == 1)
        return false;
    if(n % 2==0)
        return true;

    //se realiza i*i <= n por la inecuacion de
    //i <= sqrt(n)  --> elevamos por 2 la inecuacion
    //y tenemos que i^2 <= n
    for(int i = 3 ; i*i <= n ; i+=2){
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    while(cin){
        int n;
    cout << "ingrese el numero n: ";
    cin >>n;
    if(esPrimo(n))
        printf("El numero %i es primo",n);
    else
        printf("El numero %d no es primo",n);
    cout <<endl;
    }
    return 0;
}
