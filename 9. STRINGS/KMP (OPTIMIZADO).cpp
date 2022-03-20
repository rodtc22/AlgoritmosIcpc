#include <bits/stdc++.h>
using namespace std;

vector<int>cnt,kmp;

//PRIMERA FORMA DE OPTIMIZAR
//complejidad O(|t|+|p|)
void kmp_fast(string t, string p,bool sw){
	if(sw) cnt.assign(p.size(),0);
	else kmp.assign(t.size(),0),kmp_fast(p,p,1);
	
	int len = 0,i=sw,n;
	if(sw) n = cnt.size();
	else n = kmp.size();

	while(i<n){
		if(!sw && len == p.size()) len= cnt[len-1];
		if(t[i]==p[len]){
			len++;
			sw? cnt[i]=len:kmp[i]=len;
			i++;
		}else{
			if(len==0) i++;
			else len = cnt[len-1];
		}
	}
}

void mostrar(string a, string b){
	cout<<"TEXTO\n";
	for(auto c:a) cout<<c<<" ";cout<<endl;
	for(auto d:kmp) cout<<d<<" ";cout<<endl;
		cout<<"PATRON\n";
	for(auto c:b) cout<<c<<" ";cout<<endl;
	for(auto d:cnt) cout<<d<<" ";cout<<endl;	
}

//SEGUNDA FORMA DE OPTIMIZAR
void kmp(const string &T, const string &P) {
  if (P.empty()) return ;

  vector<int> pi(P.size(), 0);
  vector<int> ti(T.size(), 0);

  for (int i = 1, k = 0; i < P.size(); ++i) {
    while (k && P[k] != P[i]) k = pi[k - 1];
    if (P[k] == P[i]) ++k;
    pi[i] = k;
  }

  for (int i = 0, k = 0; i < T.size(); ++i) {
    while (k && P[k] != T[i]) k = pi[k - 1];
    if (P[k] == T[i]) ++k;
    ti[i]=k;
  }
}

int main(){
	string word;
	string pat;
	cin>>word>>pat;
	kmp_fast(word,pat,0);
	mostrar(word,pat);
	return 0;
}