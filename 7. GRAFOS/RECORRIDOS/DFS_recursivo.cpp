#include <bits/stdc++.h>
using namespace std;
/*
5 5
0 1
1 4
3 4
3 2
2 4

*/

vector<int> grafo [100];
int nro_nodos, nro_arcos, origen, destino;


//ESTA PARTE ES LA NORMAL YA QUE CONSTRUIMOS EL GRAFO

void init_grafo(){
    for (int i = 0; i <= nro_nodos; i++)
        grafo[i].clear();
}

void mostrar_vector(vector<int> v){
    int tam = v.size();
    for (int i = 0 ; i < tam ; i++)
        cout << v[i]<<"  ";
}

void mostrar_grafo(){
    cout<<endl;
    for (int i = 0; i < nro_nodos; i++)
    {
        cout << "Nodo "<<i<<": ";
        mostrar_vector(grafo[i]);
        cout<<endl;
    }
}

void mostrar_estados(bool e []){
    cout<<"\nESTADOS=\n";
    for (int i = 0; i < nro_nodos; i++)
    {
        cout << "Nodo "<<i<<": "<<e[i]<<endl;
    }
}

void construye_grafo(){
    cout << "ingrese nro_nodos, nro_arcos: ";
    cin >> nro_nodos>>nro_arcos;
    init_grafo();

    while(nro_arcos >0){
        cout << "ingrese origen y destino: ";
        cin>>origen>>destino;
        grafo[origen].push_back(destino);

        grafo[destino].push_back(origen);
        nro_arcos--;
    }
}

//AHORA VIENE LO INTERESANTE
void dfs_parte_recursiva(int nodo, bool b []){
    b[nodo]=true;
    cout << "ahora es true, nodo: "<<nodo<<endl;
    int tam = grafo[nodo].size();
    for (int i = 0; i < tam; i++)
    {
        int elem = grafo[nodo][i];
        if(b[elem]==false){
            cout << "es false, nodo: "<<elem<<endl;
            dfs_parte_recursiva(elem,b);
        }
    }
}

//AQUI ESTOY CREANDO EN DOS POR QUE EL PRIMER METODO
//INSTANCIA LOS ARRAYS Y EL ELEMENTO USADO POR PRIMERA VEZ
void dfs(int nodo){

    bool visitado[nro_nodos];
    for(int i = 0 ; i < nro_nodos ; i++){
        visitado[i]=false;
    }
    mostrar_estados(visitado);
    dfs_parte_recursiva(nodo,visitado);

    mostrar_estados(visitado);
}



int main()
{
    construye_grafo();
    mostrar_grafo();

    //aqui leemos el primer dato
    int g;
    cout << "ingrese el nodo a visitar: ";
    cin >>g;
    while(g<nro_nodos){
        dfs(g);
        cout << "ingrese el nodo a visitar: ";
        cin >>g;
    }

    return 0;
}
