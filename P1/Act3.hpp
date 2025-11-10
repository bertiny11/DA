#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "grafo-ponderado.hpp"
#include  "Act2.hpp"
#include <list>
#include <vector>


template <typename G>
G Kruskal(const G& g)
    {
    using std::list;
    using Arista = typename G::Arista;
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices(); // Número de vértices del grafo original
    G s(n); // Grafo solución.
    Particion p(n); // Construye la partición inicial.
    list<Arista> c(g.aristas()); // Lista de candidatos.
    // ...
    //Ahora hacemos la preordenacion
    //Primero elegimos las aristas mas baratas, (usamos sort) de la lista de candidatos c
    c.sort([](const Arista &a, const Arista &b){
        return a.peso() < b.peso(); 
    });
    
    //luego para cada arista de forma ascendente buscamos los representantes con buscar de particion y si son distintos no hay ciclo
    //por lo que podemos añadirlo a la arbol solucion y unir los conjuntos

    for (const auto &a : c) // asi vamos de arista en arista
    {
        Vertice u = p.buscar(a.primero());
        Vertice v = p.buscar(a.segundo());
        if(u != v)
        {
            p.unir(u, v);
            s.insertarArista(a);
        }
    }
    return s;
}

#endif