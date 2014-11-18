/* 
 * File:   main.cpp
 * Author: FeisEater
 *
 * Created on November 8, 2014, 8:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/*
 * 
 */

class complex
{
public:
    complex(double ix, double iy) : x(ix), y(iy) {};
    friend complex operator+(complex l, const complex& r)
    {
        l.x += r.x;
        l.y += r.y;
        return l;
    }
    friend complex operator-(complex l, const complex& r)
    {
        l.x -= r.x;
        l.y -= r.y;
        return l;
    }
    friend complex operator*(complex l, const complex& r)
    {
        return complex(l.x * r.x - l.y * r.y, l.x * r.y + r.x * l.y);
    }
    friend complex operator/(complex l, const complex& r)
    {
        double denom = r.x * r.x + r.y * r.y;
        if (denom == 0) throw overflow_error("Divide by zero exception");
        return complex((l.x * r.x + l.y * r.y) / denom,
                (l.y * r.x - l.x * r.y) / denom);
    }
    friend ostream& operator<<(std::ostream& os, const complex& obj)
    {
        os << "(" << obj.x << ", " << obj.y << ")";
        return os;
    }

private:
    double x;
    double y;
};

int main(int argc, char** argv) {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    complex c1(x1, y1);
    complex c2(x2, y2);
    cout << c1 << " + " << c2 << " = " << (c1 + c2) << endl;
    cout << c1 << " - " << c2 << " = " << (c1 - c2) << endl;
    cout << c1 << " * " << c2 << " = " << (c1 * c2) << endl;
    try
    {
        cout << c1 << " / " << c2 << " = " << (c1 / c2) << endl;
    }
    catch (overflow_error& e)
    {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
