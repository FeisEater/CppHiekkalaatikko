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

/*
class MyVector {
public:
    explicit MyVector(int sz) : array(new int[sz]), size(sz) {}
    int* array;
    int size;
};

void print(MyVector m)
{
    for (int i = 0; i < m.size; i++)
        cout << m.array[i] << " ";
    cout << endl;
}

int main(int argc, char** argv) {
    print(5);
    return 0;
}
*/

class X {
public:
    explicit X(int j) : i(j) {cerr << "Constructed with " << j << endl;}
    X() : i(69) {cerr << "Default construct" << endl;}
    X(X const& x) : i(x.i) {cerr << "Copy constructed with " << x.i << endl;}
    X& operator=(X const& x)
    {
        i = x.i;
        cerr << "Copy assignment with " << x.i << endl;
        return *this;
    }
    ~X() {cerr << "Destructed " << i << endl;}
    /*X(X&& x) :i(x.i) {cerr << "Move constructed with " << i << endl;}
    X& operator=(X&& x)
    {
        i = x.i;
        cerr << "Move assignment with " << i << endl;
        return *this;
    }*/
private:
    int i;
};

#define execute(cmd) cout << "--Executing: " << #cmd << endl; cmd
X global_x;

int main(int argc, char** argv) {
    /*execute(X x1(5));
    execute(X x2(x1));
    execute(X x3(1));
    execute(x2 = x3);
    execute(vector<X> v(3));
    execute(X *x4 = new X(10));
    execute(delete(x4));*/
    execute(vector<X> v);
    execute(v.push_back(X(1000)));
    execute(X x1(1));
    execute(X x2(2));
    execute(x2 = move(x1));
}

/*
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
*/