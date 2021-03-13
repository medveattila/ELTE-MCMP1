
#include <iostream>

template <typename F1, typename F2, typename T>
T Newton(F1 fun, F2 dif, T x0) { //A függvény bemeneti paramétereinek típusa nincs meghatátozva
    
    double eps = 0.0000001; //Az elérni kívánt pontosság
    
    if (dif(x0) < eps) { //Ha a derivált az x0-ban 0, akkor 0-val kéne osztani, az nem szerencsés
                        //Itt azt vesszük 0-nak, ha a kapott eredmény az epsilon-nál kisebb
        std::cout << "Error: Derivate of the function is 0.\n";
        return 0;
        
    }
    
    double x1 = x0 - (fun(x0)/dif(x0)); //A Newton-Raphson módszer szerinti képlet
    
    while (fabs(x1-x0) > eps) { //Addig csináljuk az iterációt, amíg a 2 egymást követően kapott
                              //eredmény kisebb lesz, mint az epsilon
        if (dif(x1) < eps) { //Mindig megnézzük, hogy nem-e lép fel 0-val való osztás
            
            std::cout << "Error: Derivate of the function is 0.\n";
            return 0;
            
        }
        
        x0 = x1;
        
        x1 = x0 - (fun(x0)/dif(x0));
        
    }
    
    return x1;
    
}

int main(int argc, const char * argv[]) {
    
    std::cout.precision(17); //Beállítjuk a tizedesjegyek számát
    
    std::cout << std::fixed << Newton([](double x){ return x*x-612.0;},[](double x){ return 2.0*x; }, 10.0) << "\n"; //A próba fgv, ami a diában szerepelt
    
}
