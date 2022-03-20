#include <bits/stdc++.h>
using namespace std;

int main(){
    
    /*PRIMERA FORMA ponemos la frase en un caracter
    char x[100];
    while(gets(x)){
        cout<< x<<endl;
    }*/

    /*SEGUNDA FORMA solo lee una frase 
    const int dim = 500;
    char linea [dim];
    cin.get(linea,dim);
    cout << "cadena: "<<linea<<endl;
    */

   /*TERCERA FORMA un nro con n-lineas
    int n;
    cin >> n;
    int dim=1000;
    char linea[dim];
    cin.get();
    for (int  i = 0; i < n; i++)
    {
        gets(linea);
        cout << "nro: "<<(i+1)<<" frase: "<<linea<<endl;
    }*/

    /*CUARTA FORMA leer frases hasta que la ultima sea fin
    ademas cuando presionamos enter en la linea, luego 
    empieza a leer los dos numeros
    int dim = 500;
    char linea[dim];
    int a,b;
    while(gets(linea)){
        if(strcmp(linea,"fin")==0)
            break;
        cin >>a>>b;
        cin.get();
        cout <<linea <<"suma: "<<a+b<<endl;
    }
    */

    	/*QUINTA FORMA (LA MEJOR)
	string x;
	getline(cin,x);
	coout<<x<<endl;
	*/

   /*
   parece que cuando hacemos entradas de frases, luego de
   hace cualquier entrada hay que poner cin.get() para, 
   evitar que se solape el dato

    obtiene el tamaño de la cadena introducida
   long long tam = cin.gcount();
   */
    return 0;
}
