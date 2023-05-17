#include "Team.hpp"
#include <algorithm>
#include <iostream>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include "Character.hpp"
#include "Point.hpp"
#include <string>


using namespace std;
namespace ariel {

    Team::Team(Character *l) : leader(l) {
        members.push_back(l);
    }

    void Team::add(Character *member) {
        members.push_back(member);
    }

    void Team::attack(Team *enemy) {
        if (!leader->isAlive()) {
            auto it = min_element(members.begin(), members.end(),
                                       [&](Character *c1, Character *c2) {
                                           return c1->distance(*leader) < c2->distance(*leader);
                                       });
            leader = *it;
        }

        Character *victim = nullptr;
        double minDistance = numeric_limits<double>::max();
        for (Character *enemyMember: enemy->members) {
            double dist = leader->distance(*enemyMember);
            if (dist < minDistance && enemyMember->isAlive()) {
                victim = enemyMember;
                minDistance = dist;
            }
        }

        if (victim == nullptr) {
            return;
        }

        for (Character *member: members) {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy != nullptr) {
                if (cowboy->hasBullets()) {
                    cowboy->shoot(*victim);
                } else {
                    cowboy->reload();
                }
            } else {
                Ninja *ninja = dynamic_cast<Ninja *>(member);
                if (ninja != nullptr) {
                    ninja->move(*victim);
                    ninja->slash(*victim);
                }
            }
        }

        if (!victim->isAlive()) {
            attack(enemy);
        }
    }

    int Team::stillAlive() const {
        int count = 0;
        for (Character *member: members) {
            if (member->isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team::print() const {
        for (Character *member: members) {
            member->print();
        }
    }

    Team::~Team() {
        for (Character *member: members) {
            delete member;
        }
    }
}