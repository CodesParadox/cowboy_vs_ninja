#include "Ninja.hpp"
#include "Character.hpp"
#include <iostream>
#include "Point.hpp"
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>


using namespace std;
namespace ariel {
    Ninja::Ninja(const Point &loc, int hp, const string &n) : Character(loc, hp, n) {}

    YoungNinja::YoungNinja(const Point &loc, const string &n) : Ninja(loc, 100, "N" + n) {}

    void YoungNinja::move(const Character &enemy) {
        location = location.moveTo(location, enemy.getLocation(), speed);
    }

    void YoungNinja::slash(Character &enemy) {
        double dist = distance(enemy);
        if (isAlive() && dist < 1.0) {
            enemy.hit(40);
        }
    }

    TrainedNinja::TrainedNinja(const Point &loc, const string &n) : Ninja(loc, 120, "N" + n) {}

    void TrainedNinja::move(const Character &enemy) {
        location = location.moveTo(location, enemy.getLocation(), speed);
    }

    void TrainedNinja::slash(Character &enemy) {
        double dist = distance(enemy);
        if (isAlive() && dist < 1.0) {
            enemy.hit(40);
        }
    }

    OldNinja::OldNinja(const Point &loc, const string &n) : Ninja(loc, 150, "N" + n) {}

    void OldNinja::move(const Character &enemy) {
        location = location.moveTo(location, enemy.getLocation(), speed);
    }

    void OldNinja::slash(Character &enemy) {
        double dist = distance(enemy);
        if (isAlive() && dist < 1.0) {
            enemy.hit(40);
        }
    }
}