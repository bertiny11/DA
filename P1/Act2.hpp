#ifndef ACT2_HPP
#define ACT2_HPP


#include <vector>

class Particion {
    public:
        Particion(int n): p(n, -1){}; //el -1 indica que el arbol es altura 1, se guarda en - porque las alturas se guardan con signos negativos
        int buscar(int i) const;
        void unir(int i, int j);
    private:
        std::vector<int> p; // usamos un vector ya que usamos un bosque de control de alturas, donde esas alturas se representas implicitamente 
};

#endif