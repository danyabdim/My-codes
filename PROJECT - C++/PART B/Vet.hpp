#ifndef C44EFD48_28B2_4F31_9712_680D25E15EED
#define C44EFD48_28B2_4F31_9712_680D25E15EED

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"
#include "Libraries.hpp"

class Vet {
    private:
        std::vector< Animal* > animals;
    
    public:
        /// @brief Empty Constractor
        Vet();

        /// @brief Add animal to animal's vector
        /// @param an 
        void add_animal(Animal * &&an);

        /// @brief Show animals that are not in good shape
        void show_sick();

        /// @brief Show dogs (not cats or cows) that are not in good shape
        void show_sick_dogs();

        /// @brief Get Singelton Vet
        /// @return Singelton Vet
        static Vet& get_instance();

        /// @brief Destractor of Vet
        ~Vet();
};

#endif /* C44EFD48_28B2_4F31_9712_680D25E15EED */
