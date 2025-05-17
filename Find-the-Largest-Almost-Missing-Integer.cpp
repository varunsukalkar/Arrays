class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
           unordered_map<int, int> countMap;
    for (int i = 0; i <= nums.size() - k; i++) {
        unordered_set<int> uniqueVals(nums.begin() + i, nums.begin() + i + k); // Unique elements in subarray
        for (int val : uniqueVals) {
            countMap[val]++;
        }
    }
    int result = -1;
    for (auto& [num, count] : countMap) {
        if (count == 1) {
            result = max(result, num);
        }
    }

    return result;
    }
};