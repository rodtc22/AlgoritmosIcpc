#include <bits/stdc++.h>
using namespace std;

const int N = 1000*1000;

int nxt[N][26]; // estoy en altura i y quiero saber cual es el numero que identifica en ir a la letra j{a,b,...,z}
int cnt[N];		// cuenta el nuemro de palabras que pasaron por ese nodo, ya que todos los nodos estan asociados con un numero
bool finish[N];	// me indica si cierto nodo es terminador de una palabra
int nodes = 1;	// es el valor que ira avanzando para ir identificando a nuevos nodos que se vayan agregando

void trie(string x, int d){
	int i= 0;	//iniciamos en el nivel cero, que pertenece a la cadena vacia
	for(auto c: x){	
		int j = c-'a';
		if(nxt[i][j]==0){// no existe un nodo con esa letra desde ese nivel
			nxt[i][j]=nodes;
			nodes++;
		}
		i=nxt[i][j]; //anda a la fila indice del nodo al que sigues
		cnt[i]+=d;
		//si d==1 entonces significa que sumale que hay una palabra que pasa por ese noso
		//si d==-1  entonces significa que restale uno  a ese nodo, ya que estamos quitando una palabra que pasa por ese nodo
	}
	if(d==1) finish[i]=1;
	else finish[i]=0;
}

int query_number(string x){
	int i=0;
	for(auto c:x){
		int j = c-'a';
		if(nxt[i][j]==0) return 0; //si no existe entonces sale no mas ya que hay cero palabras con ese prefijo
		i = nxt[i][j];// ve a la fila que tiene el indice de ese nodo
	}
	return cnt[i];
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int d;
		cin>>d;
		string x;
		cin>>x;
		if(d == -1){// elimina una palabra
			//notemos que las palabras que se pueden eliminar, deben estar si o si  en el diccionario
			trie(x,d);
		}else if(d==1){//aniade una palabra
			trie(x,d);
		}else{//pregunta cuantas palabras hay con el prefijo que estamos enviando
			cout<<query_number(x)<<endl;
		}
	}
	return 0;
}