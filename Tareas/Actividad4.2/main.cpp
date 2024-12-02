#include "MyGraph.h"

int main() {
    // Grafo 1: Un arbol (4 nodos, 3 aristas)
    vector<vector<int>> grafo1 = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    };

    MyGraph g1(grafo1);

    cout << "Pruebas con Grafo 1:" << endl;

    // Verificar si es un arbol
    cout << "Es un arbol? " << (g1.isTree() ? "Si" : "No") << endl;
    // Respuesta esperada: Si (es un arbol)

    // Realizar el orden topologico
    cout << "Orden topologico: ";
    g1.topologicalSort();
    // Respuesta esperada: 0 1 2 3 (El orden puede variar si el grafo tiene múltiples caminos)

    // Verificar si es bipartito
    cout << "Es un grafo bipartito? " << (g1.bipartiteGraph() ? "Si" : "No") << endl;
    // Respuesta esperada: Si

    cout << endl;

    // Grafo 2: No conexo (2 componentes, 4 nodos)
    vector<vector<int>> grafo2 = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    MyGraph g2(grafo2);

    cout << "Pruebas con Grafo 2:" << endl;

    // Verificar si es un arbol
    cout << "Es un arbol? " << (g2.isTree() ? "Si" : "No") << endl;
    // Respuesta esperada: No (No está conectado)

    // Realizar el orden topologico
    cout << "Orden topologico: ";
    g2.topologicalSort();
    // Respuesta esperada: No se puede hacer orden topologico (tiene ciclos o no es DAG)

    // Verificar si es bipartito
    cout << "Es un grafo bipartito? " << (g2.bipartiteGraph() ? "Si" : "No") << endl;
    // Respuesta esperada: Si (bipartito)

    cout << endl;

    // Grafo 3: Un grafo bipartito (4 nodos, 4 aristas)
    vector<vector<int>> grafo3 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    MyGraph g3(grafo3);

    cout << "Pruebas con Grafo 3:" << endl;

    // Verificar si es un arbol
    cout << "Es un arbol? " << (g3.isTree() ? "Si" : "No") << endl;
    // Respuesta esperada: No (tiene ciclos)

    // Realizar el orden topologico
    cout << "Orden topologico: ";
    g3.topologicalSort();
    // Respuesta esperada: 0 1 2 3 o 1 0 2 3 (cualquier orden válido de un DAG)

    // Verificar si es bipartito
    cout << "Es un grafo bipartito? " << (g3.bipartiteGraph() ? "Si" : "No") << endl;
    // Respuesta esperada: Si (es un grafo bipartito)

    cout << endl;

    // Grafo 4: Un ciclo impar (3 nodos)
    vector<vector<int>> grafo4 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    MyGraph g4(grafo4);

    cout << "Pruebas con Grafo 4:" << endl;

    // Verificar si es un arbol
    cout << "Es un arbol? " << (g4.isTree() ? "Si" : "No") << endl;
    // Respuesta esperada: No (es un ciclo)

    // Realizar el orden topologico
    cout << "Orden topologico: ";
    g4.topologicalSort();
    // Respuesta esperada: No se puede hacer orden topologico (ciclo)

    // Verificar si es bipartito
    cout << "Es un grafo bipartito? " << (g4.bipartiteGraph() ? "Si" : "No") << endl;
    // Respuesta esperada: No (ciclo impar, no bipartito)

    cout << endl;

    vector<vector<int>> grafo5 = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    MyGraph g5(grafo5);

    cout << "Pruebas con Grafo 5:" << endl;
    cout << "Orden topologico: ";
    g5.topologicalSort();

    return 0;
}

/*int main(){
    vector<vector<int> > mientras={
    {0,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}};

    MyGraph grafo(mientras);
    grafo.loadGraph(mientras);
    if( grafo.isTree() )
        cout<<"Es Arbol\n";
    else
        cout<<"No es Arbol\n";

    if( grafo.bipartiteGraph() )
        cout<<"Es bipartito\n";
    else
        cout<<"No es bipartito\n";

    cout<<"---Orden Topologico\n";
    grafo.topologicalSort();
    return 0;
}*/
