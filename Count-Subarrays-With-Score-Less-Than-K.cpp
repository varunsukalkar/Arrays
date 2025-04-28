class Solution {
public:
    
        using ll = long long;
        long long countSubarrays(vector<int>& nums, long long k) {
         
        ll count = 0, sum = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left++];
            }
            count += (right - left + 1);
        }
        return count;
    }
    
};