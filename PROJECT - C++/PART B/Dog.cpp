#include "Dog.hpp"

Dog::Dog(std::string name, double temp, double breath, double heart, bool is_large) // use my parent's constractor and set is_large
: Animal(name, temp, breath, heart), is_large(is_large) { }

bool Dog::check_health() {
    if (temp < DOG_MIN_TEMP || temp > DOG_MAX_TEMP) { // Check if the Dog's tempature is between minumum and maximum
        return false;
    }

    if (breath < DOG_MIN_BREATH || breath > DOG_MAX_BREATH) { // Check if the Dog's breath is between minumum and maximum
        return false;
    }

    if (is_large == true && (heart < DOG_MIN_HEART_LARGE || heart > DOG_MAX_HEART_LARGE)) { // Check if the Large Dog's heartbeats is between minumum and maximum
        return false;
    }

    if (is_large == false && (heart < DOG_MIN_HEART_SMALL || heart > DOG_MAX_HEART_SMALL)) { // Check if the Small Dog's heartbeats is between minumum and maximum
        return false;
    }

    return true;
}

bool Dog::get_is_large() { return is_large; }
void Dog::set_is_large(bool val) { is_large = val; }