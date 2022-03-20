//esta biblioteca me permite tener flujo de entrada y salida
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    cout << "Hola a todos!!!"; //imprime mensaje en consola
    cin.get();  //lectura(entrada del teclado)


    //declaramos un array de caracteres
    char nombre[80];
    cout << "ingrese su  nombre: ";
    cin >> nombre;
    //aqui hacemos una referencia al + para imprimir
    cout << "Hola, " << nombre;
    cin.get();


    //si es necesario hacer varias veces la entrada o salida da datos
    string x,y,z;
    cin >> x >> y >> z;
    cout << x << y << z;


    //SCANF PRINTF

    //para usarlos, se debe incluir la libreria #include <cstdio>
    //ahora para imprimir con printf se necesita:

    //caracteres
    char a = 'a';
    printf("el caracter %c",a);

    //strings
    string b = "aaaaa";
    printf("la cadena %s",b);

    //entero
    int c = 12345;
    printf("el entero %d ó %i",c);

    //entero sin signo
    unsigned d = 121;
    printf ("el entero sin signo %u",d);

    //entero largo
    long long e = 7948987;
    printf("entero largo %lld",e);

    //entero largo sin signo
    unsigned long long f = 1236589;
    printf("entero largo sin signo %llu",f);

    //flotante
    float flotante = 1.2345;
    printf("flotante %f",flotante);

    //flotante con doble precision
    double doble = 4.56789;
    printf("doble precision %lf",doble);

    //ejemplo mayor
    printf("decimal: %d, flotante: %f. cadena: %s y doble: %lf",a,flotante,b,doble);

   //para decimales se usar % #.b para decir que solo temdra b-decimales.
   //pero si es con cadenas entondes muestra los primeros b-elementos.


    //ahora para scanf son los mismos terminos solo que en lugar
    //de las variables se le aumenta & a menos que sea un string
    int edad;
    string nom;
    scanf("%d %s",&edad,nom);


    return 0;
}
