#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel {

    Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double Point::distance(const Point &other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    void Point::print() const {
        cout << "(" << x << ", " << y << ")";
    }

    Point Point::moveTo(const Point &source, const Point &destination, double distance) const {
        double dx = destination.x - source.x;
        double dy = destination.y - source.y;
        double currentDistance = std::sqrt(dx * dx + dy * dy);
        if (currentDistance <= distance) {
            return destination;
        } else {
            double ratio = distance / currentDistance;
            double newX = source.x + dx * ratio;
            double newY = source.y + dy * ratio;
            return Point(newX, newY);
        }
    }
}