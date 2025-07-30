#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        double x;
        double y;
    public:
        // constructors for class point
        Point() {
            x = y = 0;
        }
        Point(double a, double b) {
            x = a;
            y = b;
        }

        // virtual function to calculate distance
        virtual double calcDistance(const Point& sPoint) const {
            return sqrt(pow(x - sPoint.x, 2) + pow(y - sPoint.y, 2));
        }

        // friend function to calculate distance
        friend double calcDistance(const Point& point1, const Point& point2){
            return point1.calcDistance(point2);
        }

        // function to find quadrant
        int findQuad() const {
            if (x > 0 && y > 0){
                return 1;
            } else if (x < 0 && y > 0) {
                return 2;
            } else if (x < 0 && y < 0) {
                return 3;
            } else if (x > 0 && y < 0) {
                return 4;
            } else {
                return 0;
            }
        }

        Point sum (const Point& sPoint) const {
            return Point(x + sPoint.x, y + sPoint.y);
        }

        Point mult (const Point& sPoint) const {
            return Point(x * sPoint.x, y * sPoint.y);
        }

        Point min (const Point& sPoint) const {
            return Point(x - sPoint.x, y - sPoint.y);
        }

        Point div (const Point& sPoint) const {
            if (sPoint.x != 0 && sPoint.y != 0){
                return Point(x / sPoint.x, y / sPoint.y);
            } else {
                // cout << "can't divide by zero";
                return Point(x,y);
            }
        }

        // Getter  and Setter
        void setx(double h) {
            x = h;
        }
        void sety(double g) {
            y = g;
        }
        double getx() const {
            return (x);
        }
        double gety() const {
            return (y);
        }

        // Operator overloads
        Point operator+(const Point& other) const {
            return sum(other);
        }
        Point operator*(const Point& other) const {
            return mult(other);
        }
        friend ostream& operator<<(ostream& os, const Point& pt) {
            os << "(" << pt.x << ", " << pt.y << ")";
            return os;
        }
};

class Circle : public Point {
    private:
        double rad;
    public:
        Circle (double x, double y, double rad) : Point(x, y), rad(rad){}

        double area() const
        {
            return (3.14 * rad * rad);
        }

        double circum() const
        {
            return (3.14 * 2 * rad);
        }

        void relation(const Circle& t) const
        {
            double d = this->calcDistance(t);
            if (d > rad + t.rad)
                cout << "far" << endl;
            else if (d < fabs(rad - t.rad))
                cout << "one inside another" << endl;
            else if (d == rad + t.rad)
                cout << "touching externally" << endl;
            else if (d == fabs(rad - t.rad))
                cout << "touching internally" << endl;
            else
                cout << "intersecting" << endl;
        }
};

int main() {
    Point point1(1.0, 2.0);
    Point point2(3.0, 4.0);

    double dist = point1.calcDistance(point2);
    cout << "The distance is: " << dist << endl;
    // using friend function
    dist = calcDistance(point1, point2);
    cout << "The distance is: " << dist << endl;
    
    int quad = point1.findQuad();
    cout << "The point is in quad: " << quad << endl;

    Point sum = point1 + point2;
    Point mul = point1 * point2;
    cout << "The sum of two points is: " << sum << endl;
    cout << "The mul of two points is: " << mul << endl;

    // Circle
    Circle cir(1.0, 2.0, 5.0);
    double area = cir.area();
    double circum = cir.circum();
    cout << "Area: " << area << ", Circumference: " << circum << endl;
    
    Circle cir2(10.0, 10.0, 2.0);
    cir.relation(cir2);
    
    return 0;
}