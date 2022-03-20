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

int n,m;
const int N=1e3,oo=1e9;
int dp[N][N];
int dp_nro[N][N];
int grid[N][N];

//encuentra cual es el camino minimo
int f_min(int i, int j){
	if(i==n-1 && j==m-1) return dp[i][j]=grid[i][j];
	if(i==n || j==m) return oo;
	if(grid[i][j]<0) return oo;
	int &ans = dp[i][j];
	if(ans==-1){
		ans = min(f_min(i+1,j),f_min(i,j+1))+grid[i][j];
	}
	return ans;
}

//encuentra el nro de caminos minimos que hay
//basandonos en la anterior dp que tenia los caminos minimos
int f_nro_min(int i, int j){
	if(i==n-1 && j == m-1) return dp_nro[i][j]=1;
	if(i==n || j == m) return 0;
	if(grid[i][j]<0) return dp_nro[i][j]=0;
	int &ans = dp_nro[i][j];
	if(ans != -1) return ans;
	int d = f_min(i+1,j);
	int r = f_min(i,j+1);
	ans = 0;
	if(d+grid[i][j]==dp[i][j]){
		ans += f_nro_min(i+1,j);
	}
	if(r+grid[i][j]==dp[i][j]){
		ans+=f_nro_min(i,j+1);
	}
	return ans ;
}

//nos basamos que solo es una solucion
//entonces usamos el que tiene solo la minima solucion
string path;
void build(int i ,int j){
	if(i==n-1 && j == m-1) return ;
	if(i==n || j==m) return ;
	//if(grid[i][j]<0) return;
	int d = f_min(i+1,j);
	int r = f_min(i,j+1);
	if(r+grid[i][j]==dp[i][j]){
		path.push_back('R');
		build(i,j+1);
		return;
	}
	if(d+grid[i][j]==dp[i][j]){
		path.push_back('D');
		build(i+1,j);	
		return;
	}
	path="NO EXISTE EL CAMINO MINIMO";
}

//nos basamos en el que tiene el nro de soluciones
void buildK(int i,int j ,int k){
	if(i == n-1 && j == m-1) return;
	if(i==n || j == m) return;
	int d = dp_nro[i+1][j];
	int r = dp_nro[i][j+1];
	if(k<=d){
		path.push_back('D');
		buildK(i+1,j,k);
		return;
	}
	path.push_back('R');
	if(d<0) d=0;
	buildK(i,j+1,k-d);
}

int main(){
	cin>>n>>m;
	int i,j;
	FOR(i,0,n) FOR(j,0,m) cin>>grid[i][j];
	FOR(i,0,n){
		FOR(j,0,m) cout<<grid[i][j]<<" ";
		cout<<endl;
	}
	
	memset(dp,-1,sizeof dp);
	int ans = f_min(0,0);
	cout<<"valor del camino minimo:"<<ans<<endl;
	FOR(i,0,n){
		FOR(j,0,m) cout<<dp[i][j]<<" ";
		cout<<endl; 
	}
	
	memset(dp_nro,-1,sizeof dp_nro);
	int nro = f_nro_min(0,0);
	cout<<"nro de caminos minimos: "<<nro<<endl;
	FOR(i,0,n){
		FOR(j,0,m) cout<<dp_nro[i][j]<<" ";
		cout<<endl;
	}
	path.clear();
	build(0,0);
	cout<<"una ruta para la solucion: "<<path<<endl;

	cout<<"MOSTRAMOS TODAS LAS SOLUCIONES EN ORDEN LEXICOGRAFICAMENTE MENOR\n";
	FOR(i,1,nro+1){
		path.clear();
		buildK(0,0,i);
		cout<<path<<endl;
	}

}