#include <iostream>
#include <tuple>
#include <string>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    // Unpacking structure
    Point p{10, 20};
    auto [xVal, yVal] = p; // // work if the compiler supports C++17 or later
    /* Older style
    int x.Val = p.x;
    int y.Val = p.y;
    */
    cout << "Point: " << xVal << ", " << yVal << "\n";

    // Unpacking tuple
    tuple<int, string, double> item{1, "Apple", 2.99};
    auto [id, name, price] = item; // work if the compiler supports C++17 or later
    /* Older style
    int id = get<0>(item);
    string name = get<1>(item);
    double price = get<2>(item);*/
    cout << "Item: " << id << " " << name << " $" << price << "\n";

    return 0;
}
