#include <bits/stdc++.h>
using namespace std;
/*
6 8
5 0 5
1 3 2
3 3 1
9 0 2
2 2 1
7 1 4
1 5 4
4 2 5

*/

//vector <coste,origen,destino> nombre:
vector <pair<int,pair<int,int>>> lista_arcos;
int nro_nodos,nro_arcos, origen,destino,coste;
int padre [1000];

//DECLARANDO DISJOIN SET UNION-FIND
void init(){
    for(int i = 0 ; i < nro_nodos ; i++){
        padre[i]=i;
    }
}

void union_elem(int a, int b){
    padre[a] = b;
}

int find_padre(int elem){
    if(padre[elem] == elem){
        return elem;
    }else{
        return (padre[elem]=find_padre(padre[elem]));
    }
}

//DECLARANDO EL GRAFO
void init_lista_arcos(){
    lista_arcos.clear();
}

void mostrar_lista_arcos(){
    cout <<endl;
    int nroElem = lista_arcos.size();
    for (int i = 0; i < nroElem; i++)
    {
        cout<<"arco #"<<i<<"= ";
        pair <int, int > p = lista_arcos[i].second;
        cout<<" coste: "<<lista_arcos[i].first<<" origen: "<<p.first<<" destino: "<<p.second<<endl;
    }
}

void construye_grafo(){
    cout << "ingrese nro_nodos, nro_arcos: ";
    cin >> nro_nodos>>nro_arcos;
    init_lista_arcos();

    while(nro_arcos>0){
        cout << "ingresar coste, origen, destino: ";
        cin >> coste >> origen>>destino;
        lista_arcos.push_back(make_pair(coste,make_pair(origen,destino)));
        nro_arcos--;
    }
}

//AQUI VIENE LO INTERESANTE
/*inicio el union find, poniendo a todos los nodos como sus mismos padres 
ordeno el vector segun su coste el cual será cambiado de menor
a mayor , entonces tomamos el arco y preguntamos si el padre del nodo origen
es el mismo padre de nodo destino, si lo es entonces es ciclo y no lo
tomamos en cuenta, si no es ciclo, entonces unimos lo dos nodos
y seguimos al arco siguiente preguntado lo mismo
 */
void kruskal(){
    init();
    sort(lista_arcos.begin(),lista_arcos.end());
    nro_arcos = lista_arcos.size();
    for (int i = 0; i < nro_arcos; i++)
    {
        int o = find_padre(lista_arcos[i].second.first);
        int d = find_padre(lista_arcos[i].second.second);
        if(o!= d){
            union_elem(o,d);
            printf("orig: %i, dest: %i cost: %i\n",o,d,lista_arcos[i].first);
        }
    }

}

int main()
{
    construye_grafo();
    mostrar_lista_arcos();
    kruskal();
    return 0;
}
