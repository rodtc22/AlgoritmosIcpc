#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int tree[1000000];


//AQUI MUESTRO CUALQUIER VECTOR HASTA EL TAMAÑO QUE DESEE
void mostrar_vector(int v[],int tam){
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}

//AQUI REALIZO LA OPERACIO  QUE ME PIDAN
int operacion(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

//AQUI CONSTRUYO EL SEGMENT TREE A PARTIR DE UN VECTOR QUE ME DAN,
//RANGO LEFT Y RANGO RIGHT, ADEMAS DE UN ID QUE ME SERVIRÁ PARA
//PONER EN CIERTA POSICION DE MI ARRAY(TREE) EL RESULTADO
//QUE TENGA LA OPERACION DESEADA
int init(int vec[], int left, int right, int id){
    if(left==right)
    {
        tree[id] = vec[left];//pongo el valor del vector al array tree
        return vec[left];
    }else
    {
        int mitad = (left+right)/2;//calculo la mitad del rango
        int izq = init(vec, left, mitad, id*2);//construyo nodo izq
        int der = init(vec, mitad+1, right, (id*2)+1);//construyo nodo der
        int resultado = operacion(izq,der);//hago la operacion
        tree[id] = resultado;//pongo la operacion al array tree
        return resultado;
    }
}

//QUERY ES DONDE HAGO LAS CONSULTAS EN MI RANGO i,j
int query(int vec[], int left, int right, int i, int j, int id){

   // cout << "rango: "<<left<<"-"<<right<<endl;

    if(left >= i && right <= j)
    {
       // cout << "retorno: "<<tree[id]<<endl;
        return tree[id];
    }
    if(left>j || right<i)
    {
       // cout << "retorno neutro: \n";
        int neutro = 99999999;
        return neutro;
    }
    else
    {
        int mitad = (left+right)/2;
        int izq = query(vec, left, mitad, i, j, id*2);
        int der = query(vec, mitad+1, right, i, j, id*2+1);
        int resultado = operacion(izq,der);
        return resultado;
    }
}

//EL UPDATE ME PIDE UNA POSICION Y UN ELEMENTO EL CUAL
//DONDE PARA ACTUALIZARLO DEBO IR HASTA EL NODO HOJA DE SU POSICION
//VOY PREGUNTANDO SI LA DERECHA ES MENOR A LA POSICION A PONER
//O QUE LA IZQUIERDA ES MAYOR A LA POSICION QUE QUIERO
int update(int vec[], int left, int right, int id, int pos, int elem){

    //AQUI RETORNO UN NEUTRO POR SI MI POSICION NO TIENE NADA QUE VER CON EL RANGO QUE ESTÁ A CARGO
    if(right < pos || left > pos){
        int neutro = 999999999;
        return neutro;
    }
    if(left == right ){
        vec[left] = elem;
        tree[id] = vec[left];
        return elem;
    }else{
        int mitad = (left+right)/2;
        int der=update(vec,left,mitad,id*2,pos,elem);
        int izq=update(vec,mitad+1,right,id*2+1,pos,elem);
        int resultado = operacion(izq,der);
        tree[id]=resultado;
        return resultado;
    }
}


int main(){

    n=6;
    int vec [] = {1,4,-1,5,2,3};
    mostrar_vector(vec,n);
    init(vec,0,n-1,1);
    mostrar_vector(tree,4*n);
    cout << "rango [0-1]\n"<<query(vec,0,n-1,0,1,1)<<endl;
    cout << "rango [1-3]\n"<< query(vec,0,n-1,1,3,1)<<endl;
    cout <<"rango [3-5]\n"<< query(vec,0,n-1,3,5,1)<<endl;
    update(vec,0,n-1,1,3,-2);
    mostrar_vector(vec,n);
    mostrar_vector(tree,4*n);
    return 0;
}
