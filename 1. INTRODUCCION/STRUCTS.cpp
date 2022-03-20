#include <bits/stdc++.h>
using namespace std;

//DECLARAMOS EL STRUCT ANTES DE LA CLASE PRINCIPAL
struct punto{
    //declaramos las variables que tendrรก nuestro struct
    long long x,y;
    //creamoos un constructor para crear valores por defecto o asignarle
    punto(long long x=0, long long y=0) : x(x),y(y){}

    //podemos hacer un metodo solo para mostrar puntos
    void mostrar(){ cout << x<<" "<<y<<endl;}

    //sobrecargamos operadores para trabajar con los puntos
    punto operator +(punto p){return { x+p.x , y+p.y};}     //suma de dos puntos

    punto operator -(punto p){return { x-p.x , y-p.y};}     //resta de dos puntos

    punto operator *(long long k) {return {k*x , k*y};}     //multiplicacion por escalar

    long long operator *(punto p) {return {x*p.x + y*p.y};} //producto escalar

    long long operator ^(punto p) {return {x*p.y - y*p.x};} //producto cruz

    double modulo(){return hypotl(x,y);}                 //modulo del vector vector

    //tengo que ponerlo si voy a hacer ordenacion en mi struct
    bool operator <(punto b)const{
        if(x==b.x)return y > b.y;
        return x > b.x;
    }
};

int main(){
    //iniciamos la variable punto con variables por defecto
    punto a;
    cout <<a.x<<" "<<a.y<<endl;

    //iniciamos una variable con valores que le asignamos por defecto
    punto b(4,5);
    cout << b.x <<" "<<b.y<<endl;

    //asignamos variables a el "punto" desde teclado
    //scanf("%lld %lld",&a.x,&a.y);
    //cout <<a.x<<" "<<a.y<<endl;

    punto c = a+b;
    c.mostrar();

    c=a-b;
    c.mostrar();

    cout << c.modulo()<<endl;
    //c= 8*c;  no es lo mismo que c = c*8
    c= c*8;
    c.mostrar();

    //usando estructuras de datos con los structs
    vector<punto> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    for(int i= 0 ; i < vec.size() ; i++) printf("%d. %lld %lld\n",(i+1),vec[i].x,vec[i].y);
    sort(vec.begin(),vec.end());
    for(int i= 0 ; i < vec.size() ; i++) printf("%d. %lld %lld\n",(i+1),vec[i].x,vec[i].y);
    
    return 0;
}

/*

PODEMOS TAMBIEN USAR CIN  Y COUT PARA LEER (TRAINING CAMP UMSA)

struct punto{
	double x, y;
	punto(int x = 0, int y= 0):x(x),y(y){}
};

ostream &operator << (ostream &COUT , punto X){
	COUT << "{"<<X.x<<","<<X.y<<"}";
	return COUT;
}

istream &operator >> (istream &CIN, punto &X){
	CIN >> X.x >>X.y;
	return CIN;
}

int main(){
	punto a;
	cin >> a;
	cout <<a<<endl;
	return 0;
}
*/