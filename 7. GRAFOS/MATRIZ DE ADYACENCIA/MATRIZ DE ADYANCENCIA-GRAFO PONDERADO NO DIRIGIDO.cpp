#include <iostream>

using namespace std;

int grafo[100][100];
int nro_nodos, nro_arcos, origen, destino;

void init(){
    for(int i = 1 ; i <=nro_nodos ; i++)
        for (int j = 1; j <= nro_nodos; j++)
            grafo[i][j]=false;
}

void mostrar(){
    cout<<endl<<"GRAFO PONDERADO NO DIRIGIDO"<<endl;
    for(int i = 1 ; i <=nro_nodos ; i++){
        for (int j = 1; j <= nro_nodos; j++)
        {
            cout<<grafo[i][j]<<"  ";
        }
        cout<<endl;
    }
}

//la unica diferencia con el grafo no ponderado no dirigido
//es el coste, el cual le pondremos para cada camino de A a B
void construye_grafo(){

    cout<<"ingrese el nro_nodos y nro_arcos"<<endl;
    cin>>nro_nodos>>nro_arcos;
    init();

    while(nro_arcos>0){
        int coste=0;
        cout<<"ingrese origen, destino y coste: "<<endl;
        cin >> origen >>destino >>coste;
        grafo[origen][destino]=coste;
        grafo[destino][origen]=coste;
        nro_arcos--;
    }
}

//ESTE ES UN GRAFO NO DIRIGIDO PERO PONDERADO

int main()
{
    construye_grafo();
    mostrar();
    return 0;
}
