#include "Cowboy.hpp"
#include "Character.hpp"
#include <iostream>
#include "Point.hpp"
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>


using namespace std;
namespace ariel {
    Cowboy::Cowboy(const Point &loc, int hp, const string &n) : Character(loc, hp, "C" + n), bullets(6) {}

    void Cowboy::shoot(Character &enemy) {
        if (isAlive() && hasBullets()) {
            enemy.hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() const {
        return bullets > 0;
    }

    void Cowboy::reload() {
        bullets = 6;
    }
}