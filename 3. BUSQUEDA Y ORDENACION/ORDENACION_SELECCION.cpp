#include <iostream>

using namespace std;

int n = 25;
int v [25];

void llenar(){
    for(int i = 0 ; i < n ; i++){
        v[i] = rand()%n+1;
    }
}

void mostrar(){
    cout << "\nMOSTRANDO EL VECTOR: \n";
    for (int i = 0 ; i < n ; i++){
        cout << v[i] << "   ";
    }
    cout << endl;
}

//CONSISTE EN OBTENER EL ELEMENTO MINIMO EN EL SEGUNDO FOR
//RECORRIENDOLO HASTA EL FINAL, LUEGO SE LO PONE EN LA POSICION
//I-ESIMA: 1,2,3,4... DONDE SE INTERCAMBIARAN LAS POSICIONES
//CON EL ANTERIOR DE DICHA POSICION.
void ordenacion_seleccion(){
    for(int i = 0; i < n-1 ; i++){
        int min = i;
        for(int j = i+1 ; j < n ; j++ ){
            if(v[j] < v[min]){
                min = j;
            }
        }
        int aux = v[i];
        v[i] = v[min];
        v[min]= aux;
    }
}

int main()
{
    llenar();
    mostrar();
    ordenacion_seleccion();
    mostrar();
    return 0;
}
