#include <bits/stdc++.h>
using namespace std;

//ESTE ES EL MISMO ALGORIMO NORMAL, PERO, SIN COMENTARIOS
void Z1(string x){
   int l=0,r=0, n =x.size();
   vector<int>z(n,0);
   for(int i = 1 ; i< n ; i++){
      if(i>r){
         l = r = i;
         while(r<n  && x[r]==x[r-l]) r++;
         z[i]=r-l;
         r--;
      }else{
         int k = i-l;
         if(z[k]<r-i+1) z[i]=z[k];
         else{
            l = i;
            while(r<n && x[r]==x[r-l]) r++;
            z[i]=r-l;
            r--;
         }
      }
   }
   for(auto c : x) cout<<c<<" ";cout<<endl;
   for(auto d: z) cout<<d<<" ";cout<<endl;
}

// SHORT IMPLEMENTATION OF Z-ALGORITHM
void Z(string s){
   int n = s.size();
   vector<int>z(n);
   int x = 0, y = 0;
   for(int i = 1; i< n; i++){
      z[i]= max(0,min(z[i-x],y-i+1));
      while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
         x =i;y = i+z[i]; z[i]++;
      }
   }
   for(auto c:s) cout<<c<<" ";cout<<endl;
   for(auto d:z) cout<<d<<" ";cout<<endl;
}

int main(){
   string x;
   cin>>x;
   Z1(x);
   return 0;
}
