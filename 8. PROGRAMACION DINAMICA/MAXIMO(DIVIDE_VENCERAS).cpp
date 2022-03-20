#include <bits/stdc++.h>
using namespace std;

//creando un vector con datos aleatorios
int vec [15];
int n=15;


void mostrar(){
    for (int i = 0; i < n; i++)
        cout << vec[i] << "  ";
    cout <<endl;
}

void llenar(){

    for (int i = 0; i < n; i++)
        vec[i] = 0;
    int num;
    for (int i = 0; i < n; i++){
        num = rand()%n+1;
        vec[i] = num;
    }
    cout <<endl;
}

//buscando max y min Antigüo
void max_min_itera(){
    int max;
    max==vec[0];
    for (int i = 1; i < n; i++)
    {
        if(max<vec[i])
            max = vec[i];
    }
    printf("maximo:%d ",max);
    cout <<endl;
}

int maximo(int a, int b){
    return (a>b) ? a : b;
}

int minimo(int a, int b){
    return (a<b) ? a : b;
}

int max_min_divide_venceras(int left, int right){
    if(left == right){
        return vec[left];
    }else if(left == right-1){
        return (maximo(vec[left],vec[right]));
    }else{
        int mitad = (left+right)/2;
        int max_izq = max_min_divide_venceras(left,mitad);
        int max_der = max_min_divide_venceras(mitad+1,right);
        return (maximo(max_izq,max_der));
    }
}

int main()
{
    llenar();
    mostrar();
    //max_min_itera();
    int max = max_min_divide_venceras(0,n-1);
    cout << "maximo: "<<max<<endl;
    return 0;
}
