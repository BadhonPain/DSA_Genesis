#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 100;

int count_x(char *ptr, char x)
{
    if (ptr == nullptr)
        return 0;
    int count = 0;
    for (; *ptr != '0'; ++ptr)
    {
        if (*ptr == x)
           ++count;
    }

    return count;
}

int main()
{
    char arr[MAX_SIZE] = {'b', 'a', 'd', 'h', 'o', 'n', 'p', 'a', 'i', 'n','0'};
    char *charPtr = arr;
    cout << count_x(charPtr, 'n') << endl;
}