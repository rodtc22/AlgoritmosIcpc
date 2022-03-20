#include <iostream>
#include <map>

using namespace std;

//mostrando los elementos
void mostrar(map<char,int> m){
    for(map <char,int> :: iterator it = m.begin() ; it != m.end() ; it++ )
    {
        cout << "key: "<<it -> first << "   value: "<<it -> second<<endl;
    }
}

int main()
{
    //busqueda eliminacion e insercion son de O(log n)

    //map <llave,valor> nombre;
    map <char,int> mapa;
    map <char,int> ::iterator it;

    //tambien se manejan mediante iteradores
    //begin y end sirve para el primer elemento y el siguiente al ultimo

    mapa.insert(make_pair('a',10));
    mapa.insert(make_pair('b',20));

    //para acceder a los valores basa con acceder a la llave
    cout << mapa['a']<<endl;
    cout << mapa['b'] << endl;

    //si la llave no existe entonces se crea con valores por defecto
    cout << mapa['c'] <<endl;

    //size me dice el tamaño del map
    cout << "EL mapa tiene " << mapa.size() << "elementos." << endl;

    //mostrando los elementos
    mostrar(mapa);

    //clear vacia todo el mapa
    mapa.clear();

    //empty pregunta si es vacio
    if(mapa.empty())
        cout << "El map esta vacio"<<endl;

    mapa.insert(make_pair('x',123));

    //mostrando el map
    mostrar(mapa);

    //find dá la posicion del elemento que le doy
    //si no hay devuelve end()
    mapa.find('y');

    //lower_bound() y upper_bound() compara las llaves como en
    //el caso del set

    return 0;
}
