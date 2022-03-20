#include <iostream>

using namespace std;

int main()
{

    //VECTORES
    bool array[5];
    array[0] = true;
    array[1] = false;
    array[2] = true;
    array[3] = false;
    array[4] = true;

    cout << "VECTOR\n";
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << array[i]<<"\t";
    }
    cout <<endl;

    //MATRICES
    double matriz[2][2];
    matriz [0][0] = 1.2;
    matriz [0][1] = 3.4;
    matriz [1][0] = 5.6;
    matriz [1][1] = 7.8;


    cout <<endl<<"MATRIZ"<<endl;
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 2 ; j++)
        {
            cout << matriz[i][j]<<"\t";
        }
        cout << "\n";
    }

    //PARES
    pair<int,string> par;
    par.first = 123;
    par.second = "abc";
    cout << "\nPAIR"<<endl;
    cout <<"par= "<<"first: "<<par.first<<" ,second: "<<par.second<<endl;
    return 0;
}
