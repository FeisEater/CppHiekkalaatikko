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

using namespace std;

/*
 * 
 */
/*int main(int argc, char** argv) { // 1) remove bracket
    cout << "Hello world" << endl;// 2) don't terminate string
    vector<string> inputs;
    string s;
    while (cin >> s && s != "quit")
        inputs.push_back(s);
    for (string s : inputs)
        cout << s.length() << endl;// 4) < instead of <<
    return 0;//3) remove semicolon
}*/

//1) main.cpp:19:5: error: expected initializer before 'cout' -> bad diagnostic
//2) main.cpp:19:5: error: missing terminating " character -> good diagnostic
//3) main.cpp:27:1: error: expected ';' before '}' token -> good diagnostic
//4) main.cpp:25:28: error: no match for 'operator<' (operand types are 'std::basic_ostream<char>::__ostream_type {aka std::basic_ostream<char>}' and '<unresolved overloaded function type>')
//      -> good enough diagnostic
/*
enum class Operand {NONE, PLUS, MINUS, PRODUCT, DIVISION};

int main(int argc, char** argv) {
    Operand op = Operand::NONE;
    double result = 0;
    bool firstNumber = true;
    bool terminate = false;
    while (!terminate)
    {
        string s;
        double d;
        switch (op)
        {
            case Operand::NONE:
                cin >> s;
                if (s == "+")
                    op = Operand::PLUS;
                if (s == "-")
                    op = Operand::MINUS;
                if (s == "*")
                    op = Operand::PRODUCT;
                if (s == "/")
                    op = Operand::DIVISION;
                if (s == "quit")
                    terminate = true;
                break;
            case Operand::PLUS:
                if (cin >> d)
                    result += d;
                break;
            case Operand::PRODUCT:
                if (cin >> d)
                {
                    if (firstNumber)
                    {
                        result = d;
                        firstNumber = false;
                    }
                    else
                        result *= d;
                }
                break;
            case Operand::MINUS:
                if (cin >> d)
                {
                    if (firstNumber)
                    {
                        result = d;
                        firstNumber = false;
                    }
                    else
                        result -= d;
                }
                break;
            case Operand::DIVISION:
                if (cin >> d)
                {
                    if (firstNumber)
                    {
                        result = d;
                        firstNumber = false;
                    }
                    else
                        result /= d;
                    }
                break;
        }
        if (cin.fail())
        {
            cin.clear();
            char c;
            cin >> c;
            if (c == ';')
            {
                cout << result << endl;
                result = 0;
                firstNumber = true;
                op = Operand::NONE;
            }
        }
    }
}
*/

template<typename T>
vector<T> reverse(vector<T> in)
{
    vector<T> out;
    for (int i = in.size() - 1; i >= 0; i--)
        out.push_back(in[i]);
    return out;
}

template<typename T>
vector<T> reverse2(vector<T> in)
{
    for (int i = 0; i < in.size() / 2; i++)
    {
        T t = in[i];
        in[i] = in[in.size() - 1 - i];
        in[in.size() - 1 - i] = t;
    }
    return in;
}

int main(int argc, char** argv) {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    v = reverse2(v);
    for (int i : v)
        cout << i << endl;
}