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
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz; //matriz de adyacencia
        int n; // numero de vertices 
        int m;  // numero de arcos
        
        //metodo para calcular los arcos de la matriz de adyacencia
        int contarArcos();
        /*metodos auzxiliares para el funcionamiento del metodo isTree()
        La funcion acontinuacion sera sacada de la actividad anteriormente hecha 
        de grafos ya que se necestita para comprobobar si desde el nodo principa
        (0) se puede llegar hasta el ultimo nodo del grafo
        */
        void DFSRecursivo(int nodo, vector<bool>& visitados);

    public:
        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& nuevaMatriz);
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
};

#endif