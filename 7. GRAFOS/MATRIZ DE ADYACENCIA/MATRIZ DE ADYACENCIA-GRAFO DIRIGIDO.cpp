#include <iostream>

using namespace std;
/*
5 6
1 3
 1 5
 3 2
  5 2
  5 4
   4 5
*/
int nro_nodos, nro_arcos, origen, destino;
bool grafo[100][100];

void init(){
    for (int i = 1 ; i <= nro_nodos ; i++)
        for (int j = 1; j <= nro_nodos; j++)
            grafo[i][j]=false;
}

void mostrar(){
    for (int i = 1 ; i <= nro_nodos ; i++)
    {
        for (int j = 1; j <= nro_nodos; j++)
        {
            cout<<grafo[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void construir(){

    cout << "ingrese el nro de nodos y nro de aristas: "<<endl;
    cin  >> nro_nodos >> nro_arcos;
    init();

    while(nro_arcos>0){
        cout << "ingrese origen, destino: ";
        cin >> origen >> destino;
        grafo[origen][destino]=true;
        nro_arcos--;
    }

}

int main()
{
    construir();
    mostrar();
    return 0;
}
