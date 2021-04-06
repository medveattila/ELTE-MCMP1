#include"vector2.h"
#include<iostream>

int main()

{
    Vector2d<double> u{}, v{};
    double c;
    
    std::cout << "Enter vector 1 (u):\n";
    std::cin >> u;
    std::cout << "Enter vector 2 (v):\n";
    std::cin >> v;
    std::cout << "Enter number c:\n";
    std::cin >> c;
    std::cout << "\n";
    
    std::cout << "Inside class operations\n";
    std::cout << "-----------------------\n\n";
    
    u += v;
    
    std::cout << "Add v to u:\n" << u <<"\n";
    
    u -= v;
    
    std::cout << "Subtract v from new u:\n" << u <<"\n";
    
    u *= c;
    
    std::cout << "Multiply u by c:\n" << u << "\n";
    
    u /= c;
    
    std::cout << "Divide u with c:\n" << u << "\n\n";

    std::cout << "Outside class operations\n";
    std::cout << "-----------------------\n\n";
    
    
    std::cout << "Sum of the vectors:\n" << u + v << "\n";
    std::cout << "Difference of the vectors:\n" << u-v << "\n";
    std::cout << "Dot product of the vectors:\n" << dot(u,v) << "\n";
    std::cout << "Length of u:\n" << length(u) << "\n";
    std::cout << "Square of the length of u:\n"<< sqlength(u) <<"\n";
    std::cout << "u normalized:\n" << normalize(u) << "\n";
    std::cout << "u multiplied by c is:\n" << u*c <<"\n";
    std::cout << "c multiplied by u:\n" << c*u <<"\n";
    std::cout << "Divide u with c:\n" << u/c << "\n";

    return 0;

}
