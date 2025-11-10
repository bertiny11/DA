#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "grafo-ponderado.hpp"
#include  "Act2.hpp"
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
    auto cmp = [](const Arista &a, const Arista &b){
        return a.valor() > b.valor();
    };

    priority_queue<Arista, vector<Arista>, decltype(cmp)> monticulo(cmp);

    for(const auto &arista : g.aristas())
        monticulo.push(arista);

    while (!monticulo.empty()){
        Arista actual = monticulo.top();
        monticulo.pop();

        Vertice u = actual.primero();
        Vertice v = actual.segundo();

        if (p.encontrar(u) != p.encontrar(v)){
            p.unir(u, v);
            s.insertarArista(actual);
        }
    }
        
    return s;
}

#endif