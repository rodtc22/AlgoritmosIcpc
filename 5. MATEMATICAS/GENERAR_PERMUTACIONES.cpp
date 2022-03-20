#include <bits/stdc++.h>
using namespace std;
int n;
int vec[1000000],p[10000000];
bool perm[1000000];

void siguiente_permutacion(int pos){
	if(pos== n){
		for(int i = 0 ; i < n ; i++) cout << p[i]<<" ";
		cout << endl; 
	}else{
		for(int i = 0 ;i < n ; i++ ){
			if(!perm[i]){
				perm[i] = true;
				p[pos] = vec[i];
				siguiente_permutacion(pos+1);
				perm[i] = false;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> vec[i];
	siguiente_permutacion(0);
	return 0;
}
