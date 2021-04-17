//
//  main.cpp
//  hf3
//
//  Created by Medveczky Attila on 2021. 04. 17..
//

#include <iostream>
#include <cmath>
#include <fstream>

using std::cosh;

const int F = 900; //A feladatban megadott paraméterek
const double q = 1.8;
const int a = 200;
const int m = 35;

template <typename T> //A szabadvezeték alakját meghatározó függvény
T wire_shape(T x) {
    
    return (F / q) * (cosh((q / F) * x) - cosh( (q * a) / (2 * F)) + m);
    
}

template <typename T> //A Richardson extrapoláció másdorendű tagja
T D(T x, double h) {
    
    return (wire_shape(x + h) - wire_shape(x - h)) / (2 * h);
    
}

template <typename T> //A Richardson extrapoláció negyedrendű tagja
T S(T x, double h) {
    
    return (4 * D(x, h) - D(x, 2 * h)) / 3;
    
}

template <typename T> //A Richardson extrapoláció hatodrendű tagja, ami a feladathoz
T RO6(T x, double h) { //szükséges
    
    return (16 * S(x, h) - S(x, 2 * h)) / 15;
    
}

template <typename T> //A középpontos szabályon alapuló integrálás
T midp_integral(T (*f)(T x), double a, double b, int n) {

    T M = 0;

    double dx = (b - a) / n; //"lépésköz"

    for (int i = 0; i < n; i++) {
    
        M += f(a + (i + 0.5) * dx);
    }

    return M*dx;
    
}

template <typename T>
T trap_integral(T (*f)(T x), double a, double b, int n) { //Trapézszabályos integrálás

    double dx = (b - a) / n;

    T M = 0;

    for (int i = 0; i < n; ++i) {
    
        if (i == 0 || i == n-1) {
            
            M += f(a + i * dx);
            
        } else {
            
            M += 2*f(a + i * dx);
            
        }
        
    }

    return M * (dx/2);
}

template <typename T>
T simp_integral(T (*f)(T x), double a, double b, int n) { //Simpson 1/3-os szabályon alapuló integrálás

    T xi = 0;
    T xj = 0;

    double dx = (b - a) / n;

    T M = 0;

    for (int i = 2; i < n; i += 2) { //Páros indexelésű tagok
    
      xi += f(a + i * dx);
        
    }

    for(int i = 1; i < n; i += 2) { //Páratlan indexelésű tagok
    
      xj += f(a + i * dx);
        
    }

    M += f(a) + 4*xi + 2*xj + f(b);

    return M * (dx/3);
}

double arc_length(double x) { //Az integráláshoz szükséges ívhossz

    return sqrt(1 + (RO6(x, 1) * RO6(x, 1)));
}

int main(int argc, const char * argv[]) {

    const int n = 1000000;
    
    double mpint = midp_integral(arc_length, 0.0, 200.0, n);
    
    double tpint = trap_integral(arc_length, 0.0, 200.0, n);
    
    double spint = simp_integral(arc_length, 0.0, 200.0, n);
    

    std::ofstream ofile ("output.txt");

    if (ofile.is_open()) {
        
        ofile << "Középpontos integrál: " << mpint << ", ";
        ofile << "Trapéz integrál: " << tpint << ", ";
        ofile << "Simpson 1/3 integrál: " << spint;
            
        ofile.close();
    }

}
