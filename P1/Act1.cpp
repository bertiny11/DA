// Operacion de reintegro en un cajero automático. Hacer el algoritmo devorador de cambio de moneda empleando un montículo para mejorar su eficiencia
#include <vector>
#include <queue>
#include "Act1.hpp"
using namespace std;


// La función del algoritmo deberá tener el siguiente prototipo:

fajos reintegrar(const fajos& caja, unsigned int cantidad){

    priority_queue<fajo> monticulo(caja.begin(), caja.end()); //Preordenacion mediante cola de prioridad(monticulos)
    fajos solucion;

    while(!monticulo.empty() && cantidad > 0)
    {
        fajo actual = monticulo.top();
        monticulo.pop();
        
        if(actual.valor()<= cantidad && actual.unidades() > 0){
            unsigned int necesario = min(cantidad / actual.valor(), actual.unidades());
            if(necesario > 0) {
                solucion.emplace_back(actual.valor(), necesario);
                cantidad -= necesario * actual.valor();
            }
        }
    }
    if (cantidad > 0) return {};

    return solucion;
}

int main(){
    ifstream datos("caja.dat");  
    if (!datos) {
        cerr << "Error: no se puede abrir caja.dat\n";
        return 1;
    }

    fajos caja;
    datos >> caja;

    unsigned int cantidad;
    cout << "Cantidad a reintegrar: ";
    cin >> cantidad;

    fajos resultado = reintegrar(caja, cantidad);

    if (resultado.empty())
        cout << "No se puede reintegrar esa cantidad.\n";
    else {
        cout << "Reintegro:\n" << resultado;
    }

    return 0;
}
