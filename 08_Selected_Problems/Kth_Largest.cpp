#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void maxHeapify(vector<int>& nums, int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        int length = nums.size();

        if (left < length && nums[left] > nums[i])
            largest = left;
        if (right < length && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[largest], nums[i]);
            maxHeapify(nums, largest);
        }
    }

    int extractMax(vector<int>& nums) {
        int oldMax = nums[0];
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        maxHeapify(nums, 0);

        return oldMax;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        for (int i = nums.size() / 2 - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
        int ans = 0;
        while (k--) {
            ans = extractMax(nums);
        }

        return ans;
    }
};