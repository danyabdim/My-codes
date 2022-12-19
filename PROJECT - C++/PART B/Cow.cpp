#include "Cow.hpp"

Cow::Cow(std::string name, double temp, double breath, double heart, double liters) // use my parent's constractor and set milk
: Animal(name, temp, breath, heart), milk(liters) { }

bool Cow::check_health() {
    if (temp < COW_MIN_TEMP || temp > COW_MAX_TEMP) { // Check if the Cow's tempature is between minumum and maximum
        return false;
    }

    if (breath < COW_MIN_BREATH || breath > COW_MAX_BREATH) { // Check if the Cow's breath is between minumum and maximum
        return false;
    }

    if (heart < COW_MIN_HEART || heart > COW_MAX_HEART) { // Check if the Cow's heartbeats is between minumum and maximum
        return false;
    }

    if (milk < COW_MIN_MILK) { // Check if the Cow's milk is above the minimum
        return false;
    }

    return true;
}

double Cow::get_milk() { return milk; }
void Cow::set_milk(double val) { milk = val; }