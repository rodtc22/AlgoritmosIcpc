#include <iostream>
#include <cstdio>

using namespace std;

//CONSISTE DIVICIR EL MAYOR ENTRE EL MENOR Y SI EL RESTO DÁ
//CERO ENTONCES EL QUE DIVIDE ES EL MCD, SINO INTERCAMBIAR
//LOS VALORES DEL RESTO Y DEL DIVISOR.

int MCD(int a, int b){
    if(b==0)
        return a;
    else
        return MCD(b,a%b);
}

int mcm(int a , int b){
    return (a/(b*MCD(a,b)));
}

int main()
{
    int a,b;
    cout <<"intro a y b:\n";
    cin >> a >>b;
    printf("MCD %i,%i : %i\n",a,b,MCD(a,b));
    printf("mcm %i,%i : %i",a,b,mcm(a,b));
    return 0;
}
