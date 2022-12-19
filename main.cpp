#include "Equation.hpp"

int main() {
    //using namespace std;
    
    Equation eq(10,20,30); 
    std::cout << eq << std::endl;
    //should print: 10X^2 + 20X + 30 = 0
    
    std::cout << eq.get_solutions_size() << std::endl;
    //should print 0
    
    eq = -20 + eq;
    std::cout << eq << std::endl;
    //should print: 10X^2 + 20X + 10 = 0
    
    std::cout << eq.get_solutions_size() << std::endl;
    //should print 1
    
    std::cout << eq.get_solutions()[0] << std::endl;
    //should print -1
    
    std::cout << Equation(1,5,3) + Equation(2,6,4) << std::endl;
    //should print: 3X^2 + 11X + 7 = 0
    
    eq = Equation(1,3,-4);
    std::cout << eq << std::endl;
    //should print 1X^2 + 3X + -4 = 0

    std::cout << eq.get_solutions_size() << std::endl;
    //should print 2

    std::cout << "X1 = " << eq.get_solutions()[0] << std::endl;
    //should print: X1 = 1

    std::cout << "X2 = " << eq.get_solutions()[1] << std::endl;
    //should print: X2 = -4

    return 0;
}