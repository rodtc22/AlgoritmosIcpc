#include <iostream>
#include <cstdlib>

using namespace std;

int n = 25;
static int m [25];

void mostrar(){
    cout<< "mostrando el vector: \n";
    for(int i = 0 ; i < n ; i++ ){
        cout << m[i] << "  ";
    }
    cout << endl;
}

void llenar(){
    cout << "llenando el vector: \n";
    for(int i = 0 ; i < n ; i++ ){
        int num = rand()%25+1;
        m[i] = num;
    }
    cout <<endl;
}

//EL METODO CONSISTE EN BUSCAR DE FORMA ITERATIVA
//HASTA QUE ENCUENTRE EL PRIMER ELEMENTO IGUAL AL
//QUE MANDAMOS POR PARAMETRO Y RETORNA LA POSICION
int buscar(int e){
    cout << "buscando el nro "<<e<<endl;
    int pos = -1;
    for(int i = 0 ; i < n ; i++ ){
        if(m[i] == e){
            pos=i;
            break;
        }
    }
    cout <<endl;
    return pos;
}

int main()
{
    llenar();
    mostrar();
    int a = buscar(5);
    cout << "La posicion es: "<<a<<endl<<endl;;
    mostrar();

    return 0;
}
