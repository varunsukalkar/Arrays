class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 2;
        int count=0;
        while(j<nums.size())
            {
                if(nums[i+1]== 2*(nums[i]+nums[j])){
                    count++;
                    i++;
                    j++;
                }
                else{
                    i++;
                    j++;
                    
                }
            }
        return count;
    }
};