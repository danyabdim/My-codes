#ifndef C18125FE_EA33_46BD_A2F5_B8953DC4CFA9
#define C18125FE_EA33_46BD_A2F5_B8953DC4CFA9

#include "Animal.hpp"
#include "Libraries.hpp"

#define CAT_MIN_TEMP 38 // minimum of cat's tempature
#define CAT_MAX_TEMP 39.2 // maximum of cat's tempature
#define CAT_MIN_BREATH 16 // minimum of cat's breath
#define CAT_MAX_BREATH 40 // maximum of cat's breath
#define CAT_MIN_HEART 120 // minimum of cat's heartbeats
#define CAT_MAX_HEART 140 // maximum of cat's heartbeats

class Cat : public Animal {
    public:
        /// @brief Constractor of Cat
        /// @param name 
        /// @param temp 
        /// @param breath 
        /// @param heart 
        Cat(std::string name, double temp, double breath, double heart);

        /// @brief Checks if the Cat is in good shape
        /// @return true/false (bool)
        bool check_health();
};

#endif /* C18125FE_EA33_46BD_A2F5_B8953DC4CFA9 */
