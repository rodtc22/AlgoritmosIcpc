#include <iostream>
#include <queue>

using namespace std;

//SI USAMOS GREATER<INT> DECIMOS QUE LA PRIORIDAD ES DE MENOR A MAYOR
void mostrar(priority_queue <int> p){
    int n = p.size();
    for(int i = 0 ; i < n ; i++){
        cout << p.top() << "   ";
        p.pop();
    }
}

int main()
{
    //IMPLEMENTACION
    priority_queue <int> prio;
    prio.push(123);
    prio.push(456);
    prio.push(789);

    cout << "\nnro de elementos: "<<prio.size()<<endl;
    mostrar(prio);

    prio.pop();
    cout << "\nnro de elementos: "<<prio.size()<<endl;
    mostrar(prio);
    /*
	priority_queue <int> pq;
	//priority_queue <dato> nombre

	int raiz = pq.top();

	//vemos i la cola de prioridad está vacía
	if(pq.empty()) cout << "la cola de prioridad está vacía\n";

	//nro de elementos de la cola
	int nroElem = pq.size();

	//añadir elementos a la cola O(log2N)
	pq.push(456);

	//elimina elemento de la cola O(log2N)
	pq.pop();

	//obtiene elemento a ser eliminado
	int elem = pq.top();
    */
	return 0;
}
