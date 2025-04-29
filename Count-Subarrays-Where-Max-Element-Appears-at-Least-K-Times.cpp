class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long maxi = *max_element(nums.begin(), nums.end()), res = 0, left = 0; 
        unordered_map <int,int> mpp;
        for (int i = 0 ; i < nums.size() ; i++) {
            mpp[nums[i]]++;
            if (mpp[maxi] >= k) {
                while (left < nums.size() && mpp[maxi] >= k) {
                    mpp[nums[left++]]--;
                }
            }
            res += left;
        } 
        return res;
    }
};