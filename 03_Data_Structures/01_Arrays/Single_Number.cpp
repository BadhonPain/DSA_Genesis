#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {3, 2, 2, 4, 4, 3, 5};
    int ans = 0;
    for (int i : nums)
    {
        ans ^= i;
    }
    cout << ans << endl;
}