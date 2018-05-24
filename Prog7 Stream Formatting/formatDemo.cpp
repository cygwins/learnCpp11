/******
*
* Author: Yuge, Cheng
* School : City University of Seattle
* Course : CS555 C++ For Programmers
* Term : Spring, 2018
* Assignment : Program 7
* Due date : May 23, 2018
*
******/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "int formatting" << endl;
    int i = 42;
    cout << "cout << i << endl;" << endl;
    cout << i << endl;
    cout << "cout.setf(std::ios::oct, std::ios::basefield);" << endl;
    cout.setf(std::ios::oct, std::ios::basefield);
    cout << i << endl;
    cout << "cout.setf(std::ios::showbase);" << endl;
    cout.setf(std::ios::showbase);
    cout << i << endl;
    cout << "cout.setf(std::ios::hex, std::ios::basefield);" << endl;
    cout.setf(std::ios::hex, std::ios::basefield);
    cout << i << endl;
    cout << "cout.unsetf(std::ios::showbase);" << endl;
    cout.unsetf(std::ios::showbase);
    cout << i << endl;
    cout << "cout.setf(std::ios::dec, std::ios::basefield);" << endl;
    cout.setf(std::ios::dec, std::ios::basefield);
    cout << i << endl;
    cout << "cout.width(10);" << endl;
    cout.width(10);
    cout << i << endl;
    cout << i << endl; // note the width setting does NOT  work for the second time

    cout << endl << "float formatting" << endl;
    float f = 314.15;
    cout << "cout << f << endl;" << endl;
    cout << f << endl;
    cout << "cout.setf(std::ios::scientific, std::ios::floatfield);" << endl;
    cout.setf(std::ios::scientific, std::ios::floatfield);
    cout << f << endl;
    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout << "cout.setf(std::ios::fixed, std::ios::floatfield);" << endl;
    cout << f << endl;
    cout.precision(1);
    cout << "cout.precision(1);" << endl;
    cout << f << endl;

    cout << endl << "istring stream" << endl;
    std::string istr{"123 abc"}; // we bind this string to a string stream
    std::string ostr; // output string
    int oint; // output int
    std::istringstream iss(istr);
    iss >> oint >> ostr;
    cout << "iss >> oint >> ostr;" << endl;
    cout << "istr: " << istr << endl;
    cout << "ostr: " << ostr << endl;
    cout << "oint: " << oint << endl;

    cout << endl << "ostring stream" << endl;
    std::ostringstream oss;
    for(int i = 5; i > 0; --i) {
        oss << i << "! ";
    }
    oss << "HAPPY NEW YEAR!!!" << endl;
    cout << oss.str() << endl;
    return 0;
}
