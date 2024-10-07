#include "iostream"
#include <climits>
#include <cmath>
#include <ostream>

void PrintHello(void)
{
    std::cout << "Hello C++" << std::endl;
}

double GetSideByArea()
{
    using namespace std;
    double area;
    cout << "Enter the floor area: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "The side is " << side << endl;
    return (int)side;
}

void DataTypePractice()
{
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "short is " << sizeof n_short << " bytes" << endl;
    cout << "long is " << sizeof n_long << " bytes" << endl;
    cout << "long long is " << sizeof n_llong << " bytes" << endl;
    cout << endl;
    cout << "Maximum values: " << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;

    cout << "-------------------" << endl;
    int a(5);
    cout << "a = "<< a << endl;
}