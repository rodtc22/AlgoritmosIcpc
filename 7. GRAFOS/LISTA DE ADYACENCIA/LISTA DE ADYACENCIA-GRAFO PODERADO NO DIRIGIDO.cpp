#include <iostream>
#include <vector>
using namespace std;
/*
4 6
1 2 1
4 1 2
3 4 2
1 1 3
2 3 1
2 4 3
*/

//vector de pares donde <destino,coste> nombre[tamaño]
vector<pair<int, int>> grafo[100];
int nro_arcos,nro_nodos,origen,destino;

void init_grafo(){
    for(int i = 0 ; i <= nro_nodos ; i++){
        grafo[i].clear();
    }
}

mostrarVector(vector<pair<int,int>> v){
    int tam = v.size();
    for (int i = 0; i < tam; i++)
    {
        pair <int, int> p = v[i];
        cout << "destino: "<<p.first<< " coste:"<<p.second<<endl;
    }

}

void mostrar_grafo(){
    cout <<endl<< "LISTA DE ADYACENCIA-GRAFO PONDERADO NO DIRIGIDO"<<endl;
    for (int i = 1; i <= nro_nodos; i++){
        cout <<"Nodo "<<i<<" :"<<endl;
        mostrarVector(grafo[i]);
        cout<<endl;
    }
}

void construye_grafo(){

    cout<<"intro nro_nodos, nro_arcos";
    cin >> nro_nodos >> nro_arcos;
    init_grafo();

    while(nro_arcos>0){
        cout<<"intro origen,destino,coste: ";
        int coste=0;
        cin >> origen >> destino >>coste;
        pair <int,int> y;
        y.first=destino;
        y.second=coste;
        grafo[origen].push_back(y);
        y.first=origen;
        grafo[destino].push_back(y);
        nro_arcos--;
    }

}

int main()
{
    construye_grafo();
    mostrar_grafo();
    return 0;
}
