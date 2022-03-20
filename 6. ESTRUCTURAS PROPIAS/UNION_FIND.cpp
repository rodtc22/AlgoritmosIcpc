#include <iostream>
#include <cstdlib>
using namespace std;

int n=5;
int padre [5];

//ME PERMITE PONER LOS CONJUNTOS APUNTANDO A ELLOS MISMOS
//COMO SUS NODOS PADRE;
void init(){
    for(int  i = 0 ; i < n ; i++ ){
        padre[i] = i;
    }
}

//BUSCA EL PADRE DEL ELEMENTO X ADEMAS HACE UNA
//CONEXION DIRECTA A SU PADRE
int find(int x){
    if(padre[x] == x){
        return x;
    }else{
        int a = find(padre[x]);
        padre[x] = a;
        return a;
    }
}

//ME INDICARÁ SI ESTOS DOS ELEMENTOS ESTÁN O NO EN EL MISMO
//CONJUNTO, VIENDO SI TIENE LOS MISMOS PADRES.S
bool disjuntos(int a , int b){
    return (find(a) != find(b));
}

//TOMA DOS ELEMENTOS DE UN CONJUNTO Y LOS UNE,
//VERIFICANDO QUE NO SEAN DEL MISMO CONJUNTO
//EL CRITERIO DE UNION LO PONDRÉ QUE SEA EL MAYOR
void unir(int a, int b){
    int padreA,padreB;
    if(disjuntos(a,b)){
        padreA = find(a);
        padreB = find(b);
        if(padreA > padreB){
            padre[padreB] = padreA;
        }else{
            padre[padreA] = padreB;
        }
    }
}



int main()
{
    init();
    unir(1,0);
    unir(4,1);
    cout << find(1)<<endl;
    unir(2,3);
    cout << find(3)<<endl;
    cout << find(2)<<endl;
    unir(3,4);
    cout << find(3)<<endl;

    /*TAMBIEN PUEDO PONER EL ARRAY EN ESTE TIPO DE DATO
    pair <int, string> r;
    r.first=78;
    r.second=" : setenta y ocho";
    cout << r.first <<r.second<<endl;

    pair <int, char> vec [10];
    char a = 'a';
    for(int i = 0 ; i < 10 ; i++ ){
        vec[i].first=i;
        vec[i].second=a++;
        cout << vec[i].first<<" - "<<vec[i].second<<"  \n";
    }
    */
    return 0;
}
