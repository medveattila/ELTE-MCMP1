//
//  main.cpp
//  Monte-Carlo
//
//  Created by Medveczky Attila on 2021. 05. 06..
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <functional>
#include <random>
#include <chrono>
using namespace std::chrono;

template<typename INT, typename DOM>
auto MonteCarlo(INT f, DOM g, float a1, float b1, float a2, float b2, float a3, float b3) {
    
    double V = (b1-a1)*(b2-a2)*(b3-a3); //A tartomány bennfoglaló téglatestjének térfogata
    
    int const n = 1000000; //Futásszám
    
    double f1 = 0;
    double f2 = 0;
    
    //Először megnézzük az egyszerű "crude method"-ot
    
    for (int i = 0; i < n; i++) {
        
        double x = fabs(a1)*((double) rand()/RAND_MAX); //A téglatesten belül veszünk pontokat
        double y = fabs(a2)*((double) rand()/RAND_MAX);
        double z = fabs(a3)*((double) rand()/RAND_MAX);
    
        bool d = g(x, y, z); //Megnézzük, hogy a tartományon belül van-e a pont
        
        if (d == 1) {
            
            f1 += f(x, y, z);
            f2 += f(x, y, z)*f(x, y, z);
            
        }
        
    }
    
    f1 /= n;
    f2 /= n;
    
    double res = V*f1; //Az integrálásunk közelítése
    
    double sigma = V*sqrt((f2-f1*f1)/n);
    
    std::cout << "Integral value: " << res << " +/- " << sigma << " (Crude method)" << "\n" ;
    
    //Itt pedig az importance sampling methodot, amely esetén a hiba jóval kisebb
    
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 1);
    
    f1 = 0;
    f2 = 0;
    
    for (int j = 0; j < n; j++) {
        
        double x = distribution(generator);
        double y = distribution(generator);
        double z = distribution(generator);

        bool d = g(x, y, z);
        
        if (d == 1) {
            
            double w = ((1/sqrt(2*M_PI))*exp(-(x*x)/2))*((1/sqrt(2*M_PI))*exp(-(y*y)/2))*((1/sqrt(2*M_PI))*exp(-(z*z)/2)); //Ez a "súlyozás"
            
            f1 += f(x, y, z) / w;
            f2 += (f(x, y, z) / w)*(f(x, y, z) / w);
        
        }
    }
        
    f1 /= n;
    f2 /= n;
        
    res = f1;
    
    sigma = sqrt((f2-f1*f1)/n);
    
    std::cout << "Integral value: " << res << " +/- " << sigma << " (Importance sampling method)" << "\n";
        
}
    
int main(int argc, const char * argv[]) {

    
    auto start = high_resolution_clock::now();
    
    MonteCarlo( [](auto x, auto y, auto z){ return exp(-x*x-y*y-z*z); }, [](auto x, auto y, auto z)->bool{ return x*x+y*y+z*z<16.0; }, -4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
      
    std::cout << "Time taken by function: "
             << duration.count() << " microseconds" << "\n";

}
