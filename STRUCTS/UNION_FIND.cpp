#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
	int n,nroSets;
	int uf[200005]; //podemos bajar el tamanio

	UnionFind(int n1){n = n1;nroSets = n;reset(n+1);}
	void reset(int n ){fill(uf,uf+n,-1);}
	int find(int x){return (uf[x]<0)? x: uf[x] = find(uf[x]);}
	bool same_component(int x, int y){ return find(x)==find(y);}
	void join(int x, int y){
		x = find(x),y = find(y);
		if(x>y) swap(x,y);
		if(same_component(x,y)) return;
		nroSets--;
		uf[x]+=uf[y];
		uf[y]=x;
	}
	//metodos que yo quiera
	//tener cuidado cuando manejo n, ya que en realidad hago de 0...n
	void mostrar(){
		for(int i = 0 ; i <= n ; i++) find(i);
		for(int i = 0 ; i <= n ; i++) cout<<i<<" "<<uf[i]<<endl;cout<<endl;
	}
};

int main(){
		UnionFind u(5);
		// u.join(2,3);    
		//u.mostrar()
		//u.countComponents()
	return 0;
}