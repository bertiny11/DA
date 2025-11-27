#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string binario(int n)
{
    if (n == 0) return "0";
    string binario = "";
    while (n > 0) {
        binario = char('0' + (n % 2)) + binario;
        n /= 2;
    }
    return binario;
}

int producto(int n, int cont){

    if (n < 2) return cont;   // caso base
    else
        if (n % 2 == 0)
            return producto(n/2, cont + 1);
        else
            return producto(n - 1, cont + 1);
}


int main()
{
    int n = 64, cont = 0;
    for(int i=0; i<=n; i++)
    {   
        cout << (i) << " ";
        cout << int(log2(i)) << " ";
        cout << binario(i) << " ";
        cout << producto(i, 0) << endl;
    }
    return 0;
}