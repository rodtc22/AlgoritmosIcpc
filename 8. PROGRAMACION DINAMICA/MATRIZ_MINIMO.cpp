#include <bits/stdc++.h>
using namespace std;
#define forn(i,a,b) for(i = a ; i < b ;i++)
int t[100][100],dp[100][100],n,m,i,j;
string path="";

void llenar(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    forn(i,0,n){
        forn(j,0,m){
            cin >> t[i][j];
        }
    }
}

void mostrardp(){
    cout <<"MATRIZ : \n";
    forn(i,0,n){
        forn(j,0,m){
            cout <<dp[i][j]<<" ";
        }
        cout <<endl;
    }     
}

int min_path(int i, int j){
    int &r = dp[i][j];
    if(r!=-1) return r;
    if(i==n-1 && j ==m-1) return r=t[n-1][m-1];
    r = (1<<31)-1; //obtiene el maxgimo de los numeros
    if(i < n-1 ) r = min(r, t[i][j]+min_path(i+1,j));
    if(j < m-1 ) r = min(r, t[i][j]+min_path(i,j+1));
    return r;
}

void built(int i, int j){
    if(i == n-1 && j == m-1) return;
    if(i < n-1 && min_path(i,j) == t[i][j]+ min_path(i+1,j)){
        path.push_back('A');
        built(i+1,j);
        return;
    }
    if(j<m-1 && min_path(i,j) == t[i][j] + min_path(i,j+1)){
        path.push_back('D');
        built(i,j+1);
        return;
    }
} 
//no funciona
int build_alfil(int i , int j , int k , bool b){
    int &r = dp[i][j];
    if(r!=-1) return r;
    if(i == n-1 && j == m-1) return r = t[i][j];
    r = 2000000000;
    if(i<n-1) return r = min (r, t[i][j]+build_alfil(i+1,j,k,0));
    if(j<m-1) return r = min (r, t[i][j]+build_alfil(i,j+1,k,0));
    if(i<n-1 && j < m-1 && k>0) 
        r = min (r,t[i][j] + build_alfil(i+1,j+1,k-1,1));
    if(i<n-1 && j<m-1 && b)
        r = min(r,t[i][j]+build_alfil(i+1,j+1,k,1));
}

int main(){
    llenar();
    min_path(0,0);
    mostrardp(); 
    built(0,0);    
    cout<<"La ruta es: " << path<<endl;
    build_alfil(0,0,1,1);
    mostrardp(); 
    return 0;
}