/*
Este programa implementa la clase llama MyGraph, la cual representara un grafo y se imolementaran
algunas funcionalidades para trabajar con el, como los son isTree(para verificar su elgrafo es un arbol), 
topologicalSort(esta funcon hace un recorredo topologico sobre el grafo) y bipartiteGraph( verifica si el grafo es bipartito).
Referencias: GeeksforGeeks. (2024, 23 julio). Topological sorting. GeeksforGeeks. https://www.geeksforgeeks.org/topological-sorting/
Club de Algoritmia ESCOM. (2022, 22 febrero). [Intermedios] Grafos: orden topológico / Topological sort [Vídeo]. YouTube. https://www.youtube.com/watch?v=fSUxuChouIs
GeeksforGeeks. (2024b, septiembre 26). What is Bipartite Graph? GeeksforGeeks. https://www.geeksforgeeks.org/what-is-bipartite-graph/
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
*/
#include "MyGraph.h"

/*
Constructor que inicializa el grafo apartir de una matriz de adyacencia, establece el numero de vertices y cuenta el numero de arcos.
Complejidad: 
Mejor de los casos: o(1) esto pasaria si la matriz esta vacia ademas de que los demas valores cuentan con funciones que retprnarian sus 
valores de forma dirrecta
Peor de los casos: o(n^2) 
*/
MyGraph::MyGraph(vector<vector<int>>& matriz){
    loadGraph(matriz);
    this->n = matriz.size();//numero de vertices
    this->m = contarArcos(); //numeor de arcos
}

/*
Metdo el cual permite cargar una matriz de adyacencia en el grafo dicho metodo solo recibira matriz ademas de que fue inspirado y basado en
el de la actividad anterior
Complejidad: o(1) esto aplicaria en todos los casos ya que esta funcion solo se encarga de cargar la matriz
*/
void MyGraph::loadGraph(vector<vector<int>>& nuevaMatriz){
    this->matriz = nuevaMatriz;
}

/*
Este funcion se encarga de contar el numero de arcos que hay en el grafo sumando todos los elementos de la matriz de adyacencia
Complejidad:
Mejor de los casos: O(1) esto pasaria si la matris estuviera en su tamaño minimo.
Peor de los casos: O(n^2) essto pasaria si se recorre toda la matriz.
*/
int MyGraph::contarArcos(){
    int contador = 0;
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < this->n; j++){
            contador += matriz[i][j];
        }
    }
    return contador;
}

/*
Esta funcion se encarga de verificar si el grafo es un arbol, para ello se utiliza DFS como codigo de apoyo
Complejidad:
Mejor de los casos: O(n) si el grafo esta vacio o si solo tiene un vertice
Peor de los casos: O(n + m) esto aplicaria si se realiza un DFS y se verifica la conectividad
*/
bool MyGraph::isTree(){
    if(this-m && this->n-1){
        return false;
    }
    vector<bool> visitados(this->n, false);
    DFSRecursivo(0, visitados);
    for(int i=0; i<visitados.size(); i++){
        if(!visitados[i]){
            return false;
        }
    }
    return true;
}

/*
Esta funcion se encarga de realizar un DFS para marcar los nodos visitados
(Este codigo fue sacado de la actividad anterior de grafos)
Complejidad:
Mejor de los casos: O(1) si el grafo esta vacio o si solo tiene un vertice
Peor de los casos: O(n + m) m seria el numero de arcos 
*/
void MyGraph::DFSRecursivo(int nodo, vector<bool>& visitados){
    visitados[nodo] = true;
    for(int i = 0; i < this->n; i++){
        if(!visitados[i] && matriz[nodo][i] == 1){
            DFSRecursivo(i, visitados);
        }
    }
}

/*
Esta funcion se encarga de realizar un ordenamiento topologico utilizando el algoritmo de kahn visto en clase
Complejidad: O(n + m) cuando el grafo que se inrgesa tiene conexiones
*/
void MyGraph::topologicalSort(){
    vector<int> gradosEntrada(this->n, 0);
    queue<int> colaP;
    vector<int> colaR;
    int contador=0;
    for(int i=0; i<this->n; i++){
        for(int j=0; j<this->n; j++){
            if(matriz[i][j] == 1){
                gradosEntrada[j]++;
            }
        }
    }
    for(int k=0; k<this->n; k++){
        if(gradosEntrada[k] == 0){
            colaP.push(k);
        }
    }
    while(!colaP.empty()){
        int nodo = colaP.front();
        colaP.pop();
        colaR.push_back(nodo);
        contador++;
        for(int i=0; i<this->n; i++){
            if(matriz[nodo][i] == 1){
                gradosEntrada[i]--;
                if(gradosEntrada[i] == 0){
                    colaP.push(i);
                }
            }
        }
    }
    if(contador != this->n){
        cout << "El grafo no es aciclico\n";
    } else {
        for(int i=0; i<colaR.size(); i++){
            cout << colaR[i] << " ";
        }
        cout<<endl;
    }
}

/*
Esta funcion nos permite conocer si el grafo es bipartito utilizando una tecnica de coloracion (dicha tecnica y codigo fue visto en clase)
Complejidad:
Mejor de los casos: O(1) esto pasa si hay pocos nodos o pocas conexiones
Peor de los casos: O(n+m) esto pasaria si se tiene que recorrer todos los nodos y arcos
*/
bool MyGraph::bipartiteGraph(){
    vector<int> color(this->n -1);
    for(int i=0; i<this->n; i++){
        if(color[i] == -1){
            queue<int> cola;
            cola.push(i);
            color[i] = 0;
            while(!cola.empty()){
                int v = cola.front();
                cola.pop();
                for(int j=0; j<this->n; j++){
                    if(matriz[v][j] == 1){
                        if (color[j] == -1) {
                            color[j] = 1 - color[v];
                            cola.push(j);    
                        } else if (color[j] == color[v]) {
                            return false;
                        }
                    }   
                }
            }
        }
    }
    return true;
}

/*
Algo que siento que se tiene que mencionar durante la realizacion de esta actividad se le hizo una consulta al profesor en la cual el 
nos indico que en el construtor teniamos que poner los arcos y los vertices ademas de que nosotros los tendriamos que calcular sin embargo
en la actividad no indica eso de hecho dice que el usuario debe de ingresar ambas variables.
*/