#include <iostream>
#include <vector>

using namespace std;

int nro_arcos,nro_nodos,origen, destino;
//vector <<origen,destino>,coste> nombre
vector<pair<pair<int,int>,int>> grafo ;

void init(){
    for (int i = 0; i <= nro_arcos; i++)
        grafo.clear();
}

void mostrar(){
    cout << endl<<"LISTA DE ARCOS"<<endl;
    int tam = grafo.size();
    for (int i = 0; i < tam; i++)
    {
        pair <int, int> nodo = grafo[i].first;
        cout <<"ARCO "<<i<< "=\torigen: "<<nodo.first<<" destino: "<<nodo.second<<" coste: "<<grafo[i].second<<"\n";
    }
}

void construye(){

    cout << "ingrese nro de arcos, nro de nodos: ";
    cin >> nro_arcos >> nro_nodos;
    init();

    while (nro_arcos > 0)
    {
        cout << "ingrese origen, destino, coste: ";
        int coste=0;
        cin >> origen >> destino >> coste;
        grafo.push_back(make_pair(make_pair(origen,destino),coste));
        nro_arcos--;
    }
}

int main()
{
    construye();
    mostrar();
    return 0;
}
