#include <bits/stdc++.h>
using namespace std;
const int oo = INT_MAX;
/*
struct STree{

	//esta es la informacion de cada nodo del segment tree
	//necesitamos el hijo izq,der
	STree *left,*right;
	int l,r,m,valor,neutro=0;

	//creamos el constructor de cada nodo
	STree(int l, int r) : l(l),r(r),valor(neutro){
		//un nodo tendrá un hijo si y solo si no es un solo valor
		if(l!=r){
			m = (l+r)/2;
			//debemos inicializar los nodos hijos ya que son punteros
			//ES COMO DECIR QUE EL HIJO IZQ ES OTRO PEQUEÑO SEGMENT TREE
			left = new STree(l,m);
			right = new STree(m+1,r);
		}		
	} 

	//ESTA FUNCION NOS PERMITE ACTUALIZAR UN NODO DE NUESTRO SEGMENTE TREE
	void update(int pos, int val){
		if(l==r) {
			//como es un solo nodo el unico nodo que puede
			//llegar a este estado es el nodo de la posicion que
			//queremos ya que nos adentramos usando la tecnica
			// de la busqueda binaria
			valor = val;
		}else{
			if(pos<=m){ //pos esta del lado izquierdo
				//DECIMOS QUE EL HIJO IZQUIERDO SIGA BUSCANDO
				left->update(pos,val);
			}else{//pos está del lado derecho
				//DECIMOS QUE EL HIJO DERECHO SIGA BUSCANDO
				right->update(pos,val);
			}
			valor = left->valor + right->valor;
		}
	}

	//PREGUNTAMOS EN UN CIERTO RANGO [a,b]
	int get(int a, int b){
		if(a>r || b<l){
			//entra si:
			//el rango que quiero esta muy a la izquierda o 
			//muy a la derecha del rango que maneja este nodo
			//a,b=[1,3] l,r=[4,6] ó l,r=[4,6] a,b=[7,10]
			return neutro;
		}

		if(a<=l && r<=b){
			//entra si todo el rango de este nodo
			//está dentro de lo que necesito
			//a,b=[2,6] l,r=[3,5]
			return valor;
		}

		//cuando llega a esta parte entonces debe preguntar a 
		//sus dos nodos hijos
		return left->get(a,b) + right->get(a,b);

	}
};
*/

//ESTE SEGMENT TREE ES SIN COMENTARIOS SOLO PARA VER CODIGO

struct STree{
	STree *left,*right;
	int l,r,m,minimo;
	STree(int l, int r) : l(l),r(r),minimo(oo) {
		if(l!=r){
			m = (l+r)/2;
			left = new STree(l,m);
			right = new STree(m+1,r);
		}
	}
	void update(int pos , int val){
		if(l==r) minimo = val;
		else{
			if(pos<=m) left->update(pos,val);
			else right->update(pos,val);
			minimo = min(left->minimo,right->minimo);
		}
	}
	int query(int a, int b){
		if(a>r || b<l) return oo;
		if(a<=l && r<=b) return minimo;
		return min(left->query(a,b),right->query(a,b));
	}
};


//YA QUE ES UN STRUCT TENEMOS LA VENTAJA DE TENER
// vector<STree> vec;
int main(){
	//leer el numero de elementos
	int n;
	cin >> n;
	STree st(0,n-1); //controla el rango [0,n-1] -> n-elementos

	//ahora llenamos es segment tree usando el update
	//y notaremos que no llenamos las posiciones como un vector
	//si no que llenamos el nodo que controla un rango de 1 elemento

	int x;
	for(int i = 0 ; i < n ; i++){
		cin >>x;
		st.update(i,x);
	}
	int a,b;
	//termina cuando a = 0, b = 0
	while((cin >> a>>b),(a||b))
		cout << st.query(a-1,b-1)<<endl;
	return 0;
}