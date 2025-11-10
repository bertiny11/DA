#include "Act4.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream G("grafo.dat");

    cout << "El grafo original es: " << endl;
    GrafoPonderado<int> grafo;
    G >> grafo;
    cout << grafo << endl;

    cout << "Un Arbol de Expansion Minimo de G es: " << endl;
    cout << Kruskal(grafo) << endl;

    return 0;
}