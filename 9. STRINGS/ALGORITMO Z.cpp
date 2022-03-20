#include <bits/stdc++.h>
using namespace std;

//NORMAL IMPLEMENTATION OF Z-ALGORITHM
void Z_explicado(string &s){
   int n = s.size();
   //empezamos nuestro z-array en ceros(DICIENDO QUE NO HAY PREFIJOS, ES DECIR, PREFIJOS DE TAMANIO CERO)
   vector<int>z(n,0);
   //l y r manejan esa "ventana" que me dice, que ese rango, ya fue procesado, y que se sabe, que desde l hasta r es un prefijo
   int l= 0, r = 0;
   //empezamos desde 1, ya que no se comienza desde cero, ya que no es prefijo
   for(int i = 1 ; i < n ; i++){
      if(i>r){
         //ya me pase del rango que estaba seguro de que habia prefijo
         //ahora estoy en terreno incierto
         l = r = i; //entonce,mi nuevo rango, empieza desde mi posicion, hasta mi posicion
         while(r < n && s[r]==s[r-l]){//calculamos a fuerza bruta, como un algoritmo normal que matchea caracter por caracter
            // s[1]==s[1-1] --> s[1]==s[0]
            // s[1]==s[2-1] --> s[2]==s[1]
            // s[5]==s[5-2] --> s[5]==s[3]
            // s[6]==s[6-2] --> s[6]==s[4]
            r++;
         }
         z[i]=r-l;
         // le restamos uno, ya que cuando deja de cumplir la condicion del while,
         // o bien, ya no matchea, o bien se salio del tamanio, entonces, hay que
         // regresar a una posicion antes en la cual cumplia
         r--;
      }else{ // ej : 4<=4 || 6 <= 4
         // o bien, cavalito, estaba y no se que hay despues, o que el numero que tiene z[i] es mayor al substring que me queda
         // es decir que dice que tiene un prefijo de 4 cuando solo hay espacio para 2, entonces estamos en terreno incierto
         // y tenemos que calcular a fuerza bruta

         //entonces mi nuevo rango empieza en k hasta r [k,r]
         // ya que voy a empezar desde el caracter que debia matchear, y no desde el princio,
         // solo matcheo desde donde me corresponde
         int k = i-l;
         if(z[k]<r-i+1){ // si el tamanio del prefijo es menor, al que podria almacenar, entonces, el maximo prefijo, es el que ya habiamos calculado mas antes
            z[i]=z[k];//entonces solo le asigno
         }else{//significa que era >=  o > entonces hay que analizar a ver que pasa...
            //cambiamos el valor de l por el valor de i ya que, como estamos,
            // en terreno desconocido , entonces tomaremos un nuevo rango , comenzando
            // desde la posicion i, el valor de r se mantiene ya que desde i+1,i+2,...,r ya era prefijo
            // entonces no hay por que volver a preguntar por ese lugar
            l = i;
            // nuevamente comparamos como un algorimo normal , a fuerza bruta
            while(r<n && s[r]==s[r-l]){
               r++;
            }
            // y volvemos a hacer lo mismo que arriba
            z[i]=r-l;
            r--;
         }
      }
   }
   for(auto c : s) cout<<c<<" ";cout<<endl;
   for(auto d: z) cout<<d<<" ";cout<<endl;
}


int main(){
   string x;
   cin>>x;
   Z(x);
   return 0;
}
