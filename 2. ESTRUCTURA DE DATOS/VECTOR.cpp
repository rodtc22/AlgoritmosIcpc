#include <iostream>
#include <vector>
using namespace std;

void mostrarVec(vector <int> v){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i]<<"   ";
    }
    cout <<endl;
}

int main(){
    //IMPLEMENTACION
    vector <int> vec (2);
    vec[0] = 123;
    vec[1] = 456;

    mostrarVec(vec);

    cout << "primer elemeneto: "<<vec.front()<<endl;
    cout << "ultimo elemeneto: "<< vec.back()<<endl;

    if(vec.empty()) cout << "El vector esta vacio";

    cout << "tamanio: "<<vec.size()<<endl;

    cout << "\nLUEGO DE INSERT\n";
    vec.insert (vec. begin () , 2, 159);
    mostrarVec(vec);

    cout << "\nLUEGO DE CLEAR\n";
    vec.clear();
    if(vec.empty()) cout << "El vector esta vacio";
    mostrarVec(vec);

    cout << "\nLUEGO DE PUSH_BACK\n";
    vec.push_back(123);
    vec.push_back(456);
    mostrarVec(vec);

    cout << "\nLUEGO DE POP_BACK\n";
    vec.pop_back();
    mostrarVec(vec);

    cout << "\nLUEGO DE SWAP\n";
    vector <int> vec2 (vec.size());
    vec2.swap(vec);
    cout << "vec2: ";
    mostrarVec(vec2);

    /*
    //vector <tipo> nombre;
    //vector <tipo> nombre (tama�o inicial)
    vector <int> vec (5);

    vec[0] = 445;
    vec[1] = 123;
    vec[2] = 523;
    vec[3] = -6546;
    vec[4] = 867;

    //mostrando el vector
    mostrarVec(vec);

    int primero = vec.front();
    int ultimo = vec.back();

    if(vec.empty()) cout << "El vector est� vacio";

    int nroElem = vec.size();

    vec.clear();//vacia el vector

    vec.insert(0,1,123);//(posicion,cantidad,elemento)

    vec.erase(0,1); //(inicio,fin)

    vec.push_back(54); //a�ade un elemento al final

    vec.pop_back(); //elimina el ultimo elemento del vector

    vector <int> vec2;
    swap(vec2); //intercambiar los elementos de un vec a otro
    */

    return 0;
}

