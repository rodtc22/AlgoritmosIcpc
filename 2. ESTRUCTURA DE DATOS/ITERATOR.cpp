#include <iostream>
#include <set>

using namespace std;

int main()
{
    //USANDO CON LA CLASE VECTOR

    set <int> grupo ;

    //set<int>::iterator it  apunto a la primer elemento del vector

    //it != grupo.end(); va a la posicion siguiente del ultimo
    //elemento del vector(posicion salida del arreglo)

    //para acceder al elemento hago *nombre_del_iterador

    //++i o i++ para avanzar al siguiente elemento

    grupo.insert(3);
    grupo.insert(4);
    grupo.insert(1);
    grupo.insert(4);
    grupo.insert(6);
    grupo.insert(5);

    for(set <int> :: iterator it = grupo.begin() ; it != grupo.end() ; it++)
    {
        cout << *it << "   ";
    }

    return 0;
}
