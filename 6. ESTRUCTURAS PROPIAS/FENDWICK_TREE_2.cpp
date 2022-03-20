#include <bits/stdc++.h>
using namespace std;

void leerVec(int n , int vec[]){
    for(int i = 1 ; i <= n ;i++)
        scanf("%d",&vec[i]);
}

void mostrarVec(int n , int vec[]){
    for(int i = 1 ; i <= n ; i++)
        printf("%d ",vec[i]);
    printf("\n");
}

int negacion(int x){
    int tam = log2(x)+1;
    int num = 1<<tam;
    num-=1;
    num = x ^ num;
    return num + 1;
}

int bitMenosSig(int x){
    return x & negacion(x);
}

void crear(int n, int tree[],int vec[]){
    for(int i = 1 ; i <= n ; i++){
        int pos = i;
        do{
            tree[pos]=tree[pos]+vec[i];
            pos = pos + bitMenosSig(pos);
        }while(pos <= n);
    }
}

int quitarBitMenosSig(int x){
    return x ^ bitMenosSig(x);
}

void add(int n, int pos, int val,int vec[],int tree[]){
    int sum = 0;
    int i = pos;
    do{
        tree[pos] = tree[pos] - vec[i] + val;
        pos = pos + bitMenosSig(pos);
    }while(pos<=n);
    vec[i] = val;
}

int sumaParcial(int n, int pos,int tree[]){
    int sum = 0;
    do{
        sum += tree[pos];
        pos = quitarBitMenosSig(pos);
    }while(pos >= 1);
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    //SERÁ DE N+1 PARA QUE EMPIECE DESDE LA POSICION 1 Y NO 0
    int vec[n+1];
    leerVec(n,vec);
    printf("MOSTRANDO LOS VECTORES: \n");
    mostrarVec(n,vec);    
    //CREAMOS EL NUEVO VECTOR DEL MISMO TAMAÑO
    int tree[n+1];
    memset(tree,0,sizeof(tree));
    crear(n,tree,vec);
    mostrarVec(n,tree);

    int a,b,dec;
    printf("1=add(x,y)        2=sumaParcial(x)\n");
    while(scanf("%d",&dec)==1){
        if(dec==1){
            scanf("%d %d",&a,&b);
            add(n,a,b,vec,tree);
            printf("Actualizado correctamente.\nMOSTRANDO VECTORES\n");
            mostrarVec(n,vec);  
            mostrarVec(n,tree);        
        }else{
            scanf("%d",&a);
            printf("suma hasta %d es: %d",a,sumaParcial(n,a,tree));
        }
        printf("\n1=add(x,y)        2=sumaParcial(x)\n");
    }

    return 0;
}
// 8 -1 3 0 -2 4 5 -3 8