#include <bits/stdc++.h>
using namespace std;

int main(){
    //estas dos lineas se ponen para que la entrada 
    //y la salida de los strings sea mas rapida
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ahora para hacer la entrada mediante un archivo externo
    //y que muestre la salida en otro archivo externo
    //SIEMPRE SE PONE AL INICIO
    ifstream fin("entrada.txt");
    ofstream fout("salida.txt");

    //ahora se hace el codigo como lo conocemos, la unica
    //diferencia es que la salida se guarda en un archivo

    int n;
    string x;
    //cout <<"Ingrese el nro de palabras: ";
    fin>> n;
    for(int i = 0 ; i < n ; i++){
      
        fin >> x;
        fout << "nro: "<<(i+1)<<"\tcadena: "<<x<<endl;
    }

    return 0;
}