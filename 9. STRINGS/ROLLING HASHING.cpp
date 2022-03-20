#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int base = 256;
const ll p = 1e9+7;
vector<ll>B,H;

void funcion(string& s){
   B.resize(s.size()),H.resize(s.size());
   ll hash = 0;
   B[0]=1;
   for(int i = 0 ; i < s.size() ; i++){
      hash = (1LL * hash * base + int(s[i]))%p;
      H[i]=hash;
      if(i>0) B[i]= (base * B[i-1])%p;
   }
}

int main(){
   string s;
   cin>>s;
   funcion(s);
   int l ,r;
   ll val = 0;
   // estas ya son las consultas para los substrings [l,r]
   while(cin>>l>>r){
      if(l) val = ((H[r]-(H[l-1]*B[r-l+1]))%p+p)%p;
      else val = H[r];
      cout<<val<<endl;
   }
   return 0;
}
