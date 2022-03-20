#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //ES NORMAL QUE PUEDA DAR ERROR PORQUE SE LO PROBÓ TODO POR PARTES.

    //SENTENCIA IF
    int n = 0;
    scanf("%d",&n);
    if(n == 0 ){
        cout << "El numero" << n << " es cero";
    }else if(n < 0){
        printf("El numero %d es negativo",n);
    }else{
        printf("El numero %d es positivo",n)
    }

    //SENTENCIA SWITCH
    int nro;
    cout << "Ingrese el numero";
    cin >> nro;
    switch(nro)
    {
        case 1:
            cout << "a";
            cout << "b";
            cout << "c";
        break;
        case 2:
            cout << "aa";
            cout << "bb";
            cout << "cc";
        break;
        case 3:
            cout << "aaa";
            cout << "bbb";
            cout << "ccc";
        break;
        default:
        break;
    }


    //OPERADOR TERNARIO
    printf("Ingresa tu edad: \n");
    int edad;
    scanf("%d",&edad);
    cout << ((edad<18) ? "Eres joven" : "Ya eres mayor de edad");


    //FOR
    int n=13;
    for(int i = 1 ; i <= n ; i++)
    {
        printf("Hola %d",&i);
    }

    //WHILE
    int n=20;
    while(n > 0)
    {
        cout << n << endl;
        n--;
    }

    //DO-WHILE
    int n = 0;
    do{
        cout << n << endl;
    }while(n<10);

    //BREAK
    for(int i = 0 ; i < 10 ; i++){
       if(i == 5)
        break;
       else
        cout << i <<endl;
    }

    int  n = 0;
    while(n<10){
        if(n == 5) break;
        cout << n <<endl;
        n++;
    }

    return 0;
}
