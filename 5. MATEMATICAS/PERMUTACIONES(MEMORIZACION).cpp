#include <bits/stdc++.h>
using namespace std;
 
#define TIEMPO_CORRIDA cerr << "tiempo: "<<1.0*clock()/CLOCKS_PER_SEC <<" seg.\n";
#define FILES freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define FOR(i,a,b) for(i = a ; i < b ; i++)
#define RFOR(i,a,b) for(i = a ; i >= b ;i--)
#define FORSW(i,a,b,sw) for(i = a ; i < b && sw ; i++)
#define RFORSW(i,a,b,sw) for(i = a ; i >= b && sw ; i--)
#define fast ios::sync_with_stdio(false),cin.tie(),cout.tie();
#define to_int(x) atoi(x.data())
#define to_long(x) atoll(x.data())
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long ll;
typedef pair<int,int> ii;
const int modN = 1e9+7;
const double PI = 3.1415926535897932384626433832795028841; 

int perm[11];
int tam ;
char f[9*8*7*6*5*4*3*2*1+1][10]={};

int funcion(){
	int i,j,sum=0;
	FOR(i,1,tam+1){
		if(i==tam+1) {sum+=1;continue;}
		int f=1,a=1,cont = 0;
		FOR(j,i+1,tam+1){
			f*=a;
			if(perm[j]<perm[i])cont++;
			a++;
		}
		sum+=(f*cont);
	}
	return sum;
}

void permutacion(int n){
	if(n==tam){
		int i;
		//FOR(i,1,tam+1) cout << perm[i]<<" ";cout <<"\n";
		int pos = funcion();
		FOR(i,1,tam+1) f[pos][i]=perm[i]+48;
	}else{
		int i;
		FOR(i,n,tam+1){
			swap(perm[i],perm[n]);
			permutacion(n+1);
			swap(perm[i],perm[n]);
		}
	}
}

int main(){
	//ESTA ES LA MANERA  DE COMO PODEMOS "MEMORIZAR UNA PERMUTACION"
	/*
	SE HACE DE LA MANERA EN QUE CADA PERMUTACION PUEDE SER MENOR A OTRA
	Y CONTAMOS LAS MANERAS GRACIAS A LA FORMULA funcion() QUE ENCONTRAMOS
	DE ESTA MANERA PODEMOS PONER EN UNA MATRIZ , O VECTOR, DICIENDO
	QUE SOLO HAY UNA PERMUTACION QUE TENGA X PERMUTACIONES MENORES
	
	ENTONCES EN EL VECTOR LO LEERIAMOS DE : VEC[2] = ES UNA PERMUTACION QUE
	SOLO TIENES 2 PERMUTACIONES MENORES A ESTA PERMUTACION.

	COMO POR EJEMPLO VEC[2]= 1 2 4 3 5  QUE SOLO TIENE 2 PERMUTACIONES "MENORES"
	A ESA

	ADEMAS COMO FORMA ADICIONAL DE OPTIMIZACION LOS NUMEROS QUE TIENE LA PERMUTACION
	EN LA MATRIZ LO GUARDAMOS COMO UN CHAR YA QUE OCUPA 1 byte AL CONTRARIO
	 QUE UN INT OCUPA 4 bytes , VALE DECIR QUE SI USARAMOS CHAR EN LUGAR DE INT
	 SOLO PODRIAMOS HACERLO HASTA  N=9
	*/
	FILES
	int i,n,j;
	cin >> n;//n=5
	tam=n;
	FOR(i,1,n+1) perm[i]=i;
	permutacion(1);
	n = 9*8*7*6*5*4*3*2*1;
	FOR(i,0,n+1){ cout << i<<": "; FOR(j,1,tam+1) cout << f[i][j]<<", ";cout <<endl;}
	TIEMPO_CORRIDA
	return 0;
}