#ifndef B90430D0_2F08_4A6D_8350_02EDF24AA653
#define B90430D0_2F08_4A6D_8350_02EDF24AA653

#include "Libraries.hpp"

class Animal {
    protected:
        std::string name;
        double temp;
        double breath;
        double heart;

    public:
        /// @brief Empty Constractor of Animal
        Animal();

        /// @brief Constractor of Animal
        /// @param name 
        /// @param temp 
        /// @param breath 
        /// @param heart 
        Animal(std::string name, double temp, double breath, double heart);
        
        /// @brief Constractor that takes another Animal's sources
        /// @param o 
        Animal(Animal const &o);

        /// @brief Constractor that takes another Animal's sources
        /// @param o 
        Animal(Animal &&o);

        /// @brief Assignment of another Equation into this
        /// @param o 
        /// @return this
        Animal& operator =(Animal const &o);

        /// @brief Assignment of another Equation into this
        /// @param o 
        /// @return this
        Animal& operator =(Animal &&o);

        /// @brief Gets the Animal's name
        /// @return name
        std::string get_name();

        /// @brief Gets the Animal's tempature
        /// @return temp
        double get_temp();

        /// @brief Gets the Animal's breath
        /// @return breath
        double get_breath();

        /// @brief Gets the Animal's heartbeats
        /// @return heart
        double get_heart();

        /// @brief Sets the Animal's name
        /// @param val 
        void set_name(std::string val);


        /// @brief Sets the Animal's tempature
        /// @param val 
        void set_temp  (bool val);

        /// @brief Sets the Animal's breath
        /// @param val 
        void set_breath(bool val);

        /// @brief Sets the Animal's heartbeats
        /// @param val 
        void set_heart (bool val);

        /// @brief Checks if the Animal is in good shape
        /// @return true/false (bool)
        virtual bool check_health()=0;

        /// @brief Destractor of Animal
        virtual ~Animal() = default;
};

#endif /* B90430D0_2F08_4A6D_8350_02EDF24AA653 */
