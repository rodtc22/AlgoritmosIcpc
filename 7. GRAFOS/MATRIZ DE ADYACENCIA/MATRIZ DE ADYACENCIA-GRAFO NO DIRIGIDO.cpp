#include <iostream>

using namespace std;

//PUESTO QUE NO ES PONDERADO BASTA PONER UN BOOLEANO
//PARA DECIR SI TIENE O NO TIENE CONEXION

bool grafo [100][100];
int origen, destino, nro_arcos, nro_nodos;

//inicializamos el grafo para que estén todos en cero=false
void init(){
    for (int i = 0; i < nro_nodos; i++)
        for (int j = 0; j < nro_nodos; j++)
            grafo[i][j] = false;
}


void llenar_grafo(){

    cout << "intro nro_nodos y nro_arcos: ";
    cin >> nro_nodos >> nro_arcos;

    init();

    //hago las conexiones con los n-arcos hasta
    //que ya no hayan mas arcos
    for(int i = 0 ; i < nro_arcos ; i++ ){

        cout<<"ingrese el nodo_origen y nodo_destino: "<<endl;
        cin >> origen >> destino;

        //voy del origen al destino y pongo true para dar
        //a conocer que hay un camino entre esos nodos
        grafo[origen][destino] = true;
        //hago lo mismo pero al reves, porque es bidireccional
        grafo[destino][origen] = true;
    }
}

void mostrar_grafo(){
    cout << "GRAFO NO DIRIGIDO NO PONDERADO"<<endl;
    for (int i = 1; i <= nro_nodos; i++){
        for (int j = 1; j <= nro_nodos; j++){
            cout<<grafo[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    llenar_grafo();
    mostrar_grafo();
    return 0;
}
