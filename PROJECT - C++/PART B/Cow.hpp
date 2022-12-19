#ifndef A4B67615_C014_478D_A968_E0A09B34101D
#define A4B67615_C014_478D_A968_E0A09B34101D

#include "Animal.hpp"
#include "Libraries.hpp"

#define COW_MIN_TEMP 38.5 // minimum of cow's tempature
#define COW_MAX_TEMP 39.5 // maximum of cow's tempature
#define COW_MIN_BREATH 26 // minimum of cow's breath
#define COW_MAX_BREATH 50 // maximum of cow's breath
#define COW_MIN_HEART 48 // minimum of cow's heartbeats
#define COW_MAX_HEART 84 // maximum of cow's heartbeats
#define COW_MIN_MILK 30 // minimum of cow's milk litters

class Cow : public Animal {
    private:
        double milk;

    public:
        /// @brief Constractor of Cow
        /// @param name 
        /// @param temp 
        /// @param breath 
        /// @param heart 
        /// @param liters 
        Cow(std::string name, double temp, double breath, double heart, double liters);

        /// @brief Checks if the Cow is in good shape
        /// @return true/false (bool)
        bool check_health();

        /// @brief getter of milk
        /// @return milk
        double get_milk();

        /// @brief setter of milk
        /// @param val 
        void set_milk(double val);
};

#endif /* A4B67615_C014_478D_A968_E0A09B34101D */
