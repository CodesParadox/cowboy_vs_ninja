#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

using namespace std;
namespace ariel {

    class Ninja : public Character {
    public:
        Ninja(const Point &loc, int hp, const string &n);

        virtual void move(const Character &enemy) = 0;

        virtual void slash(Character &enemy) = 0;
    };

    class YoungNinja : public Ninja {
    private:
        static const int speed = 14;

    public:
        YoungNinja(const Point &loc, const string &n);

        void move(const Character &enemy) override;

        void slash(Character &enemy) override;
    };

    class TrainedNinja : public Ninja {
    private:
        static const int speed = 12;

    public:
        TrainedNinja(const Point &loc, const string &n);

        void move(const Character &enemy) override;

        void slash(Character &enemy) override;
    };

    class OldNinja : public Ninja {
    private:
        static const int speed = 8;

    public:
        OldNinja(const Point &loc, const string &n);

        void move(const Character &enemy) override;

        void slash(Character &enemy) override;
    };
}

#endif
