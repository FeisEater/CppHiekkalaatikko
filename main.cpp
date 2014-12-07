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

//using namespace std;

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
/*
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
    X(X&& x) :i(x.i) {cerr << "Move constructed with " << i << endl;}
    X& operator=(X&& x)
    {
        i = x.i;
        cerr << "Move assignment with " << i << endl;
        return *this;
    }
private:
    int i;
};

#define execute(cmd) cout << "--Executing: " << #cmd << endl; cmd
X global_x;

int main(int argc, char** argv) {
    execute(X x1(5));
    execute(X x2(x1));
    execute(X x3(1));
    execute(x2 = x3);
    execute(vector<X> v(3));
    execute(X *x4 = new X(10));
    execute(delete(x4));
    execute(vector<X> v);
    execute(v.push_back(X(1000)));
    execute(X x1(1));
    execute(X x2(2));
    execute(x2 = move(x1));
}
*/
/*
template <typename T>
class complex
{
public:
    complex(T ix, T iy) : x(ix), y(iy)
    {
        static_assert(std::is_arithmetic<T>::value,
                          "Complex template's type is not arithmetic");
    }
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
        T denom = r.x * r.x + r.y * r.y;
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
    T x;
    T y;
};

int main(int argc, char** argv) {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    complex<double> c1(x1, y1);
    complex<double> c2(x2, y2);
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
/*
class SList
{
private:
    struct ListObject
    {
        ListObject* next;
        std::string value;
    };
    class list_iterator
    {
    public:
        list_iterator() : value(nullptr) {}
        list_iterator(ListObject* lo) : value(lo) {}
        std::string& operator* ()
        {
            return value->value;
        }
        std::string* operator-> ()
        {
            return &(value->value);
        }
        list_iterator& operator++ ()
        {
            value = value->next;
            return *this;
        }
        list_iterator operator++ ( int )
        {
            ListObject* lo = value;
            ++(*this);
            return list_iterator(lo);
        }
        friend bool operator==(list_iterator const& a, list_iterator const& b)
        {
            return a.value == b.value;
        }
        friend bool operator!=(list_iterator const& a, list_iterator const& b)
        {
            return !(a == b);
        }
    private:
        ListObject* value;
    };
    ListObject* head;
public:
    SList() : head(nullptr) {}
    SList(std::vector<std::string> initializor) : head(nullptr)
    {
        for (std::string s : initializor)
            push_front(s);
    }
    ~SList()
    {
       while (head)
           pop_front();
    }
    void push_front(std::string s)
    {
        ListObject* lo = new ListObject;
        lo->value = s;
        lo->next = head;
        head = lo;
    }
    void pop_front()
    {
        ListObject* lo = head;
        head = head->next;
        delete lo;
    }
    typedef const list_iterator iterator;
    iterator begin()    {return iterator(head);}
    iterator end()    {return iterator(nullptr);}
    void print()
    {
        for (auto i : *this)
            std::cout << i << std::endl;
        std::cout << "--------" << std::endl;
    }
};

int main(int argc, char** argv) {
    SList list;
    list.print();
    list.push_front("wassup");
    list.print();
    list.push_front("two strings");
    list.print();
    list.push_front("remove this");
    list.print();
    list.pop_front();
    list.print();
}
*/

class Vector {
public:
    Vector() : sz(5), space(5)
    {
        elem = new double[5];
        elem[0] = 0.0;
        elem[1] = 0.25;
        elem[2] = 0.5;
        elem[3] = 0.75;
        elem[4] = 1.0;
    }
    //iterator
    using iterator = double*; // can change the contents in-place

    iterator begin() { return elem; }		

    iterator end() { 
            if (elem) return elem + sz;
            return nullptr;
            //return elem + sz;  // (would work also because nullptr + 0 == nullptr)
    }

private:
    int sz;
    double * elem;
    int space;
};

int main(int argc, char** argv) {
    Vector v;
    double* elem = v.begin();
    for (int i = 0; i < 5; ++i)
        elem[i] = 69;
    for (auto i : v)
        std::cout << i << std::endl;
}