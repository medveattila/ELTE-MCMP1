
#include <iostream>

template <typename F1, typename F2, typename T>
T Newton(F1 fun, F2 dif, T x0) {
    
    double x1 = x0 - (fun(x0)/dif(x0));
    
    while (fabs(x1-x0) > 0.0000001) {

        x0 = x1;
        
        x1 = x0 - (fun(x0)/dif(x0));
        
    }
    
    return x1;
    
}

int main(int argc, const char * argv[]) {
    
    std::cout << Newton([](double x){ return x*x-612.0;},[](double x){ return 2.0*x; }, 10.0) << "\n";
    
}
