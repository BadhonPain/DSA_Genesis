#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, finish;
};

bool compareActivity(const Activity &s1, const Activity &s2)
{
    return s1.finish < s2.finish;
}

void selectActivities(vector<Activity> &arr)
{
    sort(arr.begin(), arr.end(), compareActivity);

    cout << "Selected Activities: \n";
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j;
        }
    }
}

int main()
{
    vector<Activity> arr = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    selectActivities(arr);
    return 0;
}
