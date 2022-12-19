#ifndef C3962CB9_8B6C_4A09_B0E6_2DF3C818E5BA
#define C3962CB9_8B6C_4A09_B0E6_2DF3C818E5BA

#include "Animal.hpp"
#include "Libraries.hpp"

#define DOG_MIN_TEMP 38 // minimum of dog's tempature
#define DOG_MAX_TEMP 39.2 // maximum of dog's tempature
#define DOG_MIN_BREATH 10 // minimum of dog's breath
#define DOG_MAX_BREATH 35 // maximum of dog's breath
#define DOG_MIN_HEART_LARGE 60 // minimum of large dog's heartbeats
#define DOG_MAX_HEART_LARGE 100 // maximum of large dog's heartbeats
#define DOG_MIN_HEART_SMALL 100 // minimum of small dog's heartbeats
#define DOG_MAX_HEART_SMALL 140 // maximum of small dog's heartbeats

class Dog : public Animal {
    private:
        bool is_large;
        
    public:
        /// @brief Constractor of Dog
        /// @param name 
        /// @param temp 
        /// @param breath 
        /// @param heart 
        /// @param is_large 
        Dog(std::string name, double temp, double breath, double heart, bool is_large);

        /// @brief Checks if the Dog is in good shape
        /// @return true/false (bool)
        bool check_health();

        /// @brief getter of is_large
        /// @return is_large 
        bool get_is_large();

        /// @brief setter of is_large
        /// @param val 
        void set_is_large(bool val);
};

#endif /* C3962CB9_8B6C_4A09_B0E6_2DF3C818E5BA */
