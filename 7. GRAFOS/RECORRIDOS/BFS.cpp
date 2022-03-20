#include <bits/stdc++.h>
using namespace std;
/*
5 6
0 4
3 1
3 2
1 4
1 2
4 2

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

//ESTA PARTE ES LA INTERESANTE

/*lo que hago es poner un nodo del cual empezar a preguntar y luego
  voy preguntado por sus vecinos entonces estos se ponen a la cola
  siempre y cuando no hayan sido visitados, si no fueron visitados
  en un array que tiene el estado de cada nodo ponemos que si fueron
  o no fueron visitados así hasta que no queden nodos que visitar

  La idea es que: de un nodo visitar 1° vecinos 2°vecinos de vecinos 3°vecinos de...
*/
void bfs(int nodo){
    bool estado[nro_nodos];
    for(int i = 0 ; i < nro_nodos ; i++){
        estado[i]=false;
    }
    estado[nodo]=true;
    queue <int> vecinos;
    cout<<endl<<"añadiendo: "<<nodo<<endl;
    vecinos.push(nodo);
    while(!vecinos.empty())
    {
        int elem = vecinos.front();
        vecinos.pop();
        //preguntando por los vecinos que tiene y verificando que
        //no hayan sido visitados
        for (int i = 0 ; i < grafo[elem].size(); i++)
        {
            //si no fue visitado lo marca como visitado
            //y sis estaba visitado, no hace nada
            int elemVec = grafo[elem][i];
            if(estado[elemVec]==false){
                estado[elemVec]=true;
                cout<<endl<<"añadiendo: "<<elemVec<<endl;
                vecinos.push(elemVec);
            }else{
                cout << "descartando: "<<elemVec<<endl;
            }
        }
    }
    mostrar_estados(estado);
}


int main()
{
    construye_grafo();
    mostrar_grafo();
    cout << "ingrese nodo a visitar:"<<endl;
    int g; cin>>g;
    while(g<nro_nodos){
        bfs(g);
        mostrar_grafo();
        cout <<endl<< "ingrese nodo a visitar:"<<endl;
        cin>>g;
    }


    return 0;
}
