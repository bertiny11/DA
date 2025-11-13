#include "Act2.hpp"
#include <cassert>

//En esta funcion lo que hacemos es: si p[i] es <0 signica que i es la raiz, si  p[i] <= 0 debe de buscar recursivamente la raiz
int Particion::buscar(int i) const {
    assert(0 <= i && unsigned(i) < p.size());
    if (p[i] < 0)   
        return i;
    else
        return buscar(p[i]);
}

//Con un ejemplo se entiende, imagina que tenemos (-3, 0, 0, 2), cuando llamamos a buscar (3) haremos p[3] = 2, 2 > 0 por lo que p[2] != a la raiz,
//entonces busquemos en p[2] = 0, no es raiz, ahora hace buscar con p[2]= 0 y ya p[0] es -3 y estará la raiz

void Particion::unir(int i, int j)
{
    assert(0 <= i && unsigned(i) < p.size());
    assert(0 <= j && unsigned(j) < p.size());
    assert(p[i] < 0 && p[j] < 0);

    //su el arbol i tiene mayor altura, todo el arbol de j se cuelga de i
    if (p[i] < p[j]) {
        p[j] = i;
    } else if (p[i] > p[j]) {
        p[i] = j;
    } else {
        //si son iguales hacemos que j cuelgue de i y j debe de tener un nivel mas de altura
        p[j] = i;
        --p[i];
    }
}

