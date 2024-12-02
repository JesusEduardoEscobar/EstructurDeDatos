/*
Examen final de Estructura de Datos la cual se tiene que comprobar si el vector que se mande es un heap o no, regresando true o false.
Nombre: Jesus Eduardo Escobar Meza 
Matricula: A01743270
*/
#include <iostream>
#include <vector>

using namespace std;

/*
Funcion recursva para comprobar que el vector que se ingresa si es un heap de manera recursiva. Solo regresaria true o false. si
una condicion se cumple o si ninguna se cumple. si se cumple la primera condicion se estaria llamando asi misma de manera recursiva para
poder asi comprobar todo el vector llegar a mandar los valores anteriormente mencionados.
Complejidad: 
Peor de los casos: O(n), ya que se tendria que recorrer todo el vector para comprobarlo.
Mejor de los casos: O(1), esto ya que si el vector esta vacio, no se hace ninguna operacion o si lo solo tiene un elemento.
*/
bool isHeap(vector<int> arreglo, int n){
    if(n >= arreglo.size()){
        return true;
    } else if((n == 0) || ((n != 0) && (arreglo[(n-1)/2] >= arreglo[n]))){
        return isHeap(arreglo, (n*2)+1) && isHeap(arreglo, (n*2)+2);
    } else {
        return false;
    }
}

/*
Funcion principal para comprobar si un vector es un heap se implemento que fuera un bool ya que solo se necesita regresar un true o false.
Manda a llamar a la funcion recursiva para poder comprobar si es un heap o no.
Complejidad:
Peor de los casos: O(n), ya que se tendria que recorrer todo el vector para comprobarlo.
Mejor de los casos: O(1), esto ya que si el vector esta vacio, no se hace ninguna operacion o si lo solo tiene un elemento.
*/
bool isHeap(vector<int> arreglo){
    return isHeap(arreglo, 0);
}

/*
funcion main la cual se indico en las instrucciones que deberia de ser comentada al momento de ser entragada
int main(){
    vector<int> arreglo = {15,10,8,5,9,7,6};
    cout << isHeap(arreglo) << endl;
    return 0;
}
*/