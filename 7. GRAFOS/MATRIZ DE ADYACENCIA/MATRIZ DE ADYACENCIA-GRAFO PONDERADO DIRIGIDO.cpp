#include <iostream>

using namespace std;

int nro_nodos, nro_arcos, origen, destino;
int grafo[100][100];

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

void construye(){

    cout << "ingrese el nro de nodos, nros de arcos: ";
    cin >> nro_nodos>>nro_arcos;
    init();

    while(nro_arcos>0){
        int costo=0;
        cout<<"ingrese el origen, destino, costo: ";
        cin >> origen>>destino>>costo;
        grafo[origen][destino]=costo;

        nro_arcos--;
    }

}

int main()
{
    construye();
    mostrar();
    return 0;
}
