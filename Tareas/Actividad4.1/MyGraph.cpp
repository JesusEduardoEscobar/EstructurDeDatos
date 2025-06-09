/*
En el siguiete programa veremos las fuciones y la implmentacion de ellas para el recorrido de un grafo, en este caso se implementan dos metodos de 
recorrido, el primero es el recorrido en profundidad (DFS) y el segundo es el recorrido en anchura (BFS). Para la implementacion de estos metodos 
se utilizan dos estructuras de datos, una pila y una cola, las cuales se implementan con vectores.
Referencias: 
Murillo, J. (2022, 18 julio). Difference between Breadth Search (BFS) and Deep Search (DFS). Encora. https://insights.encora.com/es/blog/dfs-vs-bfs
Michael Sambol. (2022, 29 marzo). Breadth-first search in 4 minutes [Vídeo]. YouTube. https://www.youtube.com/watch?v=HZ5YTanv5QE
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
*/
#include "MyGraph.h"

/*
Este es un constructor que recibe una matriz de adyacencia y la carga en el grafo.
complejidad: O(n^2) esto en ambos casos ya que se recorre toda la matriz y no depende de los datos.
*/
MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
}

/*
Esta funcion nos permite cargar la matriz de ayacencia en un grafo.
complejidad: O(n^2) esto en ambos casos ya que se copia toda la matriz y no depende de los datos al igual que el constructor.
*/
void MyGraph::loadGraph(vector<vector<int>>& nuevaMatriz){
    this->matriz = nuevaMatriz;
}

/*
Esta funcion realiza un recorrido a profundidad (DFS) en el grafo desde el nodo incial.
Complejidad: 
Peor caso: O(n + m) donde n es el numero de nodos y m el numero de aristas
Mejor caso: O(n) esto sucederia cuando no hay aristas o los nodos estan desconectados
*/
void MyGraph::DFS(int inicio){
    if (inicio < 0 || inicio >= matriz.size()) {
        cout << "Error: Nodo inicial no válido." << endl;
        return;
    }
    vector<bool> visitados(matriz.size(), false);
    for(int i = 0; i < matriz.size(); i++){
        if(!visitados[i]){
            DFSRecursivo(i, visitados);
        }
    }
}

/*
Esta es una funcion auxiliar para el metodo DFS, esta funcion se encarga de realizar el recorrido a profundidad en el grafo 
de maner recursiva.
complejidad:
Peor caso: O(n + m) donde n es el numero de nodos y m el numero de aristas, este caso se da cuando el grafo es conexo.
Mejor caso: O(n) esto sucederia cuando no hay aristas o los nodos estan desconectados.
(Tanto en la funcion principal como en la funcion recursiva se tiene la misma complejidad)
*/
void MyGraph::DFSRecursivo(int nodo, vector<bool>& visitados){
    visitados[nodo] = true;
    cout << "["<< nodo << "],";
    for(int i = 0; i < matriz.size(); i++){
        if(!visitados[i] && matriz[nodo][i] == 1){
            DFSRecursivo(i, visitados);
        }
    }
}

/*
Esta funcion realiza un recorrido a anchura (BFS) en el grafo desde el nodo incial.
Complejidad:
Peor caso: O(n + m) donde n es el numero de nodos y m el numero de arista, este caso se da cuando el grafo es conexo.
Mejor caso: O(n) esto sucederia cuando no hay aristas o los nodos estan desconectados.
*/
void MyGraph::BFS(int inicio){
    if (inicio < 0 || inicio >= matriz.size()) {
        cout << "Error: Nodo inicial no válido." << endl;
        return;
    }
    vector<bool> visitados(matriz.size(), false);
    visitados[inicio] = true;
    inserFirst(inicio);
    BFSRecursivo(visitados);
}

/*
Esta es la funcion auxiliar para el metodo (BFS), esta funcion se encarga de realiza el recorrido a anchura en el grafo 
de manera recursiva.
complejidad:
Peor caso: O(n + m) donde n es el numero de nodos y m el numero de arista, este caso se da cuando el grafo es conexo.
Mejor caso: O(n) esto sucederia cuando no hay aristas o los nodos estan desconectados.
(Tanto en la funcion principal como en la funcion recursiva se tiene la misma complejidad)
(Tambien cabe aclarar que tanto el metodo BFS y DFS tienen la misma complejidad en las mismas condiciones)
*/
void MyGraph::BFSRecursivo(vector<bool>& visitados){
    if(!isQueueEmpty()){
        int nodo = first();
        removeFirst();
        cout << "["<< nodo << "],";
        for(int i = 0; i < matriz.size(); i++){
            if(!visitados[i] && matriz[nodo][i] == 1){
                visitados[i] = true;
                inserFirst(i);
            }
        }
        BFSRecursivo(visitados);
    }
}

/*
Esta funcion verifica si la matriz esta vacia
Complejidad: O(1), esto es tanto en el peor como en el mejor de los casos
*/
bool MyGraph::isEmpty(){
    return matriz.empty();
}

//METODOS PARA LA COLA
/*
Esta funcion inserta un dato al final del vector que representa la cola.
Complejidad: O(1), esto es tanto en el peor como en el mejor de los casos.
*/
void MyGraph::inserFirst(int data){
    queue.push_back(data);
}

/*
Esta funcion elimina el primer dato del vector que representa la cola.
Complejidad:
Peor caso: O(n) ya que eliminar el primer nodo implica que los demas datos se deban desplazar.
Mejor caso: O(1), esto es cuando la cola tiene un solo elemento.
*/
void MyGraph::removeFirst(){
    if(!isQueueEmpty()){
        queue.erase(queue.begin());
    }
}

/*
Esta funcion devuelve el primer elemento de un dato de la cola.
Complejidad: O(1), esto es tanto en el peor como en el mejor de los casos.
*/
int MyGraph::first(){
    if(isQueueEmpty()){
        return -1;
    }
    return queue.front();
}

/*
Esta funcion se encarga de verificar si la cola esta vacia.
Complejidad: O(1), esto es tanto en el peor como en el mejor de los casos.
*/
bool MyGraph::isQueueEmpty(){
    return queue.empty();
}


/* main con la prueba dado por el porfesor  
int main() {
    vector<vector<int> > mady =
    {
        { 1,0,1,0,0,1,0 },
        { 0,1,0,1,0,0,0 },
        { 0,1,1,0,0,0,0 },
        { 0,0,1,0,0,1,1 },
        { 1,0,1,0,1,0,0 },
        { 1,1,0,0,1,0,0 },
    };
    MyGraph grafo(mady);
    // Recorrido DFS
    cout << "Recorrido DFS:" << endl;
    grafo.DFS(0);
    // Recorrido BFS
    cout << "\nRecorrido BFS:" << endl;
    grafo.BFS(0); 

    return 0;
}*/
