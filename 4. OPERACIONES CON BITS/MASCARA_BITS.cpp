#include <iostream>

using namespace std;

int main()
{
    /*
        CARLOS ES UN ESTUDIANTE DE INFORMATICA Y PERTENECE AL GRUPO DE ESTUDIO MAKERS.
        DURANTE LA NOCHE SE ACORDÓ QUE TENIA QUE PRESENTAR UN MINIPROYECTO EL CUAL ES
        PARA EL DIA SIGUIENTE, COMO YA ES MUY TARDE Y LAS TIENDAS DE EECTRONICA NO ESTAN ABIERTAS,
        EL TIENE UN PROBLEMA.
        EL NECESITA UNA LONGITUD a  DE CABLE PARA SU PROYECTO Y TIENE n PEQUEÑOS CABLES, TODOS DE
        TAMAÑOS DISTINTOS. EL QUIERE SABER QUE CABLES DE LONGITUDES DISTINTAS ENTRE SI, DEBE UNIR PARA
        TENER LA LONGITUD DE CABLE EXACTO (SIN TENER LA NECESIDAD DE CORTAR MAS CABLE DEL QUE UNIO)
        QUE NECESITA.
        AYUDALO PARA SABER QUE CABLES TIENE QUE UNIR.

        //CASOS DE PRUEBA

        5
        14
        7 9 5 6 1
        3
        5
        4 5 2
        4
        20
        21 18 3 1

        //SALIDA
        YES.
        YES.
        NO.

    */
    while(cin){
        int n,a;
    cout << "INGRESE N: "<<endl;
    cin >> n;
    cout << "INGRESA LA LONGITUD DEL CABLE: "<<endl;
    cin >> a;

    int vec [n];
    cout << "LLENA LOS DATOS: ";
    for (int i = 0 ; i < n ; i++ ){
        cin >> vec[i];
    }
    int suma=0;
    string d="NO.";

    for(int i = 0 ; i < (1 << n) ; i++){
        int suma = 0;
        for(int j = 0 ; j < n ; j++){
            if(i & (1 << j)){
                suma+=vec[j];
            }
        }
        if(suma == a){
            d="YES.";
        }
    }
    cout << d<<endl;
    }

    return 0;
}
