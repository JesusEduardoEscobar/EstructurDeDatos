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
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz;
        vector<int> stack;
        vector<int> queue;
        void DFSRecursivo(int nodo, vector<bool>& visitados);
        void BFSRecursivo(vector<bool>& visitados);
    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& nuevaMatriz);
        //Depth First Search (primero en profundidad)
        void DFS(int inicio); //imprimi el recorrido de DFS (profundidad) a partir del nodo inicial
        //Breath First Search (primero en anchura)
        void BFS(int inicio); //imprimi el recorrido de BFS (anchura/amplitud) a partir del nodo inicial
        bool isEmpty();

        //METODOS PARA LA COLA
        void inserFirst(int data);
        void removeFirst();
        int first();
        bool isQueueEmpty();
};

#endif
