#ifndef FAJO_HPP
#define FAJO_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class fajo{
    public:
    fajo(): v{0}, u{0} {}
    fajo(unsigned int v, unsigned int u): v{v}, u{u} {}
    unsigned int valor() const { return v; }
    unsigned int& valor() { return v; }
    unsigned int unidades() const { return u; }
    unsigned int& unidades() {return u; }

private:
    unsigned int v, u; //valor y número de unidades de cada billete
};

using fajos = vector<fajo>;

bool operator<(const fajo& a, const fajo& b) {
    return a.valor() < b.valor();
}


istream& operator >>(istream& fe, fajo& f){
    return fe >> f.valor() >> f.unidades();
}

istream& operator >>(istream& fe, fajos& f){
    istream_iterator<fajo> ife(fe), fin;
    copy(ife, fin, back_inserter(f));
    return fe;
}

ostream& operator <<(ostream& fs, const fajo& f){
return fs << f.unidades() << " billete"
<< (f.unidades() == 1 ? "" : "s") << " de " << f.valor();
}

ostream& operator <<(ostream& fs, const fajos& f)
{
copy(begin(f), end(f), ostream_iterator<fajo>(fs, "\n"));
return fs;
}



#endif 