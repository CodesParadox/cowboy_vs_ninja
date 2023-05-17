#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
namespace ariel {
    class Character {
    protected:
        Point location;
        int hitPoints;
        string name;

    public:
        Character(const Point &loc, int hp, const string &n);

        bool isAlive() const;

        double distance(const Character &other) const;

        void hit(int amount);

        string getName() const;

        Point getLocation() const;

        void print() const;
    };
}
#endif
