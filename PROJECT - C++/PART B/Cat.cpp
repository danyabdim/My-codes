#include "Cat.hpp"

Cat::Cat(std::string name, double temp, double breath, double heart) // use my parent's constractor
: Animal(name, temp, breath, heart) { }

bool Cat::check_health() {
    if (temp < CAT_MIN_TEMP || temp > CAT_MAX_TEMP) { // Check if the Cat's tempature is between minumum and maximum
        return false;
    }

    if (breath < CAT_MIN_BREATH || breath > CAT_MAX_BREATH) { // Check if the Cat's breath is between minumum and maximum
        return false;
    }

    if (heart < CAT_MIN_HEART || heart > CAT_MAX_HEART) { // Check if the Cat's heartbeats is between minumum and maximum
        return false;
    }

    return true;
}