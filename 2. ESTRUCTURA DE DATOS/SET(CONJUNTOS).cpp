#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
    //la eliminacion, busqueda e insercion son O(log n)

    //set <tipo de dato> nombre;
    set <int> grupo;

    //grupo.insert(2); a�ade un dato al grupo

    grupo.insert(3);
    grupo.insert(4);
    grupo.insert(1);
    grupo.insert(4);
    grupo.insert(6);
    grupo.insert(5);

    set <int> :: iterator it;

    for(it = grupo.begin() ; it != grupo.end() ; it++)
    {
        cout << *it << "   ";
    }

    cout << endl;

    //empty() me sirve para saber si está vacia
    //size() me srive para saber la cantidad de elementos

    //clear() limpia el set
    grupo.clear();

    if(grupo.empty()){
        cout << "El grupo está vacio";
    }else{
        int a=grupo.size();
        cout << printf("El grupo tiene %i elementos\n",a);
    }

    grupo.insert(3);
    grupo.insert(4);
    grupo.insert(1);
    grupo.insert(4);
    grupo.insert(6);
    grupo.insert(5);

    //erase borra el elemento del set
    grupo.erase(4);
    int a=grupo.size();
    cout << printf("El grupo tiene %i elementos\n",a);

    //count me dice la cantidad de elemento que hay
    //en el set de cierto numero que es entre (0 y 1)


    //find retorna el el iterador apuntando al elemento
    grupo.find(5);

    cout << *it <<"elemento encontrado y a borrar...";
    grupo.erase(5);

    a=grupo.size();
    cout << printf("El grupo tiene %i elementos\n",a);

    //lower y upper_bound(5) me dice el menor o mayor
    //inmediato a ese numero

    return 0;
}
