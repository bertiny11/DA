#ifndef MOCHILA_HPP
#define MOCHILA_HPP

#include <string>

using namespace std;

class objeto{
    public:
    // Constructor
    objeto(const string& n, double v, double p)
        : nombre(n), valor(v), peso(p) {}
    private:
    string nombre;
    double valor;
    double peso;
};

#endif