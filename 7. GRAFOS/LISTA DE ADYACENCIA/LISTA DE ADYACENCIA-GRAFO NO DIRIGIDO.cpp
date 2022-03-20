#include <iostream>
#include <vector>

using namespace std;

//tipo nombre[tam]
vector <int> grafo[100];
int nro_nodos, nro_arcos, origen, destino;

//limpiamos cada vector dinamico dentro de el array de nodos
void init_grafo(){
    for(int i = 0 ; i <= nro_nodos ; i++ ){
        grafo[i].clear();
    }
}

void mostrarVecDinamico(vector<int> v){
    int tam = v.size();
    for(int i = 0 ; i < tam ; i++){
        cout<<v[i]<<"  ";
    }
}

void mostrar_grafo(){
    cout<<endl<<"LISTA ADYACENTE DE GRAFOS NO DIRIGIDOS"<<endl;
    for (int i = 1; i <= nro_nodos; i++)
    {
        cout << "nodo origen: "<<i<<" nodos destino: ";
        vector<int> v = grafo[i];
        mostrarVecDinamico(v);
        cout<<endl;
    }
}

void construye_grafo(){

    cout<<"intro nro_nodos, nro_arcos: ";
    cin >> nro_nodos >> nro_arcos;
    init_grafo();

    while(nro_arcos>0){
        cout << "intro origen, destino: ";
        cin >> origen >> destino;
        //en el origen, añadimos el destino a su respectivo
        //vector dinamico para obtener sus destinos correspondientes
        grafo[origen].push_back(destino);
        grafo[destino].push_back(origen);
        nro_arcos--;
    }

}

int main()
{
    construye_grafo();
    mostrar_grafo();
    return 0;
}
