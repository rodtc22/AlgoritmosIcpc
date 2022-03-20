#include <bits/stdc++.h>
using namespace std;

vector<int>cnt,kmp;

//construyendo el vector para tener el patron
void build_pat(string p){
	//ponemos que todos los prefijos-sufijos sean de longitud cero
	cnt.assign(p.size(),0);
	int len=0,i = 1;
	while(i<p.size()){
		//si son iguales, aumenta los dos en uno para matchear los siguientes
		if(p[i]==p[len]){
			len++;
			cnt[i]=len;
			i++;
		}else{
			//si no matchea y la longitud es cero, entonces sigue no mas, 
			//ya que el prefijo-sufijo es cero 
			if(len == 0){
				i++;
			//si no matchea pero sigue habiendo para hacer matchear, entonces
				//entonces me voy al siguiente sufijo-prefijo mas pequenio que hay
			}else{
				len = cnt[len-1];
			}
		}
	}
	for(auto c:p) cout<<c<<" ";cout<<endl;
	for(auto a:cnt) cout<<a<<" ";cout<<endl;
}

/*construyendo el array para hacer el kmp, no es necesario
que pongamos un vector para el kmp,pero,practicamente, seria
como hacer el mismo procedimiento que el patron, ya que 
solamente cuando llega a ser el tamanio del patron , es cuando
sabemos que ya hubo una ocurrencia del patron*/

void kmp_search(string t, string p){
	//primero haz el patron del match
	build_pat(p);
	kmp.assign(t.size(),0);
	int len = 0 ;
	int i = 0;
	while(i<t.size()){
		//si ya encontraste todo el patron, entonces, busca el prefijo-sufijo
		//mas pequenio que haya para seguir matcheando
		if(len == p.size()){
			len = cnt[len-1];
		}
		//si matchean, entonces avanza los dos en una posicion
		if(t[i]==p[len]){
			len++;
			kmp[i]=len;
			i++;
		}else{
			//si no matchea y la longitud es cero, entonces sigue no mas, 
			//ya que el prefijo-sufijo es cero 
			if(len == 0){
				i++;
			//si no matchea pero sigue habiendo para hacer matchear, entonces
				//entonces me voy al siguiente sufijo-prefijo mas pequenio que hay
			}else{
				len = cnt[len-1];
			}
		}
	}
	for(auto c:t) cout<<c<<" ";cout<<endl;
	for(auto d:kmp) cout<<d<<" ";cout<<endl;
}

int main(){
	string word;
	string pat;
	cin>>word>>pat;
	kmp_search(word,pat);
	return 0;
}