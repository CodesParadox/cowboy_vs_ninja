#ifndef POINT_HPP
#define POINT_HPP
using namespace std;
namespace ariel {
    class Point {
    private:
        double x;
        double y;

    public:
        Point(double xCoord, double yCoord);

        double distance(const Point &other) const;

        void print() const;

        Point moveTo(const Point &source, const Point &destination, double distance) const;
    };
}
#endif