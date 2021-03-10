
#include <iostream>

template <typename F1, typename F2, typename T>
T Newton(F1 fun, F2 dif, T x0) {
    
    double eps = 0.0000001;
    
    if (dif(x0) < eps) {
        
        std::cout << "Error: Derivate of the function is 0.\n";
        return 0;
        
    }
    
    double x1 = x0 - (fun(x0)/dif(x0));
    
    while (fabs(x1-x0) > eps) {

        if (dif(x1) < eps) {
            
            std::cout << "Error: Derivate of the function is 0.\n";
            return 0;
            
        }
        
        x0 = x1;
        
        x1 = x0 - (fun(x0)/dif(x0));
        
    }
    
    return x1;
    
}

int main(int argc, const char * argv[]) {
    
    std::cout.precision(17);
    
    std::cout << std::fixed << Newton([](double x){ return x*x-612.0;},[](double x){ return 2.0*x; }, 10.0) << "\n";
    
}
