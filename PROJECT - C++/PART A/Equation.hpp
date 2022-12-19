#ifndef ED5230BF_8428_46E0_AFA0_94296C0EA7EF
#define ED5230BF_8428_46E0_AFA0_94296C0EA7EF

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

class Equation {
    private:
        /// @brief A's (X^2) of the Equation
        double m_a;

        /// @brief B's (X) of the Equation
        double m_b;

        /// @brief C's (1) of the Equation
        double m_c;

        /// @brief Array of the Solutions
        double *solutions;

        /// @brief Number of Solutions
        size_t solution_size;

        /// @brief Solves the Equation, and updates the solutions & solution_size
        void solve_equation();

    public:
        /// @brief Constractor of Equation
        /// @param a 
        /// @param b 
        /// @param c 
        Equation(double a, double b, double c);

        /// @brief Constractor that takes another Equation's sources
        /// @param o 
        Equation(Equation const &o);

        /// @brief Constractor that takes another Equation's sources
        /// @param o 
        Equation(Equation &&o);

        /// @brief Get Function
        /// @return A's (X^2) of the Equation
        double get_a();

        /// @brief Get Function
        /// @return B's (X) of the Equation
        double get_b();

        /// @brief Get Function
        /// @return C's (1) of the Equation
        double get_c();

        /// @brief Set's A's (X^2) of the Equation value
        /// @param val 
        void set_a(double val);

        /// @brief Set's B's (X) of the Equation value
        /// @param val 
        void set_b(double val);

        /// @brief Set's C's (1) of the Equation value
        /// @param val 
        void set_c(double val);

        /// @brief Get Function
        /// @return Number of Solutions
        size_t get_solutions_size();

        /// @brief Get Function
        /// @return Array of the Solutions
        double const * get_solutions();

        /// @brief << operator
        /// @param out 
        /// @param eq 
        /// @return output stream
        friend std::ostream& operator <<(std::ostream &out, Equation const &eq);

        /// @brief Destruction
        ~Equation();

        /// @brief Assignment of another Equation into this
        /// @param o 
        /// @return this
        Equation& operator =(Equation const &o);

        /// @brief Assignment of another Equation into this
        /// @param o 
        /// @return this
        Equation& operator =(Equation &&o);
        
        /// @brief Doing Add Operator between 2 Equations
        /// @param right 
        /// @return this + Equation
        Equation operator +(Equation right);

        /// @brief Doing Add Operator between Equation and Double
        /// @param right 
        /// @return this + double
        Equation operator +(int right);

        /// @brief Doing Add Operator between Double and Equation
        /// @param left 
        /// @param right 
        /// @return double + Point
        friend Equation operator +(int left, Equation const &right);
};

#endif /* ED5230BF_8428_46E0_AFA0_94296C0EA7EF */
