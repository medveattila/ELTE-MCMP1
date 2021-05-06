
#include <iostream>
#include <chrono>
#include "montecarlo.h"

using namespace std::chrono;


int main(int argc, const char * argv[]) {

    
    auto start = high_resolution_clock::now();
    
    MonteCarlo( [](auto x, auto y, auto z){ return exp(-x*x-y*y-z*z); }, [](auto x, auto y, auto z)->bool{ return x*x+y*y+z*z<16.0; }, -4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
      
    std::cout << "Time taken by function: "
             << duration.count() << " microseconds" << "\n";

}
