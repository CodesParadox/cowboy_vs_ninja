#ifndef TEAM_HPP
#define TEAM_HPP

#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>

using namespace std;

namespace ariel {


    class Team {
    private:
        vector<Character *> members;
        Character *leader;

    public:
        Team(Character *l);

        void add(Character *member);

        void attack(Team *enemy);

        int stillAlive() const;

        void print() const;

        ~Team();
    };
}
#endif
