#include <iostream>

using namespace std;

int main()
{

	//strlen(array) me dice la longitud de este array de caracteres
	char cad[] = "adios";
	cout << strlen(cad) << endl;

	//strcmp compara dos cadenas por orden lexicografico
	//es igual que el compareTo
	//-1 izq 	0 igual		 1 der
	char cad2[] = "hola";
	cout << strcmp(cad,cad2)<<endl;

	//tambien se compara con: <, <=, >, >=, ==, !=

	//strcpy crea una copia de la cadena
	char cad3[];
	strcpy(cad3,cad);

	//para hacer de cadena a int o float -> ato?();
	#include <cstdlib>
	string a = "123";
	int aa = atoi(a);

	string b = "1.23";
	float bb = atof(b);

	//.lenght() y .size() me dice la longitud del string
	int tam = b.size();
	cout << "tamanio de la cadena b: " << tam << endl;

	int oracion = "Hay una taza en esta cocina con tazas";
	int palabra = "taza";

	//buscando la primera palabra taza
	unsigned int  encontrado = oracion.find(palabra);
	if (encontrado != string::npos){
		cout << "primera 'taza' en: "<<encontrado <<endl;
	}else{
		cout << "palabra 'taza' no encontrada";
	}

	//sustituimos la primera 'taza' por 'botella'
	//a.replace('taza',tamaño_palabra_a_reemplazar, palabra_a_reemplazar);
	oracion.replace(oracion.find('taza'),palabra.lenght(),"botella");
	cout << oracion <<endl;

	//concatenacion de palabras
	string x = "hola, ";
	string y  = "mundo";

	string s = x+y;
	cout <<s << endl;

	//se puede tratar una cadena como un vector
	//manejandolo con posiciones
	s = "hola";
	string car = s[a];
	s[0] = 'H';
	cout << s << ": "<<car<<endl;

	//entero a string
	#include <sstream>
	int n = 100;
	stringstream cad;

	cd << n;
	string numero = cad.str();

	//string a entero
	numero = "523";
	int nro = atoi(numero.c_str());


    return 0;
}
