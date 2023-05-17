#include "Character.hpp"
#include <iostream>
#include "Point.hpp"
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>

using namespace std;
namespace ariel{

Character::Character(const Point &loc, int hp, const string &n) : location(loc), hitPoints(hp), name(n) {}

bool Character::isAlive() const {
    return hitPoints > 0;
}

double Character::distance(const Character &other) const {
    return location.distance(other.location);
}

void Character::hit(int amount) {
    hitPoints -= amount;
    if (hitPoints < 0) {
        hitPoints = 0;
    }
}

string Character::getName() const {
    return name;
}

Point Character::getLocation() const {
    return location;
}

void Character::print() const {
    cout << "[" << (isAlive() ? " " : "(");
    cout << (name[0] == 'N' ? "Ninja" : "Cowboy") << "] ";
    cout << name << ", HP: " << hitPoints << ", Location: ";
    location.print();
    if (!isAlive()) {
        cout << ")";
    }
    cout << endl;
}

}