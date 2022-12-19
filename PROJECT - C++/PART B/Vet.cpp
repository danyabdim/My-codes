#include "Vet.hpp"

Vet::Vet() : animals() { }

void Vet::add_animal(Animal * &&an) {
    // Add the Animal to the animals vector
    animals.push_back(an);
}

void Vet::show_sick() {
    auto p = animals.begin(); // Begin of the vector
    std::cout << "The Sick Animals are:\n";

    while (p < animals.end()) { // Do until we are not in the end of the vector
        if (!((*p)->check_health())) { // Check if the Animal are not in good shape
            std::cout << (*p)->get_name() << " "; // Print the name's of the Sick Animal
        }
        (*p++); // Go to next Animal in the vector
    }

    std::cout << std::endl;
}

void Vet::show_sick_dogs() {
    auto p = animals.begin(); // Begin of the vector
    std::cout << "The Sick Dogs are:\n";

    while (p < animals.end()) { // Do until we are not in the end of the vector
        if
        ((!((*p)->check_health())) // Check if the Animal are not in good shape
        &&
        (typeid(**p).name() == typeid(Dog).name())) { // Check if the Animal is a Dog
            std::cout << (*p)->get_name() << " "; // Print the name's of the Sick Dog (not Cow or Cat)
        }
        (*p++); // Go to next Animal in the vector
    }

    std::cout << std::endl;
}

Vet& Vet::get_instance() {
    static Vet res;
    return res;
}

Vet::~Vet() {
    auto p = animals.begin(); // Begin of the vector
    
    while (p < animals.end()) { // Do until we are not in the end of the vector
        animals.erase(p); // Delete the Animal in the vecor
    }
}