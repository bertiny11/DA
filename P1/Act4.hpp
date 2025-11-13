#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "grafo-ponderado.hpp"
#include "Act2.hpp"
#include <list>
#include <vector>
#include <queue>

using namespace std;

template <typename G>
G Kruskal(const G& g)
{
    using std::list;
    using Arista = typename G::Arista;
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices(); // Número de vértices del grafo original
    G s(n); // Grafo solución.
    Particion p(n); // Construye la partición inicial.
    // ...
    //Ahora hacemos montículo, para hacer monticulos debemos de hacer una cola de prioridad de clase kruskal, y luego ordenarlo
    
    auto& aristas = g.aristas();

    priority_queue<Arista> monticulo(begin(aristas), end(aristas));
    size_t k = 0;
    while (k != n - 1){
        Arista actual = monticulo.top();
        monticulo.pop();

        Vertice u = p.buscar(actual.primero());
        Vertice v = p.buscar(actual.segundo());
        if (u != v) {
            p.unir(u, v);
            s.insertarArista(actual);
            ++k;
        }
    }
        
    return s;
}

#endif