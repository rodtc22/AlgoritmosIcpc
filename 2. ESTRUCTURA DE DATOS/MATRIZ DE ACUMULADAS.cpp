#include <bits/stdc++.h>
using namespace std;
//-------------------------------------------MACROS---------------------------------------------
#define 	TIEMPO_CORRIDA		cerr << "tiempo: "<<1.0*clock()/CLOCKS_PER_SEC <<" seg.\n";
#define 	FILES				freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define 	FORIT(it,e)			for(it = e.begin() ; it != e.end() ; it++)
#define 	FOR(i,a,b)			for(i = a ; i < b ; i++)
#define 	RFOR(i,a,b)			for(i = a ; i >= b ;i--)
#define 	FORSW(i,a,b,sw)		for(i = a ; i < b && sw ; i++)
#define 	RFORSW(i,a,b,sw)	for(i = a ; i >= b && sw ; i--)
#define 	fast 				ios::sync_with_stdio(false),cin.tie(),cout.tie();
#define 	to_int(x) 			atoi(x.data())
#define 	to_long(x) 			atoll(x.data())
#define 	ALL(x) 				x.begin(),x.end()
#define 	CMP(x,c)			x.begin(),x.end(),cmp
#define 	RALL(x) 			x.rbegin(),x.rend()
typedef 	long long 			ll;
typedef 	pair<int,int> 		ii;
typedef 	pair<ll,ll> 		pl;
const		int 				M = 1e9+7;
const		double 				PI = 3.1415926535897932384626433832795028841;
const		int 				mov_x[]={0,0,1,-1};
const		int 				mov_y[]={1,-1,0,0};
//---------------------------------------------------------------------------------------------

int main(){
	int n,m;
	int i,j;
	scanf("%d%d",&n,&m);
	int vec1[n],vec2[m];
	int mat[n][m],grid[n][m];
	FOR(i,0,n) scanf("%d",&vec1[i]); 
	FOR(i,0,m) scanf("%d",&vec2[i]);
	FOR(i,0,n) FOR(j,0,m) mat[i][j]=vec1[i]*vec2[j];
	FOR(i,0,n){
		grid[i][0]=mat[i][0];
		FOR(j,1,m){
			grid[i][j]= grid[i][j-1]+mat[i][j];
		}
	}
	FOR(j,0,m){
		FOR(i,1,n){
			grid[i][j]+=grid[i-1][j];
		}
	}
	FOR(i,0,n){FOR(j,0,m) cout <<grid[i][j]<<" ";cout<<endl;}
}