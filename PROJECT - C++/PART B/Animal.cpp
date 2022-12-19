#include "Animal.hpp"

Animal::Animal(std::string name, double temp, double breath, double heart)
: name(name), temp(temp), breath(breath), heart(heart) { }

Animal::Animal(Animal const &o)
: Animal(o.name, o.temp, o.breath, o.heart) { }

Animal::Animal(Animal &&o)
: Animal(o.name, o.temp, o.breath, o.heart) { }

Animal& Animal::operator =(Animal const &o) {
    if (this != &o) {
        // clean old resources + copy new resources from other
        name = o.name;
        temp = o.temp;
        breath = o.breath;
        heart = o.heart;
    }
    
    return *this;
}

Animal& Animal::operator =(Animal &&o) {
    // clean old one and replace with the other resources
    name = o.name;
    temp = o.temp;
    breath = o.breath;
    heart = o.heart;
    return *this;
}

std::string Animal::get_name() { return name; }
double Animal::get_temp()      { return temp; }
double Animal::get_breath()    { return breath; }
double Animal::get_heart()     { return heart; }

void Animal::set_name(std::string val) { name   = val; }
void Animal::set_temp  (bool val)      { temp   = val; }
void Animal::set_breath(bool val)      { breath = val; }
void Animal::set_heart (bool val)      { heart  = val; }