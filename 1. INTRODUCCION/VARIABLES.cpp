#include <iostream>

using namespace std;

int main()
{
    //CONSTANTES
    const int PI = 3.1416;
    //define no ocupa espacio en la memoria resultante
    #define PI 3.1416

    //VARIABLES

    //variables de tipo booleano(1 byte)
    bool sw = true;

    //varaibles de tipo caracter(1 byte)
    char caracter = 'b';

    //variables de tipo int pequeño (2 byte)
    short int a = 100;

    //variables de tipo int normal (4 byte)
    int b = 32154;

    //variables de tipo int largo (8 byte)
    long long c = 123456789;

    //varibles de tipo flotante (4 byte)
    float presicion = 1.1234567;

    //variables de tipo flotante mas precisa (8 byte)
    double doble = 1654.1654615;

    //unsigned me permite usar solo la parte positiva de un cierto
    //tipo de dato
    unsigned int ab;

    return 0;
}
