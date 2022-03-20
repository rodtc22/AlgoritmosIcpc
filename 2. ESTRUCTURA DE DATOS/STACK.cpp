#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

void mostrar(stack <string> n){
    int t=0;
    t= n.size();
    printf("el tamaño es: %d\n",t);

    for(int i = 0 ; i < t ; i++){
        string a = n.top();
        n.pop();
        cout << a <<endl;
    }
}

int main()
{
    //IMPLEMENTACION
    stack <string> nombres;
    nombres.push("rodrigo");
    nombres.push("cristian");
    nombres.push("lourdes");
    nombres.push("mama");
    nombres.push("papa");

    mostrar(nombres);

    nombres.pop();
    nombres.pop();
    nombres.pop();

    mostrar(nombres);
    mostrar(nombres);
    mostrar(nombres);

    /*//stack <tipo> nombre;
    //stack <tipo> nombre (pila para copiar sus datos)
    stack <int> stk;

    //obtiene el ultimo elemento
    int ultimo = stk.top();

    //elimina el ultimo elemento
    stk.pop();

    //verifica si está vacia
    if(stk.empty()) cout << "La pila esá vacia";

    //me dice el nro de elem
    int nroElem = stk.size();

    //agrega un elemento
    stk.push(12);*/

    return 0;
}
