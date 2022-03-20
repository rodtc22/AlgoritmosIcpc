#include <iostream>
#include <queue>

using namespace std;

void mostrar(queue <short int> c){
    while(!c.empty()){
        short int e = c.front();
        c.pop();
        cout << e << "   ";
    }
    cout <<endl;
}

int main()
{
    //IMPLEMENTACION
    queue <short int> edades;
    for(int i = 0 ; i < 10 ; i++) edades.push(i);

    cout << "nro de elem: "<< edades.size()<<endl;
    mostrar(edades);

    edades.pop();
    edades.pop();
    edades.pop();

    cout << "nro de elem: "<< edades.size()<<endl;
    mostrar(edades);

	/*//queue <tipo> nombre
	//queue <tipo> nombre (nombre de la cola a copiar)
	queue <int> que;

	//primer y ultimo elemento
	int primero = que.front();
	int ultimo = que.back();

	//me dice el si esta vacia
	if(que.empty()) cout << "La cola está vacia";

	//me dice el nro de elemtnos
	int nroElem = que.size();

	//inserta al final de la cola
	que.push(45);

	//elimina el primer elem de la cola
	que.pop();*/

	return 0;
}
