class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum =0;
        int s1 =0;
                      s1= nums[0]*nums[1]*nums[n-1]; // 2 minimum and 1 maximum

        sum = nums[n-1]*nums[n-2]*nums[n-3];
        return max(s1,sum);
    }
};