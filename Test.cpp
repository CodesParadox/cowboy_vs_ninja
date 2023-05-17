#include "doctest.h"
#include "Team.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <exception>
#include <iostream>
#include <cmath>
#include <memory>
using namespace std;
using namespace ariel;

TEST_CASE("Cowboy Creation")
{
    Point p1(0, 0);
    Cowboy *c1 = new Cowboy("Cow", p1);
    CHECK(c1->getName() == "CCow");
    CHECK(c1->getLocation() == p1);
    CHECK(c1->isAlive() == true);
    CHECK(c1->hasBullets() == true);
    delete c1;
}
TEST_CASE("Team Battle")
{
    Point p1(0, 0);
    Team teamA;
    Team teamB;
    Cowboy *c1 = new Cowboy("Tom", p1);
    OldNinja *n1 = new OldNinja("Ninja1", p1);
    TrainedNinja *n2 = new TrainedNinja("Ninja2", p1);
    teamA.add(c1);
    teamA.add(n1);
    teamB.add(n2);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 1);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 0);

    delete c1;
    delete n1;
    delete n2;
}

TEST_CASE("Multiple Battles")
{
    Point p1(0, 0);
    Team teamA;
    Team teamB;
    Cowboy *c1 = new Cowboy("Tom", p1);
    OldNinja *n1 = new OldNinja("Ninja1", p1);
    YoungNinja *n2 = new YoungNinja("Ninja2", p1);
    TrainedNinja *n3 = new TrainedNinja("Ninja3", p1);
    teamA.add(c1);
    teamA.add(n1);
    teamB.add(n2);
    teamB.add(n3);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 2);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 1);

    teamB.attack(&teamA);

    CHECK(teamA.stillAlive() == 1);
    CHECK(teamB.stillAlive() == 1);

    teamB.attack(&teamA);

    CHECK(teamA.stillAlive() == 0);
    CHECK(teamB.stillAlive() == 1);

    delete c1;
    delete n1;
    delete n2;
    delete n3;
}

TEST_CASE("Character Movement")
{
    Point p1(0, 0);
    Point p2(10, 10);
    Cowboy *c1 = new Cowboy("Tom", p1);
    c1->move(p2);
    CHECK(c1->getPosition() == p2);

    delete c1;
}

TEST_CASE("Character Attacks")
{
    Point p1(0, 0);
    Cowboy *c1 = new Cowboy("Tom", p1);
    OldNinja *n1 = new OldNinja("Ninja1", p1);
    TrainedNinja *n2 = new TrainedNinja("Ninja2", p1);

    c1->shoot(n1);
    CHECK(n1->getHP() == 100);

    n2->slash(c1);
    CHECK(c1->getHP() == 80);

    delete c1;
    delete n1;
    delete n2;
}

TEST_CASE("Team Battle with Multiple Rounds")
{
    Point p1(0, 0);
    Team teamA;
    Team teamB;

    Cowboy *c1 = new Cowboy("Tom", p1);
    Cowboy *c2 = new Cowboy("Jerry", p1);
    OldNinja *n1 = new OldNinja("Ninja1", p1);
    TrainedNinja *n2 = new TrainedNinja("Ninja2", p1);

    teamA.add(c1);
    teamA.add(n1);
    teamB.add(c2);
    teamB.add(n2);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 2);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 1);

    teamB.attack(&teamA);

    CHECK(teamA.stillAlive() == 1);
    CHECK(teamB.stillAlive() == 1);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 0);

    delete c1;
    delete c2;
    delete n1;
    delete n2;
}

TEST_CASE("Team Battle with Different Character Types")
{
    Point p1(0, 0);
    Team teamA;
    Team teamB;

    Cowboy *c1 = new Cowboy("Tom", p1);
    YoungNinja *n1 = new YoungNinja("Ninja1", p1);
    TrainedNinja *n2 = new TrainedNinja("Ninja2", p1);

    teamA.add(c1);
    teamB.add(n1);
    teamB.add(n2);

    CHECK(teamA.stillAlive() == 1);
    CHECK(teamB.stillAlive() == 2);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 0);
    CHECK(teamB.stillAlive() == 2);

    delete c1;
    delete n1;
    delete n2;
}
