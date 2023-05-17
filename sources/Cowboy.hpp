#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

using namespace std;
namespace ariel{

    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy(const Point &loc, int hp, const string &n);

        void shoot(Character &enemy);

        bool hasBullets() const;

        void reload();
    };
}

#endif
