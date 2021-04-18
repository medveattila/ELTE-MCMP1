//
//  main.cpp
//  HF4
//
//  Created by Medveczky Attila on 2021. 04. 18..
//

#include <iostream>
#include <fstream>
#include <math.h>


template<typename State, typename T, typename RHS>
auto solve_Newton(State y0, T t0, T t1, T h, RHS f) { //Megoldás a Newton módszerrel

    T t = t0;
    State y = y0;

    while (t < t1) {
    
        y = y + h * f(t, y);
        t = t + h;
        
    }
    
    return y;
}

template<typename State, typename T, typename RHS> //Megoldás a Runge-Kutta módszerrel
auto solve_RK4(State y0, T t0, T t1, T h, RHS f) {

    T t = t0;
    State y = y0;

    while (t < t1) {
    
        if (t + h > t1) {
        
             h = t1 - t;
        }

        State k1 = f(t, y);
        State k2 = f(t + h * (T)0.5, y + (h * (T)0.5) * k1);
        State k3 = f(t + h * (T)0.5, y + (h * (T)0.5) * k2);
        State k4 = f(t + h, y + h * k3);

        y = y + (k1 + k4 + (T)2 * (k2 + k3)) * (h / (T)6);
        t = t + h;
        
    }
    
    return y;
}


double diff_func(double t, double y) { //A feladatban megadott egyenlet

    return 1 + y * y;
    
}

int main(int argc, const char * argv[]) {

    double y0 = 0.0; //A szükséges paraméterek a megoldáshoz
    double t0 = 0.0;
    double t1 = 1.0;
    double h = 0.001;
    
    double analitikus = tan(t1);
    double Newton = solve_Newton(y0, t0, t1, h, diff_func);
    double RK4 = solve_RK4(y0, t0, t1, h, diff_func);

    std::ofstream ofile ("output.txt");

    if (ofile.is_open()) {
    
        ofile << "Analitikus megoldás: " << analitikus << ", " << "Newton-módszer megoldás: " << Newton << ", " << "Runge-Kutta megoldás: " << RK4;
        
        ofile.close();
    }
    
    
    return 0;
}
