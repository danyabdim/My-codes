#include "Equation.hpp"

Equation::Equation(double a, double b, double c)
: m_a(a), m_b(b), m_c(c), solutions(nullptr), solution_size(0)
{
    if (m_a == 0) { // if A's (X^2) of the Equation is 0 - throw
        throw std::invalid_argument("A is 0; Can't solve that.");
    }
    solve_equation(); // Solves the Equation, and updates the solutions & solution_size
}

Equation::Equation(Equation const &o) : Equation(o.m_a, o.m_b, o.m_c) { }
Equation::Equation(Equation &&o) : Equation(o.m_a, o.m_b, o.m_c) { }

void Equation::solve_equation() {
    delete[] solutions;
    solutions = nullptr;

    // solving what inside the sqrt
    double before_res_sqrt = pow(m_b, 2) - (4 * m_a * m_c);

    if (before_res_sqrt < 0) { // if bellow 0 - no solutions can be found
        solutions = nullptr;
        solution_size = 0;
        //std::cout << "There is no solutions to this\n";
    } else {
        double res_sqrt = sqrt(before_res_sqrt); // sqrt the inside
        double res1 = (0 - m_b - res_sqrt) / (2.0 * m_a); // first solution
        double res2 = (0 - m_b + res_sqrt) / (2.0 * m_a); // second solution

        solutions = new double[2] {res1, res2}; // Set solution as array of 2 double
        solution_size = (res1 == res2) ? 1 : 2; // Set the size to 2

        /*
        if (res1 == res2) { // the solutions are equal to each other - the sqrt was 0
            solutions = new double{res1};
            solution_size = 1;
        } else { // the solutions are not equal to each other
            solutions = new double[2] {res1, res2};
            solution_size = 2;
        }
        */
    }
}

double   Equation::get_a() { return m_a; }
double   Equation::get_b() { return m_b; }
double   Equation::get_c() { return m_c; }
void     Equation::set_a(double val) { m_a = val; }
void     Equation::set_b(double val) { m_b = val; }
void     Equation::set_c(double val) { m_c = val; }
size_t   Equation::get_solutions_size() { return solution_size; }
double const * Equation::get_solutions() { return solutions; }

std::ostream& operator <<(std::ostream &out, Equation const &eq) {
    // streaming the Equation out
    return out
    << ((int)(eq.m_a * 10) / 10.0) << "X^2 + "
    << ((int)(eq.m_b * 10) / 10.0) << "X + "
    << ((int)(eq.m_c * 10) / 10.0) << " = 0"
    << std::endl;
}

Equation::~Equation() {
    delete[] solutions;
    solutions = nullptr;
}

Equation& Equation::operator =(Equation const &o) {
    if (this != &o) {
        // clean old resources
        delete[] solutions;
        solutions = nullptr;
        
        // copy new resources from other
        m_a = o.m_a;
        m_b = o.m_b;
        m_c = o.m_c;
        solutions = new double{*o.solutions};
        solution_size = o.solution_size;
    }

    return *this;
}

Equation& Equation::operator =(Equation &&o) {
    // clean old one and replace with the other resources
    m_a = o.m_a;
    m_b = o.m_b;
    m_c = o.m_c;

    delete solutions;
    solutions = o.solutions;
    o.solutions = nullptr;

    solution_size = o.solution_size;
    return *this;
}

//this + Equation
Equation Equation::operator +(Equation right) {
    return {m_a + right.m_a, m_b + right.m_b, m_c + right.m_c};
}

//this + double
Equation Equation::operator +(int right) {
    return {m_a, m_b, m_c + right};
}

// double + Point
Equation operator +(int left, Equation const &right) {
    return {right.m_a, right.m_b, right.m_c + left};
}